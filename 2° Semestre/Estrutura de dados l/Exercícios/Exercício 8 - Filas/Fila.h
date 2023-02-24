
#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include "aluno.h"

typedef struct fila FILA;

FILA *iniciaFila(void);

// insere no final da fila

void insereFila(FILA *f, Aluno *a);

// retira sempre no inico
Aluno *retiraFila(FILA *f);

// imprime do inico ao fim da fila
void imprimeFila(FILA *f);

// libera memoria da fila
void destroifila(FILA *f);

#endif /* FILA_H */
