#include <stdio.h>
#include <stdlib.h>


int EhPalindromo(int num){
    int numOriginal, palindromo, resto;
    
    numOriginal=num;
    palindromo=0;
    
    while(num !=0){
        resto=num%10;
        palindromo=palindromo+resto;
        num=num/10;
        
        if(num!=0){
            palindromo= palindromo*10;
        }
    }
    if(palindromo==numOriginal){
        return (1);
    }
    else{
        return (0);
    }
}

int main(int argc, char** argv) {
    int num;
    
    while(scanf("%d", &num)==1){
        if(EhPalindromo(num)==1){
            printf("S\n");
        }
        else{
            printf("N\n");
        }
    }
    

    return (EXIT_SUCCESS);
}

