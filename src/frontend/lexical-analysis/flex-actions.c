#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>
//#include "../../backend/support/shared.h"
#include <string.h>
//#include "shared.h"

/**
 * Implementación de "flex-rules.h".
 */

yytoken_kind_t StartTokenPattern(const char *lexeme)
{
	LogDebug("StartTokenPattern: '%s'.", lexeme);
	return START;
}

yytoken_kind_t EndTokenPattern(const char *lexeme)
{
	LogDebug("EndTokenPattern: '%s'.", lexeme);
	return END;
}

yytoken_kind_t BoxTokenPattern(const char *lexeme)
{
	LogDebug("BoxTokenPattern: '%s'.", lexeme);
	return BOX;
}

yytoken_kind_t EndBoxTokenPattern(const char *lexeme)
{
	LogDebug("EndBoxTokenPattern: '%s'.", lexeme);
	return ENDBOX;
}

yytoken_kind_t TitleTokenPattern(const char *lexeme)
{
	LogDebug("TitleTokenPattern: '%s'.", lexeme);
	return TITLE;
}

yytoken_kind_t TableTokenPattern(const char *lexeme)
{
	LogDebug("TableTokenPattern: '%s'.", lexeme);
	return TABLE;
}

yytoken_kind_t EndTableTokenPattern(const char *lexeme)
{
	LogDebug("EndTableTokenPattern: '%s'.", lexeme);
	return ENDTABLE;
}

yytoken_kind_t RandomTokenPattern(const char *lexeme)
{
	LogDebug("RandomTokenPattern: '%s'.", lexeme);
	return RANDOM;
}

yytoken_kind_t ImageTokenPattern(const char *lexeme)
{
	LogDebug("ImageTokenPattern: '%s'.", lexeme);
	return IMAGE;
}

yytoken_kind_t HyperlinkTokenPattern(const char *lexeme)
{
	LogDebug("HyperlinkTokenPattern: '%s'.", lexeme);
	return HYPERLINK;
}

yytoken_kind_t BoldTokenPattern(const char *lexeme)
{
	LogDebug("BoldTokenPattern: '%s'.", lexeme);
	return BOLD;
}

yytoken_kind_t ItalicTokenPattern(const char *lexeme)
{
	LogDebug("ItalicTokenPattern: '%s'.", lexeme);
	return ITALIC;
}

yytoken_kind_t UnderlinedTokenPattern(const char *lexeme)
{
	LogDebug("UnderlinedTokenPattern: '%s'.", lexeme);
	return UNDERLINED;
}

yytoken_kind_t RowTokenPattern(const char *lexeme)
{
	LogDebug("RowTokenPattern: '%s'.", lexeme);
	return ROW;
}

yytoken_kind_t EndRowTokenPattern(const char *lexeme)
{
	LogDebug("EndRowTokenPattern: '%s'.", lexeme);
	return ENDROW;
}

yytoken_kind_t DataTokenPattern(const char *lexeme)
{
	LogDebug("DataTokenPattern: '%s'.", lexeme);
	return DATA;
}

yytoken_kind_t TextTokenPattern(const char *lexeme)
{
	LogDebug("TextTokenPattern: '%s'.", lexeme);
	return TEXT;
}

yytoken_kind_t TimesTokenPattern(const char *lexeme)
{
	LogDebug("TimesTokenPattern: '%s'.", lexeme);
	return TIMES;
}

yytoken_kind_t DefDelimiterTokenPattern(const char *lexeme)
{
	LogDebug("DefDelimiterTokenPattern: '%s'.", lexeme);
	return DEF_DELIMITER;
}

yytoken_kind_t CommaTokenPattern(const char *lexeme)
{
	LogDebug("CommaTokenPattern: '%s'.", lexeme);
	return COMMA;
}

yytoken_kind_t LinkPatternAction(const char *lexeme)
{
	LogDebug("LinkPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return LINK;
}

yytoken_kind_t IdrefPatternAction(const char *lexeme)
{
	LogDebug("IDrefPatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return IDREF;
}

yytoken_kind_t IdPatternAction(const char *lexeme)
{
	LogDebug("IDPatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return ID;
}

yytoken_kind_t SourcePatternAction(const char *lexeme)
{
	LogDebug("SourcePatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return SOURCE;
}

yytoken_kind_t ContentPatternAction(const char *lexeme)
{
	LogDebug("ContentPatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return CONTENT;
}

yytoken_kind_t TitleSizePatternAction(const char *lexeme)
{
	LogDebug("TitleSizePatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return TITLE_SIZE;
}

yytoken_kind_t ColorPatternAction(const char *lexeme)
{
	LogDebug("ColorPatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return COLOR;
}

yytoken_kind_t PositionPatternAction(const char *lexeme)
{
	LogDebug("PositionPatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return POSITION;
}

yytoken_kind_t NumberPatternAction(const char *lexeme)
{
	LogDebug("NumberPatternAction: '%s'.", lexeme);
	//yylval.string = lexeme;
	return NUMBER;
}

yytoken_kind_t UnknownPatternAction(const char *lexeme)
{
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}

// yytoken_kind_t WordPatternAction(const char *lexeme)
// {
// 	LogDebug("WordPatternAction: '%s'.", lexeme);
// 	return WORD;
// }
