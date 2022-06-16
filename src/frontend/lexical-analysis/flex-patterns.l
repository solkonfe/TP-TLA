%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno
/* Dejo regexs viejas aca por las dudas: */
/* link            \'https?:\/\/.*\..*' */
/* source          src=\'https?:\/\/.*\..*\' */


/* Patrones reutilizables. */
crlf			\r\n
/* https://stackoverflow.com/questions/3809401/what-is-a-good-regular-expression-to-match-a-url */
link            \'https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,4}\'
source          src=\'https?:\/\/(www\.)?.*\.*\'
idref           idref=\'#.*\'
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
"endbox"                                    { return EndBoxTokenPattern(yytext);}
"title"                                     { return TitleTokenPattern(yytext); }
"table"                                     { return TableTokenPattern(yytext); }
"endtable"                                  { return EndTableTokenPattern(yytext); }
"random"                                    { return RandomTokenPattern(yytext); }
"image"                                     { return ImageTokenPattern(yytext); }
"link"                                      { return HyperlinkTokenPattern(yytext); }

"bold"                                      { return BoldTokenPattern(yytext); }
"italic"                                    { return ItalicTokenPattern(yytext); }
"underlined"                                { return UnderlinedTokenPattern(yytext); }

"row"                                       { return RowTokenPattern(yytext); }
"endrow"                                    { return EndRowTokenPattern(yytext);}
"data"                                      { return DataTokenPattern(yytext); }
"text"                                      { return TextTokenPattern(yytext); }

"x"                                         { return TimesTokenPattern(yytext);}
":"                                         { LogDebug("DefDelimiterTokenPattern: ':'"); return DEF_DELIMITER; }
","                                         { return CommaTokenPattern(yytext); }



{link}                                      { return LinkPatternAction(yytext, yyleng); }

{idref}                                     { return IdrefPatternAction(yytext, yyleng); }

{id}                                        { return IdPatternAction(yytext, yyleng); }

{source}                                   { return SourcePatternAction(yytext, yyleng); }

{content}                                   { return ContentPatternAction(yytext, yyleng); }

{title_size}                                { return TitleSizePatternAction(yytext, yyleng); }

{color}                                     { return ColorPatternAction(yytext, yyleng);}

{position}                                  { return PositionPatternAction(yytext, yyleng);}

{number}                                    { return NumberPatternAction(yytext);}

{whitespace}								{}

.											{ return UnknownPatternAction(yytext); }


%%
