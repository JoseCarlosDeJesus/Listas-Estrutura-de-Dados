|#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista*insere(Lista*a,int i){
      Lista*novo=(Lista*)malloc(sizeof(Lista));
      novo->info=i;
      novo->prox=a;
      return novo;
}

//nesse caso o v vai ser o elemento que sera avaliado,se ele estar na lista nao sera adicionado
int avalia_elemento(Lista*a,int v){
      Lista*p;
      for(p=a;p!=NULL;p=p->prox){
          if(p->info==v)
             return 1;//ele esta na lista e nao sera adicionado
          else
             return 0;// ele nao esta na lista
      }
}

void copia_sem_repeticao(Lista*a,Lista*b){
    Lista*p;int repetido=0,int i=0;
    for(p=a;p!=NULL;p=p->prox){
        //ve se e o primeiro elemento a ser inserido
        if(i==0){
            b=insere(b,p->info);
            continue;
        }
        //para os outros casos avalia se ele esta e depois se nao estiver adiciona ele, caso esteja passa
        repetido=avalia(b,p->info);
        if(repetido==0){
           b=insere(b,p->info);
        }
        else{
           continue;
        }
        i++;
    }
}
