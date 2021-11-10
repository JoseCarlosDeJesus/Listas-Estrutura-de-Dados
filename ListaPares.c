#include<stdio.h>
#include<stdlib.h>

struct lista{
   int info;
   struct lista *prox;
};

typedef struct lista Lista;

Lista* inicializa(){
     return NULL;
}
Lista*insere(Lista* a,int i){
    Lista* novo=(Lista*)malloc(sizeof(Lista));
    novo->info=i;
    novo->prox=a;
    return novo;
}

 Lista* paresLista(Lista* a){
    Lista*p;
    Lista* b=(Lista*)malloc(sizeof(Lista));
    b=inicializa()
    for(p=a;p!=NULL;p=p->prox){
        if((p->info%2)==0){
            b=insere(b,p->info);
        }
    }
    return b;
}
