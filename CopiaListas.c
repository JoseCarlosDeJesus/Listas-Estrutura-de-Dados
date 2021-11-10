#include<stdio.h>
#include<stdlib.h>

struct lista{
   int info;
   struct lista*prox;
};
typedef struct lista Lista;

Lista*insere(lista*l,int i){
    Lista*novo=(Lista*)malloc(sizeof(Lista));
    novo->info=i;
    novo->prox=l;
    return novo;
}

//copia o conteudo da lista a para a lista b
void copia_lista(Lista*a,Lista*b){
     Lista*p;
     for(p=a;p!=NULL;p=p->prox){
         b=insere(b,p->info);
     }
}
