#include <stdio.h>

int main(){
    int a, b, i;
    char caracter;
    
    a=0;
    b=0;
    i=0;
    
    scanf("%c", &caracter);
    printf("RESP:");
    while(caracter !='.'){
        if(caracter=='('){
            a++;
        }
        if(caracter==')'){
            b++;
        }
        if(caracter=='(' && i==0){
            scanf("%c", &caracter);
            if(caracter== '('){
                a++;   
            }
            if(caracter== ')'){
                b++;
            }
            i++;
        }
        if(a==b && i!=0){
            i=0;
        }
        if(a != b){
            printf("%c", caracter);
        }
        scanf("%c", &caracter);
        
        while(caracter=='.' && a !=b){
            printf("%c", caracter);
            scanf("%c", &caracter);
        }
    }

    return 0;
}