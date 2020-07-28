#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include "acoes.h"


int main(){
    PRODUTO p = NULL;
    FILE *f,*new; 
    f = fopen("db","r+");
    new = fopen("ans", "w");
    p = carregar_Produtos(f,p);
    PRODUTO add = criar_Produto(1, "Pessego", 65);
    PRODUTO addb = criar_Produto(2, "Bananas", 26);
    p = adicionar_PRODUTO(p,add);
    p = adicionar_PRODUTO(p,addb);
    gravar(new,&p);
    fclose(f);
    fclose(new);
    return 0;
}
