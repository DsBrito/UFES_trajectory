#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int qtd1, qtd2, i, j=0;
    
    scanf("%d", &qtd1);
    int vet1[qtd1];
    for(i=0; i<qtd1; i++){
        scanf("%d", &vet1[i]);
    }
    
    scanf("%d", &qtd2);
    int vet2[qtd2];
    for(i=0; i<qtd2; i++){
        scanf("%d", &vet2[i]);
    }
    
    //parear listas
    printf("PARES:\n");
    for(i=0; i<qtd1; i++){
        if(j != qtd2){
            printf("%d - %d\n", vet1[i], vet2[j]);
        }
        if(j== qtd2){
            j=0;
            printf("%d - %d\n", vet1[i], vet2[j]);
        }
        j++;
    }
    
    return (EXIT_SUCCESS);
}

