#include <stdio.h>

int main(){
int hora1,min1,seg1,hora2,min2,seg2,resultado1, resultado2;

    scanf("%d%d%d%d%d%d", &hora1,&min1,&seg1,&hora2,&min2,&seg2);
    resultado1= hora1+min1+seg1;
    resultado1= resultado1/10;
    resultado1= resultado1%10;

    resultado2= hora2+min2+seg2;
    resultado2= resultado2/10;
    resultado2= resultado2%10;

    if(hora1>hora2){
    printf("RESP:%d", resultado1);
} else if(hora2>hora1){
    printf("RESP:%d", resultado2);
}
    else{
    if(min1>min2){
    printf("RESP:%d", resultado1);
} else if(min2>min1){
    printf("RESP:%d", resultado2);
}   else{
    if(seg1>seg2){
    printf("RESP:%d", resultado1);
}   else if(seg2>seg1){
    printf("RESP:%d", resultado2);
} else{ printf("IGUAIS");}
}
}
return 0;
}
