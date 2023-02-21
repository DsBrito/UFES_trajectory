#include <stdio.h>

int main(){
    char letra;

    scanf("%c", &letra);

    while(letra != '.' && letra != '!' && letra !='?'){
        if(letra>='a' && letra <='z'){
            letra = letra - 'a';
            printf("%c", 'A' + letra);
        }
        else{
            printf("%c", letra);
        }
        scanf("%c", &letra);
    }
    if(letra=='.'){
        printf(".");
    }
    if(letra=='!'){
        printf("!");
    }
    if(letra=='?'){
        printf("?");
    }
    return 0;
}
