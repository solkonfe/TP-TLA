#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>
//#include "../../backend/support/shared.h"
#include <string.h>
//#include "shared.h"

/**
 * Implementación de "flex-rules.h".
 */

unsigned StartTokenPattern(const char *lexeme)
{
	LogDebug("StartTokenPattern: '%s'.", lexeme);
	return START;
}

unsigned EndTokenPattern(const char *lexeme)
{
	LogDebug("EndTokenPattern: '%s'.", lexeme);
	return END;
}

unsigned BoxTokenPattern(const char *lexeme)
{
	LogDebug("BoxTokenPattern: '%s'.", lexeme);
	return BOX;
}

unsigned EndBoxTokenPattern(const char *lexeme)
{
	LogDebug("EndBoxTokenPattern: '%s'.", lexeme);
	return ENDBOX;
}

unsigned TitleTokenPattern(const char *lexeme)
{
	LogDebug("TitleTokenPattern: '%s'.", lexeme);
	return TITLE;
}

unsigned TableTokenPattern(const char *lexeme)
{
	LogDebug("TableTokenPattern: '%s'.", lexeme);
	return TABLE;
}

unsigned EndTableTokenPattern(const char *lexeme)
{
	LogDebug("EndTableTokenPattern: '%s'.", lexeme);
	return ENDTABLE;
}

unsigned RandomTokenPattern(const char *lexeme)
{
	LogDebug("RandomTokenPattern: '%s'.", lexeme);
	return RANDOM;
}

unsigned ImageTokenPattern(const char *lexeme)
{
	LogDebug("ImageTokenPattern: '%s'.", lexeme);
	return IMAGE;
}

unsigned HyperlinkTokenPattern(const char *lexeme)
{
	LogDebug("HyperlinkTokenPattern: '%s'.", lexeme);
	return HYPERLINK;
}

unsigned BoldTokenPattern(const char *lexeme)
{
	LogDebug("BoldTokenPattern: '%s'.", lexeme);
	return BOLD;
}

unsigned ItalicTokenPattern(const char *lexeme)
{
	LogDebug("ItalicTokenPattern: '%s'.", lexeme);
	return ITALIC;
}

unsigned UnderlinedTokenPattern(const char *lexeme)
{
	LogDebug("UnderlinedTokenPattern: '%s'.", lexeme);
	return UNDERLINED;
}

unsigned RowTokenPattern(const char *lexeme)
{
	LogDebug("RowTokenPattern: '%s'.", lexeme);
	return ROW;
}

unsigned EndRowTokenPattern(const char *lexeme)
{
	LogDebug("EndRowTokenPattern: '%s'.", lexeme);
	return ENDROW;
}

unsigned DataTokenPattern(const char *lexeme)
{
	LogDebug("DataTokenPattern: '%s'.", lexeme);
	return DATA;
}

unsigned TextTokenPattern(const char *lexeme)
{
	LogDebug("TextTokenPattern: '%s'.", lexeme);
	return TEXT;
}

unsigned TimesTokenPattern(const char *lexeme)
{
	LogDebug("TimesTokenPattern: '%s'.", lexeme);
	return TIMES;
}

unsigned DefDelimiterTokenPattern(const char *lexeme)
{
	LogDebug("DefDelimiterTokenPattern: '%s'.", lexeme);
	return DEF_DELIMITER;
}

unsigned CommaTokenPattern(const char *lexeme)
{
	LogDebug("CommaTokenPattern: '%s'.", lexeme);
	return COMMA;
}

unsigned LinkPatternAction(const char *lexeme)
{
	LogDebug("LinkPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return LINK;
}

unsigned IdrefPatternAction(const char *lexeme)
{
	LogDebug("IDrefPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return IDREF;
}

unsigned IdPatternAction(const char *lexeme)
{
	LogDebug("IDPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return ID;
}

unsigned SourcePatternAction(const char *lexeme)
{
	LogDebug("SourcePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return SOURCE;
}

unsigned ContentPatternAction(const char *lexeme)
{
	LogDebug("ContentPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return CONTENT;
}

unsigned TitleSizePatternAction(const char *lexeme)
{
	LogDebug("TitleSizePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return TITLE_SIZE;
}

unsigned ColorPatternAction(const char *lexeme)
{
	LogDebug("ColorPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return COLOR;
}

unsigned PositionPatternAction(const char *lexeme)
{
	LogDebug("PositionPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return POSITION;
}

unsigned NumberPatternAction(const char *lexeme)
{
	LogDebug("NumberPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return NUMBER;
}

unsigned UnknownPatternAction(const char *lexeme)
{
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
