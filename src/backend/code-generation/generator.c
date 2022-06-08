#include "../support/logger.h"
#include "generator.h"
#include <stdlib.h>

/**
 * Implementación de "generator.h".
 */

char * Generator(tProgram * result) {
	//LogInfo("El resultado de la expresion computada es: '%d'.", result);

	char * toPrint = NULL;

	if (result == NULL){
		LogInfo("El resultado de la compilacion es nulo.");
		return NULL;
	}

	//Abro HTML
	//strcat(toPrint, "<!DOCTYPE html>\n<html>\n<body>");
	printf("<!DOCTYPE html>\n<html>\n<body>");

	//strcat(toPrint, printHTML(result->initial->first));
	printHTML(result->initial->first, toPrint);

	//toPrint = realloc(toPrint, 50);
	//strcat(toPrint, "</body>\n</html>");
	printf("</body>\n</html>");

	return toPrint;
}

void printHTML(tWebExpr * result, char * text){

	tWebExpr * current = result;
	text = realloc(text, 50);

	switch (current->type) {
		case TITLEEXPR:
			//printf("Title expr...");
			printTitle(current->expr);
			break;
		case IMGEXPR:
            printImage(current->expr);
			break;
		case LINKEXPR:
            printLink(current->expr);
			break;
		case TABLEEXPR:
			printTable(current->expr); //TODO
			break;
		case DIVEXPR:
			//printf("Div expr...");
			printDiv(current->expr); //TODO
			break;
		case TEXTEXPR:
			printText(current->expr); //TODO
			break;
		default:
			printf("\nNone matched\n");
			break;
	}
}

void printText(tText * text){}
void printTable(tTable * table){}
void printDiv(tDiv * div){}

char * possibleSizes[6] = {"x-small", "small", "medium", "large", "x-large", "xx-large"};
#define MAX_SIZES 6

char * getSizeOfTitle(char * sizeName){
	for(int i = 0; i < MAX_SIZES; i++){
		if(strcmp(sizeName, possibleSizes[i]) == 0)
			return MAX_SIZES-i;
	}
	return -1;
}

void printTitle(tTitle * title){
	printf("<h");
	int bold = 0, italic = 0, underlined = 0;
	if (title->attrs != NULL){

		char * size = getSizeOfTitle(title->attrs->titleSize);
		printf("%s ", size);

		//printf("size=%d ", title->attrs->titleSize);

		if (title->attrs->ID != NULL)
			printf("id=\"%s\" ", title->attrs->ID);
		
		tAttribute * currAttr = title->attrs->first;
		while (currAttr != NULL){
			switch (currAttr->type){
				case COLORVAL:
					printf("color=%s ", currAttr->value);
					break;
				case POSITIONVAL:
					printf("position=%s ", currAttr->value);
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
	
	if (bold == 1)
		printf("</b>");
	if (italic == 1)
		printf("</i>");
	if (underlined == 1)
		printf("</u>");

	printf("</title>");
}


void printImage(tImage* image){
	printf("<img ");
	printf("src=\"%s\" ", image->source); //habria que ver si ya lo estamos guardando con comillas
	if(image->idref != NULL){
		printf("id=\"%s\" ", image->idref);
	}
	if(image->altText != NULL){
		printf("alt=\"%s\" ", image->altText);
	}
	printf("/img>");
}

void printLink(tLink * link){
	printf("<link ");
	printf("href=\"%s\"", link->ref); //fijarse lo de las comillas
	int bold = 0, italic = 0, underlined = 0;
	if(link->attrs != NULL){
		tAttribute * current= link->attrs->first;
		while(current != NULL){
			switch (current->type){
				case COLORVAL:
					printf("color=%s ", current->value);
					break;
				case POSITIONVAL:
					printf("position=%s ", current->value);
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
	
	if (bold == 1)
		printf("</b>");
	if (italic == 1)
		printf("</i>");
	if (underlined == 1)
		printf("</u>");

	printf("</link>");
}