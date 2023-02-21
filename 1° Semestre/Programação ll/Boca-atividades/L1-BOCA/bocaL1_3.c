#include <stdio.h>
#include <math.h>

int main(){
    float n1, n2, n3, n4, perimetro;
    scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
    perimetro = 2*(n3-n1) + 2*(n4-n2);
    printf("%.2f\n", perimetro);
    return 0;
}
