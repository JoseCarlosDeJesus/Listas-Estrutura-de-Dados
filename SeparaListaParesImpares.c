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

Lista* pares_impares(Lista*a){
       Lista* pares=(Lista*)malloc(sizeof(Lista));
       Lista  impares=(Lista*)malloc(sizeof(Lista));
       Lista*p;
       for(p=a;p!=NULL;p=p->prox){
           if(p->info%2==0){
             pares=insere(pares,p->info);
           }
           else{
             impares=insere(impares,p->info);
           }
       }
       return pares;
}
