%{

#include "bison-actions.h"

%}

%union{
	tAttributes * data_attrs;
	tAttribute * data_attr;

	char * string;
}

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
%token ENDTABLE
%token LINK
%token RANDOM
%token IMAGE
%token HYPERLINK
%token ID
%token IDREF
%token SOURCE
%token BOLD
%token ITALIC
%token UNDERLINED
%token NUMBER
%token ROW
%token ENDROW
%token DATA
%token TIMES
%token TEXT
%token CONTENT

%%

program: START web_expression END				{ $$ = ProgramGrammarAction(0); }
	;

web_expression: title_expression				{ $$ = WebGrammarAction(0);}
	| text_expression
	| img_expression							{ $$ = WebGrammarAction(1);}
	| link_expression							{ $$ = WebGrammarAction(2);}
	| web_expression web_expression				{ $$ = WebGrammarAction(3);}
	| table_expression							{ $$ = WebGrammarAction(4);}
	| RANDOM									{ $$ = WebGrammarAction(6);}
	| div_expression							{ $$ = WebGrammarAction(7);}
	;

img_expression: IMAGE img_attrs 					{}
	| IMAGE img_attrs DEF_DELIMITER CONTENT		{}
	
	;

img_attrs: SOURCE
	| IDREF 
	| SOURCE LINK
	;

link_expression: HYPERLINK link_attrs DEF_DELIMITER CONTENT
	;

link_attrs: SOURCE
	| SOURCE link_attr_expression
	| IDREF link_attr_expression
	;

link_attr_expression: link_attr
	| link_attr COMMA link_attr
	| link_attr_expression COMMA link_attr
	| link_attr COMMA link_attr_expression
	| link_attr_expression COMMA link_attr_expression
	;

link_attr: BOLD
	| ITALIC
	| UNDERLINED
	| COLOR
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

text_expression: TEXT text_attrs DEF_DELIMITER CONTENT
	| DEF_DELIMITER CONTENT
	;

text_attrs: data_attrs
	| ID data_attrs
	;

simple_expression: text_expression														{}
	| title_expression															{}
	| simple_expression simple_expression										{}
	| img_expression															{}
	| link_expression															{}
	;

title_expression: TITLE DEF_DELIMITER CONTENT			{ $$ = TitleGrammarActionNoAttrsCont($3); }
	| TITLE title_attrs DEF_DELIMITER CONTENT			{ $$ = TitleGrammarActionWithAttrsCont($2, $4); }
	| TITLE DEF_DELIMITER LINK							{ $$ = TitleGrammarActionNoAttrsLink($3); }
	| TITLE title_attrs DEF_DELIMITER LINK				{ $$ = TitleGrammarActionWithAttrsLink($2, $4); }
	;

title_attrs: data_attrs									{ $$ = TitleAttrsPlainAction($1); }
	| TITLE_SIZE data_attrs								{ $$ = TitleAttrsWithSizeAction($1, $2); }
	| ID data_attrs										{ $$ = TitleAttrsWithIDAction($1, $2); }
	;

table_expression: TABLE DEF_DELIMITER NUMBER TIMES NUMBER table_resolve	ENDTABLE { $$ = TableExpressionAction($3, $5, $6); }
	;

table_resolve: row_resolve								{ $$ = SingleRowAction($1); }
	| table_resolve row_resolve							{ $$ = RightAppendRowAction($1, $2); }
	;

row_resolve: ROW DEF_DELIMITER row_cell_union ENDROW	{ $$ = RowExpressionAction($3); }
	;

row_cell_union: row_data row_data						{ $$ = RowDataUnion($1, $2); }
	| row_cell_union row_data							{ $$ = RowExprUnion($1, $2); }
	;

row_data: DATA DEF_DELIMITER CONTENT					{ $$ = RowDataAction($3); }
	| DATA data_attrs DEF_DELIMITER CONTENT				{ $$ = RowDataWithAttrsAction($2, $4); }		
	;

data_attrs: data_attr									{ $$ = DataSingleAttrExpressionAction($1); }
	| data_attr COMMA data_attrs						{ $$ = LeftAppendAttrExpressionAction($1, $3); }
	;

data_attr: COLOR										{ $$ = DataAttrAction($1); }
	| POSITION											{ $$ = DataAttrAction($1); }
	| BOLD												{ $$ = DataAttrAction($1); }
	| ITALIC											{ $$ = DataAttrAction($1); }
	| UNDERLINED										{ $$ = DataAttrAction($1); }
	;
%%
