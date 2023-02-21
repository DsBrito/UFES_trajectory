#include <stdio.h>

int main(){
    int n1, Domingo, Segunda, Terca, Quarta, Quinta, Sexta,
Sabado, Invalido;

    scanf("%d", &n1);
    if (n1==1){
    printf("Domingo");
    }
    else if(n1==2){
    printf("Segunda");
    }
    else if(n1==3){
    printf("Terca");
    }
    else if(n1==4){
    printf("Quarta");
    }
    else if(n1==5){
    printf("Quinta");
    }
    else if(n1==6){
    printf("Sexta");
    }
    else if(n1==7){
    printf("Sabado");
    }
    else{
    printf("Invalido");
}
    return 0;
}
