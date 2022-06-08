#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../syntactic-analysis/bison-parser.h"

#define YYUNDEF 257
#define UNKNOWN 0

/**
 * Se definen los diferentes IDs de cada token disponible para el scanner Flex.
 */
/*typedef enum TokenID
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
} unsigned;
*/

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 */

unsigned StartTokenPattern(const char *lexeme);
unsigned EndTokenPattern(const char *lexeme);

unsigned BoxTokenPattern(const char *lexeme);
unsigned EndBoxTokenPattern(const char *lexeme);

unsigned TitleTokenPattern(const char *lexeme);
unsigned TableTokenPattern(const char *lexeme);
unsigned EndTableTokenPattern(const char *lexeme);
unsigned RandomTokenPattern(const char *lexeme);
unsigned ImageTokenPattern(const char *lexeme);
unsigned HyperlinkTokenPattern(const char *lexeme);

unsigned BoldTokenPattern(const char *lexeme);
unsigned ItalicTokenPattern(const char *lexeme);
unsigned UnderlinedTokenPattern(const char *lexeme);

unsigned RowTokenPattern(const char *lexeme);
unsigned EndRowTokenPattern(const char *lexeme);
unsigned DataTokenPattern(const char *lexeme);
unsigned TextTokenPattern(const char *lexeme);

unsigned TimesTokenPattern(const char *lexeme);
unsigned DefDelimiterTokenPattern(const char *lexeme);
unsigned CommaTokenPattern(const char *lexeme);

unsigned LinkPatternAction(const char *lexeme);
unsigned IdrefPatternAction(const char *lexeme);
unsigned IdPatternAction(const char *lexeme);
unsigned SourcePatternAction(const char *lexeme);
unsigned ContentPatternAction(const char *lexeme);

unsigned TitleSizePatternAction(const char *lexeme);
unsigned ColorPatternAction(const char *lexeme);
unsigned PositionPatternAction(const char *lexeme);
unsigned NumberPatternAction(const char *lexeme);

unsigned UnknownPatternAction(const char *lexeme);

// unsigned WordPatternAction(const char *lexeme);

#endif
