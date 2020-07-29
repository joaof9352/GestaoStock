#ifndef __ACOES
#define __ACOES

#include "estado.h"

PRODUTO carregar_Produtos(FILE *, PRODUTO);
void escrever_Produto(FILE *, PRODUTO *);
void gravar(FILE *, PRODUTO *);
PRODUTO criar_Produto(int, char*, int);
void adicionar_PRODUTO(PRODUTO *atual, PRODUTO toAdd);

#endif