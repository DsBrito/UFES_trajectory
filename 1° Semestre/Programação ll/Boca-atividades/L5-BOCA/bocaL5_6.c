#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int i, k=0, qtd1, qtd2, total=0;
    int verif=0;
    
    scanf("%d", &qtd1);
    int vetA[qtd1];
    
    for(i=0; i<qtd1; i++){
        scanf("%d", &vetA[i]);
    }
    
    scanf("%d", &qtd2);
    int vetB[qtd2];
    
    for(i=0; i<qtd2; i++){
        scanf("%d", &vetB[i]);
    }
    
    for(i=0; i<qtd1; i++){
        for(k=0; k<qtd2; k++){
            if(vetA[i]==vetB[k] && verif==0){
                total++;
                verif++;
            }
        }
        verif=0;
    }
    if(total==qtd1)
        printf("TODOS");
    if(total==0)
        printf("NENHUM");
    if(total!=qtd1 && total!=0)
        printf("PARCIAL");
    return (EXIT_SUCCESS);
}

