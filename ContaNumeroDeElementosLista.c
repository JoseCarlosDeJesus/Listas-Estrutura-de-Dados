#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

int conta_numero_elementos_lista(Lista*a){
    Lista*p;int i=0;
    for(p=a;p!=NULL;p=p->prox){
        i++;
    }
    return i;
}

int conta_numero_elementos_lista_recursiva(Lista*a){
    if(a==NULL)
       return 0;
    else{
       return 1+ conta_numero_elementos_lista_recursiva(a->prox);
    }
}
