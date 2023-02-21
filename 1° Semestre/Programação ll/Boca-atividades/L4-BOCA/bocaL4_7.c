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

int VerificaQuadrante(tPonto ponto1, tPonto ponto2){
    if(ponto1.x==0 || ponto1.y==0 || ponto2.x==0 || ponto2.y==0){
        return 0;
    }
    if((ponto1.x>0 && ponto2.x>0) || ((ponto1.x<0 && ponto2.x<0))){
        if((ponto1.y>0 && ponto2.y>0) || ((ponto1.y<0 && ponto2.y<0))){
            return 1;
        }
        return 0;
    }
    return 0;
}


int main(int argc, char** argv) {
    int qtd, i;
    tPonto ponto1, ponto2;
    
    scanf("%d", &qtd);
    
    for(i=0; i<qtd; i++){
        ponto1= LePonto();
        ponto2= LePonto();
        if(VerificaQuadrante(ponto1, ponto2)){
            printf("MESMO\n");
        }
        else{
            printf("DIFERENTE\n");
        }
    }
    return (EXIT_SUCCESS);
}

