//
// Created by henrycky on 31/08/2021.
//

#include "estruturaGrafo.h"

struct vertice
{
    Aresta *aresta;
};

struct aresta
{
    Aresta *prox;
    int destino;
    double peso;
};

Vertice *inicVertice()
{
    Vertice *vertice = (Vertice *)malloc(sizeof(Vertice));
    vertice->aresta = NULL;
    return vertice;
}

Vertice **inicVetorVertice(int numVertice)
{
    Vertice **vertices = (Vertice **)malloc(numVertice * sizeof(Vertice *));
    for (int i = 0; i < numVertice; i++)
    {
        vertices[i] = inicVertice();
    }
    return vertices;
}

void destroiVertice(Vertice *vertice)
{
    destroiListaAresta(vertice->aresta);
    free(vertice);
}

void destroiVetorVertice(Vertice **vertice, int numVertice)
{
    for (int i = 0; i < numVertice; i++)
    {
        destroiVertice(vertice[i]);
    }

    free(vertice);
}

void destroiListaAresta(Aresta *aresta)
{
    Aresta *aux;
    while (aresta != NULL)
    {
        aux = aresta;
        aresta = aresta->prox;
        free(aux);
    }
    free(aresta);
}

Aresta *iniciaAresta(int destino, double peso)
{
    Aresta *novaAresta = (Aresta *)malloc(sizeof(Aresta));
    novaAresta->destino = destino;
    novaAresta->peso = peso;
    novaAresta->prox = NULL;

    return novaAresta;
}

void adicionaVertice(Vertice *vertice, int destino, double peso)
{
    Aresta *novaAresta = iniciaAresta(destino, peso);

    if (vertice->aresta == NULL)
    {
        vertice->aresta = novaAresta;
    }
    else
    {
        novaAresta->prox = vertice->aresta;
        vertice->aresta = novaAresta;
    }
}

Aresta *retornaAresta(Vertice *vertice)
{
    return vertice->aresta;
}

Aresta *retornaArestaProx(Aresta *aresta)
{
    return aresta->prox;
}

int retornaDestino(Aresta *aresta)
{
    return aresta->destino;
}

double retornaPeso(Aresta *aresta)
{
    return aresta->peso;
}
