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
/* https://stackoverflow.com/questions/3809401/what-is-a-good-regular-expression-to-match-a-url */
link            \"chau\"
title_size      (x-small|small|medium|large|x-large|xx-large)
color           (black|red|blue|green|orange|yellow|pink)
position        (left|center|right)
content         \".*\"
endline			\n
whitespace		[ \f\n\r\t\v]

%%

"start"                                     { return StartTokenPattern(yytext);}
"end"                                       { return EndTokenPattern(yytext);}
"box"                                       { return BoxTokenPattern(yytext); }
"endbox"                                    { return EndBoxTokenPattern(yytext); }

"title"                                     { return TitleTokenPattern(yytext); }
"table"                                     { return TABLE; }
"matrix"                                    { return MATRIX; }
"random"                                    { return RANDOM; }
"tutorial"                                  { return TUTORIAL; }
"image"                                     { return IMAGE; }
"link"                                      { return HYPERLINK; }

":"                                         { return DEF_DELIMITER; }
","                                         { return COMMA; }

{link}                                      { return LINK; }

{content}                                   { return ContentPatternAction(yytext); }

{title_size}                                { return TitleSizePatternAction(yytext); }

{color}                                     { return ColorPatternAction(yytext);}

{position}                                  { return PositionPatternAction(yytext);}

{digit}+									{ return IntegerPatternAction(yytext); }

{whitespace}								{ IgnoredPatternAction(yytext); }

.											{ return UnknownPatternAction(yytext); }

%%
