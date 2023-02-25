#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arvore.h"


struct arv {
    float simbolo;
    int tipo;
    struct arv* esq;
    struct arv* dir;
};

Arv* arv_criavazia(void)
{
    return NULL;
}


Arv* arv_cria(float simbolo, Arv* e, Arv* d, int tipo)
{
    Arv* p = (Arv*) malloc (sizeof(Arv));
    p->tipo = tipo;
    p->simbolo = simbolo;
    p->esq = e;
    p->dir = d;
    return p;
}

int arv_vazia(Arv* a)
{
    return a==NULL;
}

Arv* retornaEsq(Arv* a){
    return a->esq;
}

Arv* retornaDir(Arv* a){
    return a->dir;
}

int retornaTipo(Arv* a){
    return a->tipo;
}

Arv* arv_libera(Arv* a)
{
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

float retornaSimbolo(Arv* a)
{
    return a->simbolo;
}


Arv* arv_insere(Arv* a, float simbolo, int tipo){
    if(a==NULL){
        a = (Arv*) malloc (sizeof(Arv));
        a->tipo = tipo;
        a->simbolo = simbolo;
        a->esq = a->dir = NULL;
    }
    else if(arv_vazia(a->esq))a->esq = arv_insere(a->esq, simbolo, tipo);
    else a->dir = arv_insere(a->dir, simbolo, tipo);
    return a;
}

void insereSimbolo(Arv* a, float simbolo, int tipo){ 
    a->simbolo = simbolo;
    a->tipo = tipo;
}
/*
int imprimeArvore(FILE* graphviz, int i, Arv* a){
    if(retornaTipo(a) == OPERADOR){
        char simbolo = retornaSimbolo(a);
        fprintf(graphviz, "no%d[label=""%c""];\n", i, simbolo);
    }
    else{
        int simbolo = retornaSimbolo(a);
        fprintf(graphviz, "no%d[label=""%d""];\n", i, simbolo);
    }
    if(retornaEsq(a) != NULL){
        fprintf(graphviz, "no%d--no%d\n", i, i+1);
        i = imprimeArvore(graphviz, (i+1), retornaEsq(a));
    }
    if(retornaDir(a) != NULL){
        fprintf(graphviz, "no%d--no%d\n", i, i+1);
        i = imprimeArvore(graphviz, (i+2), retornaDir(a));
    }
}*/

void imprimeArvore(FILE* graphviz, Arv* a){
    if(retornaEsq(a) == NULL)return;
    if(retornaTipo(a) == OPERADOR){
        char simbolo = a->simbolo;
        fprintf(graphviz, "\"%c\" -> ", simbolo);
    }
    if(retornaTipo(a) == OPERANDO){
        int simbolo = a->simbolo;
        fprintf(graphviz, "%d -> ", simbolo);
    }
    if(retornaTipo(retornaEsq(a)) == OPERADOR){
        char simbolo = retornaEsq(a)->simbolo;
        fprintf(graphviz, "\"%c\";\n", simbolo);
    }
    if(retornaTipo(retornaEsq(a)) == OPERANDO){
        int simbolo = retornaEsq(a)->simbolo;
        fprintf(graphviz, "%d;\n", simbolo);
    }
    if(retornaTipo(a) == OPERADOR){
        char simbolo = a->simbolo;
        fprintf(graphviz, "\"%c\" -> ", simbolo);
    }
    if(retornaTipo(a) == OPERANDO){
        int simbolo = a->simbolo;
        fprintf(graphviz, "%d -> ", simbolo);
    }
    if(retornaTipo(retornaDir(a)) == OPERADOR){
        char simbolo = retornaDir(a)->simbolo;
        fprintf(graphviz, "\"%c\";\n", simbolo);
    }
    if(retornaTipo(retornaDir(a)) == OPERANDO){
        int simbolo = retornaDir(a)->simbolo;
        fprintf(graphviz, "%d;\n", simbolo);
    }
    imprimeArvore(graphviz, retornaEsq(a));
    imprimeArvore(graphviz, retornaDir(a));
}

float calculaArvore(Arv* a){
    float esq;
    float dir; 
    if(retornaTipo(retornaEsq(a)) == OPERADOR){
        esq = calculaArvore(retornaEsq(a));
    }
    else{
        esq = retornaEsq(a)->simbolo;
    }
    if(retornaTipo(retornaDir(a)) == OPERADOR){
        dir = calculaArvore(retornaDir(a));
    }
    else {
        dir = retornaDir(a)->simbolo;
    }
    if(a->simbolo == '-'){
        return esq - dir;
    }
    if(a->simbolo == '+'){
        return esq + dir;
    }
    if(a->simbolo == '*'){
        return esq * dir;
    }
    if(a->simbolo == '/'){
        return esq / dir;
    }
    
}










