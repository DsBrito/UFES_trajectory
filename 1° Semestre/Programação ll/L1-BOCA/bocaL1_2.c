#include <stdio.h>

int main(){
    float l1, l2,perimetro;

    scanf("%f%f", &l1, &l2);
    perimetro= 2*l1 + 2*l2;
    printf("%.2f\n", perimetro);
    return 0;
}
