

#include <stdio.h>
#include <stdlib.h>
#include "tJogo.h"
#include "tMessage.h"
/*
 *
 */
int Continua()
{
    char simounao = '\0';
    while (simounao != 's' && simounao != 'n')
    {
        MsgRequisitaDados("Jogar novamente? (s,n)");

        scanf("%*[^sn]");
        scanf("%c", &simounao);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    if (simounao == 's')
        return 1;
    else
        return 0;
}

tJogo jogo;
int main(int argc, char **argv)
{

    do
    {
        CriaJogo(&jogo);

        ComecaJogo(&jogo);

    } while (Continua());

    return (EXIT_SUCCESS);
}
