
// Elabore um programa que leia um n�mero de entrada () que indicar� a quantidade de n�meros a serem lidos.
// Em seguida, leia  n�meros (conforme o valor informado anteriormente) e imprima o triplo de cada um.

// biblioteca
#include <stdio.h>
int main()
{

    // variaveis
    int n;
    int lidos;
    int naoLidos = 1;
    int triplo = 3;
    int loop;

    // entrada
    while (1)
    {
        /*Questione se eh para continuar no loop*/
        printf("\n\nDigite (1) para dar inicio ao programa e (0) para sair  ): ");
        scanf("%d", &loop);

        if (loop == 1)
        {
            printf("insira a quantidade de numeros a serem lidos:\t");
            scanf("%d", &lidos);

            // processamento

            while (naoLidos <= lidos)
            {
                printf("insira o numero desejado\t");
                scanf("%d", &n);
                triplo = triplo * n;
                printf("o seu triplo �: %d\n", triplo);
                naoLidos++;
                triplo = 3;
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
