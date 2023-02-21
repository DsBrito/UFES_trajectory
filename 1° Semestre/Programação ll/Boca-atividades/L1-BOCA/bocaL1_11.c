#include <stdio.h>

int main(){
    int n1;

    scanf("%d", &n1);

    if(n1 == 1)
    printf("Jan.");

    if(n1 == 2)
    printf("Fev.");

    if(n1 == 3)
    printf("Mar.");

    if(n1 == 4)
    printf("Abr.");

    if(n1 == 5)
    printf("Mai.");

    if(n1 == 6)
    printf("Jun.");

    if(n1 == 7)
    printf("Jul.");

    if(n1 == 8)
    printf("Ago.");

    if(n1 == 9)
    printf("Set.");

    if(n1 == 10)
    printf("Out.");

    if(n1 == 11)
    printf("Nov.");

    if(n1 == 12)
    printf("Dez.");

    if(n1>12 || n1<1)
    printf("Invalido.");

    return 0;
}
