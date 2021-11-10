#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

void imprime_rec (Lista* l)
{
 if (l==NULL)
    return;
 //imprime primeiro elemento
 printf(“%d\n”,l->info);

 //imprime sub-lista
 imprime_rec(l->prox);
}
