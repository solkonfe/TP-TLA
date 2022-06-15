#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"

/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */

// Programa.
void ProgramGrammarAction(tWebExprs * value);

tAttribute * ColorAttrAction(char * value);
tAttribute * PositionAttrAction(char * value);
tAttribute * BoldAttrAction();
tAttribute * ItalicAttrAction();
tAttribute * UnderlinedAttrAction();

tAttributes * DataSingleAttrExpressionAction(tAttribute * node);
tAttributes * LeftAppendAttrExpressionAction(tAttribute * leftNode, tAttributes * attrExpr);
tAttributes * RightAppendAttrExpressionAction(tAttributes * attrExpr, tAttribute * rightNode);

tRowData * RowDataAction(char * content);
tRowData * RowDataWithAttrsAction(tAttributes * attrs, char * content);

tRow * SingleRowDataExprAction(tRowData * r1);
tRow * RowDataUnion(tRowData * r1, tRowData * r2);
tRow * RowExprUnion(tRow * row, tRowData * cell);
tRow * RowExpressionAction(tRow * row_content);

tRows * SingleRowAction(tRow * row);
tRows * RightAppendRowAction(tRows * rows, tRow * row);

tTable * TableExpressionAction(int rows, int cols, tRows * r);

tTitleAttrs  * TitleAttrsPlainAction(tAttributes * attrs);
tTitleAttrs * TitleAttrsWithSizeAction(char * titleSize, tAttributes * attrs);
tTitleAttrs * TitleAttrsWithIDAction(char * ID, tAttributes * attrs);
tTitleAttrs * TitleAttrsOnlySizeAction(char * titleSize);
tTitleAttrs * TitleAttrsOnlyIDAction(char * ID);


tTitle * TitleGrammarActionNoAttrsCont(char * value);
tTitle * TitleGrammarActionWithAttrsCont(tTitleAttrs * attrs, char * value);
tTitle * TitleGrammarActionNoAttrsLink(char * value);
tTitle * TitleGrammarActionWithAttrsLink(tTitleAttrs * attrs, char * value);

tText * TextExprNoAttrs(char * content);
tText * TextExprWithAttrs(tAttributes * attrs, char * content);
tText * TextExprWithAttrsAndID(char * ID, tAttributes * attrs, char * content);

tDivAttrs * DivAttrsPos(char * pos);
tDivAttrs * DivAttrsPosAndID(char * ID, char * pos);

tImage * ImgExprAction(char * src, char * alt);
tImage * ImgExprActionWithIdref(char * src, char * alt, char * idref);

tLink * LinkExpressionWithAttrs(char * src, tAttributes * attrs, char * content);
tLink * LinkExpressionNoAttrs(char * src, char * content);
tLink *LinkExpressionNoAttrsIDREF(char * idref, char * content);

tWebExpr * TitleExprAction(tTitle * title);
tWebExpr * TextExprAction(tText * text);
tWebExpr * ImgExpressionAction(tImage * img);
tWebExpr * LinkExprAction(tLink * link);
tWebExpr * TableExprAction(tTable * table);
tWebExpr * DivExprAction(tDiv * div);

tWebExprs * SimpleWebExpressionAction(tWebExpr * exp);
tWebExprs * RightAppendWebExprAction(tWebExprs * exps, tWebExpr * exp);

tDiv * DivExprWithAttrsSingleWeb(tDivAttrs * attrs, tWebExprs * content);
tDiv * DivExprNoAttrsSingleWeb(tWebExprs * content);
tDiv * DivExprWithAttrsMulExp(tDivAttrs * attrs, tWebExprs * content);
tDiv * DivExprNoAttrsMulExp(tWebExprs * content);
#endif
