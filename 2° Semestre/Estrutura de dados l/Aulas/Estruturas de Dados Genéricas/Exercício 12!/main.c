
#include <stdio.h>
#include <stdlib.h>
#include "listaalunos.h"
/*
 * 
 */
int main() {
    
   
    ListaGen* lista= criaLista();
    
            
    Aluno* bruna = IniciaAluno(123,"bruna",10);
    lista=insereLista(lista,bruna);
    Aluno* diego = IniciaAluno(241,"diego",5);
    lista=insereLista(lista,diego);
    Aluno* patricia = IniciaAluno(523,"patricia",9);
    lista=insereLista(lista,patricia);
    Aluno* joao = IniciaAluno(999,"joao",8);
    lista=insereLista(lista,joao);
    Aluno* ezio = IniciaAluno(123,"ezio",2);
    lista=insereLista(lista,ezio);
    Aluno* kassio = IniciaAluno(241,"kassio",10);
    lista=insereLista(lista,kassio);

    
    //imprime
    printf("\nImprimindo lista f:\n");
    imprimeAlunos(lista);    
  
    //retira
    lista= retriaAluno(lista,123);
    
     printf("\nImprimindo lista novamente:\n");
    imprimeAlunos(lista);
    
    
    //verifica pertence
    int i= pertenceAluno(lista,999);
    
    if(i==0)
        printf("\nJoao esta na lista:\n");

    else
         printf("\nJoao nao esta na lista:\n");
    
    //retorna media
    
    float media= mediaTurma(lista);
      printf("\nmedia %f:\n",media);
    
    libera(lista);
    
    DestroiAluno(bruna);
    DestroiAluno(diego);
    DestroiAluno(patricia);
    DestroiAluno(joao);
    DestroiAluno(ezio);
    DestroiAluno(kassio);
  
    
    
    
}

