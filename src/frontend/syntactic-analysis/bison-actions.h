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
int ProgramGrammarAction(const int value);

int TitleGrammarAction(const int value);

int WebGrammarAction(const int value);

tAttribute * DataAttrAction(char * value);
tAttributes * DataSingleAttrExpression(tAttribute * node);
tAttributes * LeftAppendAttrExpressionAction(tAttribute * leftNode, tAttributes * attrExpr);



#endif
