#include <stdio.h>

int main(){
int n1, n2;

    scanf("%d %d", &n1, &n2);
    if(n2 == 1){
    if(n1%2 == 0){
    printf("PAR");
}
else{ 
    printf("IMPAR");
}
}
else if(n2 == 2){
n1 = n1/10;
    if(n1%2 == 0){
    printf("PAR");
}
else{ 
    printf("IMPAR");
}
}
else if(n2 == 3){
n1 = n1/100;
    if(n1%2 == 0){
    printf("PAR");
}
else{ 
    printf("IMPAR");
}
}
    return 0;
}
