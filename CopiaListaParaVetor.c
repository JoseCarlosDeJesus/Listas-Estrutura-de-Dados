#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista*prox;
};
typedef struct lista Lista;

int* copia_para_vetor(Lista*a,int*v,int n){
     Lista*p;int i=0;
     for(p=a;p!=NULL;p=p->prox){
         v[i]=p->info;
         i++;
         if(i>n)//se tiver mais elementos na lista que cabe no vetor
            break;
     }
     return v;
}
