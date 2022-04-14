%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno

/* Patrones reutilizables. */
crlf			\r\n
digit			[0-9]
/* Fuente: https://stackoverflow.com/questions/3809401/what-is-a-good-regular-expression-to-match-a-url */
link            "[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)"
text            "[\s\S]*"
endline			\n
whitespace		[ \f\n\r\t\v]
colors          (black|white|red|blue|green)

%%

"+"											{ return ADD; }
"-"											{ return SUB; }
"*"											{ return MUL; }
"/"											{ return DIV; }

"box"                                       { return OPEN_DIV; }
"closebox"                                  { return CLOSE_DIV; }
"header"                                    { return HEADER; }
"link"                                      { return LINK; }
"matrix"                                    { return MATRIX; }
"image"                                     { return IMAGE; }

"from"                                      { return ATR_IMG_SOURCE; }
"source"                                    { return ATR_SOURCE; }
"go-to"                                     { return ATR_INTERNAL_LINK; }
"size"                                      { return ATR_SIZE; }

","                                         { return ATR_DELIMITER; }
":"                                         { return DEF_DELIMITER; }
"="                                         { return ATR_ASSIGNATION; }

"("											{ return OPEN_PARENTHESIS; }
")"											{ return CLOSE_PARENTHESIS; }

link                                        { return LinkPatternAction(yytext); }

text                                        { return TextPatternAction(yytext); }

colors                                      { return AtrColorPatternAction(yytext); }

position                                    { return AtrPositionPatternAction(yytext); }

{digit}+									{ return IntegerPatternAction(yytext); }

{whitespace}								{ IgnoredPatternAction(yytext); }

.											{ return UnknownPatternAction(yytext); }

%%
