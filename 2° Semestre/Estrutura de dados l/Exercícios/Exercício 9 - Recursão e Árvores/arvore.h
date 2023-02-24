
#ifndef ARVORE_H
#define ARVORE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

// tipo  opaco
typedef struct arvore tArvore;

tArvore *arv_criaVazia(void);

int arv_vazia(tArvore *arvore);

tArvore *arv_cria(tAluno *aluno, tArvore *esquerda, tArvore *direita);

tArvore *arv_libera(tArvore *arvore);

int arv_pertence(tArvore *arvore, char *nome);

void arv_imprime(tArvore *arvore);

int altura(tArvore *arvore);

tArvore *arvore_pai(tArvore *arvore, char *nome);

int ocorrencias(tArvore *arvore, char *nome);

tAluno *info(tArvore *arvore);

int folhas(tArvore *arvore);

#endif /* ARVORE_H */
