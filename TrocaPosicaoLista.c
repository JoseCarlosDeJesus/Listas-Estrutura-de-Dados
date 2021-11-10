#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista*prox;
};
typedef struct lista Lista;

Lista *busca(Lista*l,int v){
    Lista *p;
    for(p=l;p!=NULL;p=p->prox){
        if((p->info)==v)
            return p;
        else{
            return NULL;
        }
    }
}


//troca a posicao de a por b

int troca_posicao(Lista*l, int a, int b){
    Lista*p=l;
    p=busca(p,a);
    if(p==NUll)
       return 1;//nao conseguiu
    p->info=b;//troca posicao de a para b
    p=busca(p,b)
    if(p==NULL)
       return 1;
    p->info=a;
    return 0;
}
