#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../syntactic-analysis/bison-parser.h"

/**
 * Se definen los diferentes IDs de cada token disponible para el scanner Flex.
 */
/*typedef enum yytoken_kind_t
{

	// Por defecto, el valor "0" hace fallar el analizador sintáctico.
	UNKNOWN = 0,

	// Código de error de Bison, que permite abortar el escaneo de lexemas cuando
	// se presente un patrón desconocido. El número "257" coincide con el valor
	// que Bison le otorga por defecto, pero además permite que el resto de
	// tokens continúen desde el valor "258" lo que permite proteger los IDs
	// internos que Bison reserva para crear "tokens literales":
	YYUNDEF = 257,

	// Tipos de dato.
	BOX,
	ENDBOX,
	START,
	END,
	TITLE,
	TITLE_SIZE,
	COLOR,
	POSITION,
	DEF_DELIMITER,
	COMMA,
	TABLE,
	ENDTABLE,
	LINK,
	RANDOM,
	IMAGE,
	HYPERLINK,
	ID,
	IDREF,
	SOURCE,
	BOLD,
	ITALIC,
	UNDERLINED,
	NUMBER,
	ROW,
	ENDROW,
	DATA,
	TIMES,
	TEXT,
	CONTENT
} yytoken_kind_t;
*/

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 */

yytoken_kind_t StartTokenPattern(const char *lexeme);
yytoken_kind_t EndTokenPattern(const char *lexeme);

yytoken_kind_t BoxTokenPattern(const char *lexeme);
yytoken_kind_t EndBoxTokenPattern(const char *lexeme);

yytoken_kind_t TitleTokenPattern(const char *lexeme);
yytoken_kind_t TableTokenPattern(const char *lexeme);
yytoken_kind_t EndTableTokenPattern(const char *lexeme);
yytoken_kind_t RandomTokenPattern(const char *lexeme);
yytoken_kind_t ImageTokenPattern(const char *lexeme);
yytoken_kind_t HyperlinkTokenPattern(const char *lexeme);

yytoken_kind_t BoldTokenPattern(const char *lexeme);
yytoken_kind_t ItalicTokenPattern(const char *lexeme);
yytoken_kind_t UnderlinedTokenPattern(const char *lexeme);

yytoken_kind_t RowTokenPattern(const char *lexeme);
yytoken_kind_t EndRowTokenPattern(const char *lexeme);
yytoken_kind_t DataTokenPattern(const char *lexeme);
yytoken_kind_t TextTokenPattern(const char *lexeme);

yytoken_kind_t TimesTokenPattern(const char *lexeme);
yytoken_kind_t DefDelimiterTokenPattern(const char *lexeme);
yytoken_kind_t CommaTokenPattern(const char *lexeme);

yytoken_kind_t LinkPatternAction(const char *lexeme);
yytoken_kind_t IdrefPatternAction(const char *lexeme);
yytoken_kind_t IdPatternAction(const char *lexeme);
yytoken_kind_t SourcePatternAction(const char *lexeme);
yytoken_kind_t ContentPatternAction(const char *lexeme);

yytoken_kind_t TitleSizePatternAction(const char *lexeme);
yytoken_kind_t ColorPatternAction(const char *lexeme);
yytoken_kind_t PositionPatternAction(const char *lexeme);
yytoken_kind_t NumberPatternAction(const char *lexeme);

yytoken_kind_t UnknownPatternAction(const char *lexeme);

// yytoken_kind_t WordPatternAction(const char *lexeme);

#endif
