#ifndef TRAB2ED2_LEITURA_H
#define TRAB2ED2_LEITURA_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

typedef struct grafo Grafo;

/** Verifica se o arquivo pode ser aberto */
FILE* abreArquivo(FILE* file, char* nomeDoArquivo);

/** Lê a quantidade de arestas e vértices do grafo, além de inicializá-lo */
void leDimensao(FILE* file, Grafo* grafo);

/** Converte os tokens lidos pelo strtok em double */
double converteNumero (char * token);

/** Grava as arestas e seus vértices na matriz de adjacencias*/
void formaArestas (FILE * file, Grafo* grafo);


#endif //TRAB2ED2_LEITURA_H
