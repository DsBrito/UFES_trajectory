#include <stdio.h>
#include <stdlib.h>

int EhIgual(int a, int b){
    if(a==b){
        return 1;
    }
    else{
        return 0;
    }
}
int InverteNumero(int num){
    int palindromo=0;
    while(num !=0){
        palindromo= palindromo*10 + num%10;
        num= num/10;
    }
    return palindromo;
}

int main(int argc, char** argv) {
    int numero, palindromo, quantidade=0;
    
    while(scanf("%d", &numero)==1){
        palindromo= InverteNumero(numero);
        if(EhIgual(numero, palindromo)==1){
            quantidade++;
        }
    }
    printf("COUNT:%d", quantidade);
    return (EXIT_SUCCESS);
}

