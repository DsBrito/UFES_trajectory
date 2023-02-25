#include <stdio.h>
#include <stdlib.h>


#include "ListaComSentinela.h"
#include "Arvore.h"


 
struct celula{
    int num;
    Arv* a;
    Celula* prox;
};

struct lista{
    Celula* Prim;
    Celula* Ult;
};



Lista* inicLista(){
    Lista* lista = (Lista*) malloc(sizeof(lista));
    lista->Prim = NULL;
    lista->Ult = NULL;
    return lista;
}

void insereListaUltFila(Lista* l, int i){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->num = i;
    nova->prox = NULL;
    if(l->Ult == NULL){
        l->Prim = l->Ult = nova;
        return;
    }
    l->Ult->prox = nova;
    l->Ult = nova;
}

void destroiLista(Lista* l){
    Celula* p = l->Prim;
    Celula* t;

    while(p!=NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    free(l);
}



int retiraPrimeiro(Lista* l){
    Celula* Deletado;
    if(l->Prim != NULL){
        Deletado = l->Prim;
        l->Prim = l->Prim->prox;
        int i = Deletado->num;
        free(Deletado);
        return i;
    }
}

Arv* retiraUltimo(Lista* p, int pos){
    Celula* cel = p->Prim;
    Celula* ant = NULL;
    int i = 0;
    while(i<pos && p!=NULL){
        ant = cel;
        i++;
        cel = cel->prox;
    }
    if(cel == p->Prim && cel == p->Ult){
        p->Prim = p->Ult = NULL;
    }
    else if(cel == p->Prim){
        p->Prim = cel->prox;
    }
    else if(cel == p->Ult){
        p->Ult = ant;
        p->Ult->prox = NULL;
    }
    else{
        ant->prox = cel->prox;
    }
    Arv* a = cel->a;
    free(cel);
    return a;
}

void insereListaUltPilha(Lista* l, Arv* a){
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->a = a;
    nova->prox = NULL;
    if(l->Prim == NULL){
        l->Prim = nova;
    }
    if(l->Ult == NULL){
        l->Prim = l->Ult = nova;
        return;
    }
    l->Ult->prox = nova;
    l->Ult = nova;
}



