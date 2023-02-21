#include <stdio.h>

int main(){
int n1,n2;
char op,esp1,esp2;

  scanf("%d%c%c%c%d", &n1,&esp1,&op,&esp2,&n2);

  switch (op) {
    case '+':
    printf("SOMA:%d\n", n1+n2);
    break;

    case '-':
    printf("SUB:%d\n", n1-n2);
    break;

    case '*':
    printf("MULT:%d\n", n1*n2);
    break;

    case '/':
    if(n1%n2){
      printf("DIV:%d, RESTO:%d\n", n1/n2, n1%n2 );

    }else {printf("DIV:%d\n",n1/n2 );}
  }
}
