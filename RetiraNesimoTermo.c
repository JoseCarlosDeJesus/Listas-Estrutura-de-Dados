#include<stdio.h>
#include<stdlib.h>

struct lista{
   int info;
   struct lista* prox;
};
typedef struct lista Lista;

Lista*retira(Lista*l, int v){
      Lista* ant=NULL;
      Lista * p=l;
      while(p!=NULL && p->info !=v){
           ant=p;
           p=p->prox;
      }
      if(p==NULL){
         return l; //nao achou retorna lista original
      }
      if(ant==NULL){
         l=p->prox;
      }
      else{
         ant->prox=p->prox;
      }
      free(p);
      return l;
}

Lista* remove_n_esimo_termo(Lista*a,int n){
     int i=1;
     Lista* novo;
     for(novo=a;novo!=NULL;novo=novo->prox){
         if(i==n){
            novo=retira(novo,novo->info);
            break;
         }
     }
     return novo;
}
