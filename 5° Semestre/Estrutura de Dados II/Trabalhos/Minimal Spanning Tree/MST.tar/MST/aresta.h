#ifndef _ARESTA_H
#define _ARESTA_H

typedef struct aresta tAresta;

tAresta *criaAresta();
tAresta *iniciaAresta(tAresta *a, int ini, int fim, double peso, char *nomeini, char *nomefim);
int compara(const void *a, const void *b);
void Kruskal(tAresta **aresta, int totalVert, int totalAresta, int k, FILE *f2, tPonto **vetPontos);
void liberaAresta(tAresta *a);
int getIni(tAresta *a);
int getFim(tAresta *a);
double getPeso(tAresta *a);
int comparaPrimeiroNome(const void *a, const void *b);
int comparaNome(const void *a, const void *b);
void imprimeAresta(tAresta *a);

#endif