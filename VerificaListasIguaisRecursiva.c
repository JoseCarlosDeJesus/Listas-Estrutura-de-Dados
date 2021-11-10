#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

int verifica_listas_iguais_recursiva(Lista*a,Lista*b){
    if(a->info!=b->info)
        return 1;//nao sao iguais
    else{
        if(a!=NULL && b!=NULL){
           verifica_listas_iguais_recursiva(a->prox,b->prox);
        }
    }
    return 0;
}
