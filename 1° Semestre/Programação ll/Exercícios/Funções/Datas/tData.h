#ifndef TDATA_H
#define	TDATA_H

//Estrutura para armazenar uma data
typedef struct {
    int dia; //Dia da data
    int mes; //Mes da data
    int ano; //Ano da data
} tData;

//Retorna uma data valida a partir do dia, mes e ano informados
void InicializaDataParam( tData *data, int a_dia, int a_mes, int a_ano);

//Le uma data da entrada padrao 
//considerando o dia, mes e ano separados por um espaco
void LeData( tData *data );

//Imprime na saida padrao a data informada 
void ImprimeData( tData *a_data );

//Retorna verdadeiro se o ano for bisexto, ou falso caso contrario
int EhBissexto( tData *a_data );

//Retorna a quantidade de dias contido no mes da data em questao
int InformaQtdDiasNoMes( tData *a_data );

//Retorana o dia postarior ao da data informada
void AvancaParaDiaSeguinte( tData *a_data );

//Retorna verdadeiro se as datas forem iguais, ou falso caso contrario
int EhIgual( tData *a_data1, tData *a_data2 );

int EhMenorDataAqDataB(tData *a, tData *b);

#endif	/* TDATA_H */

