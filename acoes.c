#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "acoes.h"

PRODUTO carregar_Produtos(FILE *f, PRODUTO x){
    
    int foundID, foundStock;
    char *buffer, *foundName;
    PRODUTO new;

    buffer = malloc(61);

    //strsep
    while((fgets(buffer,60,f)) != NULL){
        foundID = atoi(strsep(&buffer,"."));
        foundName = strsep(&buffer, ".");
        foundStock = atoi(buffer);
        new = criar_Produto(foundID, foundName, foundStock);
        adicionar_PRODUTO(&x,new);
    }
    return x;
}

void escrever_Produto(FILE *f, PRODUTO *x){
    fprintf(f, "%d.%s.%d\n", (*x)->ID,(*x)->nome,(*x)->stock);
}

void gravar(FILE *f, PRODUTO *x){
    while((*x)){
        escrever_Produto(f,x);
        x = &((*x)->prox);
    }
}

PRODUTO criar_Produto(int ID, char* nome, int stock){
    PRODUTO newProduto = malloc(sizeof(struct product));
    newProduto->ID = ID;
    strcpy(newProduto->nome,nome);
    newProduto->stock = stock;

    return newProduto;
}

void adicionar_PRODUTO(PRODUTO *x, PRODUTO add){
    PRODUTO *prev = x;
    add->prox = NULL;
    while((*x) && (*x)->prox){
        if(strcmp(add->nome,(*x)->nome) == 0 && add->ID == (*x)->ID){
            (*x)->stock += add->stock;
            return;
        }
        prev = x;
        x = &((*x)->prox);
    }
    if(!(*prev)) *x = add;
    else (*x)->prox = add;
}