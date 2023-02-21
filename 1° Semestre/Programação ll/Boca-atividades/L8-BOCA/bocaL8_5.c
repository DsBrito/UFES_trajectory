#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num1, num2;
    char op, espaco;
    
    scanf("%d%d", &num1, &num2);
    scanf("%c%c", &espaco, &op);
    switch(op)
    {
    case '+':
     printf("RESP:%d", num1+num2);
     break;
    case '-':
     printf("RESP:%d", num1-num2);
     break;
    case '*':
    case 'x':
     printf("RESP:%d", num1*num2);
     break;
    case '/':
    case':':
     printf("RESP:%d", num1/num2);
     break;
    default:
     printf("Invalido");
    break;
    }
    return 0;
}
