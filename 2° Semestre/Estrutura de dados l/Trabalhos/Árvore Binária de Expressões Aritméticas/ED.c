#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ListaComSentinela.h"
#include "Arvore.h"
#include "ED.h"


struct ed{
    Lista* lista;
    int tamanho;
};

ED* inicED(){
    ED* f = (ED*) malloc (sizeof(ED));
    f->lista = inicLista();
    f->tamanho = 0;
    return f;
}

void insereFila(ED* f, int i){
    insereListaUltFila(f->lista, i);
    f->tamanho=f->tamanho+1; 
}

void destroiED(ED* f){
    destroiLista(f->lista);  
    free(f);
}

Lista* retornaListaED(ED* ed){
    return ed->lista;
};

int retiraFila(ED* f){
    f->tamanho=f->tamanho -1; 
    return retiraPrimeiro(f->lista);
}


int ConverteFilaPraInt(ED* f, int i){
    int num = 0;
    for(int j = retiraFila(f);  ; j = retiraFila(f)){
        num = num + j*pow(10, i-1);
        i--;
        if(f->tamanho==0)
            break;
    }
    return num;
}

int retornaTamanho(ED* f){
    return f->tamanho;
}

Arv* retiraPilha(ED* p){
    p->tamanho = p->tamanho -1;
    return retiraUltimo(p->lista, p->tamanho);
}

void inserePilha(ED* p, Arv* a){
    p->tamanho = p->tamanho + 1;
    insereListaUltPilha(p->lista, a);
}











