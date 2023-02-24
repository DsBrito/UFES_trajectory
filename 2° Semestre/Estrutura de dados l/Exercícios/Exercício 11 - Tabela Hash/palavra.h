

#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>

typedef struct palavra Palavra;

Palavra *IniciaPalavra(char *str);

char *retornaString(Palavra *pal);

void atualizaOcorrencias(Palavra *pal);

int retornaOcorrencias(Palavra *pal);

Palavra *buscaPalavra(Palavra *pal, char *string);

Palavra *inserePalavraLista(Palavra *lista, Palavra *p);

int contaPalavrasLista(Palavra *p);

void imprimeLista(Palavra *p);

void liberaListaPalavra(Palavra *pal);

#endif /* PALAVRA_H */
