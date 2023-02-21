#include <stdio.h>
#include <math.h>

int main(){
    int x1,y1,x2,y2,x3,y3;
    
    scanf("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);

    if((x3>=x1 && x3<=x2 && y3>=y1 && y3<=y2) || (x3>=x2 && x3<=x1 && y3>=y2 && y3<=y1) || (x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2) || (x3>=x2 && x3<=x1 && y3<=y2 && y3>=y1)){
    printf("Dentro");
}
    else{
    printf("Fora");
}
    return 0;
}
