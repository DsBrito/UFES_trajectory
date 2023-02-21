#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int cont(char *s)
// VE SE AMBOS LADOS SAO IGUAIS
{
   int i, j;
   for (i = 0, j = strlen(s) - 1; i < j; i++, j--)

      if (s[i] != s[j])

         return 0;

   return 1;
}

int main()
{
   char texto[100];
   printf("\nDigite o texto:");
   gets(texto);
   printf("%d", cont(texto));

   getch();
   return 1;
}
