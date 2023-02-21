// Fa�a um programa que leia um valor  indicando a quantidade de valores a ler em seguida.
// Um n�mero deve ser lido por vez e seu programa deve classific�-lo como positivo ou negativo

// biblioteca

#include <stdio.h>
int main()
{

    // variaveis
    int n;
    int lidos;
    int naoLidos = 0;
    int loop;

    // ENTRADA
    while (1)
    {
        /*Questione se eh para continuar no loop*/
        printf("\n\nDigite (1) para dar inicio ao programa e (0) para sair  ): ");
        scanf("%d", &loop);

        if (loop == 1)
        {
            printf("insira a quantidade de numeros a serem lidos:\t");
            scanf("%d", &lidos);

            // PROCESSAMENTO

            while (naoLidos <= lidos)
            {
                printf("insira o numero desejado\t");
                scanf("%d", &n);
                if (n < 0)
                {
                    printf("este numero eh negativo: %d\n", n);
                }
                else if (n > 0)
                {
                    printf("este numero eh positivo : %d\n", n);
                }
                else
                {
                    printf("este numero esta entre o negativo e o positivo : %d\n", n);
                }
                naoLidos++;
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
