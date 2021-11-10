#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

int tamanho_lista(Lista* a){
    if(a==NULL)
       return 0;//nao tem nenhum elemento na lista
    else{
       return 1+tamanho_lista(a->prox);
    }
}
