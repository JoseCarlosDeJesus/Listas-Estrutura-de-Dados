#include<stdio.h>
#include<stdlib.h>

struct lista{
   int info;
   struct lista *prox;
};

typedef struct lista Lista;

int retorna_paresLista(Lista* a){
    Lista*p;int cont=0;
    for(p=a;p!=NULL;p=p->prox){
        if((p->info%2)==0){
            cont++;
        }
    }
    return cont;
}
