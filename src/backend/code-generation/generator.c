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
			printTitle(current->expr);
		case IMGEXPR:
		case LINKEXPR:
		case TABLEEXPR:
		case DIVEXPR:
		case TEXTEXPR:
		default:
			break;
	}
}

void printTitle(tTitle * title){
	printf("<title ");
	int bold = 0, italic = 0, underlined = 0;
	if (title->attrs != NULL){
		printf("size=%d ", title->attrs->titleSize);
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
		}
	}
	printf(">");
	if (bold == 1)
		printf("</b>");
	if (italic == 1)
		printf("</i>");
	if (underlined == 1)
		printf("</u>");
	
	printf("%s", title->value);
	
	if (bold == 1)
		printf("<b>");
	if (italic == 1)
		printf("<i>");
	if (underlined == 1)
		printf("<u>");

	printf("</title>");
}
