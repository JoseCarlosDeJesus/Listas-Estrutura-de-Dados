#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;
//cria uma lista com a uniao entre a lista a e b

Lista*insere(Lista*a,int i){
      Lista*novo=(Lista*)malloc(sizeof(Lista));
      novo->info=i;
      novo->prox=a;
      return novo;
}

//nesse caso o v vai ser o elemento que sera avaliado,se ele estiver na interseccao ele nao sera adicionado
int avalia_elemento(Lista*a,int v){
      Lista*p;
      for(p=a;p!=NULL;p=p->prox){
          if(p->info==v)
             return 1;//ele esta na interseccao e nao sera adicionado
          else
             return 0;// ele nao esta na interseccao
      }
}

Lista* UNION(Lista*a,Lista*b){
    Lista*union;int repetido=0,int i=0;Lista*p;
    for(p=a;p!=NULL;p=p->prox){
        //para os outros casos avalia se ele esta na interseccao,se estiver, nao adiciona,se nao estiver adiciona
        repetido=avalia(b,p->info);
        if(repetido==0){
           union=insere(b,p->info);
        }
        else{
           continue;
        }
    }
    return union;
}
