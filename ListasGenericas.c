#include<stdio.h>
#include<stdlib.h>

//lista de dados genéricos
#define RET 0
#define TRI 1
#define CIR 2
#define PI 3.14159

struct retangulo{
    float b;
    float h;
};
typedef struct retangulo Retangulo;

struct triangulo{
    float b;
    float h;
};
typedef struct triangulo Triangulo;

struct circulo{
   float r;
};
typedef struct circulo Circulo;

struct listagen{
   int tipo;
   void* info;
   struct listagen*prox;
};
typedef struct listagen Listagen;

//Cria um nó de retângulo
Listagen*cria_ret(float b,float h){
   Retangulo*r;
   Listagen*p;

   r=(Listagen*)malloc(sizeof(Listagen));
   p->tipo=RET;
   p->info=r;
   p->prox=NULL;
   return p;
}
//cria um nó de triângulo
Listagen*cria_tri(float b,float h){
   Triangulo*t;
   Listagen*p;
   t=(Triangulo*)malloc(sizeof(Triangulo));
   t->b=b;
   t->h=h;

   //aloca nó
   p=(Listagen*)malloc(sizeof(Listagen));
   p->tipo=TRI;
   p->info=t;
   p->prox=NULL;
   return p;
}

//cria um nó de círculo
Listagen*cria_cir(float r){
  Circulo*c;
  Listagen*p;
  c=(Circulo*)malloc(sizeof(Circulo));
  c->r=r;
  //aloca nó
  p=(Listagen*)malloc(sizeof(Listagen));
  p->tipo=CIR;
  p->info=c;
  p->prox=NULL;
  return p;
}

//lista heterogênea de retângulo,triângulo e circulo que devolve como valor o maior valor da área da lista
float area(Listagen*p){
  float a;
  switch(p->tipo){
      case RET:
      {
        //converte para retângulo e calcula a área
        Retangulo*r=(Retangulo*)p->info;
        a=r->b*r->h;
      }
      break;
      case TRI:
      {
        //converte para triângulo e calcula a área
        Triangulo*t=(Triangulo*)p->info;
        a=(t->b*t->h)/2;
      }
      break;

      case CIR:
      {
        //converte para circulo e calcula a área
        Circulo*c=(Circulo*)p->info;
        a=PI*c->r*c->r;
      }
      break;
  }
  return a;
}

//funcao para cálculo da maior área

float max_area(Listagen*t){
   float amax=0.0;//maior área
   Listagen*p;
   for(p=t;p!=NULL;p=p->prox){
      float a=area(p);
      if(a>amax)
         amax=a;
   }
   return amax;
}
