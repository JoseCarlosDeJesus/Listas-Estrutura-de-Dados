#include<stdio.h>
#include<stdlib.h>

struct lista{
       int info;
       struct lista *prox;
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


int remove_n(Lista*l,int n){
       Lista*p=l;
       if(p==NULL)
          return 1;
       int i=0;
       while(i!=(n-1)){
        p=retira(l,l->info);
        p=p->prox;
        i++;
       }
       return 0;
}

