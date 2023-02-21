#include <stdio.h>
#include "tMessage.h"

void MsgRequisitaDados(char *msg)
{
    printf("%s\n", msg);
    // printf("DADOS:%s\n", msg);
}

void MsgSaida(char *msg)
{
    printf("%s\n", msg);
    // printf("SAIDA: %s\n", msg);
}

void MsgErro(char *msg)
{
    printf("%s\n", msg);
    // printf("ERRO:%s\n", msg);
}
