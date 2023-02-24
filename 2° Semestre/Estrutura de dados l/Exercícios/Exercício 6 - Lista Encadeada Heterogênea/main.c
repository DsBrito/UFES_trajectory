

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "listahet.h"
/*
 *
 */
int main(int argc, char **argv)
{

    Aluno *Salatiely = IniciaAluno(444, "Salatiely", 10);
    Aluno *Sandra = IniciaAluno(412, "Sandra", 4);
    Aluno *Thiago = IniciaAluno(232, "Thiago", 7);
    Aluno *Bernado = IniciaAluno(213, "Bernado", 8);

    Professor *Gabriel = IniciaProfessor(123456, "Gabriel", 9435.00);
    Professor *Elizabeth = IniciaProfessor(789102, "Elizabeth", 7432.00);

    ListaHet *churrasco = IniciaLista();

    InsereAluno(churrasco, Salatiely);
    InsereAluno(churrasco, Thiago);
    InsereAluno(churrasco, Bernado);
    InsereAluno(churrasco, Sandra);
    InsereProfessor(churrasco, Gabriel);
    InsereProfessor(churrasco, Elizabeth);

    printf("\nImprimindo a lista:\n");
    ImprimeListaHet(churrasco);

    printf("\nVALOR: %.2f", ValorChurrasco(churrasco));

    DestroiLista(churrasco);

    DestroiAluno(Salatiely);
    DestroiAluno(Bernado);
    DestroiAluno(Thiago);
    DestroiAluno(Sandra);

    DestroiProfessor(Gabriel);
    DestroiProfessor(Elizabeth);

    return 0;
}
