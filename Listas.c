#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista*prox;
};
typedef struct lista Lista;

Lista* inicializa(){
     return NULL;
}

Lista*insere(Lista*l,int i){
     Lista*novo=(Lista*)malloc(sizeof(Lista));
     novo->info=i;
     novo->prox=l;
     return novo;
}

void imprime(Lista* l){
     Lista*p;
     for(p=l;p!=NULL;p=p->prox){
         printf("info= %d\n", p->info);
     }
}

int vazia(Lista *l){
    if(l==NULL)
       return 1;
    else
       return 0;
}

Lista*busca(Lista*l,int v){
     Lista*p;
     for(p=l;p!=NULL;p=p->prox){
         if(p->info==v)
            return p;
         else{
            return NULL;
         }
     }
}

Lista* retira(Lista* l, int v){
     Lista* ant=NULL;//ponteiro para elemento anterior
     Lista* p=l;//ponteiro para percorrer lista

     while(p!=NULL && p->info!=v){
          ant=p;
          p=p->prox;
     }

     if(p==NULL)
        return l;//n�o achou: retorna lista original
     if(ant==NULL){
        l=p->prox;//retira elemento do inicio
     }
     else{
        //retira elemento do meio da lista
        ant->prox=p->prox;
     }
     free(p);
     return l;
}

void libera(Lista* l){
     Lista*p=l;
     while(p!=NULL){
          Lista*t=p->prox;//guarda referencia para o proximo elemento
          free(p);//libera a memoria do ponteiro p
          p=t;//faz p apontar para o proximo
     }
}

//lista ordenada inicio

//fun��o auxiliar: cria e inicializa um n�

Lista*cria(int v){
    Lista* p=(Lista*)malloc(sizeof(Lista));
    p->info=v;
    return p;
}

//fun��o insere_ordenado:insere elemento em ordem
Lista*insere_ordenado(Lista*l,int v){
      Lista*novo=cria(v);//cria novo n�
      Lista*ant=NULL;//ponteiro para elemento anterior
      Lista*p=l;//ponteiro para percorrer a lista
      //procura posi��o de inser��o
      while(p!=NULL && p->info<v){
           ant=p;
           p=p->prox;
      }
      //insere elemento
      if(ant==NULL){//insere elemento no inicio
         novo->prox=l;
         l=novo;
      }
      else{//insere elemento no meio da lista
         novo->prox=ant->prox;
         ant->prox=novo;
      }
      return l;
}

