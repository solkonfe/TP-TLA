%{

#include "bison-actions.h"

%}

%union{
	tAttributes * data_attrs;
	tAttribute * data_attr;

	tWebExprs * web_expressions;
	tWebExpr * web_expression;

	tImage * img_expression;
	tLink * link_expression;
	tAttribute * link_attr;
	tAttributes * link_attrs;
	tDiv * div_expression;
	tDivAttrs * div_attrs;
	tText * text_expression;
	tTitle * title_expression;
	tTitleAttrs * title_attrs;
	tTable * table_expression;
	tRows * table_resolve;
	tRow * row_resolve;
	tRow * row_cell_union;
	tRowData * row_data;

	char * string;
	int token;
	int integer;
}

%type <data_attrs> data_attrs
%type <data_attr> data_attr
%type <web_expressions> web_expressions
%type <web_expression> web_expression
%type <img_expression> img_expression
%type <link_expression> link_expression
%type <link_attr> link_attr
%type <link_attrs> link_attrs
%type <div_expression> div_expression
%type <div_attrs> div_attrs
%type <text_expression> text_expression
%type <title_expression> title_expression
%type <title_attrs> title_attrs
%type <table_expression> table_expression
%type <table_resolve> table_resolve
%type <row_resolve> row_resolve
%type <row_cell_union> row_cell_union
%type <row_data> row_data


// IDs de los tokens generados desde Flex:

%token <token> BOX
%token <token> ENDBOX
%token <token> START
%token <token> END
%token <token> TITLE
%token <string> TITLE_SIZE
%token <string> COLOR
%token <string> POSITION
%token <token> DEF_DELIMITER
%token <token> COMMA
%token <token> TABLE
%token <token> ENDTABLE
%token <string> LINK
%token <token> RANDOM
%token <token> IMAGE
%token <string> HYPERLINK
%token <string> ID
%token <string> IDREF
%token <string> SOURCE
%token <token> BOLD
%token <token> ITALIC
%token <token> UNDERLINED
%token <integer> NUMBER
%token <token> ROW
%token <token> ENDROW
%token <token> DATA
%token <token> TIMES
%token <string> TEXT
%token <string> CONTENT

%%

	program: START web_expressions END				{ ProgramGrammarAction($2); }
		;

	web_expressions: web_expression					{ $$ = SimpleWebExpressionAction($1); }
		| web_expressions web_expression			{ $$ = RightAppendWebExprAction($1, $2); }
		;

	web_expression: title_expression				{ $$ = TitleExprAction($1);}
		| text_expression							{ $$ = TextExprAction($1);}
		| img_expression							{ $$ = ImgExpressionAction($1);}
		| link_expression							{ $$ = LinkExprAction($1);}
		| table_expression							{ $$ = TableExprAction($1);}
		| div_expression							{ $$ = DivExprAction($1);}
		;

	img_expression: IMAGE SOURCE DEF_DELIMITER CONTENT							{ $$ = ImgExprAction($2, $4); }
		| IMAGE SOURCE IDREF DEF_DELIMITER CONTENT								{ $$ = ImgExprActionWithIdref($2, $3, $5); }
		| IMAGE IDREF SOURCE DEF_DELIMITER CONTENT								{ $$ = ImgExprActionWithIdref($3, $2, $5); }
		;

	link_expression: HYPERLINK SOURCE link_attrs DEF_DELIMITER CONTENT			{ $$ = LinkExpressionWithAttrs($2, $3, $5); }
		| HYPERLINK SOURCE DEF_DELIMITER CONTENT 								{ $$ = LinkExpressionNoAttrs($2, $4);}
		| HYPERLINK IDREF link_attrs DEF_DELIMITER CONTENT						{ $$ = LinkExpressionWithAttrs($2, $3, $5); }
		| HYPERLINK IDREF DEF_DELIMITER CONTENT									{ $$ = LinkExpressionNoAttrsIDREF($2, $4);}
		;

	link_attrs: link_attr													{ $$ = DataSingleAttrExpressionAction($1); }												
		| link_attrs COMMA link_attr										{ $$ = RightAppendAttrExpressionAction($1, $3); }
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
		| ID POSITION																{ $$ = DivAttrsPosAndID($1, $2); }
		;

	text_expression: TEXT data_attrs DEF_DELIMITER CONTENT							{ $$ = TextExprWithAttrs($2, $4); } 
		| TEXT ID data_attrs DEF_DELIMITER CONTENT									{ $$ = TextExprWithAttrsAndID($2, $3, $5); }
		| TEXT DEF_DELIMITER CONTENT												{ $$ = TextExprNoAttrs($3); }
		;

	title_expression: TITLE DEF_DELIMITER CONTENT			{ $$ = TitleGrammarActionNoAttrsCont($3); }
		| TITLE title_attrs DEF_DELIMITER CONTENT			{ $$ = TitleGrammarActionWithAttrsCont($2, $4); }
		| TITLE DEF_DELIMITER LINK							{ $$ = TitleGrammarActionNoAttrsLink($3); }
		| TITLE title_attrs DEF_DELIMITER LINK				{ $$ = TitleGrammarActionWithAttrsLink($2, $4); }
		;

	title_attrs: data_attrs									{ $$ = TitleAttrsPlainAction($1); }
		| TITLE_SIZE data_attrs								{ $$ = TitleAttrsWithSizeAction($1, $2); }
		| ID data_attrs										{ $$ = TitleAttrsWithIDAction($1, $2); }
		| TITLE_SIZE										{ $$ = TitleAttrsOnlySizeAction($1); }
		| ID												{ $$ = TitleAttrsOnlyIDAction($1);}
		;

	table_expression: TABLE DEF_DELIMITER NUMBER TIMES NUMBER table_resolve	ENDTABLE { $$ = TableExpressionAction($3, $5, $6); }
		;

	table_resolve: row_resolve								{ $$ = SingleRowAction($1); }
		| table_resolve row_resolve							{ $$ = RightAppendRowAction($1, $2); }
		;

	row_resolve: ROW DEF_DELIMITER row_cell_union ENDROW	{ $$ = RowExpressionAction($3); }
		;

	row_cell_union: row_data								{ $$ = SingleRowDataAction($1); }
		| row_data row_data									{ $$ = RowDataUnion($1, $2);}
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
