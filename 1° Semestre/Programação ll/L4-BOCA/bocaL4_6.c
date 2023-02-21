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
    int qtd, i;
    float distancia1, distancia2;
    tPonto ponto, pontoIni, pontoFin;
    
    scanf("%d", &qtd);
    
    for(i=0; i<qtd; i++){
        ponto= LePonto();
        pontoIni= LePonto();
        pontoFin= LePonto();
        
        distancia1= CalculaDistanciaDoisPontos(ponto, pontoIni);
        distancia2= CalculaDistanciaDoisPontos(ponto, pontoFin);
        
        if(distancia1<distancia2){
            printf("INICIO\n");
        }
        if(distancia1>distancia2){
            printf("FIM\n");
        }
        else if(distancia1==distancia2){
            printf("EQUIDISTANTE\n");
        }
    }
    return (EXIT_SUCCESS);
}

