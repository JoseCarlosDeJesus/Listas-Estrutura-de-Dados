#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista*prox;
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

void retira_x_da_lista(Lista*a, int x){
     for(a=a;a!=NULL;a=a->prox){
         if(a->info==x)
            a=retira(a,a->info);
     }

}
