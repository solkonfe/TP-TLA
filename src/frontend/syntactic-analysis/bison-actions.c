#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../backend/support/shared.h"

/**
 * Implementación de "bison-grammar.h".
 */

void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

int ProgramGrammarAction(const int value) {
	LogDebug("Reconozco patrón. ProgramGrammarAction(%d)", value);
	state.succeed = true;
	state.result = value;
	return value;
}

int WebGrammarAction(const int value){
	LogDebug("Reconozco patrón. WebGrammarAction(%d)", value);
	return value;
}

int TitleGrammarAction(const int value){
	LogDebug("Reconozco patrón. TitleGrammarAction(%d)", value);
	return value;
}

tAttribute * DataAttrAction(char * value){
	LogDebug("DataAttrAction with value %s", value);
	tAttribute * attr = malloc(sizeof(tAttribute));
	if(attr == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	attr->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(attr->value, value);
	attr->next = NULL;
	return attr;
}

tAttributes * DataSingleAttrExpression(tAttribute * node){
	if(node == NULL){
		LogDebug("Error with node parameter");
		return NULL;
	}
	LogDebug("DataSingleAttrExpression with node value %s", node->value);
	tAttributes * attrExpr = malloc(sizeof(tAttributes));
	if(attrExpr == NULL){
		LogDebug("Error with malloc");
		return NULL;
	}
	attrExpr->size = 1;
	attrExpr->first = node;
	return attrExpr;
}

tAttributes * LeftAppendAttrExpressionAction(tAttribute * leftNode, tAttributes * attrExpr){
	if(leftNode == NULL || attrExpr == NULL){
		LogDebug("Error with parameters on LeftAppend");
		return NULL;
	}
	LogDebug("DataSingleAttrExpression with node value %s and expr size %d", leftNode->value, attrExpr->size);
	leftNode->next = attrExpr->first;
	attrExpr->first = leftNode;
	attrExpr->size++;
	return attrExpr;
}

tRowData * RowDataAction(char * content){
	tRowData * rData = malloc(sizeof(tRowData));
	if(rData == NULL){
		return NULL;
	}
	rData->value = malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(rData->value, content);
	rData->nextCell = NULL;
	rData->rowAttrs = NULL;
	return rData; 
}

tRowData * RowDataWithAttrsAction(tAttributes * attrs, char * content){
	tRowData * rData = malloc(sizeof(tRowData));
	if(rData == NULL){
		return NULL;
	}
	rData->value = malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(rData->value, content);
	rData->nextCell = NULL;
	rData->rowAttrs = attrs;
	return rData; 
}

tRow * RowDataUnion(tRowData * r1, tRowData * r2){
	tRow * newRow = malloc(sizeof(tRow));
	if(newRow == NULL){
		return NULL;
	}
	newRow->firstCell = r1;
	r1->nextCell = r2;
	newRow->size = 2;
	return newRow;
}

tRow * RowExprUnion(tRow * row, tRowData * cell){
	cell->nextCell = row->firstCell;
	row->firstCell = cell;
	row->size++;
	return row;
}

tRow * RowExpressionAction(tRow * row_content){
	// Aca no se que hacer porque todo el contenido de la
	// fila ya está formateado bien. TODO: charlarlo.
	return row_content;
}

tRows * SingleRowAction(tRow * row){
	tRows * rows = malloc(sizeof(tRows));
	if(rows == NULL){
		return NULL;
	}
	rows->firstRow = row;
	rows->size = 1;
	return rows;
}

tRows * RightAppendRowAction(tRows * rows, tRow * row){
	row->nextRow = rows->firstRow;
	rows->firstRow = row;
	rows->size++;
	return rows;
}

tTable * TableExpressionAction(int rows, int cols, tRows * r){
	tTable * newTable = malloc(sizeof(tTable));
	if(newTable == NULL)
		return NULL;

	newTable->firstRow = rows;
	newTable->colsDeclared = cols;
	newTable->rowsDeclared = r;
	return newTable;
}

tTitleAttrs  * TitleAttrsPlainAction(tAttributes * attrs){
	tTitleAttrs * aux = malloc(sizeof(tTitleAttrs));
	if(aux == NULL){
		return NULL;
	}
	aux->first = attrs->first;
	aux->size = attrs->size;
	aux->titleSize = -1;
	aux->ID = NULL;

	return aux;
}

tTitleAttrs * TitleAttrsWithSizeAction(int titleSize, tAttributes * attrs){
	tTitleAttrs * aux = malloc(sizeof(tTitleAttrs));
	if(aux == NULL){
		return NULL;
	}
	aux->titleSize = titleSize;
	aux->first = attrs->first;
	aux->size = attrs->size + 1; //TitleSize cuenta como attr pero no está declarado como tal
	return aux;
}

tTitleAttrs * TitleAttrsWithIDAction(char * ID, tAttributes * attrs){
	tTitleAttrs * aux = malloc(sizeof(tTitleAttrs));
	if(aux == NULL){
		return NULL;
	}
	aux->ID = malloc(sizeof(char) * (strlen(ID) + 1));
	strcpy(aux->ID, ID);
	aux->first = attrs->first;
	aux->size = attrs->size + 1; //ID cuenta como attr pero no está declarado como tal
	return aux;
}

tTitle * TitleGrammarActionNoAttrsCont(char * value){
	tTitle * title = malloc(sizeof(tTitle));
	if(title == NULL){
		return NULL;
	}
	title->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(title->value, value);
	title->attrs = NULL;
	title->isLink = 1; //NOT a link
	return title;
}

tTitle * TitleGrammarActionWithAttrsCont(tTitleAttrs * attrs, char * value){
	tTitle * title = malloc(sizeof(tTitle));
	if(title == NULL){
		return NULL;
	}
	title->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(title->value, value);
	title->attrs = attrs;
	title->isLink = 1;
	return title;
}

tTitle * TitleGrammarActionNoAttrsLink(char * value){
	tTitle * title = malloc(sizeof(tTitle));
	if(title == NULL){
		return NULL;
	}
	title->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(title->value, value);
	title->attrs = NULL;
	title->isLink = 0; 
	return title;
}

tTitle * TitleGrammarActionWithAttrsLink(tTitleAttrs * attrs, char * value){
	tTitle * title = malloc(sizeof(tTitle));
	if(title == NULL){
		return NULL;
	}
	title->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(title->value, value);
	title->attrs = attrs;
	title->isLink = 0;
	return title;
}