#ifndef TRAB2ED2_PRIORITYQUEUE_H
#define TRAB2ED2_PRIORITYQUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct par Par;

typedef struct pq PQ;

PQ *pqInicializa(int max_n);

void pqInsere(PQ *heap, int key, double dist);

int pqVerificaVazia(PQ *heap);

int pqMinimo(PQ *heap);

void pqDeletaMinimo(PQ *heap);

void pqDecreaseKey(PQ *heap, int id, double valor);

void pqDestroi(PQ *heap);

#endif // TRAB2ED2_PRIORITYQUEUE_H
