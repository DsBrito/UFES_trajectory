
#include <stdio.h>

int main (int argc, char const *argv[]) {
    int cont, cont134;
    int i;
    int vet[100];
    cont = 0;
    for (i=0 ; i<99 ; i++) {
        printf ("digite o numero na posicao %d\n", i+1);
        scanf ("%d", &vet[i]);
        if (vet[i] == -1){
            break;
            }else{
            while (vet[i] <= 0){
                scanf ("%d", &vet[i]);
            }
            cont = (cont+1);
            }
            cont134 = 0;
    }
            for (i=0 ; i< (cont); i++) {
                if ((vet[i] ==1 ) && (vet[i+1] == 3) && (vet[i+2] == 4) ){
                    cont134 = (cont134 + 1);
                }
            }
        printf ("foram lidos %d vezes a sequencia 134", cont134);


    return 0;
}
