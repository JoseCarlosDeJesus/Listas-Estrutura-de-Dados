#include<stdio.h>
#include<stdlib.h>

//as funções não listadas aqui, servem as de listas encadeadas simples

struct lista2{
     int info;
     struct lista2*prox;
     struct lista2*ant;
};
typedef struct lista2 Lista2;

Lista2*insere(Lista2*l,int v){
    Lista2* novo=(Lista2*)malloc(sizeof(Lista2));
    novo->info=v;
    novo->prox=l;
    novo->ant=NULL;
    //verifica se a lista não está vazia
    if(l!=NULL)
       l->ant=novo;
    return novo;
}

//busca um elemento da lista
Lista2*busca(Lista2*l,int v){
     Lista2*p;
     for(p=l;p!=l->ant;p=p->prox){
         if(p->info==v)
            return p;
         else
            return NULL;//não achou elemento
     }
}

Lista2*retira(Lista2*l, int v){
    Lista2*p=busca(l,v);

    if(p==NULL){
       return l;//não achou elemento: retorna lista inalterada
    }
    //retira elemento do encadeamento
    if(l==p)
       l=p->prox;
    else
       p->ant->prox=p->prox;
    if(p->prox!=NULL)
       p->prox->ant=p->ant;

    free(p);
    return l;
}
