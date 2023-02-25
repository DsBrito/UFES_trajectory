#ifndef ED_h
#define ED_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ListaComSentinela.h"
#include "Arvore.h"


typedef struct ed ED;

ED* inicED();

int retornaTamanho(ED* f);

void insereFila(ED* f, int i);

void destroiED(ED* f);

Lista* retornaListaED(ED* ED);


int retiraFila(ED* f);

int ConverteFilaPraInt(ED* f, int i);

Arv* retiraPilha(ED* p);

void inserePilha(ED* p, Arv* a);

        
#endif