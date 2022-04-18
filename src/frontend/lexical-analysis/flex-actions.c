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
	LogDebug("TitleSizePatternAction: '%s'.", lexeme);
	return TITLE_SIZE;
}

TokenID ColorPatternAction(const char * lexeme){
	LogDebug("ColorPatternAction: '%s'.", lexeme);
	return COLOR;
}

TokenID PositionPatternAction(const char * lexeme){
	LogDebug("PositionTokenPattern: '%s'.", lexeme);
	return POSITION;
}

TokenID ContentPatternAction(const char * lexeme) {
	LogDebug("ContentPatternAction: '%s'.", lexeme);
	return CONTENT;
}

TokenID LinkPatternAction(const char * lexeme) {
	LogDebug("LinkPatternAction: '%s'.", lexeme);
	return LINK;
}

TokenID IdrefPatternAction(const char * lexeme){
	LogDebug("IDrefPatternAction: '%s'.", lexeme);
	return IDREF;
}

TokenID IdPatternAction(const char * lexeme){
	LogDebug("IDPatternAction: '%s'.", lexeme);
	return ID;
}

TokenID SourcePatternAction(const char * lexeme){
	LogDebug("SourcePatternAction: '%s'.", lexeme);
	return SOURCE;
}

TokenID TitleTokenPattern(const char * lexeme){
	LogDebug("TitlePatternAction: '%s'.", lexeme);
	return TITLE;
}

TokenID HyperlinkPatternAction(const char * lexeme){
	LogDebug("HyperlinkPatternACtion: '%s'", lexeme);
	return HYPERLINK;
}

void IgnoredPatternAction(const char * lexeme) {
	//LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
