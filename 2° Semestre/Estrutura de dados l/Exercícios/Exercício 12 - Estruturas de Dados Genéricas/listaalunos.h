

#ifndef LISTAALUNOS_H
#define LISTAALUNOS_H

#include <stdio.h>
#include "aluno.h"
#include "listagen.h"

// retira alluno com matricula passada como parametro
ListaGen *retriaAluno(ListaGen *lista, int matricula);

// verifica se o aluno esta na lista
int pertenceAluno(ListaGen *lista, int matricula);

// imprime lista de alunos
void imprimeAlunos(ListaGen *lista);

// calcula media de CR da turma
float mediaTurma(ListaGen *lista);

#endif /* LISTAALUNOS_H */
