
#include <stdio.h>
#include<math.h>

int main (int argc, char const *argv[]) {
    float r,v,a;

    printf("digite o raio da esfera\n");
    scanf("%f", &r);
    v = ((4/3)*(M_PI)*(pow(r,3)));
    a = (4*M_PI*(pow(r,2)));
    printf("a area da esfera eh %0.3f e o volume eh %0.3f\n",a,v);

    return 0;
}
