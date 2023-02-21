#include <stdio.h>

int main(){
int n1,n2;

    scanf("%d%d", &n1, &n2);

    if(n1>=1 && n1<=5){
    if(n2>=1 && n2<=5){
    if(n1==n2){
    printf("Um homem");
}
    else{
    printf("Par de homens");
}
} else if(n2<=10){
    printf("Um casal");
} else{
    printf("Invalido");
}
} else if(n1>=6 && n1<=10){
    if(n2>=6 & n2<=10){
    if(n1==n2){
    printf("Uma mulher");
} else{
    printf("Par de mulheres");
}
}
} else{
    printf("Invalido");

}
    return 0;
}
