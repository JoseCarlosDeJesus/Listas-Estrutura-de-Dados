#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

float soma_lista(Lista* a){
      Lista*p;
      int soma=0;
      for(p=a;p!=NULL;p=p->prox){
          soma=soma+(p->info);
      }
      return soma;
}
