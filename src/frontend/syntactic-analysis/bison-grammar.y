%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:

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
%token LINK
%token RANDOM
%token TUTORIAL 
%token IMAGE
%token HYPERLINK
%token ID
%token IDREF
%token SOURCE
%token CONTENT

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV

%%

program: START web_expression END				{ $$ = ProgramGrammarAction(0); }
	;

web_expression: title_expression				{ $$ = WebGrammarAction(0);}
	| img_expression							{ $$ = WebGrammarAction(1);}
	| link_expression							{ $$ = WebGrammarAction(2);}
	| web_expression web_expression				{ $$ = WebGrammarAction(3);}
	| TABLE										{ $$ = WebGrammarAction(4);}
	| MATRIX									{ $$ = WebGrammarAction(5);}
	| RANDOM									{ $$ = WebGrammarAction(6);}
	| div_expression							{ $$ = WebGrammarAction(7);}
	;

img_expression: IMAGE img_attrs	SOURCE					{}
	| IMAGE img_attrs SOURCE DEF_DELIMITER CONTENT		{}
	;

img_attrs: IDREF 
	| LINK
	;

link_expression: HYPERLINK link_attrs DEF_DELIMITER CONTENT
	;

link_attrs: LINK
	| LINK COMMA COLOR
	| IDREF COMMA COLOR
	| IDREF
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
	| ID POSITION																{}
	;

simple_expression: CONTENT														{}
	| title_expression															{}
	| simple_expression simple_expression										{}
	| img_expression															{}
	| link_expression															{}
	;

title_expression: TITLE DEF_DELIMITER CONTENT			{ $$ = TitleGrammarAction(0); }
	| TITLE title_attrs DEF_DELIMITER CONTENT			{ $$ = TitleGrammarAction(1); }
	| TITLE DEF_DELIMITER LINK							{ $$ = TitleGrammarAction(2); }
	| TITLE title_attrs DEF_DELIMITER LINK				{ $$ = TitleGrammarAction(3); }
	;

title_attrs: TITLE_SIZE COMMA COLOR COMMA POSITION			{}
	| TITLE_SIZE COMMA COLOR COMMA POSITION COMMA ID		{}
	| TITLE_SIZE COMMA COLOR								{}
	| TITLE_SIZE COMMA COLOR COMMA ID						{}
	| TITLE_SIZE COMMA POSITION								{}
	| TITLE_SIZE COMMA POSITION	COMMA ID					{}
	| TITLE_SIZE											{}
	| TITLE_SIZE ID											{}
	| COLOR COMMA POSITION									{}	
	| COLOR COMMA POSITION COMMA ID							{}
	| COLOR													{}
	| COLOR COMMA ID										{}
	| POSITION												{}
	| POSITION	COMMA ID									{}
	| ID													{}
	;

%%
