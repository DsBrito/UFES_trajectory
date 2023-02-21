#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int n, maior, quant;
    float soma;
    
    n=1;
    maior=0;
    soma=0;
    quant=1;

	scanf("%d", &n);

    while(n){
        if(n>maior){
            maior=n;
        }
        soma= soma+n;
                
        printf("%d %.6f\n", maior, (soma/quant));
        quant++;
	scanf("%d", &n);
    }

    return (EXIT_SUCCESS);
}
