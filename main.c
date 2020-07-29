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
    PRODUTO add = criar_Produto(4, "Maracuja", 65);
    PRODUTO addb = criar_Produto(3, "Bananas", 26);
    adicionar_PRODUTO(&p,add);
    adicionar_PRODUTO(&p,addb);
    gravar(new,&p);
    gravar(stdout,&p);
    fclose(f);
    fclose(new);
    return 0;
}
