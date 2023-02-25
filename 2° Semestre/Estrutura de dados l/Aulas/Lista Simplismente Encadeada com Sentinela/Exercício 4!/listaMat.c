
#include<stdio.h>
#include "listaMat.h"
#include<stdlib.h>
#include<string.h>

typedef struct cel Celula;

struct cel{
    Matriz* mat;
    Celula* proximo;


};

struct lista{
    Celula* primeiro;
    Celula* ultimo;

};


Lista* IniciaLista(void){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro=NULL;
    lista->ultimo=NULL;
    
    return lista;

};

void ImprimeLista(Lista* lista){
    
    //ponteiro auxiliar, nao precisa alocar
    Celula*p;
    int contMatriz=1;
    for(p=lista->primeiro; p!=NULL; p=p->proximo){
        printf("\nImprimindo Matriz [%d]\n",recuperaId(p->mat));
       imprimeMatriz(p->mat);
       contMatriz = contMatriz +1;
    }



};
void InsereLista(Lista* lista,Matriz* mat){

    //alocar uma nova celula
    Celula* nova=(Celula*)malloc(sizeof(Celula));
    nova->mat=mat;
    nova->proximo= lista->primeiro;
    lista->primeiro = nova;
    
    if(lista->ultimo==NULL){
        lista->ultimo=nova;
    }
    




};



Matriz* Retira(Lista* lista, int busca){
    Celula* p= lista->primeiro;
    Matriz* mat;
    Celula* ant = NULL;
    
/* a função recuperaId ira retornar o id da matriz e comparar com o valor
 * de busca solicidado no testador.c
 */
 
    while(p!=NULL && (recuperaId(p->mat)!=busca)){
        ant = p;
        p= p->proximo;
    
    }
    
    //lista vazia
    if(p == NULL){
        return NULL;
    }
    
    //se for no inicio
    mat= p->mat;
    
    //se for o unico
    if(p==lista->primeiro && p==lista->ultimo){
        lista->primeiro= lista->ultimo =NULL;
    }
    else if(p == lista->primeiro){
        lista->primeiro = p->proximo;
    }
    else if(p == lista->ultimo){
        lista->ultimo = ant;
        lista->ultimo->proximo = NULL;
    }
    
    else{
        ant->proximo= p->proximo;
    }
    
    free(p);
    
    return mat;


};

void DestroiLista(Lista* lista){
    Celula* p= lista->primeiro;
        Celula* t;
    
    while(p!=NULL){
        t=  p->proximo;
        destroiMatriz(p->mat);
        free(p);
        p= t;
    
    }
    free(lista);
    printf("\n toda memoria alocada foi liberada!!\n");



};

