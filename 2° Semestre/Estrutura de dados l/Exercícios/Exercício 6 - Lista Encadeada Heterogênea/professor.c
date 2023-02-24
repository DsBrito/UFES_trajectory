

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct professor
{
    int siape;
    char *nome;
    float salario;
};

Professor *IniciaProfessor(int siape, char *nome, float salario)
{
    Professor *novo = (Professor *)malloc(sizeof(Professor));
    novo->nome = strdup(nome);
    novo->salario = salario;
    novo->siape = siape;
    return novo;
};

void ImprimeProfessor(Professor *professor)
{
    printf("\nsiape: %d, nome: %s, salario %.2f", professor->siape, professor->nome, professor->salario);
};

int RetornaSiape(Professor *professor)
{
    return professor->siape;
};

char *RetornaNomeProfessor(Professor *professor)
{
    return professor->nome;
};

float RetornaSalario(Professor *professor)
{
    return professor->salario;
};

void DestroiProfessor(Professor *professor)
{

    free(professor->nome);
    free(professor);
};