#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID TextPatternAction(char * lexeme){
	LogDebug("TextPatternAction: '%s'.", lexeme);
	//memmove(lexeme, lexeme+1, strlen(lexeme));

	// TODO: Sacar comillas del final
	yytext = lexeme;
	return TEXT;

}

TokenID AtrColorPatternAction(char * lexeme){
	LogDebug("AtrColorPatternAction: '%s'.", lexeme);
	yytext = lexeme;
	return ATR_COLOR;
}

TokenID AtrPositionPatternAction(char * lexeme){
	LogDebug("AtrColorPatternAction: '%s'.", lexeme);
	yytext = lexeme;
	return ATR_POSITION;
}

TokenID LinkPatternAction(char * lexeme){
	LogDebug("LinkPatternAction: '%s'.", lexeme);
	yytext = lexeme;
	return LINK;
}

TokenID IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
