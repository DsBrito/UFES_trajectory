

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include <string.h>

struct aluno
{
    int matricula;
    char *nome;
    float CR;
};

Aluno *IniciaAluno(int matricula, char *nome, float CR)
{
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    novo->nome = strdup(nome);
    novo->CR = CR;
    novo->matricula = matricula;
    return novo;
};

void ImprimeAluno(Aluno *aluno)
{
    printf("matricula: %d, nome: %s, CR %.2f\n", aluno->matricula, aluno->nome, aluno->CR);
};

int RetornaMatricula(Aluno *aluno)
{
    return aluno->matricula;
};

char *RetornaNomeAluno(Aluno *aluno)
{
    return aluno->nome;
};

float RetornaCR(Aluno *aluno)
{
    return aluno->CR;
};

void DestroiAluno(Aluno *aluno)
{

    free(aluno->nome);
    free(aluno);
};