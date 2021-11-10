#include<stdio.h>
#include<stdlib.h>

struct lista{
   int info;
   struct lista *prox;
};
typedef struct lista Lista;

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


Lista* intercalada(Lista*a,Lista*b){
   Lista* intercalada=(Lista*)malloc(sizeof(Lista));
   Lista*p;
   for(p=a;p!=NULL;p=p->prox){
       intercalada=insere_ordenado(intercalada,p->info);
       if(b!=NULL)
          intercalada=insere_ordenado(intercalada,b->info);
       b=b->prox;
   }
   return intercalada;
}
