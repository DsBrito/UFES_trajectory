/* programa goto.c */
#include <stdio.h>
int main (void)
{
   int iValor_a;
   int iValor_b;
 
   while(1)
   {
      printf ("Valore a:");
      scanf ("%d", &iValor_a);
      printf ("Valore b:");
      scanf ("%d",&iValor_b);
      if (iValor_a == 0)
      {
         goto fim;
      }
 
      if (iValor_b == 0) /* Caso seja informado 0 para iValor_b o programa é desviado para o label erro através do comando goto */
      {
         goto erro;
      }
      printf ("Dvivisão inteira : %d\n", iValor_a / iValor_b);
      printf ("Resto da divisão : %d\n", iValor_a % iValor_b);
   }
 
erro: /* executando somente se for informado valor 0 para iValor_b */
   printf ("Divisao por zero\n");
 
fim: /* esta linha é executada sempre, pois todos os comandos após um label goto serão interpretados.
        Mesmo que faça parte de outro label goto */
   printf ("goto - Fim da execucao do programa\n");
 
   return 0;
}
