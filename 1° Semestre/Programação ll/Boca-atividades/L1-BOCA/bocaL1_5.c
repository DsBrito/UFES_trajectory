#include <stdio.h>
#include <math.h>

int main(){
    int n1, n2;
    
    scanf("%d%d", &n1, &n2);

    if(n1==n2){
    printf("N1 = N2\n");
}
    if(n1>n2){
    printf("N1 = %d\n", n1);
}
    if(n2>n1){
    printf("N2 = %d\n", n2);
}
}
