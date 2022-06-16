#include "../support/logger.h"
#include "generator.h"
#include <stdlib.h>

/**
 * Implementación de "generator.h".
 */

char * Generator(tProgram * result) {
	//LogInfo("El resultado de la expresion computada es: '%d'.", result);

	char * toPrint = NULL;

	if (result == NULL || result->initial == NULL){
		LogInfo("El resultado de la compilacion es nulo.");
		return NULL;
	}

	//Abro HTML
	//strcat(toPrint, "<!DOCTYPE html>\n<html>\n<body>");
	printf("<!DOCTYPE html>\n<html>\n\t<head>\n\t<meta charset=\"utf-8\">\n</head>\n<body>\n");

	//strcat(toPrint, printHTML(result->initial->first));
	printPage(result->initial);

	//toPrint = realloc(toPrint, 50);
	//strcat(toPrint, "</body>\n</html>");
	printf("</body>\n</html>\n\n");
/*
	if(result->initial->size > 1)
		freeAllMemory(result->initial->first);
	freeExpression(result->initial->first);
	free(result->initial);
*/
	return toPrint;
}

void printPage(tWebExprs * expressions){
	tWebExpr * current = expressions->first;
	while (current != NULL){
		printHTML(current, NULL);
		current = current->next;
	}
}

void printCellInformation(tRowData * data){ //TODO: Reduce this function, está copiada en otra función
	int bold = 0, italic = 0, underlined = 0, color = 0, align = 0;
	printf("\n\t<td");
	if(data->rowAttrs != NULL){
		tAttribute * current = data->rowAttrs->first;
		while(current != NULL){
			switch (current->type){
				case COLORVAL:
					printf(" color=%s", current->value);
					color = 1;
					break;
				case POSITIONVAL:
					printf(" align=%s", current->value);
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
	printf(">");
	if (bold == 1)
		printf("<b>");
	if (italic == 1)
		printf("<i>");
	if (underlined == 1)
		printf("<u>");
	
	printf("%s", data->value);
	
	if (underlined == 1)
		printf("</u>");
	if (italic == 1)
		printf("</i>");
	if (bold == 1)
		printf("</b>");
	
}

void printTable(tTable * table){
	printf("<table>\n");
	//printf("rows: %d, cols: %d\n", table->rowsDeclared, table->colsDeclared);
	tRow * auxRowPtr = table->firstRow->firstRow;
	for(int row = 0; row < table->rowsDeclared; row++){
		printf("<tr>");
		if(auxRowPtr != NULL){
			tRowData * auxDataPtr = auxRowPtr->firstCell;
			for(int col = 0; col < table->colsDeclared; col++){
				if(auxDataPtr != NULL){
					printCellInformation(auxDataPtr);
					auxDataPtr = auxDataPtr->nextCell;
				}
				else{
					printf("\n\t<td>");
				}
				printf("</td>\n");
			}
			auxRowPtr = auxRowPtr->nextRow;
		}
		else{
			printf(">");
		}
		printf("</tr>\n");
	}
	printf("</table>\n");
}

void printHTML(tWebExpr * result, char * text){

	tWebExpr * current = result;
	text = realloc(text, 50);

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
			printf("\nNone matched\n");
			break;
	}
}

void printText(tText * text){
	printf("<p");
	if (text->ID != NULL)
		printf(" id= %s", text->ID); 
	int bold = 0, italic = 0, underlined = 0;
	if(text->attrs != NULL){
		tAttribute * current= text->attrs->first;
		while(current != NULL){
			switch (current->type){
				case COLORVAL:
					printf(" color=\"%s\"", current->value);
					break;
				case POSITIONVAL:
					printf(" position=\"%s\"", current->value);
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
	printf(">");
	if (bold == 1)
		printf("<b>");
	if (italic == 1)
		printf("<i>");
	if (underlined == 1)
		printf("<u>");
	
	printf("%s", text->content);
	
	if (underlined == 1)
		printf("</u>");
	if (italic == 1)
		printf("</i>");
	if (bold == 1)
		printf("</b>");
	

	printf("</p>\n");
}

char * possibleSizes[6] = {"x-small", "small:", "medium", "large", "x-large", "xx-large"};
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

	printf("<h%d", size);

	if (title->attrs != NULL){

		if (title->attrs->ID != NULL)
			printf(" id=\"%s\"", title->attrs->ID);
		
		tAttribute * currAttr = title->attrs->first;
		while (currAttr != NULL){
			switch (currAttr->type){
				case COLORVAL:
					printf(" color=%s", currAttr->value);
					break;
				case POSITIONVAL:
					printf(" position=%s", currAttr->value);
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
	printf(">");
	if (bold == 1)
		printf("<b>");
	if (italic == 1)
		printf("<i>");
	if (underlined == 1)
		printf("<u>");

	
	printf("%s", title->value);

	if (underlined == 1)
		printf("</u>");
	if (italic == 1)
		printf("</i>");
	if (bold == 1)
		printf("</b>");
	

	printf("</h%d>\n", size);
}


void printImage(tImage* image){
	printf("<img");
	printf(" %s", image->source); //habria que ver si ya lo estamos guardando con comillas
	if(image->idref != NULL){
		printf(" %s", image->idref);
	}
	if(image->altText != NULL){
		printf(" alt=%s", image->altText);
	}
	printf(">\n");
}

void printLink(tLink * link){
	printf("<link");
	printf(" href=\"%s\"", link->ref); //fijarse lo de las comillas
	int bold = 0, italic = 0, underlined = 0;
	if(link->attrs != NULL){
		tAttribute * current= link->attrs->first;
		while(current != NULL){
			switch (current->type){
				case COLORVAL:
					printf(" color=%s", current->value);
					break;
				case POSITIONVAL:
					printf(" position=%s", current->value);
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
	printf(">");
	if (bold == 1)
		printf("<b>");
	if (italic == 1)
		printf("<i>");
	if (underlined == 1)
		printf("<u>");
	
	printf("%s", link->text);
	
	if (underlined == 1)
		printf("</u>");
	if (italic == 1)
		printf("</i>");
	if (bold == 1)
		printf("</b>");
	

	printf("</link>\n");
}

void printDiv(tDiv * div){
	printf("<div>\n");
	char * toPrint = NULL;
	printPage(div->content);
	printf("</div>\n");
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