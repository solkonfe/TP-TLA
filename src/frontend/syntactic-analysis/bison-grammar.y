%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:

%token INTEGER
%token BOX
%token ENDBOX
%token START
%token END
%token TITLE
%token TITLE_SIZE
%token COLOR
%token POSITION
%token DEF_DELIMITER
%token COMMA
%token TABLE
%token MATRIX
%token CONTENT
%token LINK
%token RANDOM
%token TUTORIAL 
%token IMAGE
%token HYPERLINK

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV

%%

program: START web_expression END				{ $$ = ProgramGrammarAction(0); }
	;

web_expression: title_expression				{ $$ = WebGrammarAction(0);}
	| img_expression							{}
	| link_expression							{}
	| web_expression web_expression				{ $$ = WebGrammarAction(1);}
	| TABLE										{}
	| MATRIX									{}
	| RANDOM									{}
	| div_expression							{}
	;

img_expression: IMAGE img_attrs					{}
	| IMAGE img_attrs CONTENT					{}
	;

img_attrs: LINK CONTENT
	;

link_expression: HYPERLINK link_attrs DEF_DELIMITER CONTENT
	| HYPERLINK link_attrs 
	;

link_attrs: LINK
	| LINK COMMA COLOR
	;

div_expression: BOX div_attrs DEF_DELIMITER div_expression ENDBOX				{}
	| BOX DEF_DELIMITER div_expression ENDBOX									{}
	| BOX DEF_DELIMITER simple_expression ENDBOX								{}
	| BOX div_attrs DEF_DELIMITER simple_expression ENDBOX						{}
	| BOX DEF_DELIMITER div_expression simple_expression ENDBOX					{}
	| BOX div_attrs DEF_DELIMITER div_expression simple_expression ENDBOX		{}
	| BOX DEF_DELIMITER simple_expression div_expression ENDBOX					{}
	| BOX div_attrs DEF_DELIMITER simple_expression div_expression ENDBOX		{}
	;

div_attrs: POSITION																{}
	;

simple_expression: CONTENT														{}
	| title_expression															{}
	| simple_expression simple_expression										{}
	| img_expression															{}
	| link_expression															{}
	;

title_expression: TITLE DEF_DELIMITER CONTENT			{ $$ = TitleGrammarAction(0); }
	| TITLE title_attrs DEF_DELIMITER CONTENT			{ $$ = TitleGrammarAction(1); }
	| TITLE DEF_DELIMITER LINK							{ $$ = TitleGrammarAction(0); }
	| TITLE title_attrs DEF_DELIMITER LINK				{ $$ = TitleGrammarAction(1); }
	;

title_attrs: TITLE_SIZE COMMA COLOR COMMA POSITION			{}
	| TITLE_SIZE COMMA COLOR								{}
	| TITLE_SIZE COMMA POSITION								{}
	| TITLE_SIZE											{}
	| COLOR COMMA POSITION									{}	
	| COLOR													{}
	| POSITION												{}
	;

constant: INTEGER										{ $$ = IntegerConstantGrammarAction($1); }
	;
	
%%
