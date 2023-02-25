
#ifndef ABB_H
#define ABB_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "aluno.h"

typedef struct arv Arv;

Arv* abb_cria(void);

void abb_imprime (Arv* a);

Arv* abb_busca(Arv* r, int chave);

Arv* abb_insere (Arv* a,tAluno* al);

Arv* abb_retira(Arv* r, int v);

Arv* abb_libera(Arv* r);

#endif /* ABB_H */

