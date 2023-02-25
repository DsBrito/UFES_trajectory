#ifndef ListaComSentinela_h
#define ListaComSentinela_h

#include "ListaComSentinela.h"
#include "Arvore.h"

typedef struct celula Celula;
typedef struct arv Arv;
typedef struct lista Lista;


Lista* inicLista();
void insereListaUltFila(Lista* l, int i);
void destroiLista(Lista* l);
int retiraPrimeiro(Lista* l);
Arv* retiraUltimo(Lista* p, int pos);
void insereListaUltPilha(Lista* l, Arv* a);

#endif