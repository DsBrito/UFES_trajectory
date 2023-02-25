
#include <stdio.h>
#include<stdlib.h>
#include "listaMat.h"

//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 4
#define NCOLUNAS 3

int main()
{
    
//o programa é composto por 3 matrizes.
    
    Matriz* mat1;
    Matriz* mat2;
    Matriz* mat3;
    
//chamando a funcao do TAD Matriz que inicializa a matriz.
    mat1 = inicializaMatriz(NLINHAS, NCOLUNAS,1);
    mat2 = inicializaMatriz(NLINHAS, NCOLUNAS,2);
    mat3 = inicializaMatriz(NLINHAS, NCOLUNAS,3);

    int i, j;  //contadores.
    int elem=0; //variavel para a criação dos elementos das matrizes.
    
//preenchendo a matriz com valores para teste.
    for (i=0;i<NLINHAS;i++)
        for (j=0;j<NCOLUNAS; j++){  
            //chamando a funcao do TAD matriz para modificar um dado elemento da matriz.
            modificaElemento(mat1, i, j,elem);
            modificaElemento(mat2, i, j,elem+1);
            modificaElemento(mat3, i, j,elem+2);
            elem = elem +1;
        }
    
    
//criando a lista de matrizes .
   Lista* lista1 = IniciaLista();

//inserindo as 3 matrizes na lista1.
   InsereLista(lista1,mat1);
   InsereLista(lista1,mat2);
   InsereLista(lista1,mat3);
   
   
     
//chamando a funcao do TAD matriz para imprimir os elementos da matriz
  
    printf("\nImprimindo a lista1 com 3 matrizes \n");
    ImprimeLista(lista1);
   
    

/* cada matriz possui um numero de identificação "Id", atraves dele podemos ter controle sobre as 
 * matrizes que estao na lista.
 * Ex : 1 = mat1
 *      2 = mat2 
 *      3 = mat3
 * 
 * assim podemos remover a matriz desejada inserindo o seu id
 */
    
 //retirando matrizes da lista
    printf("\n----------------------RETIRANDO-----------------------------------------\n");
 
    Retira(lista1,1);   
   // Retira(lista1,2);   
   // Retira(lista1,3);   


    
//imprimindo a lista após a remoção de 1 + matrizes.
    printf("\nNova lista 1:\n");   
    ImprimeLista(lista1); 
    
    
/* podemos inserir a matriz retirada chamando a função "InsereLista" passando como parametro
 * a matriz retirada (para verificar se o retira não "quebrou" a lista.
 * 
 */  
    printf("\n----------------------INSERINDO-----------------------------------------\n");
    InsereLista(lista1,mat1);
    //InsereLista(lista1,mat2);
    //nsereLista(lista1,mat3);

    ImprimeLista(lista1); 

    
/*criando a matriz transposta (podemos realizar os mesmos passos que foram feitos
 *  com as outras matrizes (remover/inserir)
 */
    Matriz* trp1 = transposta(mat1);
    Matriz* trp2 = transposta(mat2);
    Matriz* trp3 = transposta(mat3);
    Lista* lista2 = IniciaLista();
    InsereLista(lista2,trp1);
    InsereLista(lista2,trp2);
    InsereLista(lista2,trp3);
    
    printf("\n----------------------IMPRIMINDO MATRIZ TRANSPOSTA-----------------------------------------\n");
    ImprimeLista(lista2);

    
/* Liberando toda memoria alocada de ambas as listas
 */
    DestroiLista(lista1);
    DestroiLista(lista2);


    return 1;
}
