#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ponto.h"
#include "aresta.h"
#include "subconjunto.h"
#include "vertice.h"
#include "lista.h"

struct aresta
{
    int ini, fim;
    double peso;
    char *nomeini, *nomefim;
};

/* aloca espaco e cria uma struct aresta vazia*/
tAresta *criaAresta()
{
    tAresta *a = (tAresta *)malloc(sizeof(tAresta));
    a->nomeini = NULL;
    a->nomefim = NULL;
    a->ini = 0;
    a->fim = 0;
    a->peso = 0;
    return a;
}

/*inicializa as variaveis da aresta*/
tAresta *iniciaAresta(tAresta *a, int ini, int fim, double peso, char *nomeini, char *nomefim)
{
    a->nomeini = strdup(nomeini);
    a->nomefim = strdup(nomefim);
    a->ini = ini;
    a->fim = fim;
    a->peso = peso;
    return a;
}

/* retorna o valor de referencia inteiro da aresta inicial */
int getIni(tAresta *a)
{
    return a->ini;
}

/* retorna o valor de referencia inteiro da aresta final */
int getFim(tAresta *a)
{
    return a->fim;
}

/* retorna o valor do peso da aresta*/
double getPeso(tAresta *a)
{
    return a->peso;
}

/*funcao generica que compara dois valores de peso*/
int compara(const void *a, const void *b)
{
    tAresta *a1 = *(tAresta **)a;
    tAresta *a2 = *(tAresta **)b;

    if ((getPeso(a1) - getPeso(a2)) > 0)
    {
        return 1;
    }
    else if ((getPeso(a1) - getPeso(a2)) < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*funcao generica que compara dois valores de referencia*/
int compara2(const void *a, const void *b)
{
    tAresta *a1 = *(tAresta **)a;
    tAresta *a2 = *(tAresta **)b;

    if ((a1->ini) - (a2->ini) > 0)
    {
        return 1;
    }
    else if ((a1->ini - a2->ini) < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*funcao generica que compara dois nomes*/
int comparaNome(const void *a, const void *b)
{
    tVertice *a1 = *(tVertice **)a;
    tVertice *a2 = *(tVertice **)b;
    return strcmp(retornaNome(a1), retornaNome(a2));
}

int comparaPrimeiroNome(const void *a, const void *b)
{
    tVertice **a1 = *(tVertice ***)a;
    tVertice **a2 = *(tVertice ***)b;
    return strcmp(retornaNome(a1[0]), retornaNome(a2[0]));
}

/*Função para imprimir no arquivo*/
void imprime(tVertice **vet, int tam, FILE *f)
{
    int i = 0;
    char *nome;

    for (i = 0; i < tam; i++)
    {
        nome = retornaNome(vet[i]);
        if (i == tam - 1)
        {
            fprintf(f, "%s", nome);
            return;
        }
        fprintf(f, "%s,", nome);
    }
}

/* algoritmo de kruskal*/
void Kruskal(tAresta **aresta, int totalVert, int totalAresta, int k, FILE *f2, tPonto **vetPontos)
{
    int a = 0, b = 0, i = 0;

    // inicaliza o vetor de listas com NULL
    tLista *vetLista[k + 1];
    for (i = 0; i < (k + 1); i++)
    {
        vetLista[i] = iniciavazia();
    }

    int num = totalVert - k;
    tAresta *resultados[num];

    qsort(aresta, totalAresta, sizeof(aresta[0]), compara); // faz a ordenacao do vetor aresta por peso

    tSub *sub[totalVert];

    for (size_t i = 0; i < totalVert; ++i)
    {
        sub[i] = criaSubconjunto(i, 0); // cria o subconjunto
    }

    while ((a < (num - 1)) && b < (totalAresta - k))
    {
        tAresta *prox = aresta[b++];
        /*encontra a menor aresta e incrementa para a proxima iteracao*/
        int x = find(sub, prox->ini);
        int y = find(sub, prox->fim);
        /* verifica se nao possui ciclos e incrementa o vetor de resultados para a proxima aresta*/
        if (x != y)
        {
            resultados[a++] = prox;
            Union(sub, x, y);
        }
    }

    for (size_t i = 0; i < totalAresta; i++)
    {
        liberaAresta(aresta[i]);
    }
    free(aresta);

    /*NOVA PARTE!! PEGA O VETOR DE LISTA (CRIADO NO INICIO) E INSERE OS VERTICES NAS LISTAS DE SUAS RESPECTIVAS RAIZES*/
    for (i = 0; i < totalVert; i++)
    {                                                     // percorre o vetor de pontos inicial
        int idRaiz = find(sub, getIDPonto(vetPontos[i])); // acha o id da raiz do ponto
        char *nom;
        for (int m = 0; m < totalVert; m++)
        { // percorre o vetor de pontos inicial novamente, para achar o nome da raiz
            if (idRaiz == getIDPonto(vetPontos[m]))
            {
                nom = strdup(getNome(vetPontos[m]));
            }
        }
        for (int n = 0; n < (k + 1); n++)
        { // percorre o vetor de listas
            if (vetLista[n] == NULL || idRaiz == getIdLista(vetLista[n]))
            { // se a lista for nula ou achar a raiz
                tVertice *v = iniciaVertice(getIDPonto(vetPontos[i]), getNome(vetPontos[i]));
                vetLista[n] = insere(v, vetLista[n], idRaiz, nom); // insere ponto na lista
                break;
            }
        }
        free(nom);
    }
    for (size_t i = 0; i < totalVert; i++)
    {
        liberaPonto(vetPontos[i]);
    }

    tVertice **vetVetor[k + 1];
    int tam[k + 1];

    /*Passa a lista para um vetor de vetores, e ordena esses vetores menores
    que são os grupos*/
    for (size_t i = 0; i < (k + 1); i++)
    {
        tam[i] = getTamanho(vetLista[i]);
        vetVetor[i] = pop(vetLista[i], tam[i]);
        qsort(vetVetor[i], tam[i], sizeof(tVertice **), comparaNome);
        // printf("%s\n", retornaNome(vetVetor[i][0]));
    }

    qsort(vetVetor, k + 1, sizeof(tVertice **), comparaPrimeiroNome);

    /*Imprime os grupos*/
    for (int i = 0; i < (k + 1); i++)
    {
        imprime(vetVetor[i], tam[i], f2);
        fprintf(f2, "\n");
    }

    /*Liberando*/
    for (size_t i = 0; i < totalVert; i++)
    {
        free(sub[i]);
    }

    for (size_t i = 0; i < (k + 1); i++)
    {
        liberaLista(vetLista[i]);
        free(vetVetor[i]);
    }

    return;
}

/*libera a memoria de uma aresta*/
void liberaAresta(tAresta *a)
{
    free(a->nomefim);
    free(a->nomeini);
    free(a);
}
