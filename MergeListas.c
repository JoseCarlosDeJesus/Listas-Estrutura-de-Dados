#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista*prox;
};
typedef struct lista Lista;

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


Lista*retira(Lista*a,int v){
    Lista*ant=NULL;
    Lista* p=a;
    while(p!=NULL && p->info!=v){
          ant=p;
          p=p->prox;
    }
    if(p==NULL)
       return a;
    else{
       ant->prox=p->prox;
    }
    free(p);
    return a;
}

Lista* cria_no(int v){
   Lista*p=(Lista*)malloc(sizeof(Lista));
   p->info=v;
   return p;
}

Lista*insere_ordenado(Lista*l,int v){
     Lista*novo=cria(v);
     Lista*ant=NULL;
     Lista*p=l;

     //procura posicao de intercao
     while(p!=NULL && (p->info)<v){
         ant=p;
         p=p->prox;
     }

     //insere elemento inicio
     if(ant==NULL){
        novo->prox=l;
        l=novo;
     }
     //insere elemento meio ou final
     else{
        novo->prox=ant->prox;
        ant->prox=novo;
     }
     return l;
}


Lista* merge(Lista*a,Lista*b){
    Lista *p;//percorre a lista
    int cont=0;
    for(p=b;p!=NULL;p=p->prox){
        cont=avalia(a,p->info);//avalia se já tem um elemento de b em a
        if(cont==1){//ele esta na lista, remove ele da lista b
           b=retira(b,p->info);
        }
        else{
           continue;//ele nao esta na lista
        }
    }
    for(p=b;p!=NULL;p=p->prox){
        a=insere_ordenado(a,p->info);//coloca os elementos nao repetidos de b em a,de forma ordenada
    }
    return a;
}
