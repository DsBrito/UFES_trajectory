

#ifndef LISTAGEN_H
#define LISTAGEN_H

#include <stdio.h>

typedef struct listagen ListaGen;

// cria lista vazia
ListaGen *criaLista(void);

// insere
ListaGen *insereLista(ListaGen *lista, void *item);

// retira
ListaGen *retiraLista(ListaGen *lista, int (*cb)(void *, void *), void *chave);

// pecorre
int pecorreLista(ListaGen *lista, int (*cb)(void *, void *), void *dado);

// libera celulas
ListaGen *libera(ListaGen *lista);

#endif /* LISTAGEN_H */
