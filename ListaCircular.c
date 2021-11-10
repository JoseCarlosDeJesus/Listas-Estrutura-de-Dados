#include<stdio.h>
#include<stdlib.h>

//estrutura de lista encadeada simples
struct lista{
    int info;
    struct lista*prox;
};
typedef struct lista Lista;

//estrutura de lista duplamente encadeada
struct lista2{
     int info;
     struct lista2*prox;
     struct lista2*ant;
};
typedef struct lista2 Lista2;


void imprime_circular(Lista*l){
     Lista*p=l;//faz p apontar para o nó inicial
     //testa se a lista não é vazia
     if(p){
       //percorre os elementos até alcançar novamente o inicio
       do{
          printf("%d\n", p->info);//imprime info
          p=p->prox;
       }while(p!=l);//até chegar no primeiro elemento denovo
     }
}

//imprime lista circular duplamente encadeada
void imprime_circular_rev(Lista2*l){
     Lista2*p=l;//faz p apontar para o nó inicial
     //testa se lista não vazia
     if(p){
       //percorre os elementos até alcançar novamente o inicio
       do{
          printf("%d\n",p->info);
          p=p->ant;//avança para nó anterior
       }while(p!=l);
     }
}

//daqui em diante vai ser a implementação do video
struct aluno{
   int matricula;
   char nome[30];
   float n1,n2,n3;
};
typedef struct elemento*Lista;

struct elemento{
   struct aluno dados;
   struct elemento*prox;
};
typedef struct elemento Elem;

//funcao que cria lista de lista circular
Lista*cria_lista(){
     Lista* li=(Lista*)malloc(sizeof(Lista));
     if(li!=NULL)
        *li=NULL;
     return li;
}
//libera lista circular
void libera_lista(Lista*li){
     if(li!=NULL && (*li)!=NULL){
        Elem*aux, *no=*li;
        while((*li)!=no->prox){//se o elemento anterior for diferento do proximo (*li) é o primeiro nó
           aux=no;
           no=no->prox;
           free(aux);//elimina o nó anterior
        }
        free(no);//libera ultimo nó
        free(li);
     }
}

int insere_lista_inicio(Lista* li,struct aluno al){
    if(li==NULL)return 0;//lista não alocada
    Elem *no=(Elem*)malloc(sizeof(Elem));
    if(no==NULL)return 0;
    no->dados=al;
    if((*li)==NULL){//lista vazia:insere no inicio
       *li=no;
        no->prox=no;
    }else{
       Elem *aux=*li;
       while(aux->prox!=(*li))
             aux=aux->prox;
       aux->prox=no;//aponta o ultimo para o nó que quer inserir
       no->prox=li;//aponta para o antigo inicio da lista
       *li=no;//coloca ele como o ínicio da lista
    }
    return 1;
}

int insere_lista_final(Lista*li,struct aluno al){
    if(li==NULL)return 0;
    Elem*no=(Elem*)malloc(sizeof(Elem));
    if(no==NULL)return 0;
    no->dados=al;
    if((*li)==NULL){//lista vazia: insere inicio
       *li=no;
        no->prox=no;
    }
    else{
       Elem*aux=*li;
       while(aux->prox!=(*li))
            aux=aux->prox;
       aux->prox=no;//o ultimo aponta para o nó desejado
       no->prox=*li;//o nó desejado se torna o último e aponta para o primeiro
    }
    return 1;
}

//insere em lista circular de forma ordenada

int insere_lista_ordenada(Lista*li,struct aluno al){
    if(li==NULL)
       return 0;
    Elem*no=(Elem*)malloc(sizeof(Elem));
    if(no==NULL)
       return 0;
    no->dados=al;
    if((*li)==NULL){//insere no inicio
       *li=no;
       no->prox=no;
       return 1;
    }
    else{
       if((*li)->dados.matricula>al.matricula){
          Elem*atual=*li;
          while(atual->prox!=(*li)){//procura o ultimo
               atual=atual->prox;
               no->prox=*li;
               atual->prox=no;
               *li=no;
               //return 1;
          }
          Elem *ant=*li;
          *atual=(*li)->prox;
          while(atual!=(*li)&& atual->dados.matricula<al.matricula){
               ant=atual;
               atual=atual->prox;
          }
          ant->prox=no;//encontrou onde insere
          no->prox=atual;
       }
       return 1;
    }
}
