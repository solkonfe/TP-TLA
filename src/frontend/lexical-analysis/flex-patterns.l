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
/* https://stackoverflow.com/questions/3809401/what-is-a-good-regular-expression-to-match-a-url */
link            \'https:\/\/.*\..*\'
source          src=\"https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)\"
idref           \'#.*\'
id              id=\'.*\'
title_size      (x-small|small|medium|large|x-large|xx-large)
color           (black|red|blue|green|orange|yellow|pink)
position        (left|center|right)
number          [0-9]+
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
"endtable"                                  { return ENDTABLE; }
"random"                                    { return RANDOM; }
"image"                                     { return IMAGE; }
"link"                                      { return HYPERLINK; }

"bold"                                      { return BOLD; }
"italic"                                    { return ITALIC; }
"underlined"                                { return UNDERLINED; }

"row"                                       { return ROW; }
"endrow"                                    { return ENDROW;}
"data"                                      { return DATA; }

"x"                                         {return TIMES;}
":"                                         { return DEF_DELIMITER; }
","                                         { return COMMA; }



{link}                                      { return LinkPatternAction(yytext); }

{idref}                                     { return IdrefPatternAction(yytext); }

{id}                                        { return IdPatternAction(yytext); }

{source}                                   { return SourcePatternAction(yytext); }

{content}                                   { return ContentPatternAction(yytext); }

{title_size}                                { return TitleSizePatternAction(yytext); }

{color}                                     { return ColorPatternAction(yytext);}

{position}                                  { return PositionPatternAction(yytext);}

{number}                                    {return NUMBER;}

{whitespace}								{ IgnoredPatternAction(yytext); }

.											{ return UnknownPatternAction(yytext); }

%%
