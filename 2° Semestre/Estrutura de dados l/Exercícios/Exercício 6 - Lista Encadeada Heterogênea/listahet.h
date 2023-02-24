

#ifndef LISTAHET_H
#define LISTAHET_H

#include <stdio.h>
#include "aluno.h"
#include "professor.h"

typedef struct listahet ListaHet;
ListaHet *IniciaLista(void);
void InsereAluno(ListaHet *lista, Aluno *aluno);
void InsereProfessor(ListaHet *lista, Professor *professor);
void ImprimeListaHet(ListaHet *lista);
float ValorChurrasco(ListaHet *lista);
void DestroiLista(ListaHet *lista);
#endif /* LISTAHET_H */
