#include <stdio.h>
int main(void)
{
   int iValor_01;
   int iResultado;
 
   printf("Entre com um numero :");
   scanf ("%d", &iValor_01);
 
   /* Se o resto da divisão for zero, o número é par.
      Exemplo: 4 dividido por 2 = 2 com resto 0 */
   if((iValor_01 % 2) == 0)
   {
      printf("Numero Par\n");
   }
   return 0;
}
