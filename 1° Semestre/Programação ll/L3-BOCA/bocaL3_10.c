#include <stdio.h>
#include <stdlib.h>

int EhLetra(char c){
    if((c>= 'a' && c<='z') || (c>='A' && c<='Z')){
        return (1);
    }
    else{
        return (0);
    }
}

int EhLetraMaiuscula(char c){
    if(c>='A' && c<='Z'){
        return (1);
    }
    else{
        return (0);
    }
}

int EhLetraMinuscula(char c){
    if(c>= 'a' && c<='z'){
        return (1);
    }
    else{
        return (0);
    }
}

char Codifica(char letra, int n){
    int l;
    l= letra;
    if(EhLetraMaiuscula(letra)==1){
        l= l + (2*n);
        while(l>'Z'){
            l= (l -'Z')+('A'-1);
        }
    }
    if(EhLetraMinuscula(letra)==1){
        l= l+n;
        while(l>'z'){
            l= (l -'z')+('a'-1);
        }
    }
    return l;
}

char Decodifica(char letra, int n){
    int l;
    l= letra;
    if(EhLetraMaiuscula(letra)==1){
        l= l - (2*n);
        while(l<'A'){
            l= 'Z' - ('A'-l) +1;
        }
    }
    if(EhLetraMinuscula(letra)==1){
        l= l-n;
        while(l<'a'){
            l= 'z' - ('a'-l) +1;
        }
    }
    return l;
}


int main(int argc, char** argv) {
    int num;
    char letra;
    
    letra= '\0';
    
    scanf("%d", &num);
    
    if(num>2){
        printf("Operacao invalida.");
    }
    if(num<1){
        printf("Operacao invalida.");
    }
    
    switch(num){
        case 1:
            scanf("%d", &num);
            scanf("%*c");
            while(letra != '.'){
                scanf("%c", &letra);
                if(EhLetra(letra)==1){
                    letra=Codifica(letra, num);
                    printf("%c", letra);
                }
                else{
                    printf("%c", letra);
                }
            }
            break;
            
        case 2:
            scanf("%d", &num);
            scanf("%*c");
            while(letra != '.'){
                scanf("%c", &letra);
                if(EhLetra(letra)==1){
                    letra=Decodifica(letra, num);
                    printf("%c", letra);
                }
                else{
                    printf("%c", letra);
                }
            }
            break;
    }

    return (EXIT_SUCCESS);
}

