/*  APLICA��O DE UMA FOR�A */

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(void)
{

    int quantidade_Vetores; // Vari�vel para armazenar a quantidade de vetores que o usu�rio deseja inserir;
    int vetor_Velocidade[3];
    int vetores_Conjunto[3][50]; // Vetores para encontrar o Vetor Resultante
    int aux;

    // Entrada de dados referentes aos vetor velocidade:
    printf("DADOS DO VETOR VELOCIDADE: \n");
    printf("Insira o versor � do vetor: ");
    fflush(stdin);
    scanf("%d", &vetor_Velocidade[0]);
    printf("Insira o versor j do vetor: ");
    fflush(stdin);
    scanf("%d", &vetor_Velocidade[1]);
    printf("Insira o versor k do vetor: ");
    fflush(stdin);
    scanf("%d", &vetor_Velocidade[2]);
    printf("Vetor Velocidade = (%di, %dj, %dk)\n", vetor_Velocidade[0], vetor_Velocidade[1], vetor_Velocidade[2]);
    printf("--------------------------------------------------------------------------------------------------------------\n");

    // Quantidade de vetores para a an�lise:
    printf("Entre com a quantidade de vetores que serao analisados: ");
    fflush(stdin);
    scanf("%d", &quantidade_Vetores);
    aux = quantidade_Vetores;
    printf("\n");

    // Preenchendo o conjunto de vetores "soma":
    for (quantidade_Vetores; quantidade_Vetores > 0; quantidade_Vetores--)
    {
        printf("DADOS DO VETOR %d: \n", (aux + 1) - quantidade_Vetores);
        printf("Insira o versor � do vetor: ");
        fflush(stdin);
        scanf("%d", &vetores_Conjunto[0][aux - quantidade_Vetores]);
        printf("Insira o versor j do vetor: ");
        fflush(stdin);
        scanf("%d", &vetores_Conjunto[1][aux - quantidade_Vetores]);
        printf("Insira o versor k do vetor: ");
        fflush(stdin);
        scanf("%d", &vetores_Conjunto[2][aux - quantidade_Vetores]);
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("\n");
    }
    quantidade_Vetores = aux;

    for (aux; quantidade_Vetores > 0; quantidade_Vetores--)
    {
        printf("Os vetores (%d�, %dj, %dk) ", vetores_Conjunto[0][aux - quantidade_Vetores], vetores_Conjunto[1][aux - quantidade_Vetores], vetores_Conjunto[2][aux - quantidade_Vetores]);
        if (((vetor_Velocidade[0] == 0) && (vetor_Velocidade[1] == 0) && (vetor_Velocidade[2] != 0)) && ((vetores_Conjunto[0][aux - quantidade_Vetores] == 0) && (vetores_Conjunto[1][aux - quantidade_Vetores] == 0) && (vetores_Conjunto[2][aux - quantidade_Vetores] != 0)))
        {
            printf("e o Velocidade s�o paralelos, logo n�o � movimento circular\n");
        }
        else if (((vetor_Velocidade[0] == 0) && (vetor_Velocidade[1] != 0) && (vetor_Velocidade[2] == 0)) && ((vetores_Conjunto[0][aux - quantidade_Vetores] == 0) && (vetores_Conjunto[1][aux - quantidade_Vetores] != 0) && (vetores_Conjunto[2][aux - quantidade_Vetores] == 0)))
        {
            printf("e o Velocidade s�o paralelos, logo n�o � movimento circular\n");
        }
        else if (((vetor_Velocidade[0] != 0) && (vetor_Velocidade[1] == 0) && (vetor_Velocidade[2] == 0)) && ((vetores_Conjunto[0][aux - quantidade_Vetores] != 0) && (vetores_Conjunto[1][aux - quantidade_Vetores] == 0) && (vetores_Conjunto[2][aux - quantidade_Vetores] == 0)))
        {
            printf("e o Velocidade s�o paralelos, logo n�o � movimento circular\n");
        }
        else if (((vetor_Velocidade[0] == 0) && (vetor_Velocidade[1] == 0) && (vetor_Velocidade[2] == 0)) || ((vetores_Conjunto[0][aux - quantidade_Vetores] == 0) && (vetores_Conjunto[1][aux - quantidade_Vetores] == 0) && (vetores_Conjunto[2][aux - quantidade_Vetores] == 0)))
        {
            printf("e o Velocidade s�o ortogonais e paralelos, logo h� MCUV\n");
        }
        else if (((vetor_Velocidade[0] / vetores_Conjunto[0][aux - quantidade_Vetores]) == (vetor_Velocidade[1] / vetores_Conjunto[1][aux - quantidade_Vetores])) && (vetor_Velocidade[0] / vetores_Conjunto[0][aux - quantidade_Vetores] == vetor_Velocidade[2] / vetores_Conjunto[2][aux - quantidade_Vetores]))
        {
            printf("e o Velocidade s�o paralelos, logo n�o � movimento circular\n");
        }
        else if (((vetor_Velocidade[0] * vetores_Conjunto[0][aux - quantidade_Vetores]) + (vetor_Velocidade[1] * vetores_Conjunto[1][aux - quantidade_Vetores]) + (vetor_Velocidade[2] * vetores_Conjunto[2][aux - quantidade_Vetores])) == 0)
        {
            printf("e o Velocidade s�o ortogonais, logo existe MCU\n");
        }
        else
        {
            printf("e o Velocidade n�o s�o ortogonais e nem paralelos, logo h� MC\n");
        }
    }

    return 0;
}
