#include<stdio.h>
#include<stdlib.h>

struct produto{
int codProd; //codigo do produto
char nomeProd[10]; //nome do produto
float valor; //valor do produto
int qtdeEstoque; //quantidade disponıvel em estoque
struct produto *prox;
};
typedef struct produto Produto;

int menor_precoProduto(Produto* a){
    Produto *p=a;
    int i=0;
    float menor_valor=p->valor;
    for(p!=NULL;p=a->prox){
        if((p->valor)< menor_valor && menor_valor != (p->valor)){
              menor_valor=p->valor;
        }
    }
    return 0;
}
