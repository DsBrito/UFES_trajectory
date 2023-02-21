#include <stdio.h>

int main(){
    int n1;
    char l0, l1, l2;

    scanf("%c%d%c%c", &l0, &n1, &l1, &l2);
    if(l0>='A' && l0<='Z' && n1>=0 && n1<=9 && (l1 == 'a' || l1 == 'e'|| l1 == 'i' || l1 == 'o'|| l1 == 'u' || l1 == 'A'|| l1 == 'E'|| l1 == 'I'|| l1 == 'O'|| l1 == 'U') && l2>='a' && l2<='z'){

l2= 'A' + (l2 - 'a');

    if(l1 == 'A'|| l1 == 'E'|| l1 == 'I'|| l1 == 'O'|| l1 == 'U'){
    printf("%c%d%c%c", l0, n1,l1,l2);
}

else{
l1= 'A' + (l1 - 'a');
    printf("%c%d%c%c", l0, n1,l1,l2);
}
}
 else{
    printf("Invalido");
}
    return 0;
}
