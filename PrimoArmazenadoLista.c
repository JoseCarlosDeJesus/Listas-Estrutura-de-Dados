#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

int primo_armazenado(Lista*a){
    Lista*p;int i=0; int m;int primo=1;
    for(p=a;p!=NULL;p=p->prox){
        for(m=2;m*m=<(p->info);m++){
            if((p->info)%m==0){
                primo=0;
            }
        }
        if(primo){
           i++;
           primo=1;
        }
        else{
          primo=1;
          continue;
        }
    }
    return i;
}
