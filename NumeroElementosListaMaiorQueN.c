#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

//devolve o numero de elementos maior que n
int maior_que_n(Lista*a, int n){
    Lista*p;int i=0;
    for(p=a;p!=NULL;p=p->prox){
          if((p->info)>n){
             i++;
          }
    }
    return i;
}
