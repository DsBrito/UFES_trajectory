

#include <stdio.h>

int main (int argc, char const *argv[]) {
    int vetA[10];
    int i, minimo, maximo;

    printf ("digite o numero na posicao 1 \n");
    scanf ("%d", &vetA[0]);
    minimo = vetA[0];
    maximo = vetA[0];

    for (i=1; i<=9; i++){
        printf ("digite o numero na posicao %d \n", (i+1));
        scanf ("%d", &vetA[i]);
        if (vetA[i]<minimo){
            minimo = vetA[i];
        }else{
        if (vetA[i]>maximo){
        maximo = vetA[i];
        }
        }
    }
    printf ("o minimo eh %d e o maximo eh %d", minimo, maximo);
    return 0;
}
