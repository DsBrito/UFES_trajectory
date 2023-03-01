#include "./priorityQueue.h"
#include <stdlib.h>

typedef struct par {
    double dist; //distancia
    int key; //id do item
} Par;

#define key(A) (A->key)                 // retorna identificador do nó
#define dist(A) (A->dist)               // retorna valor do nó
#define more(A, B) (dist(A) > dist(B))  // compara nós, por valor
#define exch(A, B) { Par *x = A;A = B;B = x; }  // troca dois nós

struct pq {
    int n;
    int *map;
    Par **pq;
};

static void swap(Par **pq, int *map, int i, int j) {
    exch(pq[i], pq[j]);
    map[key(pq[i])] = i;
    map[key(pq[j])] = j;
}

void fix_up(Par **pq, int *map, int k) {
    while (k > 1 && more(pq[k / 2], pq[k])) {
        swap(pq, map, k, k / 2);
        k = k / 2;
    }
}

void fix_down(Par **pq, int *map, int sz, int k) {
    while (2 * k <= sz) {
        int j = 2 * k;
        if (j < sz && more(pq[j], pq[j + 1])) {
            j++;
        }
        if (!more(pq[k], pq[j])) {
            break;
        }
        swap(pq, map, k, j);
        k = j;
    }
}

PQ *pqInicializa(int maxN) {
    PQ *heap = (PQ *)malloc(sizeof(PQ));
    heap->pq = (Par **)malloc((maxN + 1) * sizeof(Par *));
    heap->map = (int *)malloc((maxN + 1) * sizeof(int));
    heap->n = 0;
}

void pqInsere(PQ *heap, int key, double dist) {
    Par *par = (Par *)malloc(sizeof(Par));
    par->key = key;
    par->dist = dist;
    heap->n++;
    heap->pq[heap->n] = par;
    heap->map[key(par)] = heap->n;
    fix_up(heap->pq, heap->map, heap->n);
}

void pqDeletaMinimo(PQ *heap) {
    Par *min = heap->pq[1];
    swap(heap->pq, heap->map, 1, heap->n);
    heap->n--;
    fix_down(heap->pq, heap->map, heap->n, 1);
    free(min);
}

int pqMinimo(PQ *heap) {
    return heap->pq[1]->key;
}

void pqDecreaseKey(PQ *heap, int id, double valor) {
    int i = heap->map[id];
    dist(heap->pq[i]) = valor;
    fix_up(heap->pq, heap->map, i);
}

int pqVerificaVazia(PQ *heap) {
    return heap->n == 0;
}

void pqDestroi(PQ *heap) {
    for (int i = 1; i < heap->n; i++) {
        free(heap->pq[i]);
    }
    free(heap->map);
    free(heap->pq);
    free(heap);
}