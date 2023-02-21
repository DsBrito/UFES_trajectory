#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}tPonto;

tPonto LePonto(){
    tPonto coordenadas;
    
    scanf("%d%d", &coordenadas.x, &coordenadas.y);
    
    return coordenadas;
}

void ImprimeCoordenadas(tPonto coordenadas){
    printf("(%d,%d)", coordenadas.x, coordenadas.y);
}

tPonto AlteraCoordenada(tPonto coordenadas){
    tPonto coordenadasAlteradas;
    coordenadasAlteradas.x= coordenadas.x * (-1);
    coordenadasAlteradas.y= coordenadas.y * (-1);
    
    return coordenadasAlteradas;
}

int Quadrante(tPonto coordenadas){
    if(coordenadas.x && coordenadas.y){
        if(coordenadas.x>0 && coordenadas.y>0){
            return 1;
        }
        if(coordenadas.x>0 && coordenadas.y<0){
            return 4;
        }
        if(coordenadas.x<0 && coordenadas.y>0){
            return 2;
        }
        if(coordenadas.x<0 && coordenadas.y<0){
            return 3;
        }
    }
    return 0;
}


int main(int argc, char** argv) {
    tPonto coordenadas;
    int qtd, i, quadrante1, quadrante2;
    
    scanf("%d", &qtd);
    
    for(i=0; i<qtd; i++){
        coordenadas = LePonto();
        ImprimeCoordenadas(coordenadas);
        quadrante1= Quadrante(coordenadas);
        printf(" %d ", quadrante1);
        
        coordenadas= AlteraCoordenada(coordenadas);
        ImprimeCoordenadas(coordenadas);
        quadrante2= Quadrante(coordenadas);
        printf(" %d", quadrante2);
        
        printf("\n");
    }
    
    return (EXIT_SUCCESS);
}

