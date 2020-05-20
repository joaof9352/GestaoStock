#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "acoes.h"

PRODUTO carregar_Produtos(FILE *f, PRODUTO *x){
    
    int foundID, foundStock;
    char *buffer,*foundName;
    PRODUTO *new;

    while(fgets(buffer, 71, f) != NULL){
        
        foundID = atoi(strsep(&buffer,"."));
        foundName = strsep(&buffer,".");
        foundStock = atoi(strsep(&buffer,"."));
        new = criar_Produto(foundID, foundName, foundStock);
        x = &(adicionar_PRODUTO(x,new));
    }
    return x;
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

PRODUTO * criar_Produto(int ID, char* nome, int stock){
    PRODUTO newProduto = malloc(sizeof(struct product));
    newProduto->ID = ID;
    for(int i = 0; nome[i]; i++) newProduto->nome[i] = nome[i];
    newProduto->stock = stock;

    return &newProduto;
}



PRODUTO adicionar_PRODUTO(PRODUTO *x, PRODUTO add){
    add->prox = x;
    return add;
}