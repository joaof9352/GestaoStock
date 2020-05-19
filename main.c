#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include "acoes.h"


int main(){
    PRODUTO p;
    FILE *f,*new; 
    f = fopen("db","r+");
    new = fopen("ans", "w");
    p = carregar_Produtos(f,p);
    gravar(new,&p);
    fclose(f);
    fclose(new);
    return 0;
}
