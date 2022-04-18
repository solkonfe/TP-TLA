#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"

/**
 * Se definen los diferentes IDs de cada token disponible para el scanner Flex.
 */
typedef enum TokenID {

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
} TokenID;

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 */

TokenID StartTokenPattern(const char * lexeme);
TokenID EndTokenPattern(const char * lexeme);

TokenID BoxTokenPattern(const char * lexeme);
TokenID EndBoxTokenPattern(const char * lexeme);

TokenID TitleSizePatternAction(const char * lexeme);
TokenID ColorPatternAction(const char * lexeme);
TokenID PositionPatternAction(const char * lexeme);

TokenID IdrefPatternAction(const char * lexeme);
TokenID IdPatternAction(const char * lexeme);
TokenID SourcePatternAction(const char * lexeme);

TokenID BoldTokenPattern(const char * lexeme);
TokenID ItalicTokenPattern(const char * lexeme);
TokenID UnderlinedTokenPattern(const char * lexeme);

TokenID TitleTokenPattern(const char * lexeme);
TokenID HyperlinkPatternAction(const char * lexeme);

TokenID ContentPatternAction(const char * lexeme) ;
TokenID LinkPatternAction(const char * lexeme);

void IgnoredPatternAction(const char * lexeme);

TokenID UnknownPatternAction(const char * lexeme);

#endif
