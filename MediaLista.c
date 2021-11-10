#include<stdio.h>
#include<stdlib.h>

struct lista{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;

float mediaLista(Lista* a){
      Lista*p;
      float media=0;int n=0;
      for(p=a;p!=NULL;p=p->prox){
          media=media+(p->info);
          n++;
      }
      media=media/n;
      return media;
}
