

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
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    
   
    Matriz* matriz;
    int i;
    
    matriz=(Matriz*)malloc(sizeof(Matriz));
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



/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
 * pos-condicao: mat não é modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->matriz_allocada[linha][coluna];
};

/*Retorna o número de colunas da matriz mat
 * inputs: a matriz
 * output: o número de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada
 */
int recuperaNColunas (Matriz* mat){
    return mat->colunas;
};

/*Retorna o número de linhas da matriz mat
 * inputs: a matriz
 * output: o número de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada
 */
int recuperaNLinhas (Matriz* mat){
    return mat->linhas;
};




/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat){

    int i,j;
    Matriz* transposta= inicializaMatriz (mat->colunas, mat->linhas);
    
    for(i=0;i<mat->linhas;i++){
        for(j=0;j<mat->colunas;j++){
            transposta->matriz_allocada[j][i]=mat->matriz_allocada[i][j];
        }
    }
    return transposta;



};



/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicação
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 não são modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    
    int i,j,k;
    Matriz* multiplicacao= inicializaMatriz (mat1->linhas, mat1->colunas);
    for(i=0;i<mat1->linhas;i++){
        for(j=0;j<mat2->colunas;j++){
            for(k=0;k<mat1->colunas;k++){
            multiplicacao->matriz_allocada[i][j] = multiplicacao->matriz_allocada[i][j] + mat1->matriz_allocada[i][k]*mat2->matriz_allocada[k][j];
            
            
            }
        }
    }


    return multiplicacao;



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
