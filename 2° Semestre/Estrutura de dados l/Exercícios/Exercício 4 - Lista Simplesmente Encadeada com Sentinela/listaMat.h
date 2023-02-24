

#ifndef LISTAMAT_H
#define LISTAMAT_H


#include<stdio.h>
#include"matriz.h"

typedef struct lista Lista;

Lista* IniciaLista();

void InsereLista(Lista* lista,Matriz* mat);

void ImprimeLista(Lista* lista);

Matriz* Retira(Lista* lista, int busca);

void DestroiLista(Lista* lista);





#endif /* LISTAMAT_H */

