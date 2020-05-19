#ifndef __ACOES
#define __ACOES

#include "estado.h"

PRODUTO carregar_Produtos(FILE *f, PRODUTO *x);
void escrever_Produto(FILE *, PRODUTO *);
void gravar(FILE *, PRODUTO *);
void adicionar_PRODUTO(PRODUTO *, PRODUTO );

#endif