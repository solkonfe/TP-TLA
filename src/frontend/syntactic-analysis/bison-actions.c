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

void ProgramGrammarAction(tWebExprs * exprs) {
	LogDebug("Reconozco patrón. ProgramGrammarAction()");
	tProgram * value = malloc(sizeof(tProgram));
	if(value == NULL)
		return;
	value->initial = exprs;
	state.succeed = true;
	state.result = value;
}

tAttribute * ColorAttrAction(char * value){
	LogDebug("DataAttrAction with value %s", value);
	tAttribute * attr = malloc(sizeof(tAttribute));
	if(attr == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	attr->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(attr->value, value);
	attr->next = NULL;
	attr->type = COLORVAL;
	return attr;
}


tAttribute * PositionAttrAction(char * value){
	LogDebug("[BISON] DataAttrAction with value %s", value);
	tAttribute * attr = malloc(sizeof(tAttribute));
	if(attr == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	attr->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(attr->value, value);
	attr->next = NULL;
	attr->type = POSITIONVAL;
	return attr;
}

tAttribute * BoldAttrAction(){
	tAttribute * attr = malloc(sizeof(tAttribute));
	if(attr == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	attr->value = malloc(sizeof(char) * (strlen("bold") + 1));
	strcpy(attr->value, "bold");
	attr->next = NULL;
	attr->type = BOLDVAL;
	return attr;
}

tAttribute * ItalicAttrAction(){
	tAttribute * attr = malloc(sizeof(tAttribute));
	if(attr == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	attr->value = malloc(sizeof(char) * (strlen("italic") + 1));
	strcpy(attr->value, "italic");
	attr->next = NULL;
	attr->type = ITALICVAL;
	return attr;
}

tAttribute * UnderlinedAttrAction(){
	tAttribute * attr = malloc(sizeof(tAttribute));
	if(attr == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	attr->value = malloc(sizeof(char) * (strlen("underlined") + 1));
	strcpy(attr->value, "underlined");
	attr->next = NULL;
	attr->type = UNDERLINEDVAL;
	return attr;
}

tAttributes * DataSingleAttrExpressionAction(tAttribute * node){
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
	LogDebug("LeftAppendAttrExpressionAction with node value %s and expr size %d", leftNode->value, attrExpr->size);
	leftNode->next = attrExpr->first;
	attrExpr->first = leftNode;
	attrExpr->size++;
	return attrExpr;
}

tAttributes * RightAppendAttrExpressionAction(tAttributes * attrExpr, tAttribute * rightNode){
	if(rightNode == NULL || attrExpr == NULL){
		LogDebug("Error with parameters on LeftAppend");
		return NULL;
	}
	LogDebug("[BISON] RightAppendAttrExprAction with value %s", rightNode->value);
	tAttribute * aux = attrExpr->first;
	while(aux->next != NULL)
		aux = aux->next;
	aux->next = rightNode;
	attrExpr->size++;
	return attrExpr;
}

tRowData * RowDataAction(char * content){
	tRowData * rData = malloc(sizeof(tRowData));
	if(rData == NULL){
		return NULL;
	}
	LogDebug("[BISON] RowDataAction");
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
	LogDebug("[BISON] RowDataWithAttrsAction");
	rData->value = malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(rData->value, content);
	rData->nextCell = NULL;
	rData->rowAttrs = attrs;
	return rData; 
}

tRow * SingleRowDataAction(tRowData * r1){
	tRow * row = malloc(sizeof(tRow));
	if(row == NULL){
		return NULL;
	}
	LogDebug("[BISON] singleRowDataExprAction");
	row->firstCell = r1;
	row->size = 1;
	return row;
}

tRow * RowDataUnion(tRowData * r1, tRowData * r2){
	tRow * newRow = malloc(sizeof(tRow));
	if(newRow == NULL){
		return NULL;
	}
	LogDebug("[BISON] RowDataUnion");
	newRow->firstCell = r1;
	r1->nextCell = r2;
	newRow->size = 2;
	return newRow;
}

tRow * RowExprUnion(tRow * row, tRowData * cell){
	cell->nextCell = row->firstCell;
	row->firstCell = cell;
	row->size++;
	LogDebug("[BISON] RowExprAction");
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

	newTable->firstRow = r;
	newTable->colsDeclared = cols;
	newTable->rowsDeclared = rows;
	return newTable;
}

tTitleAttrs  * TitleAttrsPlainAction(tAttributes * attrs){
	tTitleAttrs * aux = malloc(sizeof(tTitleAttrs));
	if(aux == NULL){
		return NULL;
	}
	aux->first = attrs->first;
	aux->size = attrs->size;
	aux->titleSize = NULL;
	aux->ID = NULL;

	return aux;
}

tTitleAttrs * TitleAttrsWithSizeAction(char * titleSize, tAttributes * attrs){
	printf("TItleATtrsWithSizeACtion with titleSize: %s\n", titleSize);
	printf("attrs->first->value: %s\n", attrs->first->value);
	tTitleAttrs * aux = malloc(sizeof(tTitleAttrs));
	if(aux == NULL){
		return NULL;
	}
	aux->titleSize = malloc(sizeof(char) * (strlen(titleSize) + 1));
	strcpy(aux->titleSize, titleSize);
	aux->first = attrs->first;
	aux->size = attrs->size + 1; //TitleSize cuenta como attr pero no está declarado como tal
	return aux;
}

tTitleAttrs * TitleAttrsOnlySizeAction(char * titleSize){
	printf("%s\n", titleSize);
	tTitleAttrs * aux = malloc(sizeof(tTitleAttrs));
	if(aux == NULL){
		return NULL;
	}
	aux->titleSize = malloc(sizeof(char) * (strlen(titleSize) + 1));
	strcpy(aux->titleSize, titleSize);
	aux->first = NULL;
	aux->size = 1; //TitleSize cuenta como attr pero no está declarado como tal
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

tTitleAttrs * TitleAttrsOnlyIDAction(char * ID){
	tTitleAttrs * aux = malloc(sizeof(tTitleAttrs));
	if(aux == NULL){
		return NULL;
	}
	aux->ID = malloc(sizeof(char) * (strlen(ID) + 1));
	strcpy(aux->ID, ID);
	aux->first = NULL;
	aux->size = 1; //ID cuenta como attr pero no está declarado como tal
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

tText * TextExprNoAttrs(char * content){
	tText * text = malloc(sizeof(tText));
	if(text == NULL){
		return NULL;
	}
	text->content = malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(text->content, content);
	text->ID = NULL;
	text->attrs = NULL;
	return text;
}


tText * TextExprWithAttrs(tAttributes * attrs, char * content){
	tText * text = malloc(sizeof(tText));
	if(text == NULL){
		return NULL;
	}
	text->content = malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(text->content, content);
	text->ID = NULL;
	text->attrs = attrs;
	return text;
}

tText * TextExprWithAttrsAndID(char * ID, tAttributes * attrs, char * content){
	tText * text = malloc(sizeof(tText));
	if(text == NULL){
		return NULL;
	}
	text->content = malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(text->content, content);
	text->ID = malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(text->ID, ID);
	text->attrs = attrs;
	return text;
}

tDivAttrs * DivAttrsPos(char * pos){
	tDivAttrs * divA = malloc(sizeof(tDivAttrs));
	if(divA==NULL)
		return NULL;
	divA->pos = malloc(sizeof(char) * (strlen(pos) + 1));
	strcpy(divA->pos, pos);
	divA->ID = NULL; 
	return divA;
}

tDivAttrs * DivAttrsPosAndID(char * ID, char * pos){
	tDivAttrs * divA = malloc(sizeof(tDivAttrs));
	if(divA==NULL)
		return NULL;
	divA->pos = malloc(sizeof(char) * (strlen(pos) + 1));
	strcpy(divA->pos, pos);
	divA->ID = malloc(sizeof(char) * (strlen(ID)));
	strcpy(divA->ID, ID); 
	return divA;
}

tImage * ImgExprAction(char * src, char * alt){
	tImage * img = malloc(sizeof(tImage));
	if(img == NULL)
		return NULL;
	img->source = malloc(sizeof(char) * (strlen(src) + 1));
	img->altText = malloc(sizeof(char) * (strlen(alt) + 1));
	strcpy(img->source, src);
	strcpy(img->altText, alt);
	return img;
}

tImage * ImgExprActionWithIdref(char * src, char * alt, char * idref){
	tImage * img = malloc(sizeof(tImage));
	if(img == NULL)
		return NULL;
	img->source = malloc(sizeof(char) * (strlen(src) + 1));
	img->altText = malloc(sizeof(char) * (strlen(alt) + 1));
	img->idref = malloc(sizeof(char) * (strlen(idref) + 1));
	strcpy(img->source, src);
	strcpy(img->altText, alt);
	strcpy(img->idref, idref);
	return img;
}

tLink * LinkExpressionWithAttrs(char * src, tAttributes * attrs, char * content){
	tLink * link = malloc(sizeof(link));
	if(link == NULL){
		return NULL;
	}

	link->ref = malloc(sizeof(char)*(strlen(src) + 1));
	link->text = malloc(sizeof(char)*(strlen(src)+1));
	strcpy(link->ref, src);
	strcpy(link->text, content);
	link->attrs = attrs;
	return link;
}

tLink * LinkExpressionNoAttrs(char * src, char * content){
	tLink * link = malloc(sizeof(link));
	if(link == NULL){
		return NULL;
	}

	link->ref = malloc(sizeof(char)*(strlen(src) + 1));
	link->text = malloc(sizeof(char)*(strlen(src)+1));
	strcpy(link->ref, src);
	strcpy(link->text, content);
	link->attrs = NULL;
	return link;
}

tLink *LinkExpressionNoAttrsIDREF(char * idref, char * content){
	tLink * link = malloc(sizeof(link));
	if(link == NULL){
		return NULL;
	}

	link->ref = malloc(sizeof(char)*(strlen(idref) + 1));
	link->text = malloc(sizeof(char)*(strlen(idref)+1));
	strcpy(link->ref, idref);
	strcpy(link->text, content);
	link->attrs = NULL;
	return link;
}

tWebExpr * TitleExprAction(tTitle * title){
	tWebExpr * webExp = malloc(sizeof(tWebExpr));
	if(webExp == NULL)
		return NULL;
	webExp->type=TITLEEXPR;
	webExp->expr = title;
	webExp->next = NULL;
	return webExp;
}

tWebExpr * TextExprAction(tText * text){
	tWebExpr * webExp = malloc(sizeof(tWebExpr));
	if(webExp == NULL)
		return NULL;
	webExp->type = TEXTEXPR;
	webExp->expr = text;
	webExp->next = NULL;
	return webExp;
}

tWebExpr * ImgExpressionAction(tImage * img){
	tWebExpr * webExp = malloc(sizeof(tWebExpr));
	if(webExp == NULL)
		return NULL;
	webExp->type = IMGEXPR;
	webExp->expr = img;
	webExp->next = NULL;
	return webExp;
}

tWebExpr * LinkExprAction(tLink * link){
	tWebExpr * webExp = malloc(sizeof(tWebExpr));
	if(webExp == NULL)
		return NULL;
	webExp->type = LINKEXPR;
	webExp->expr = link;
	webExp->next = NULL;
	return webExp;
}

tWebExpr * TableExprAction(tTable * table){
	tWebExpr * webExp = malloc(sizeof(tWebExpr));
	if(webExp == NULL)
		return NULL;
	webExp->type = TABLEEXPR;
	webExp->expr = table;
	webExp->next = NULL;
	return webExp;
}

tWebExpr * DivExprAction(tDiv * div){
	tWebExpr * webExp = malloc(sizeof(tWebExpr));
	if(webExp == NULL)
		return NULL;
	webExp->type = DIVEXPR;
	webExp->expr = div;
	webExp->next = NULL;
	return webExp;
}

tWebExprs * SimpleWebExpressionAction(tWebExpr * exp){
	tWebExprs * exps = malloc(sizeof(tWebExprs));
	if(exps == NULL)
		return NULL;
	exps->first = exp;
	exps->size = 1;
	return exps;
}

tWebExprs * RightAppendWebExprAction(tWebExprs * exps, tWebExpr * exp){
	tWebExpr * aux = exps->first;
	while(aux->next != NULL)
		aux = aux->next;
	aux->next = exp;
	exps->size++;
	return exps;
}

tDiv * DivExprWithAttrsSingleWeb(tDivAttrs * attrs, tWebExprs * content){
	tDiv * div = malloc(sizeof(tDiv));
	if(div == NULL)
		return NULL;
	div->attrs = attrs;
	div->content = content;
	div->size = 1;
	return div;
}

tDiv * DivExprNoAttrsSingleWeb(tWebExprs * content){
	tDiv * div = malloc(sizeof(tDiv));
	if(div == NULL)
		return NULL;
	div->attrs = NULL;
	div->content = content;
	div->size = 1;
	return div;
}

tDiv * DivExprWithAttrsMulExp(tDivAttrs * attrs, tWebExprs * content){
	tDiv * div = malloc(sizeof(tDiv));
	if(div == NULL)
		return NULL;
	div->attrs = attrs;
	div->content = content;
	div->size = content->size;
	return div;
}

tDiv * DivExprNoAttrsMulExp(tWebExprs * content){
	tDiv * div = malloc(sizeof(tDiv));
	if(div == NULL)
		return NULL;
	div->attrs = NULL;
	div->content = content;
	div->size = content->size;
	return div;
}