#include<stdio.h>
#include<stdlib.h>

//lista de dados gen�ricos
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

//Cria um n� de ret�ngulo
Listagen*cria_ret(float b,float h){
   Retangulo*r;
   Listagen*p;

   r=(Listagen*)malloc(sizeof(Listagen));
   p->tipo=RET;
   p->info=r;
   p->prox=NULL;
   return p;
}
//cria um n� de tri�ngulo
Listagen*cria_tri(float b,float h){
   Triangulo*t;
   Listagen*p;
   t=(Triangulo*)malloc(sizeof(Triangulo));
   t->b=b;
   t->h=h;

   //aloca n�
   p=(Listagen*)malloc(sizeof(Listagen));
   p->tipo=TRI;
   p->info=t;
   p->prox=NULL;
   return p;
}

//cria um n� de c�rculo
Listagen*cria_cir(float r){
  Circulo*c;
  Listagen*p;
  c=(Circulo*)malloc(sizeof(Circulo));
  c->r=r;
  //aloca n�
  p=(Listagen*)malloc(sizeof(Listagen));
  p->tipo=CIR;
  p->info=c;
  p->prox=NULL;
  return p;
}

//lista heterog�nea de ret�ngulo,tri�ngulo e circulo que devolve como valor o maior valor da �rea da lista
float area(Listagen*p){
  float a;
  switch(p->tipo){
      case RET:
      {
        //converte para ret�ngulo e calcula a �rea
        Retangulo*r=(Retangulo*)p->info;
        a=r->b*r->h;
      }
      break;
      case TRI:
      {
        //converte para tri�ngulo e calcula a �rea
        Triangulo*t=(Triangulo*)p->info;
        a=(t->b*t->h)/2;
      }
      break;

      case CIR:
      {
        //converte para circulo e calcula a �rea
        Circulo*c=(Circulo*)p->info;
        a=PI*c->r*c->r;
      }
      break;
  }
  return a;
}

//funcao para c�lculo da maior �rea

float max_area(Listagen*t){
   float amax=0.0;//maior �rea
   Listagen*p;
   for(p=t;p!=NULL;p=p->prox){
      float a=area(p);
      if(a>amax)
         amax=a;
   }
   return amax;
}
