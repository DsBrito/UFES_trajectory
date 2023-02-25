

#include"pilha.h"  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define  MaxTam 10   //alterar caso queira que a pilha fosse maior


struct pessoa{
  char* nome;
  int idade;
  float peso;
  float altura;
  char* endereco;
  char* genero;
};

// Com MaxTam = 10
 struct indice{
  int topo;
  int base;

};


 struct pilha{

  tPessoa* Pessoas[MaxTam];
  IndicePilha Pilha1, Pilha2;

};


tPilhaDupla* cria_pilha(){
  tPilhaDupla * pilha;

  pilha=(tPilhaDupla*)malloc(sizeof(tPilhaDupla));

  pilha->Pilha1.base=0;
  pilha->Pilha1.topo=-1;
  pilha->Pilha2.base=MaxTam-1;
  pilha->Pilha2.topo=MaxTam;
 
  return pilha;
}



void push(tPessoa* pessoa, tPilhaDupla* pilha, int indice){

  if(pilha->Pilha1.topo == pilha->Pilha2.topo){
    printf("ERRO: pilha esta cheia\n");
  }
  else{
      
      
      //colocar genero feminino na pilha 1
      if(indice==1){
        pilha->Pessoas[(pilha->Pilha1.topo)+1]=pessoa;
           
        pilha->Pilha1.topo++;
      }
      
      //colocar genero masculino la pilha 2
      if(indice==2){
        pilha->Pessoas[(pilha->Pilha2.topo)-1]=pessoa;
            
        pilha->Pilha2.topo--;
      }
      
  }
}

tPessoa* pop(tPilhaDupla* pilha, int indice){

  tPessoa* aux;
  
  if(indice==1){
    if(pilha->Pilha1.topo==0){
        printf("ERRO: pilha vazia\n");
        return NULL;
  }
  else{
    aux= pilha->Pessoas[pilha->Pilha1.topo+1];
    pilha->Pilha1.topo--;
    return aux;
  }
  }
  
  
  if(indice==2){
    if(pilha->Pilha2.topo==MaxTam-1){
        printf("ERRO: pilha vazia\n");
        return NULL;
    }
    else{
      aux= pilha->Pessoas[pilha->Pilha2.topo];
      pilha->Pilha2.topo--;
      return aux;
    }
  }
}



void imprime_pilha (tPilhaDupla* pilha){

  int Aux;
  int tamanho= pilha->Pilha1.topo + pilha->Pilha2.topo;
  for (Aux = 0; Aux<tamanho+1; Aux++){
        printf ("NOME: %s\n", pilha->Pessoas[Aux]->nome);
        printf ("IDADE: %d\n", pilha->Pessoas[Aux]->idade);
        printf ("PESO: %.2f\n", pilha->Pessoas[Aux]->peso);
        printf ("ALTURA: %.2f\n", pilha->Pessoas[Aux]->altura);
        printf ("GENERO: %s\n", pilha->Pessoas[Aux]->genero);
        printf ("ENDERECO: %s\n", pilha->Pessoas[Aux]->endereco);
        printf("\n");

  }
 
}



tPilhaDupla* destroi_pilha(tPilhaDupla* pilha){
  int i;
  for(i=0; i<10;i++){
    free(pilha->Pessoas[i]->nome);
    free(pilha->Pessoas[i]->endereco);
    free(pilha->Pessoas[i]->genero);
    free(pilha->Pessoas[i]);
  }
  free(pilha);
  return NULL;
}


int recuperaGenero(tPessoa* pessoa){

    if(strcmp(pessoa->genero,"feminino")){
        return 1;
    }
    
    
    if(strcmp(pessoa->genero,"masculino")){
        return 2;
    }
};




tPessoa* inicializaPessoa(char* nome, int idade, float peso, float altura, char* endereco, char* genero){


    tPessoa* pessoa;

    pessoa = (tPessoa*)malloc(sizeof(tPessoa));
    pessoa->nome=strdup(nome);
    pessoa->endereco=strdup(endereco);
    pessoa->genero=strdup(genero);
    pessoa->idade=idade;
    pessoa->peso=peso;
    pessoa->altura=altura;
    
    return pessoa;
}