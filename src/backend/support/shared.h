#ifndef SHARED_HEADER
#define SHARED_HEADER

#include <stdio.h>

// Descriptor del archivo de entrada que utiliza Bison.
extern FILE * yyin;

// Descriptor del archivo de salida que utiliza Bison.
extern FILE * yyout;

// Variable global que contiene el número escaneado.

// extern int yylval;

// Variable global que contiene el número de la línea analizada.
extern int yylineno;

// Token actual en el tope de la pila del analizador Bison.
extern char * yytext;

// Función global de manejo de errores en Bison.
extern void yyerror(const char * string);

// Función global del analizador léxico Flex.
extern int yylex(void);

// Función global del analizador sintáctico Bison.
extern int yyparse(void);

// Emular tipo "boolean".
typedef enum {
	false = 0,
	true = 1
} boolean;

typedef enum {
	COLORVAL = 0,
	POSITIONVAL,
	BOLDVAL,
	ITALICVAL, 
	UNDERLINEDVAL
} atr_type;

typedef enum expr_type {
	TITLEEXPR = 0,
	IMGEXPR,
	LINKEXPR,
	TABLEEXPR,
	DIVEXPR,
	TEXTEXPR
} expr_type;

typedef struct tAttribute
{
	//atr_type type;
	atr_type type;
	char * value;
	struct tAttribute * next;
} tAttribute;

typedef struct tAttributes
{
	struct tAttribute * first;
	int size;
} tAttributes;

typedef struct tRowData
{
	char * value;
	struct tRowData * nextCell;
	tAttributes * rowAttrs;
} tRowData;

typedef struct tRow
{
	tRowData * firstCell;
	struct tRow * nextRow;
	int size;
} tRow;

typedef struct tRows
{
	tRow * firstRow;
	int size;
} tRows;

typedef struct tTable{
	tRows * firstRow;
	int colsDeclared;
	int rowsDeclared;
} tTable;

typedef struct tTitleAttrs{
	tAttribute * first;
	int titleSize;
	char * ID;
	int size;
} tTitleAttrs;

typedef struct tTitle{
	char * value;
	tTitleAttrs * attrs;
	int isLink; // If link, isLink = 0. If content, isLink = 1.
} tTitle;

typedef struct tText{
	tAttributes * attrs;
	char * ID;
	char * content;
} tText;

typedef struct tDivAttrs{
	char * pos;
	char * ID;
} tDivAttrs;

typedef struct tDiv{
	tDivAttrs * attrs;
	void * content;
	int size;
} tDiv;

typedef struct tImage{
	char * source;
	char * idref;
	char * altText;
} tImage;

typedef struct tLink{
	tAttributes * attrs;
	char * ref;
	char * text;
} tLink;

typedef struct tWebExpr{
	expr_type type;
	void * expr;
	struct tWebExpr * next;
} tWebExpr;

typedef struct tWebExprs{
	int size;
	tWebExpr * first;
} tWebExprs;

typedef struct tProgram{
	tWebExprs * initial;
} tProgram;


// Estado global de toda la aplicación.
typedef struct {

	// Indica si la compilación tuvo problemas hasta el momento:
	boolean succeed;

	// Indica el resultado de la compilación:
	int result;

	// Agregar una pila para almacenar tokens/nodos.
	// Agregar un nodo hacia la raíz del árbol de sintaxis abstracta.
	// Agregar una tabla de símbolos.
	// ...

} CompilerState;

// El estado se define e inicializa en el archivo "main.c":
extern CompilerState state;

#endif
