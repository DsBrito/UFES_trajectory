//
// Created by henrycky on 31/08/2021.
//

#ifndef TRAB2ED2_ESTRUTURAGRAFO_H
#define TRAB2ED2_ESTRUTURAGRAFO_H

#include <stdlib.h>

typedef struct vertice Vertice;
typedef struct aresta Aresta;

Vertice *inicVertice();

Vertice **inicVetorVertice(int numVertice);

void destroiVertice(Vertice *vertice);

void destroiVetorVertice(Vertice **vertice, int numVertice);

void destroiListaAresta(Aresta *aresta);

void adicionaVertice(Vertice *vertice, int destino, double peso);

Aresta *retornaAresta(Vertice *vertice);

Aresta *retornaArestaProx(Aresta *aresta);

int retornaDestino(Aresta *aresta);

double retornaPeso(Aresta *aresta);

#endif // TRAB2ED2_ESTRUTURAGRAFO_H
