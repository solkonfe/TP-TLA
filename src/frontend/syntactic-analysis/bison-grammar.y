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

program: START web_expressions END				{ $$ = ProgramGrammarAction($2); }
	;

web_expressions: web_expression					{ $$ = SimpleWebExpressionAction($1); }
	| web_expressions web_expression			{ $$ = RightAppendWebExprAction($1, $2); }
	;

web_expression: title_expression				{ $$ = TitleExprAction($1);}
	| text_expression							{ $$ = TextExprAction($1);}
	| img_expression							{ $$ = ImgExprAction($1);}
	| link_expression							{ $$ = LinkExprAction($1);}
	| table_expression							{ $$ = TableExprACtion($1);}
	| RANDOM									{ $$ = WebGrammarAction($1);}
	| div_expression							{ $$ = DivExprAction($1);}
	;

img_expression: IMAGE SOURCE DEF_DELIMITER CONTENT							{ $$ = ImgExprAction($2, $4); }
	| IMAGE SOURCE IDREF DEF_DELIMITER CONTENT								{ $$ = ImgExprWithIdref($2, $3, $5); }
	| IMAGE IDREF SOURCE DEF_DELIMITER CONTENT								{ $$ = ImgExprWithIdref($3, $2, $5); }
	;

link_expression: HYPERLINK SOURCE link_attrs DEF_DELIMITER CONTENT			{ $$ = LinkExpressionWithAttrs($2, $3, $5); }
	| HYPERLINK SOURCE DEF_DELIMITER CONTENT 								{ $$ = LinkExpressionNoAttrs($2, $5);}
	| HYPERLINK IDREF link_attrs DEF_DELIMITER CONTENT						{ $$ = LinkExpressionWithAttrs($2, $3, $5); }
	;

link_attrs: link_attr													{ $$ = DataSingleAttrExpressionAction($1); }												
	| link_attr COMMA link_attrs										{ $$ = LeftAppendAttrExpressionAction($1, $3); }
	;

link_attr: BOLD				{ $$ = BoldAttrAction($1); }																
	| ITALIC 				{ $$ = ItalicAttrAction($1); }																	
	| UNDERLINED 			{ $$ = UnderlinedAttrAction($1); }																
	| COLOR					{ $$ = ColorAttrAction($1); }																
	;

div_expression: BOX div_attrs DEF_DELIMITER web_expression ENDBOX				{ $$ = DivExprWithAttrsSingleWeb($2, $4);}
	| BOX DEF_DELIMITER web_expression ENDBOX									{ $$ = DivExprNoAttrsSingleWeb($3); }
	| BOX DEF_DELIMITER web_expressions ENDBOX									{ $$ = DivExprNoAttrsMulExp($3); }
	| BOX div_attrs DEF_DELIMITER web_expressions ENDBOX						{ $$ = DivExprWithAttrsMulExp($2, $4); }
	;

div_attrs: POSITION																{ $$ = DivAttrsPos($1); }
	| ID POSITION																{ $$ = DivAttrsPostAndID($1, $2); }
	;

text_expression: TEXT data_attrs DEF_DELIMITER CONTENT							{ $$ = TextExprWithAttrs($2, $4); }
	| TEXT ID data_attrs DEF_DELIMITER CONTENT									{ $$ = TextExprWithAttrsAndID($2, $3, $5); }
	| DEF_DELIMITER CONTENT														{ $$ = TextExprNoAttrs($2); }
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

data_attr: COLOR										{ $$ = ColorAttrAction($1); }
	| POSITION											{ $$ = PositionAttrAction($1); }
	| BOLD												{ $$ = BoldAttrAction($1); }
	| ITALIC											{ $$ = ItalicAttrAction($1); }
	| UNDERLINED										{ $$ = UnderlinedAttrAction($1); }
	;
%%
