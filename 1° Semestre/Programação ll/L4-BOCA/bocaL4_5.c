#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
}tPonto;

tPonto LePonto(){
    tPonto coordenadas;
    
    scanf("%d%d", &coordenadas.x, &coordenadas.y);
    
    return coordenadas;
}

float CalculaDistanciaDoisPontos(tPonto ponto1, tPonto ponto2){
    float distancia;
    
    distancia= sqrt((ponto1.x-ponto2.x)*(ponto1.x-ponto2.x) + (ponto1.y-ponto2.y)*(ponto1.y-ponto2.y));
    return distancia;
}

int main(int argc, char** argv) {
    tPonto pontoAtual, ponto;
    int qtd, i;
    float distancia;
        
    scanf("%d", &qtd);
    
    pontoAtual = LePonto();
    ponto= pontoAtual;
    printf("-\n");
    
    for(i=1; i<qtd; i++){
        
        pontoAtual = LePonto();
        distancia=CalculaDistanciaDoisPontos(pontoAtual, ponto);
        printf("%.2f\n",distancia);
        
        ponto= pontoAtual;
    }
    return (EXIT_SUCCESS);
}

