#include <stdio.h>
#include <stdlib.h>

int EhFinalDaLista(int buraco){
    return (buraco == -1);
}
int EcontraMaiorBuraco(){
    int buraco, maiorBuraco=0;
    
    scanf("%d", &buraco);
    while(buraco != -1){
        if(buraco>maiorBuraco){
        maiorBuraco=buraco;
        }
        scanf("%d", &buraco);
    }
    return maiorBuraco;
}
int ContaEsferasGrandes(int maiorBuraco){
    int esfera=0, qtd=0;
    
    while(esfera != -1){
        scanf("%d", &esfera);
        if(esfera>=maiorBuraco){
            qtd++;
        }
    }
    return qtd;
}

int main(int argc, char** argv) {
    int maiorBuraco, qtd;
    
    maiorBuraco= EcontraMaiorBuraco();
    qtd= ContaEsferasGrandes(maiorBuraco);
    printf("QTD:%d", qtd);
    return (EXIT_SUCCESS);
}

