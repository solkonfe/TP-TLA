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
%token TABLE
%token MATRIX
%token CONTENT
%token LINK

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV

%%

program: START web_expression END				{ $$ = ProgramGrammarAction(0); }
	;

web_expression: title_expression				{ $$ = WebGrammarAction(0);}
	| web_expression web_expression				{ $$ = WebGrammarAction(1);}
	| TABLE										{}
	| MATRIX									{}
	| div_expression							{}
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
	;

title_expression: TITLE DEF_DELIMITER CONTENT			{ $$ = TitleGrammarAction(0); }
	| TITLE title_attrs DEF_DELIMITER CONTENT			{ $$ = TitleGrammarAction(1); }
	| TITLE DEF_DELIMITER LINK							{ $$ = TitleGrammarAction(0); }
	| TITLE title_attrs DEF_DELIMITER LINK				{ $$ = TitleGrammarAction(1); }
	;

title_attrs: TITLE_SIZE COLOR POSITION			{}
	| TITLE_SIZE COLOR							{}
	| TITLE_SIZE POSITION						{}
	| TITLE_SIZE								{}
	| COLOR POSITION							{}	
	| COLOR										{}
	| POSITION									{}
	;

constant: INTEGER										{ $$ = IntegerConstantGrammarAction($1); }
	;
	
%%
