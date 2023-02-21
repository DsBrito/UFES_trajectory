#include <stdio.h>

int main(){
    int coluna, linha, i,p,j,posicaoLinha, posicaoColuna, maior, numero;
    
    scanf("%d%d", &linha, &coluna);
    j=0;
    
    for(i=0; i<linha; i++){ //ele vai ler todas as linhas até o parametro "i" chegar no valor da quantidade de linhas
        for(p=0; p<coluna; p++){ // mesma ideia da linha de cima, porém para as colunas da matriz
            scanf("%d", &numero);
            if(j==0){
                maior=numero;
                j++;                
            }
            if(numero>=maior){
                maior=numero;
                posicaoLinha=i+1;
                posicaoColuna=p+1;
            }
        }
    }
    printf("%d (%d, %d)", maior, posicaoLinha, posicaoColuna);

    return 0;
}
    
    