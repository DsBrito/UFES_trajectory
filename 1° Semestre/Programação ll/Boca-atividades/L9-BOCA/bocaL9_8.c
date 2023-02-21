#include <stdio.h>
#include <stdlib.h>

int ReduzInteiro(int n){
    int reduzido=0, numero;
    while(n){
        numero= n%10;
        reduzido= reduzido + numero;
        n= n/10;
    }
    if(reduzido<10){
        return reduzido;
    }
    else{
        ReduzInteiro(reduzido);
    }
}

int MontaSenha(int senha, int dig){
    senha= senha*10 + dig;
    return senha;
}

int ReduzCodigo(){
    int num=0, numReduzido=0;
    
    if(scanf("%1d", &num)==1){
        numReduzido = numReduzido+ num;
        while(scanf("%1d", &num)==1){
            numReduzido = numReduzido+ num;
        }
        numReduzido= ReduzInteiro(numReduzido);
        scanf(")");
        return numReduzido;
    }
    else{
        scanf(")");
        return (-1);
    }
}

int main(int argc, char** argv) {
    int numReduzido, senha=0, i=0;
    char caracter;
    
    scanf("%c", &caracter);
    while(caracter != '.'){
        if(caracter == '('){
            numReduzido= ReduzCodigo();
            if(numReduzido== -1){
                printf("[ERRO]");
            }
            else{
                printf("[%d]", numReduzido);
                if(i !=0){
                    senha= MontaSenha(senha, numReduzido);
                }
                if(i==0){
                    senha= numReduzido;
                    i++;
                }
            }
        }
        else{
            printf("%c", caracter);
        }
        scanf("%c", &caracter);
    }
    printf(". SENHA:%d", senha);
    return (EXIT_SUCCESS);
}

