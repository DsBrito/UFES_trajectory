#ifndef _VERTICE_H
#define _VERTICE_H
typedef struct vertice tVertice;

tVertice *inicializaVertice();
tVertice *iniciaVertice(int id, char *nome);
char *retornaNome(tVertice *vertice);
int comparaVertice(const void *a, const void *b);
void imprimeNomeVertice(tVertice *v, FILE *f);
void liberaVertice(tVertice *vertice);
#endif