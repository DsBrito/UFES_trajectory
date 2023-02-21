#include <stdio.h>

int main(){
    float n1, n2, media;
    
    scanf("%f%f", &n1, &n2);

    media = (n1+n2)/2;

    if(media >= 7.0)
    printf("%.1f - Aprovado\n", media);

    else
    if(media < 5.0)
    printf("%.1f - Reprovado\n", media);

    else
    printf("%.1f - De Recuperacao\n", media);
}
