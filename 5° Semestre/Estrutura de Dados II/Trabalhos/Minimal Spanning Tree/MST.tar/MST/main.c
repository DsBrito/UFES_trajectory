#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Arquivo.h"
#include "ponto.h"
#include "aresta.h"
#include "vertice.h"
#include "lista.h"

int main(int argc, char *argv[])
{

    int k = atoi(argv[2]);
    char split[2] = ",";
    char *token;
    char linha[1000];

    FILE *f;

    int num = contaLinha(f, argv[1]);
    int numArestas = (num * (num - 1)) / 2;
    char *vetNomes[num];
    tPonto *vetPontos[num];
    double vetCoord[1000];

    f = fopen(argv[1], "r");
    int aux = 0, d = 0; // auxiliar para o vetor de nomes, d é a dimensão

    /*Leitura do arquivo*/
    while (fscanf(f, "%s\n", linha) != EOF)
    {
        token = strtok(linha, split);
        vetNomes[aux] = strdup(token);
        while (token != NULL)
        {
            token = strtok(NULL, split);
            if (token != NULL)
            { // para não pegar o ultimo token q é null
                vetCoord[d] = atof(token);
                d++;
            }
        }
        double vetNovo[d];
        for (size_t k = 0; k < d; k++)
        {
            vetNovo[k] = vetCoord[k];
        }
        vetPontos[aux] = iniciaPonto(vetNomes[aux], d, vetNovo, aux);
        aux++;
        d = 0;
    }

    tAresta **vetorAresta = (tAresta **)malloc(sizeof(tAresta *) * numArestas);

    for (size_t z = 0; z < numArestas; z++)
    {
        vetorAresta[z] = criaAresta();
    }
    double dist = 0;
    int m = 0;

    /*Calculo da distancia e inicializando as arestas*/
    for (size_t i = 0; i < num; i++)
    {
        for (size_t j = 0; j < num; j++)
        {
            if (i < j)
            {
                dist = distancia(getTam(vetPontos[i]), getVet(vetPontos[i]), getVet(vetPontos[j]));
                iniciaAresta(vetorAresta[m], i, j, dist, vetNomes[i], vetNomes[j]);
                m++;
            }
        }
    }

    FILE *f2;
    f2 = fopen(argv[3], "w");

    for (size_t i = 0; i < num; i++)
    {
        free(vetNomes[i]);
    }

    Kruskal(vetorAresta, num, numArestas, k - 1, f2, vetPontos);

    fclose(f);
    fclose(f2);

    return 0;
    return 0;
}
