#include<stdio.h>
#include<stdlib.h>

#DEFINE N 50;
struct lista{
       int info;
       struct lista *prox;
};
typedef struct lista Lista;

Lista*insere_vetor(Lista*a,int*b){
      Lista*novo=(Lista*)malloc(sizeof(Lista));
      int cont;
      novo=a;
      for(i=0;i<=N;i++){
          if(novo!=NULL){
             novo->info=b[i];
             novo=novo->prox;
          }
      }
      return novo;
}
