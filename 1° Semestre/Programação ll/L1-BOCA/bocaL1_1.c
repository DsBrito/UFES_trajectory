#include <stdio.h>
#include <math.h>

int main(){
    int n1,n2;
    float resultado;

    scanf("%d%d", &n1, &n2);
    resultado= sqrt(n1)+ sqrt(n2);
    printf("%.2f\n", resultado);
    return 0;
}
