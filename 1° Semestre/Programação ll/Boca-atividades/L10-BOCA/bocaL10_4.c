#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int qtdPassageiros;
    char tipo[101];
    int km;
    
}tCarro;

typedef struct{
    int qtd;
    tCarro carro[100];
}tConcessionaria;

tCarro LeCarro();
void ImprimeCarro(tCarro carro);
int ObtemNumPassageirosCarro(tCarro carro);
int ObtemKmCarro(tCarro carro);
tConcessionaria LeCarrosConcessionaria();
void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);

int main(){
    tConcessionaria concessionaria;
    
    concessionaria = LeCarrosConcessionaria();
    
    int qtdPassageiros, km, i = 0;
    while(scanf("%d,%d", &qtdPassageiros, &km) == 2){
        printf("Caso %d:\n", ++i);
        ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);
    }
    
    return 0;
}

tCarro LeCarro(){
    tCarro carro;
    
    scanf("%d", &carro.id);
    scanf("%d", &carro.qtdPassageiros);
    scanf("%s", carro.tipo);
    scanf("%d", &carro.km);
    
    return carro;
}

void ImprimeCarro(tCarro carro){
    printf("CARRO (%d): %s de %d passageiros e com %d km\n", carro.id, carro.tipo, carro.qtdPassageiros, carro.km);
}

int ObtemNumPassageirosCarro(tCarro carro){
    return carro.qtdPassageiros;
}

int ObtemKmCarro(tCarro carro){
    return carro.km;
}

tConcessionaria LeCarrosConcessionaria(){
    int qtd, i;
    tConcessionaria concessionaria;
    
    scanf("%d", &concessionaria.qtd);
    qtd=concessionaria.qtd;
    
    tCarro carroX;
    for(i=0; i<qtd; i++){
        carroX = LeCarro();
        concessionaria.carro[i]= carroX;
    }
    
    return concessionaria;
}

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km){
    int i;
    
    for(i=0; i<concessionaria.qtd; i++){
        if(pass== ObtemNumPassageirosCarro(concessionaria.carro[i]) && ObtemKmCarro(concessionaria.carro[i])<= km && pass!=-1 && km!=-1)
            ImprimeCarro(concessionaria.carro[i]);
        
        if(ObtemKmCarro(concessionaria.carro[i])<= km && pass==-1 && km!=-1)
            ImprimeCarro(concessionaria.carro[i]);
        
        if(pass== ObtemNumPassageirosCarro(concessionaria.carro[i]) && pass!=-1 && km==-1)
            ImprimeCarro(concessionaria.carro[i]);
        
        if(pass==-1 && km==-1)
            ImprimeCarro(concessionaria.carro[i]);
    }
    
}