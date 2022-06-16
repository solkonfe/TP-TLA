#include "../support/logger.h"
#include "generator.h"
#include <stdlib.h>

/**
 * Implementación de "generator.h".
 */

FILE * file;

char * Generator(tProgram * result) {
	//LogInfo("El resultado de la expresion computada es: '%d'.", result);

	file = fopen("out.html", "w+");

	if (result == NULL || result->initial == NULL){
		LogInfo("El resultado de la compilacion es nulo.");
		return NULL;
	}

	//Abro HTML
	//strcat(toPrint, "<!DOCTYPE html>\n<html>\n<body>");
	fprintf(file, "<!DOCTYPE html>\n<html>\n\t<head>\n\t<meta charset=\"utf-8\">\n</head>\n<body>\n");

	//strcat(toPrint, printHTML(result->initial->first));
	printPage(result->initial);

	//toPrint = realloc(toPrint, 50);
	//strcat(toPrint, "</body>\n</html>");
	fprintf(file, "</body>\n</html>\n\n");
/*
	if(result->initial->size > 1)
		freeAllMemory(result->initial->first);
	freeExpression(result->initial->first);
	free(result->initial);
*/
	fclose(file);
	return NULL;
}

void printPage(tWebExprs * expressions){
	tWebExpr * current = expressions->first;
	while (current != NULL){
		printHTML(current);
		current = current->next;
	}
}

void printCellInformation(tRowData * data){ //TODO: Reduce this function, está copiada en otra función
	int bold = 0, italic = 0, underlined = 0, color = 0, align = 0;
	fprintf(file, "\n\t<td");
	if(data->rowAttrs != NULL){
		tAttribute * current = data->rowAttrs->first;
		while(current != NULL){
			switch (current->type){
				case COLORVAL:
					fprintf(file, " color=%s", current->value);
					color = 1;
					break;
				case POSITIONVAL:
					fprintf(file, " style=\"text-align:%s;\"", current->value);
					align = 1;
					break;
				case BOLDVAL:
					bold = 1;
					break;
				case ITALICVAL:
					italic = 1;
					break;
				case UNDERLINEDVAL:
					underlined = 1;
					break;
			}
			current = current->next;
		}
	}
	fprintf(file, ">");
	if (bold == 1)
		fprintf(file, "<b>");
	if (italic == 1)
		fprintf(file, "<i>");
	if (underlined == 1)
		fprintf(file, "<u>");
	
	fprintf(file, "%s", data->value);
	
	if (underlined == 1)
		fprintf(file, "</u>");
	if (italic == 1)
		fprintf(file, "</i>");
	if (bold == 1)
		fprintf(file, "</b>");
	
}

void printTable(tTable * table){
	fprintf(file, "<table style=\"border:1px solid black;\">\n");
	tRow * auxRowPtr = table->firstRow->firstRow;
	for(int row = 0; row < table->rowsDeclared; row++){
		fprintf(file, "<tr>");
		if(auxRowPtr != NULL){
			tRowData * auxDataPtr = auxRowPtr->firstCell;
			for(int col = 0; col < table->colsDeclared; col++){
				if(auxDataPtr != NULL){
					printCellInformation(auxDataPtr);
					auxDataPtr = auxDataPtr->nextCell;
				}
				else{
					fprintf(file, "\n\t<td>");
				}
				fprintf(file, "</td>\n");
			}
			auxRowPtr = auxRowPtr->nextRow;
		}
		fprintf(file, "</tr>\n");
	}
	fprintf(file, "</table>\n");
}

void printHTML(tWebExpr * result){

	tWebExpr * current = result;

	switch (current->type) {
		case TITLEEXPR:
			printTitle(current->expr);
			break;
		case IMGEXPR:
            printImage(current->expr);
			break;
		case LINKEXPR:
            printLink(current->expr);
			break;
		case TABLEEXPR:
			printTable(current->expr);
			break;
		case DIVEXPR:
			printDiv(current->expr);
			break;
		case TEXTEXPR:
			printText(current->expr);
			break;
		default:
			fprintf(file, "\nNone matched\n");
			break;
	}
}

void printText(tText * text){
	fprintf(file, "<p");
	if (text->ID != NULL)
		fprintf(file, " %s", text->ID); 
	int bold = 0, italic = 0, underlined = 0;
	if(text->attrs != NULL){
		tAttribute * current= text->attrs->first;
		while(current != NULL){
			switch (current->type){
				case COLORVAL:
					fprintf(file, " color=\"%s\"", current->value);
					break;
				case POSITIONVAL:
					fprintf(file, " style=\"text-align:%s;\"", current->value);
					break;
				case BOLDVAL:
					bold = 1;
					break;
				case ITALICVAL:
					italic = 1;
					break;
				case UNDERLINEDVAL:
					underlined = 1;
					break;
			}
			current = current->next;
		}
	}
	fprintf(file, ">");
	if (bold == 1)
		fprintf(file, "<b>");
	if (italic == 1)
		fprintf(file, "<i>");
	if (underlined == 1)
		fprintf(file, "<u>");
	
	fprintf(file, "%s", text->content);
	
	if (underlined == 1)
		fprintf(file, "</u>");
	if (italic == 1)
		fprintf(file, "</i>");
	if (bold == 1)
		fprintf(file, "</b>");
	

	fprintf(file, "</p>\n");
}

char * possibleSizes[6] = {"x-small", "small", "medium", "large", "x-large", "xx-large"};
#define MAX_SIZES 6

int getSizeOfTitle(char * sizeName){
	for(int i = 0; i < MAX_SIZES; i++){
		if(strcmp(sizeName, possibleSizes[i]) == 0){
			int aux = MAX_SIZES-i;
			return aux;
		}
	}
	return -1;
}

void printTitle(tTitle * title){
	int bold = 0, italic = 0, underlined = 0;

	int size = 6;
	if (title->attrs != NULL && title->attrs->titleSize != NULL){
		size = getSizeOfTitle(title->attrs->titleSize);
	}

	fprintf(file, "<h%d", size);

	if (title->attrs != NULL){

		if (title->attrs->ID != NULL)
			fprintf(file, " id=\"%s\"", title->attrs->ID);
		
		tAttribute * currAttr = title->attrs->first;
		while (currAttr != NULL){
			switch (currAttr->type){
				case COLORVAL:
					fprintf(file, " color=%s", currAttr->value);
					break;
				case POSITIONVAL:
					fprintf(file, " style=\"text-align:%s;\"", currAttr->value);
					break;
				case BOLDVAL:
					bold = 1;
					break;
				case ITALICVAL:
					italic = 1;
					break;
				case UNDERLINEDVAL:
					underlined = 1;
					break;
			}	
			currAttr = currAttr->next;
		}
	}
	fprintf(file, ">");
	if (bold == 1)
		fprintf(file, "<b>");
	if (italic == 1)
		fprintf(file, "<i>");
	if (underlined == 1)
		fprintf(file, "<u>");

	
	fprintf(file, "%s", title->value);

	if (underlined == 1)
		fprintf(file, "</u>");
	if (italic == 1)
		fprintf(file, "</i>");
	if (bold == 1)
		fprintf(file, "</b>");
	

	fprintf(file, "</h%d>\n", size);
}


void printImage(tImage* image){
	fprintf(file, "<img");
	fprintf(file, " %s", image->source); //habria que ver si ya lo estamos guardando con comillas
	if(image->idref != NULL){
		fprintf(file, " %s", image->idref);
	}
	if(image->altText != NULL){
		fprintf(file, " alt=%s", image->altText);
	}
	fprintf(file, ">\n");
}

void printLink(tLink * link){
	fprintf(file, "<a");
	fprintf(file, " href=\"%s\"", link->ref); //fijarse lo de las comillas
	int bold = 0, italic = 0, underlined = 0;
	if(link->attrs != NULL){
		tAttribute * current= link->attrs->first;
		while(current != NULL){
			switch (current->type){
				case COLORVAL:
					fprintf(file, " color=%s", current->value);
					break;
				case POSITIONVAL:
					fprintf(file, " style=\"text-align:%s;\"", current->value);
					break;
				case BOLDVAL:
					bold = 1;
					break;
				case ITALICVAL:
					italic = 1;
					break;
				case UNDERLINEDVAL:
					underlined = 1;
					break;
			}
			current = current->next;
		}
	}
	fprintf(file, ">");
	if (bold == 1)
		fprintf(file, "<b>");
	if (italic == 1)
		fprintf(file, "<i>");
	if (underlined == 1)
		fprintf(file, "<u>");
	
	fprintf(file, "%s", link->text);
	
	if (underlined == 1)
		fprintf(file, "</u>");
	if (italic == 1)
		fprintf(file, "</i>");
	if (bold == 1)
		fprintf(file, "</b>");
	

	fprintf(file, "</a>\n");
}

void printDiv(tDiv * div){
	fprintf(file, "<div>\n");
	printPage(div->content);
	fprintf(file, "</div>\n");
}



/*
			FREEING MEMORY FUNCTIONS
*/



void freeAllMemory(tWebExpr * expr){
	if(expr == NULL){
		printf("error");
		return;
	}
	else if(expr->next->next == NULL){
		freeExpression(expr->next);
		tWebExpr * prev = expr->next;
		expr->next = NULL;
		free(prev);
		return;
	}
	else{
		freeAllMemory(expr->next);
		freeExpression(expr->next);
		tWebExpr * prev = expr->next;
		expr->next = NULL;
		free(prev);
		return;
	}
}

void freeAttributes(tAttribute * attrs){
	if(attrs == NULL){
		return;
	}
	else if(attrs->next->next == NULL){
		free(attrs->next->value);
		tAttribute * prev = attrs->next;
		attrs->next = NULL;
		free(prev);
		return;
	}
	else{
		freeAttributes(attrs->next);
		free(attrs->next->value);
		tAttribute * prev = attrs->next;
		attrs->next = NULL;
		free(prev);
		return;
	}
}

void freeAttrsWrp(tAttributes * result){
	if(result == NULL)
		return;

	if(result->size > 1)
		freeAttributes(result->first);
	free(result->first->value);
	free(result->first->next);
	free(result->first);
}

void freeTAttrsWrp(tTitleAttrs * result){
	if(result == NULL)
		return;

	if(result->size > 1)
		freeAttributes(result->first);
	free(result->first->value);
	free(result->first->next);
	free(result->first);
}

void freeRows(tRow * row){

}

void freeExpression(tWebExpr * expr){
	switch(expr->type){
		case TITLEEXPR:
		{
			tTitle * aux = (tTitle *) expr->expr;
			free(aux->value);
			freeTAttrsWrp(aux->attrs); // TODO: freeTAttributes(tTitleAttrs * attrs);
			free(aux->attrs->titleSize);
			free(aux->attrs->ID);
			free(aux->attrs);
			free(aux);
			free(expr);
			return;
		}
		case IMGEXPR:
		{
			tImage * aux = (tImage *) expr->expr;
			free(aux->source);
			free(aux->idref);
			free(aux->altText);
			free(aux);
			free(expr);
			return;
		}
		case LINKEXPR:
		{
			tLink * aux = (tLink *) expr->expr;
			free(aux->ref);
			free(aux->text);
			freeAttrsWrp(aux->attrs);
			free(aux->attrs);
			free(aux);
			free(expr);
			return;
		}
		case TABLEEXPR:
		{
			tTable * aux = (tTable *) expr->expr;
			// expr->expr->firstRow->firstRow->firstCell->value
			freeRows(aux->firstRow->firstRow); // tRow *
			// TODO: freeRows(tRow * row);
			// Desde aca puedo liberar todas las filas
			free(aux->firstRow->firstRow);
			free(aux->firstRow);
			free(aux);
			free(expr);
			return;
		}
		case DIVEXPR:
		{
			tDiv * aux = (tDiv *) expr->expr;
			free(aux->attrs->pos);// TODO: freeDAttributes(tDivAttrs * attrs);
			free(aux->attrs->ID);
			freeAllMemory(aux->content->first);
			free(aux->content);
			free(aux);
			free(expr);
			return;
		}
		case TEXTEXPR:
		{
			tText * aux = (tText *) expr->expr;
			freeAttrsWrp(aux->attrs); // TODO: freeAttributes(tAttributes * attrs);
			free(aux->ID);
			free(aux->content);
			free(aux);
			free(expr);
			return;
		}
		default:
			free(expr);
			break;
	}
}