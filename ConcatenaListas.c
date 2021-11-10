#include<stdio.h>
#include<stdlib.h>

struct lista{
       int info;
       struct lista *prox;
};
typedef struct lista Lista;

Lista*insere(Lista*l, int i){
      Lista*novo=(Lista*)malloc(sizeof(Lista));
      novo->info=i;
      novo->prox=l;
      return novo;
}

Lista* concatena(Lista* l,Lista *l2){
     Lista*novo= (Lista*)malloc(sizeof(Lista));
     if(novo== NULL){
        return NULL;// nao conseguiu fazer a alocação
     }
     for(novo=l;novo!=NULL;novo=l->prox){
         novo=insere(novo,novo->info);
     }
     for(novo=l2;novo!=NULL;novo=l2->prox){
         novo=insere(novo,novo->info);
     }
     return novo;
}
