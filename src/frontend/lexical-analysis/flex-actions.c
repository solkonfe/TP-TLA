#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID StartTokenPattern(const char * lexeme) {
	LogDebug("StartTokenPattern: '%s'.", lexeme);
	return START;
}

TokenID EndTokenPattern(const char * lexeme) {
	LogDebug("EndTokenPattern: '%s'.", lexeme);
	return END;
}

TokenID BoxTokenPattern(const char * lexeme) {
	LogDebug("BoxTokenPattern: '%s'.", lexeme);
	return BOX;
}

TokenID EndBoxTokenPattern(const char * lexeme) {
	LogDebug("EndBoxTokenPattern: '%s'.", lexeme);
	return ENDBOX;
}

TokenID TitleSizePatternAction(const char * lexeme) {
	LogDebug("ColorTokenPattern: '%s'.", lexeme);
	return TITLE_SIZE;
}

TokenID ColorPatternAction(const char * lexeme){
	LogDebug("ColorTokenPattern: '%s'.", lexeme);
	return COLOR;
}

TokenID PositionPatternAction(const char * lexeme){
	LogDebug("PositionTokenPattern: '%s'.", lexeme);
	return POSITION;
}

TokenID IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

TokenID TitleTokenPattern(const char * lexeme){
	LogDebug("TitlePatternAction: '%s'.", lexeme);
	return TITLE;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

TokenID UnknownPatternAction(const char *lexeme)
{
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}

TokenID WordPatternAction(const char *lexeme)
{
	LogDebug("WordPatternAction: '%s'.", lexeme);
	return WORD;
}
