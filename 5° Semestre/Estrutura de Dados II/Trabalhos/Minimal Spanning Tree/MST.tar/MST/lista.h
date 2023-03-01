#include "vertice.h"

#ifndef _LISTA_H
#define _LISTA_H

typedef struct lista tLista;
tLista *iniciavazia();
tLista *insere(tVertice *vertice, tLista *lista, int id, char *nome);
void insereOrdenado(tVertice *vertice, tLista *lista, int id, char *nome);
int comparaLista(const void *a, const void *b);
int getIdLista(tLista *lista);
int getTamanho(tLista *l);
tVertice **pop(tLista *l, int tam);
void imprimeLista(tLista *l, FILE *f);
void liberaLista(tLista *lista);

#endif