#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int preco1, preco2, preco3, qtd, soma=0, numero, i;
    
    scanf("%d%d%d", &preco1, &preco2, &preco3);
    scanf("%d", &qtd);
    
    for(i=0; i<qtd; i++){
        scanf("%d", &numero);
        switch (numero){
            case 1:
                soma=soma + preco1;
                break;
                
            case 2:
                soma=soma + preco2;
                break;
                
            case 3:
                soma=soma + preco3;
                break;
        }
    }
    printf("CUSTO:%d", soma);

    return (EXIT_SUCCESS);
}

