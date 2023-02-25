
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTA_HET.h"

#define PROFESSOR 0
#define ALUNO 1 

//sentinela
typedef struct cel tCelula;

struct cel{
    tCelula* proximo;
    void* item;
    int tipo;
};

struct listahet {
    tCelula* primeiro;
    tCelula* ultimo;

};


ListaHet* IniciaLista(){
    ListaHet* lista= (ListaHet*)malloc(sizeof(ListaHet));
    
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    
    return lista;

};

void InsereAluno(ListaHet* lista, tAluno* a){

 tCelula* Nova;
    
    
    Nova= (tCelula*)malloc(sizeof(tCelula));
    
    Nova->item= a;
    Nova->tipo= ALUNO;
    Nova->proximo= lista->primeiro;
    
    lista->primeiro= Nova;
    
    if (lista->ultimo==NULL)
        lista->ultimo= Nova;
    
}

void InsereProfessor(ListaHet* lista, tProfessor* p ){
    tCelula* Nova;
    
    
    Nova= (tCelula*)malloc(sizeof(tCelula));
    
    Nova->item= p;
    Nova->tipo= PROFESSOR;
    Nova->proximo= lista->primeiro;
    
    lista->primeiro= Nova;
    
    if (lista->ultimo==NULL)
        lista->ultimo= Nova;

};

void ImprimeListaHet(ListaHet* lista){
   tCelula* L;
   
   for(L=lista->primeiro;L!=NULL;L=L->proximo){
       if(L->tipo == ALUNO){
           printf("\nALUNO:");
           ImprimeAluno((tAluno*)L->item);
       }
       if(L->tipo == PROFESSOR){
           printf("\nPROFESSOR:");
           ImprimeProfessor((tProfessor*)L->item);
       }
   
   }

};

float ValorChurrasco(ListaHet* lista){

    tCelula* aux;
    
    aux= lista->primeiro;
    
    float valor =0;0;
    
    while (aux!=NULL){
        if(aux->tipo == PROFESSOR)
            valor= valor + 0.02*RetornaSalario(aux->item);
    
        if(aux->tipo == ALUNO)
            valor= valor + + 30.0;
        aux=aux->proximo;
    
    }
    
    return valor;


};

void DestroiLista(ListaHet* lista){

    tCelula* p = lista->primeiro;
    tCelula* t;
    
    while(p!=NULL){
        t= p->proximo;
        free(p);
        p=t;
    }

    free(lista);
};