
#ifndef TDATAS_H
#define TDATAS_H

#include "tData.h"

// Acha a menor data em um intervalo [a,b] de um vetor de datas
int AcharMenorEntreAeB(tData *vet, int a, int b);

// Ordena um vetor de datas em ordem crescente
void OrdeneDatasCrescente(tData *vet, int qtd);

// Apresenta valores de um vetor de datas
void ApresentaDatas(tData *vet, int qtd);

// Acha a maior data em um intervalo [a,b] de um vetor de ponteiros p datas
int AcharMaiorEntrePAePB(tData **vet, int a, int b);

// Ordena um vetor de ponteiros p datas
void OrdenePDatasDecrescente(tData **vet, int qtd);

// Apresenta valores de um vetor de ponteiros p datas
void ApresentaPDatas(tData **vet, int qtd);

// Copia os enderecos das datas de um vetor de datas p um vetor de ponteiros p datas
int IniciaVetorPDatas(tData **vetOut, tData *vetIn, int qtd);

#endif /* TDATAS_H */
