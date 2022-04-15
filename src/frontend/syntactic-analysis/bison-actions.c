#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

/**
 * Implementación de "bison-grammar.h".
 */

void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

int ProgramGrammarAction(const int value) {
	LogDebug("Reconozco patrón. ProgramGrammarAction(%d)", value);
	state.succeed = true;
	state.result = value;
	return value;
}

int WebGrammarAction(const int value){
	LogDebug("Reconozco patrón. WebGrammarAction(%d)", value);
	return value;
}

int TitleGrammarAction(const int value){
	LogDebug("Reconozco patrón. TitleGrammarAction(%d)", value);
	return value;
}

int FactorExpressionGrammarAction(const int value) {
	LogDebug("FactorExpressionGrammarAction(%d)", value);
	return value;
}

int ExpressionFactorGrammarAction(const int value) {
	LogDebug("ExpressionFactorGrammarAction(%d)", value);
	return value;
}

int ConstantFactorGrammarAction(const int value) {
	LogDebug("ConstantFactorGrammarAction(%d)", value);
	return value;
}

int IntegerConstantGrammarAction(const int value) {
	LogDebug("IntegerConstantGrammarAction(%d)", value);
	return value;
}
