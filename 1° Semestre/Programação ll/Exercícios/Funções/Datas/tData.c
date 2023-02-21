#include "tData.h"
#include <stdio.h>
#include <stdlib.h>

void InicializaDataParam(tData *data, int a_dia, int a_mes, int a_ano)
{
    int qtdDiasNoMes;

    data->ano = a_ano;

    // Garante que o mes esta entre 1 e 12
    if (a_mes > 12)
    {
        a_mes = 12;
    }
    else if (a_mes < 1)
    {
        a_mes = 1;
    }
    data->mes = a_mes;

    // Garante que o dia esta dentro dos limites permitidos para o mes
    qtdDiasNoMes = InformaQtdDiasNoMes(data);
    if (a_dia > qtdDiasNoMes)
    {
        a_dia = qtdDiasNoMes;
    }
    else if (a_dia < 1)
    {
        a_dia = 1;
    }
    data->dia = a_dia;
}

void LeData(tData *data)
{
    int d, m, a;
    // Le a data do teclado
    // OBS:Se nao for para o BOCA, pode ter um printf pedindo para digitar a data
    printf("Data no formato DD/MM/AAAA:  ");

    if (scanf("%d %d %d", &d, &m, &a) != 3)
    {
        printf("ERRO: Formato de entrada nao compativel!\n");
        exit(1);
    }

    // Inicializa a data e garante q eh vailida
    InicializaDataParam(data, d, m, a);
}

void ImprimeData(tData *a_data)
{
    printf("'%02d/%02d/%04d'", a_data->dia, a_data->mes, a_data->ano);
}

// Funcao auxiliar para verificar se o ano e bisexto
int EhBissextoAno(int a_ano)
{
    if (!(a_ano % 400))
    {
        return 1;
    }
    if (!(a_ano % 100))
    {
        return 0;
    }
    if (!(a_ano % 4))
    {
        return 1;
    }
    return 0;
}

int EhBissexto(tData *a_data)
{
    int rtn;
    rtn = EhBissextoAno(a_data->ano);
    return rtn;
}

// Funcao auxiliar para informar a quantidade de dias no mes, dado o mes e o ano
int InformaQtdDiasNoMesMA(int a_mes, int a_ano)
{
    if (a_mes == 4 || a_mes == 6 || a_mes == 9 || a_mes == 11)
    {
        return 30;
    }
    if (a_mes == 2)
    {
        if (EhBissextoAno(a_ano))
        {
            return 29;
        }
        return 28;
    }
    return 31;
}

int InformaQtdDiasNoMes(tData *a_data)
{
    int rtn;
    rtn = InformaQtdDiasNoMesMA(a_data->mes, a_data->ano);
    return rtn;
}

void AvancaParaDiaSeguinte(tData *a_data)
{
    if (a_data->dia < InformaQtdDiasNoMes(a_data))
    {
        a_data->dia++;
    }
    else
    {
        a_data->dia = 1;
        if (a_data->mes < 12)
        {
            a_data->mes++;
        }
        else
        {
            a_data->mes = 1;
            a_data->ano++;
        }
    }
}

int EhIgual(tData *a_data1, tData *a_data2)
{
    return a_data1->dia == a_data2->dia &&
           a_data1->mes == a_data2->mes &&
           a_data1->ano == a_data2->ano;
}

int EhMenorDataAqDataB(tData *a, tData *b)
{
    if (a->ano < b->ano)
        return 1;
    else if (a->ano == b->ano && a->mes < b->mes)
        return 1;
    else if (a->ano == b->ano && a->mes == b->mes && a->dia < b->dia)
        return 1;

    return 0;
}
