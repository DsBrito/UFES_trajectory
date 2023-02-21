#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int tam;
    int num[7][7];
    
}tCartela;

tCartela LeCartela();
void ImprimeCartela(tCartela cartela);

int main(){
    tCartela cartela;
    
    cartela = LeCartela();
    ImprimeCartela(cartela);
    
    return 0;
}

tCartela LeCartela(){
    tCartela cartela;
    int i, j;
    scanf("%d", &cartela.id);
    scanf("%d", &cartela.tam);
    
    for(i=0; i<cartela.tam; i++){
        for(j=0; j<cartela.tam; j++){
            scanf("%d", &cartela.num[j][i]);
        }
    }
    return cartela;
}

void ImprimeCartela(tCartela cartela){
    int i, j;
    
    printf("ID:%d\n", cartela.id);
    
    for(i=0; i<cartela.tam; i++){
        for(j=0; j<cartela.tam; j++){
            if(j!=0)
                printf("|%03d", cartela.num[i][j]);
            else
                printf("%03d", cartela.num[i][j]);
        }
        printf("\n");
    }
}