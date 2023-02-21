#include <stdio.h>
#include <stdlib.h>

int CalculaValorPalavra(int letra){
    int soma=0;
    char letra2;
    
    if(letra>= 'a' && letra<='z'){
        soma= letra-96;
    }
    if(letra>= 'A' && letra<='Z'){
        soma= letra-65+27;
    }
    while(scanf("%c", &letra2)==1){
        if(letra2>= 'a' && letra2<='z'){
        soma= soma + letra2-96;
        }
        if(letra2>= 'A' && letra2<='Z'){
        soma= soma + letra2-65+27;
        }
        if(letra2=='\n' || letra2==' '){
            return soma;
        }
    }
}
    
int EhPrimo(int n){
    int i, qtd=0;
    for(i=1; i<=n; i++){
        if(n%i==0){
            qtd++;
        }
    }
    if(qtd==2){
        return 1;
    }
    else{
        return 0;
    }
}

int ProximoPrimo(int n){
    int i, qtd=0;
    while(qtd !=2){
        qtd=0;
        n++;
        for(i=1; i<=n; i++){
            if(n%i==0){
            qtd++;
            }
        }
        if(qtd==2){
            return n;
        }
    }
}

int main(int argc, char** argv) {
    char letra;
    int soma;
    
    while(scanf("%c", &letra)==1){
        soma= CalculaValorPalavra(letra);
        if(EhPrimo(soma)==1){
            printf("E primo\n");
        }
        else{
            soma= ProximoPrimo(soma);
            printf("Nao e primo %d\n", soma);
        }
    }
    
    return (EXIT_SUCCESS);
}

