#ifndef TRAB2ED2_GRAFO_H
#define TRAB2ED2_GRAFO_H

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"
#include "estruturaGrafo.h"
#include <string.h>
#include "leitura.h"

typedef struct grafo Grafo;
typedef struct lista Lista;
typedef struct celula Celula;
typedef struct guardaRazao GuardaRazao;

struct guardaRazao
{
    int origem;
    int destino;
    double razao; /** Razão entre RTT/RTT* entre a origem(servidor) e destino(cliente) acima*/
};

/** Cria um grafo vazio que será passado como parametro para outras funções*/
Grafo *criaGrafoVazio(void);

/** Inicializa o grafo com num de vértices, arestas e inicializa sua matriz adjacência*/
void inicGrafo(Grafo *grafo, int numVertice, int numAresta);

/** Inicializa os vetores de servidores, clientes e monitores */
void inicVetoresGrafo(Grafo *grafo, int quantServidores, int quantClientes, int quantMonitores);

/** Grava as arestas e seus vértices no vetor de ponteiro pra vertices*/
void formaArestas(FILE *file, Grafo *grafo);

/** Imprime vetores de servidores, clientes e monitores*/
void imprimeVetores(Grafo *grafo);

/** Retorna o número de clientes do grafo */
int retornaNumClientes(Grafo *grafo);

/** Retorna o número de servidores do grafo */
int retornaNumServidores(Grafo *grafo);

/** Retorna o número de monitores do grafo */
int retornaNumMonitores(Grafo *grafo);

/** Retorna o número de vértices do grafo */
int retornaNumVertice(Grafo *grafo);

/** Retorna o número de arestas do grafo */
int retornaNumAresta(Grafo *grafo);

/** Retorna o vetor de servidores */
int *retornaVetorServidores(Grafo *grafo);

/** Retorna o vetor de clientes */
int *retornaVetorClientes(Grafo *grafo);

/** Retorna o vetor de monitores */
int *retornaVetorMonitores(Grafo *grafo);

/** Insere um servidor no vetor de servidores */
void insereServidor(Grafo *grafo, int posicao, int servidor);

/** Insere um cliente no vetor de clientes */
void insereCliente(Grafo *grafo, int posicao, int cliente);

/** Insere um monitor no vetor de monitores */
void insereMonitor(Grafo *grafo, int posicao, int monitor);

/** Inicializa matriz de distancia entre os vetores auxiliares de cliente, servidor e monitor*/
double **iniciMatrizVetAux(Grafo *grafo, int tamVetor, int *vetOrigem, int *vetDest1, int *vetDest2);

/** Destroi vetor de servidores, clientes e monitiores*/
void destroiVetoresAuxiliares(Grafo *grafo);

void destroiGrafo(Grafo *grafo);

double **calculaDistancias(Grafo *grafo, int tamVetor, int *origem, int *destino, int tamDestino);

/** -------------Funções relacionadas a lista------------- */
Lista *inicLista(void);

void criaLista(Grafo *grafo, int numVertice);

void insereArestasLista(Grafo *grafo, int vertice1, int vertice2, int aresta);

void destroiLista(Lista *lista);

void destroiListaComAdjacencias(Grafo *grafo);

void imprimeLista(Grafo *grafo);

void imprimeGrafoLista(Grafo *grafo, FILE *arquivodot);

/** ------------------------------------------------------------------ */

/** Calcula as distancias de cada vetorVertices para os servidores, monitores e clientes,
 * é chamada 3 vezes na funcao geraRazoes*/
double *dijkstra(Grafo *grafo, int origem, int *destino1, int tamDestino1);

GuardaRazao *calculaRazoesEntreRTT(Grafo *grafo, double **distanciaServidoreMonitor, double **distanciaMonitorServidor,
                                   double **distanciaClienteMonitor, double **distanciaMonitorCliente,
                                   double **distanciaServidorCliente, double **distanciaClienteServidor);

int compara(const void *a, const void *b);

void destroiMatriz(double **matriz, int tam);

#endif // TRAB2ED2_GRAFO_H
