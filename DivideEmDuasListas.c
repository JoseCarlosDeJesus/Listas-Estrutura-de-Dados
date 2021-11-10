#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
}

Lista*insere(lista*l,int i){
    Lista*novo=(Lista*)malloc(sizeof(Lista));
    novo->info=i;
    novo->prox=l;
    return novo;
}

Lista* divide_em_dois(Lista*a,int n){
       Lista*p;
       Lista* b;
       int cont=1;
       for(p=a;p!=NULL;p=p->prox){
           if(cont > n){
              b=insere(b,p->prox);
           }
           cont++;
       }
       if(cont > n){
          return NULL;//nao ha n elementos na lista a
       }
       return b;
}
