#ifndef __ACOES
#define __ACOES

#include "estado.h"

PRODUTO carregar_Produtos(FILE *f, PRODUTO *x);
void escrever_Produto(FILE *, PRODUTO *);
void gravar(FILE *, PRODUTO *);
PRODUTO * criar_Produto(int, char*, int);
PRODUTO adicionar_PRODUTO(PRODUTO *, PRODUTO);

#endif