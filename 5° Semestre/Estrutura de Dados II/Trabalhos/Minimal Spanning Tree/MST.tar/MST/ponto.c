#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ponto.h"
#include "aresta.h"
#include "vertice.h"
#include "lista.h"

struct ponto
{
  char *nome;
  int id;
  double *vet; // coordenadas
  int tam;     // tamanho do vetor
};

/* Aloca espaço para a struct ponto e inicializa as variaveis*/
tPonto *iniciaPonto(char *nome, int d, double *array, int id)
{
  tPonto *p = (tPonto *)malloc(sizeof(tPonto));
  p->nome = strdup(nome);
  p->tam = d;
  p->vet = (double *)malloc(sizeof(double) * d);
  p->id = id;
  for (size_t i = 0; i < d; i++)
  {
    p->vet[i] = array[i];
  }
  return p;
}

int getIDPonto(tPonto *p)
{
  return p->id;
}
/* retorna o valor do tamanho do vetor */
double getTam(tPonto *p)
{
  return p->tam;
}

/* retorna o vetor de coordenadas */
double *getVet(tPonto *p)
{
  return p->vet;
}

/* retorna a string nome do ponto */
char *getNome(tPonto *p)
{
  return p->nome;
}

/* calcula a distancia entre dois pontos quaisquer */
double distancia(int d, double *vet1, double *vet2)
{
  double soma = 0;
  for (size_t i = 0; i < d; i++)
  {
    soma = soma + pow((vet1[i] - vet2[i]), 2);
  }
  return sqrt(soma);
}

/* libera a memoria alocada por um ponto*/
void liberaPonto(tPonto *p)
{
  free(p->nome);
  free(p->vet);
  free(p);
}
/* imprime o valor do ponto no terminal, foi usado apenas para debugar*/
void imprimePonto(tPonto *p)
{
  printf("nome: %s,coordenadas:\n", p->nome);
  for (size_t i = 0; i < p->tam; i++)
  {
    printf("%lf ", p->vet[i]);
  }
  printf("\n");
}
