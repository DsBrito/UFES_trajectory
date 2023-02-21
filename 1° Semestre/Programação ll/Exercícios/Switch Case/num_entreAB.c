

/*  Desenvolva um programa que leia dois valores a e b () e mostre os seguintes resultados:
    a.    Todos os entre a e b
    b.    Todos os n�meros �mpares em entre a e b.
    c.    Todos os n�meros �mpares em  m�ltiplos de 3 entre a e b
  */

#include <stdio.h>
#include <locale.h>

// fun��o principal
int main()
{

    // variaveis
    int a, b;
    int num;
    int loop;

    while (1)
    {
        /*Questione se eh para continuar no loop*/
        printf("\n\nDigite (1) para dar inicio ao programa e (0) para sair  ): ");
        scanf("%d", &loop);

        if (loop == 1)
        {
            printf("\n (1)- Quest�o a \n (2)- Quest�o b \n (3)- Quest�o c \n\n");
            printf("\n insira o numero correspondente a letra da quest�o que deseja execultar:\t\n\n");
            scanf("%d", &num);

            switch (num)
            {
            case 1:
                printf("voc� escolheu a op��o referente a todos os numeros entre "
                       "a"
                       " e "
                       "b"
                       " ( sendo "
                       "b"
                       " maior que "
                       "a"
                       ")\n\n\n");
                printf("insira o valor do menor numero:\t");
                scanf("%d", &a);
                printf("insira o valor do maior numero:\t");
                scanf("%d", &b);
                printf("os numeros entre [a,b] s�o:\n ");
                while (a < b)
                {
                    printf("%d\n", a);
                    a++;
                }
                if (a == b)
                {
                    break;
                }

            case 2:
                printf("voc� escolheu a op��o referente a os numeros  pares entre "
                       "a"
                       " e "
                       "b"
                       " ( sendo "
                       "b"
                       " maior que "
                       "a"
                       ")\n\n\n");
                printf("insira o valor do menor numero:\t");
                scanf("%d", &a);
                printf("insira o valor do maior numero:\t");
                scanf("%d", &b);
                printf("os numeros pares entre [a,b] s�o:\n ");
                while (a < b)
                {
                    if (a % 2 == 0)
                    {
                        printf("%d\n", a);
                        a++;
                    }
                    else if (a % 2 != 0)
                    {
                        a++;
                    }

                    else if (a == b)
                    {
                        break;
                    }
                }

            case 3:
                printf("voc� escolheu a op��o referente a os numeros �mpares entre "
                       "a"
                       " e "
                       "b"
                       " ( sendo "
                       "b"
                       " maior que "
                       "a"
                       ")\n\n\n");
                printf("insira o valor do menor numero:\t");
                scanf("%d", &a);
                printf("insira o valor do maior numero:\t");
                scanf("%d", &b);
                printf("os numeros �mpares entre [a,b] s�o:\n ");
                while (a < b)
                {
                    if (a % 2 != 0 || a % 3 == 0)
                    {
                        printf("os valores impares entre a e b s�o :%d\n", a);
                        a++;
                    }
                    else if (a % 2 == 0)
                    {
                        a++;
                    }
                    else if (a == b)
                    {
                        break;
                    }
                }
            }
        }

        else if (loop == 0)
        {
            break;
        }
        printf("\n\n\nInsira qualquer tecla para continuar");

        setbuf(stdin, NULL);
    }
    return 0;
}
