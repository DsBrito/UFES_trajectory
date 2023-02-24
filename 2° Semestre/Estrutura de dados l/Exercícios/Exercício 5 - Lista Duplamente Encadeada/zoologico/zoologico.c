

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zoologico.h"

struct tipoZoo
{
    char *nome;
    char *classificacao;
    char *genero;
    int id;
};

TipoZoo *InicializaAnimal(char *nome, char *classificacao, char *genero, int id)
{

    TipoZoo *animal;

    animal = (TipoZoo *)malloc(sizeof(TipoZoo));

    animal->nome = strdup(nome);
    animal->classificacao = strdup(classificacao);
    animal->genero = strdup(genero);
    animal->id = id;

    return animal;
};

void imprimeAnimal(TipoZoo *animal)
{
    printf("    Id do Animal: %d\n", animal->id);
    printf("    Nome: %s\n", animal->nome);
    printf("    Classificacao: %s\n", animal->classificacao);
    printf("    Genero: %s\n", animal->genero);
}

void DestroiAnimal(TipoZoo *animal)
{
    free(animal->nome);
    free(animal->classificacao);
    free(animal->genero);
    free(animal);
};

int buscaZoo(TipoZoo *animal)
{
    return animal->id;
}
