#ifndef GENERATOR_HEADER
#define GENERATOR_HEADER

#include <string.h>
#include "../support/shared.h"

#define BLOCK 200

char * Generator(tProgram * result);
void printHTML(tWebExpr * result, char * text);
void printTitle(tTitle * title);

#endif
