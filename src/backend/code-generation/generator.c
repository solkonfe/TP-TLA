#include "../support/logger.h"
#include "generator.h"

/**
 * Implementación de "generator.h".
 */

char * Generator(tProgram * result) {
	//LogInfo("El resultado de la expresion computada es: '%d'.", result);

	char * toPrint = malloc(BLOCK);

	if (toPrint == NULL){
		print("Error generando memoria");
		return;
	}

	if (result == NULL){
		LogInfo("El resultado de la compilacion es nulo.");
		return;
	}

	//Abro HTML
	strcat(toPrint, "<!DOCTYPE html>\n<html>\n<body>");

	strcat(toPrint, printHTML(result->initial->first));

	toPrint = realloc(toPrint, 50);
	strcat(toPrint, "</body>\n</html>");

	return toPrint;
}

void printHTML(tWebExpr * result, char * text){

	tWebExpr * current = result;

	switch (current->type) {
		case expr_type.TITLEEXPR:
			tTitle * title = (tTitle)current->expr;
		case expr_type.IMGEXPR:
		case expr_type.LINKEXPR:
		case expr_type.TABLEEXPR:
		case expr_type.DIVEXPR:
		case expr_type.TEXTEXPR:
	}
}
