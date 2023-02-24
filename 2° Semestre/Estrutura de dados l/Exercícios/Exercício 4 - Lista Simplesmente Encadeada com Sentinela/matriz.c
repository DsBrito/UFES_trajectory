

#include <stdio.h>
#include "matriz.h"
#include<stdlib.h>

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
//contendo linhas - colunas - tamanho
struct matriz{
    int linhas;
    int colunas;
    int **matriz_allocada;
    int id;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas, int num){
    
   
    Matriz* matriz;
    int i;
    
    matriz=(Matriz*)malloc(sizeof(Matriz));
    matriz->id=num;
    matriz->linhas= nlinhas;
    matriz->colunas= ncolunas;
  
    matriz->matriz_allocada=(int**)malloc(nlinhas * sizeof(Matriz));
   
    
    for(i=0;i<nlinhas;i++){
        matriz->matriz_allocada[i]= (int*)malloc(ncolunas*sizeof(int));
      
    }

    return matriz;


};

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->matriz_allocada[linha][coluna]= elem;
};




/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat){

    int i,j;
    Matriz* transposta= inicializaMatriz (mat->colunas, mat->linhas, mat->id);
    
    for(i=0;i<mat->linhas;i++){
        for(j=0;j<mat->colunas;j++){
            transposta->matriz_allocada[j][i]=mat->matriz_allocada[i][j];
        }
    }
    return transposta;



};

int recuperaId(Matriz* mat){
    return mat->id;
};


/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat){    
    
    int i,j;


    for(i=0;i<mat->linhas;i++){
        for(j=0;j<mat->colunas;j++){
            printf(" Matriz[%d][%d]= %d\n",i,j,mat->matriz_allocada[i][j]);
        }
    }
};


/*Libera memória alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: toda a memória alocada para matriz foi liberada
 */
void destroiMatriz(Matriz* mat){
    int i;
    
    for(i=0;i<mat->linhas;i++){
        free(mat->matriz_allocada[i]);
    }
    free(mat->matriz_allocada);
    
    free(mat);


}
