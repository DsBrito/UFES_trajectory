#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arquivo.h"
#include "ponto.h"

/*funcao para contar as linhas de um arquivo*/
int contaLinha(FILE *f, char *argv)
{
  char a;
  int cont = 0;
  f = fopen(argv, "r"); //

  a = getc(f);
  while (a != EOF)
  {
    if (a == '\n')
    {
      cont++;
    }
    a = getc(f);
  }
  fclose(f);
  return cont;
}
