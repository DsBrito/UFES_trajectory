#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int tam;
    int num[7][7];
    
}tCartela;

typedef struct{
    int qtd;
    tCartela cartela[100];
    
}tPartida;

tPartida LeCartelasPartida();
void ImprimeInvCartelasPartida(tPartida partida);

int main(){
    tPartida partida;
    
    partida = LeCartelasPartida();
    ImprimeInvCartelasPartida(partida);
    
    return 0;
}

tPartida LeCartelasPartida(){
    tPartida partida;
    int i, j, k;
    scanf("%d", &partida.qtd);
    
    
    for(k=0; k<partida.qtd; k++){
        scanf("%d", &partida.cartela[k].id);
        scanf("%d", &partida.cartela[k].tam);
  
        for(i=0; i<partida.cartela[k].tam; i++){
            for(j=0; j<partida.cartela[k].tam; j++){
                scanf("%d", &partida.cartela[k].num[j][i]);
            }
        }
    }
    
    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida){
    int i, j, k,l;
    l=partida.qtd-1;
    
    for(k=0; k<partida.qtd; k++, l--){
        printf("ID:%d\n", partida.cartela[l].id);
    
        for(i=0; i<partida.cartela[l].tam; i++){
            for(j=0; j<partida.cartela[l].tam; j++){
                if(j!=0)
                    printf("|%03d", partida.cartela[l].num[i][j]);
                else
                    printf("%03d", partida.cartela[l].num[i][j]);
                }
            printf("\n");
        }
    }
}