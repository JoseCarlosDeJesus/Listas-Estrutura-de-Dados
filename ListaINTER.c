#include<stdio.h>
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
//v e o elemento a ser avaliado
int avalia_elemento(Lista*a,int v){
      Lista*p;
      for(p=a;p!=NULL;p=p->prox){
          if(p->info==v)
             return 1;//ele esta na interseccao e sera adicionado
          else
             return 0;// ele nao esta na interseccao
      }
}

Lista*INTER(Lista*a,Lista*b){
      Lista*p;int repetido=0,int i=0;
      Lista* inter=(Lista*)malloc(sizeof(Lista));
      if(inter==NULL)
         return NULL;//nao conseguiu alocar
    for(p=a;p!=NULL;p=p->prox){
        //para os outros casos avalia se ele esta na interseccao e depois se estiver adiciona ele, caso nao esteja passa
        repetido=avalia(b,p->info);
        if(repetido==1){
           inter=insere(inter,p->info);
        }
        else{
           continue;
        }
    }
    return inter;
}
