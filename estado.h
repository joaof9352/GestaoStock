#ifndef __ESTADO
#define __ESTADO

typedef struct product{
    int ID;
    char nome[61];
    int stock;
    struct product *prox;
} *PRODUTO;

#endif