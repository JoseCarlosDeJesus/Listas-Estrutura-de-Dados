#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

//nesse caso as listas tem que ser iguais em tudo ate em posicao

int verifica_listas_iguais(Lista*a,Lista*b){
    Lista*p;
    Lista*c=b;
    for(p=a;p!=NULL;p=p->prox){
           if(p->info!=c->info)
              return 1;//nao sao iguais
           c=c->prox;
           if(c==NULL)
               break;
    }
    return 0;//as duas listas sao iguais
}
