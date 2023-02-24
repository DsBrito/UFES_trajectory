

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaZooDPL.h"

struct tipoListaDPL{

    TipoListaDPL* anterior;
    TipoListaDPL* proximo;
    TipoZoo* animal;

    
};


TipoListaDPL* IniciaLista(){
    return NULL;
};

TipoListaDPL* InsereLista(TipoListaDPL* lista, TipoZoo* animal){

    TipoListaDPL* Nova;
    
    Nova=(TipoListaDPL*)malloc(sizeof(TipoListaDPL));
    
    Nova->animal= animal;
    Nova->anterior=NULL;
    Nova->proximo=lista;
    
    
    if(lista!=NULL){
        lista->anterior= Nova;
    }
    return Nova;

};

TipoListaDPL* RetiraLista(  TipoListaDPL* lista, int id){
  
    TipoListaDPL* p=lista; 
    
    for(p=lista;p!=NULL;p=p->proximo){
        if(buscaZoo(p->animal)==id){
            break;
        }
        
    }

    if (p == NULL){
        printf("\nEsse animal nao esta presente no Zoologico\n\n");
        return lista;
    }


    if (lista==p){
        lista = p->proximo;  
        
    }

    else{
        p->anterior->proximo = p->proximo;
    }
    
    if (p->proximo != NULL){
        p->proximo->anterior = p->anterior;
    }
    
    //DestroiAnimal(p->animal);
    free(p);

    return lista;
  
  };
  
  void ImprimeLista(TipoListaDPL* lista){
      TipoListaDPL* p;
      
      for(p=lista;p!=NULL;p=p->proximo){
          imprimeAnimal(p->animal);
          printf("\n");
      }
  
  
  };
  
  void DestroiLista(TipoListaDPL* lista){
      TipoListaDPL* p;
      TipoListaDPL* t;
      
      while(p!=NULL){
          t= p->proximo;
          DestroiAnimal(p->animal);
          free(p);
          p=t;
      }
  
  
  };
  