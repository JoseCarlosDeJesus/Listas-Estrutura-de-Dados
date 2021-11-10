#include<stdio.h>
#include<stdlib.h>

struct lista{
   int info;
   struct lista *prox;
};
typedef struct lista Lista;

Lista* insere(Lista*a, int i){
    Lista*novo=(Lista*)malloc(sizeof(Lista));
    novo->info= int i;
    novo->prox=l;
    return novo;
}

Lista* intercalada(Lista*a,Lista*b){
   Lista* intercalada=(Lista*)malloc(sizeof(Lista));
   Lista*p;
   for(p=a;p!=NULL;p=p->prox){
       intercalada=insere(intercalada,p->info);
       if(b!=NULL)
          intercalada=insere(intercalada,b->info);
       b=b->prox;
   }
   return intercalada;
}
