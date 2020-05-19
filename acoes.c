#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "acoes.h"

PRODUTO carregar_Produtos(FILE *f, PRODUTO *x){
    PRODUTO newProduto = malloc(sizeof(struct product));

    char *buffer;
    char *found;
    while(fgets(buffer, 71, f) != NULL){
        int i, p = 0;
        newProduto->ID = atoi(strsep(&buffer,"."));
        found = strsep(&buffer,".");
        for(i = 0; found[i]; i++) newProduto->nome[i] = found[i];
        newProduto->stock = atoi(strsep(&buffer,"."));

        newProduto->prox = (*x);
        x = &newProduto;
    }

    return newProduto;
}

void escrever_Produto(FILE *f, PRODUTO *x){
    fprintf(f, "%4d.", (*x)->ID);
    for(int i = 0; (*x)->nome[i]; i++) fprintf(f, "%c",(*x)->nome[i]);
    fprintf(f, ".%4d", (*x)->stock);
    fprintf(f,"\n");
}

void gravar(FILE *f, PRODUTO *x){
    while((*x)){
        escrever_Produto(f,x);
        x = &((*x)->prox);
    }
}

void adicionar_PRODUTO(PRODUTO *x, PRODUTO add){
    PRODUTO *prev = NULL;    
    while((*x) && (*x)->prox && strcmp((*x)->ID,add->ID) < 0){
        prev = x;
        x = &((*x)->prox);
    }
}