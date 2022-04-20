#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID StartTokenPattern(const char *lexeme)
{
	LogDebug("StartTokenPattern: '%s'.", lexeme);
	return START;
}

TokenID EndTokenPattern(const char *lexeme)
{
	LogDebug("EndTokenPattern: '%s'.", lexeme);
	return END;
}

TokenID BoxTokenPattern(const char *lexeme)
{
	LogDebug("BoxTokenPattern: '%s'.", lexeme);
	return BOX;
}

TokenID EndBoxTokenPattern(const char *lexeme)
{
	LogDebug("EndBoxTokenPattern: '%s'.", lexeme);
	return ENDBOX;
}

TokenID TitleTokenPattern(const char *lexeme)
{
	LogDebug("TitleTokenPattern: '%s'.", lexeme);
	return TITLE;
}

TokenID TableTokenPattern(const char *lexeme)
{
	LogDebug("TableTokenPattern: '%s'.", lexeme);
	return TABLE;
}

TokenID EndTableTokenPattern(const char *lexeme)
{
	LogDebug("EndTableTokenPattern: '%s'.", lexeme);
	return ENDTABLE;
}

TokenID RandomTokenPattern(const char *lexeme)
{
	LogDebug("RandomTokenPattern: '%s'.", lexeme);
	return RANDOM;
}

TokenID ImageTokenPattern(const char *lexeme)
{
	LogDebug("ImageTokenPattern: '%s'.", lexeme);
	return IMAGE;
}

TokenID HyperlinkTokenPattern(const char *lexeme)
{
	LogDebug("HyperlinkTokenPattern: '%s'.", lexeme);
	return HYPERLINK;
}

TokenID BoldTokenPattern(const char *lexeme)
{
	LogDebug("BoldTokenPattern: '%s'.", lexeme);
	return BOLD;
}

TokenID ItalicTokenPattern(const char *lexeme)
{
	LogDebug("ItalicTokenPattern: '%s'.", lexeme);
	return ITALIC;
}

TokenID UnderlinedTokenPattern(const char *lexeme)
{
	LogDebug("UnderlinedTokenPattern: '%s'.", lexeme);
	return UNDERLINED;
}

TokenID RowTokenPattern(const char *lexeme)
{
	LogDebug("RowTokenPattern: '%s'.", lexeme);
	return ROW;
}

TokenID EndRowTokenPattern(const char *lexeme)
{
	LogDebug("EndRowTokenPattern: '%s'.", lexeme);
	return ENDROW;
}

TokenID DataTokenPattern(const char *lexeme)
{
	LogDebug("DataTokenPattern: '%s'.", lexeme);
	return DATA;
}

TokenID TextTokenPattern(const char *lexeme)
{
	LogDebug("TextTokenPattern: '%s'.", lexeme);
	return TEXT;
}

TokenID TimesTokenPattern(const char *lexeme)
{
	LogDebug("TimesTokenPattern: '%s'.", lexeme);
	return TIMES;
}

TokenID DefDelimiterTokenPattern(const char *lexeme)
{
	LogDebug("DefDelimiterTokenPattern: '%s'.", lexeme);
	return DEF_DELIMITER;
}

TokenID CommaTokenPattern(const char *lexeme)
{
	LogDebug("CommaTokenPattern: '%s'.", lexeme);
	return COMMA;
}

TokenID LinkPatternAction(const char *lexeme)
{
	LogDebug("LinkPatternAction: '%s'.", lexeme);
	return LINK;
}

TokenID IdrefPatternAction(const char *lexeme)
{
	LogDebug("IDrefPatternAction: '%s'.", lexeme);
	return IDREF;
}

TokenID IdPatternAction(const char *lexeme)
{
	LogDebug("IDPatternAction: '%s'.", lexeme);
	return ID;
}

TokenID SourcePatternAction(const char *lexeme)
{
	LogDebug("SourcePatternAction: '%s'.", lexeme);
	return SOURCE;
}

TokenID ContentPatternAction(const char *lexeme)
{
	LogDebug("ContentPatternAction: '%s'.", lexeme);
	return CONTENT;
}

TokenID TitleSizePatternAction(const char *lexeme)
{
	LogDebug("TitleSizePatternAction: '%s'.", lexeme);
	return TITLE_SIZE;
}

TokenID ColorPatternAction(const char *lexeme)
{
	LogDebug("ColorPatternAction: '%s'.", lexeme);
	return COLOR;
}

TokenID PositionPatternAction(const char *lexeme)
{
	LogDebug("PositionPatternAction: '%s'.", lexeme);
	return POSITION;
}

TokenID NumberPatternAction(const char *lexeme)
{
	LogDebug("NumberPatternAction: '%s'.", lexeme);
	return NUMBER;
}

TokenID UnknownPatternAction(const char *lexeme)
{
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}

// TokenID WordPatternAction(const char *lexeme)
// {
// 	LogDebug("WordPatternAction: '%s'.", lexeme);
// 	return WORD;
// }
