#include <stdio.h>

int main(){
    int a, b, x1, y1, x2, y2, x3, y3, c, d, e;

    scanf("%d%d%d%d%d%d%d%d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);
    
    c = (a*x1)+b;
    d = (a*x2)+b;
    e = (a*x3)+b;

    if(y1==c && y2==d && y3==e){
    printf("Todos");
}
    else if((y1!=c && y2==d && y3==e) || (y1==c && y2!=d && y3==e) || (y1==c && y2==d && y3!=e)){
    printf("Dois");
}
    else if((y1!=c && y2!=d && y3==e) || (y1==c && y2!=d && y3!=e) || (y1!=c && y2==d && y3!=e)){
    printf("Um");
}
    else {
    printf("Nenhum");
}
    return 0;
}
