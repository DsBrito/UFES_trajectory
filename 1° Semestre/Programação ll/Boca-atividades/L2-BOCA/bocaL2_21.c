#include <stdio.h>


int main(){
    int numero, numElementos, n1, n2, n3, n4, n5, n6, n7, n8, n9, i;
    char letra;
    
    scanf("%d", &numElementos);
    
    for(i=1; i<=numElementos; i++){
        scanf("%d", &numero);
        if(i==1){
            n1=numero;
        }
        if(i==2){
            n2=numero;
        }
        if(i==3){
            n3=numero;
        }
        if(i==4){
            n4=numero;
        }
        if(i==5){
            n5=numero;
        }
        if(i==6){
            n6=numero;
        }
        if(i==7){
            n7=numero;
        }
        if(i==8){
            n8=numero;
        }
        if(i==9){
            n9=numero;
        }
    }
    
    i=0;
    scanf("%c", &letra);
    while(i!=2){
        scanf("%c", &letra);
        if(letra=='"'){
            i++;
        }
        if(letra=='%'){
            scanf("%d", &numero);
            if(numero>numElementos || numero<1){
                printf("ERRO");
            }
            else if(numero==1){
                printf("%d", n1);
            }
            else if(numero==2){
                printf("%d", n2);
            }
            else if(numero==3){
                printf("%d", n3);
            }
            else if(numero==4){
                printf("%d", n4);
            }
            else if(numero==5){
                printf("%d", n5);
            }
            else if(numero==6){
                printf("%d", n6);
            }
            else if(numero==7){
                printf("%d", n7);
            }
            else if(numero==8){
                printf("%d", n8);
            }
            else if(numero==9){
                printf("%d", n9);
            }
        }
        else if(letra != '"'){
            printf("%c", letra);
        }
    }
    return 0;
}
    
    