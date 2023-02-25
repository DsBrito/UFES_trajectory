/*
 *********************************
 * Programa testador do TAD Matriz
 *********************************
 */
#include <stdio.h>
#include "matriz.h"

//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 4
#define NCOLUNAS 3

int main()
{
    Matriz* mat;
    //chamando a funcao do TAD Matriz que inicializa a matriz
    mat = inicializaMatriz(NLINHAS, NCOLUNAS);
    int i, j;
    //preenchendo a matriz com valores para teste
    for (i=0;i<NLINHAS;i++)
        for (j=0;j<NCOLUNAS; j++)
            //chamando a funcao do TAD matriz para modificar um dado elemento da matriz
            modificaElemento(mat, i, j,i+j);
    //chamando a funcao do TAD matriz para imprimir os elementos da matriz
    imprimeMatriz(mat);
    
    //chamando a função do TAD para gerar a matriz transposta
    Matriz* trp = transposta(mat);
    printf ("A matriz transposta eh: \n");
    imprimeMatriz(trp);
    
    //chamando a função do TAD para gerar a matriz multiplicacao
    Matriz* mlt = multiplicacao(mat,trp);
    printf ("A matriz multiplicacao eh: \n");
    imprimeMatriz(mlt);
    
    destroiMatriz(mat);
    destroiMatriz(trp);
    destroiMatriz(mlt);
}
