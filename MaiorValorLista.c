#include<stdio.h>
#include<stdlib.h>

struct lista{
       int info;
       struct lista *prox;
};
typedef struct lista Lista;

int maior_valorLista(Lista*l,int *max,int *i){
         *max=-2147483648;
         Lista*p;i=0;
         for(p=l;p!=NULL;p=p->prox){
             if((p->info)>max && max!=(p->info))
                 max=p->info;
             else{
                 i++;
             }
         }
         return 0;
}
