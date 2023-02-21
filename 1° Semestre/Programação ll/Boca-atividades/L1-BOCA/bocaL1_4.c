#include <stdio.h>
#include <math.h>

int main(){
    float r1, r2, a1, a2;
    
    scanf("%f", &r1);

    a1 = 3.141592*r1*r1;
    r2 = sqrt(a1/(2*3.141592));

    printf("%.2f %.2f\n", a1, r2);
    return 0;
}
