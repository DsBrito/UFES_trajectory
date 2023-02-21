// Esse include eh necessario para que o usuario do tipo saiba como utiliza-lo
// Percebam que o usuario do tipo nao precisa conhecer a implementacao
#include "tData.h"
#include "tDatas.h"

#include <stdio.h>
#define TAM 5
int main()
{
    tData datas[TAM];

    // Le e apresenta as datas

    printf("Entrada teste de cinco datas (para  alterar a quantidade de datas a serem lidas, deve alterar a variavel global TAM)\n\n  ");

    for (int i = 0; i < TAM; i++)
    {
        LeData(&datas[i]);
    }

    ApresentaDatas(datas, TAM);

    // Ordena e apresenta as datas
    printf("Datas em ordem crescente:\n\n  ");
    OrdeneDatasCrescente(datas, TAM);
    ApresentaDatas(datas, TAM);

    // Cria uma copia das referencias das datas
    tData *datasP[TAM];
    IniciaVetorPDatas(datasP, datas, TAM);

    // Ordena a referencia
    OrdenePDatasDecrescente(datasP, TAM);
    // Apresenta as datas referencias ordenadas em ordem decrescente
    printf("Datas referencias ordenadas em ordem decrescente:\n\n  ");
    ApresentaPDatas(datasP, TAM);
    // Apresenta as datas referencias ordenadas em ordem crescente
    printf("Datas referencias ordenadas em ordem crescente:\n\n  ");

    ApresentaDatas(datas, TAM);

    return 0;
}
