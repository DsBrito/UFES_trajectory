

/* Importa��o de Bibliotecas */
#include <stdio.h>
#include <conio.h>

/* Declara��o de constantes */
#define ALUNOS 2      /* quantidade m�xima de alunos */
#define DISCIPLINAS 2 /* quantidade m�xima de disciplinas */

/* Programa Principal */
int main()
{

   /* Dicion�rio de Dados */
   int i, j;
   float coef, mediaTurma, soma;
   float media[ALUNOS][DISCIPLINAS]; /* Cada linha cont�m as m�dias de
         um aluno em um conjunto de disciplinas
         Cada coluna representa as m�dias dos alunos em uma disciplina */

   /* Solicitar dados - M�dias por alunos e por disciplinas */
   printf("Informar medias de alunos por conjunto de disciplinas\n");
   for (i = 0; i < ALUNOS; i++) /* Loop: Para cada aluno */
   {
      /* Loop: Para cada aluno, em cada disciplina que o aluno cursou */
      for (j = 0; j < DISCIPLINAS; j++)
      {
         printf("Media do aluno %d na disciplina %d: ", i + 1, j + 1);
         scanf("%f", &media[i][j]);
      }
   }

   /* Gerar informa��es de sa�da */

   /* Coeficiente de um aluno
      O somat�rio das m�dias de cada disciplina do aluno
      dividido pelo n�mero de disciplinas (soma de valores de cada
                                             linha) */
   printf("\n\n LISTAGEM DE COEFICIENTES DE ALUNOS\n");

   /* Loop: Para cada aluno */
   for (i = 0; i < ALUNOS; i++)
   {
      soma = 0;

      /* Loop: Somar acumulativamente as m�dias das disciplinas de
       um aluno */
      for (j = 0; j < DISCIPLINAS; j++)
      {
         soma = soma + media[i][j];
      }

      /* Obter e exibir o coeficiente do aluno */
      coef = soma / DISCIPLINAS;

      printf("Coeficiente do aluno %d: %f\n", i + 1, coef);
   }

   /* M�dia de uma turma
      O somat�rio das m�dias de cada aluno
      dividido pelo n�mero de alunos (soma de valores de cada coluna) */
   printf("\n\n LISTAGEM DE MEDIAS DE TURMAS\n");

   /* Loop: Para cada disciplina */
   for (j = 0; j < DISCIPLINAS; j++)
   {
      soma = 0;

      /* Loop: Somar acumulativamente as m�dias dos alunos de uma
         disciplina */
      for (i = 0; i < ALUNOS; i++)
      {
         soma = soma + media[i][j];
      }

      /* Obter e exibir a m�dia da disciplina */
      mediaTurma = soma / ALUNOS;

      printf("Media da disciplina %d: %f\n", j + 1, mediaTurma);
   }

   return 1;
}
