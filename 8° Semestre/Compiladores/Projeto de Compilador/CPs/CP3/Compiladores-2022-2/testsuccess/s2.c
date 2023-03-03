/*
Teste de loops (while - do while) e break
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (void )
{
  int loop;
  int loop_while = 1; 
  int loop_do_while = 0;
  int soma = 0;
  char string[20];

  strcpy (string, "Hello World\n");

  printf ("Loops:\n 1 (do while)\n 2 (while)\nDigite: ");
  scanf("%d", &loop);
  
  switch (loop) {
    case 1 : // opcao do while
        while(loop_do_while >= 0 ){
        printf("Digite um numero positivo para ser somado com [ %d ] ou negativo para sair: ",loop_do_while);
        scanf("%d", &loop_do_while);
        if( loop_do_while >= 0 ){
            soma = soma + loop_do_while;
            printf("A soma eh %d\n", soma);
            }
        }
    break;
    
    case 2 : // opcao while
        while(loop_while <= 10){            
            printf("while: %d\n", loop_while);       
            loop_while = loop_do_while + 1;                    
        }
    break;
      
    default :
    printf ("Valor invalido!\n");
  }
  return 0;
}