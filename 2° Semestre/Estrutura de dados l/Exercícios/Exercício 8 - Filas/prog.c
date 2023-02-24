
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
/*
 *
 */
int main()
{

    Aluno *bruna = IniciaAluno(312, "bruna", 10);
    Aluno *diego = IniciaAluno(241, "diego", 5);
    Aluno *kassio = IniciaAluno(453, "kassio", 6);
    Aluno *ezio = IniciaAluno(892, "ezio", 9);

    FILA *f = iniciaFila();
    FILA *f2 = iniciaFila();

    insereFila(f, bruna);
    insereFila(f, diego);
    insereFila(f, kassio);
    insereFila(f, ezio);

    printf("\nImprimindo fila f:\n");
    imprimeFila(f);

    insereFila(f2, retiraFila(f));
    printf("\nImprimindo fila f:\n");
    imprimeFila(f);

    printf("\nImprimindo fila f2:\n");
    imprimeFila(f2);

    DestroiAluno(bruna);
    DestroiAluno(diego);
    DestroiAluno(kassio);
    DestroiAluno(ezio);

    destroiFila(f);
    destroiFila(f2);
}
