

#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include "palavra.h"

typedef struct hash Hash;

Hash *inicHash(int tamanho);

Palavra *acessa(Hash *, char *string);

int contaPalavras(Hash *h);

void imprimeHash(Hash *h);

void liberaHash(Hash *h);

#endif /* HASH_H */
