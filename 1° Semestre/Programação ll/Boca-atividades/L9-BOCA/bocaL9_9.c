#include <stdio.h>
#include <stdlib.h>

int MaiorDigito(int num){
    int maior=0, n;
    while(num !=0){
        n= num%10;
        if(n > maior){
            maior=n;
        }
        num= num/10;
    }
    return maior;
}

int EhIgual(int a, int b){
    int maior1, maior2;
    
    maior1= MaiorDigito(a);
    maior2= MaiorDigito(b);
    
    if(maior1==maior2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char** argv) {
    int num1, num2, qtd=0;
    
    while(scanf("(%d,%d)", &num1, &num2)==2){
        if(EhIgual(num1, num2)==1){
            qtd++;
        }
    }
    printf("COUNT:%d", qtd);
    return (EXIT_SUCCESS);
}

