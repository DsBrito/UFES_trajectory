#include <stdio.h>
#include "tJogador.h"
#include "tMessage.h"

void CriaJogador(tJogador *jogador, int idJogador)
{
    jogador->id = idJogador;

    printf("Digite o nome do jogador %d:", jogador->id); // Para dar nome ao jogador
    scanf("%s", jogador->nome);                          // Para dar nome ao jogador
}

int LePosicao(int *x, int *y)
{

    MsgRequisitaDados("Digite uma posicao (x e y):");
    int rtn = scanf("%d %d", x, y);
    if (rtn != 2)
    {
        return 0;
    }
    return 1;
}

void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    int x, y, livre = 0, valida = 0;
    char msg[1000];
    //   sprintf(msg, "Jogador %d (%s)", jogador->id, jogador->nome); // Para dar nome ao jogador (trocar pela linha abaixo)
    sprintf(msg, "Jogador %d ", jogador->id);
    do
    {
        MsgRequisitaDados(msg);
        if (!LePosicao(&x, &y))
        {
            scanf("%*[^\n]");
            scanf("%*c");
            MsgRequisitaDados("Formato invalido!");
            continue;
        }

        valida = EhPosicaoValidaTabuleiro(tabuleiro, x, y);
        if (valida)
        {
            livre = EstaLivrePosicaoTabuleiro(tabuleiro, x, y);
            if (!livre)
            {
                MsgRequisitaDados("Posicao invalida (OCUPADA)!");
            }
        }
        else
            MsgRequisitaDados("Posicao invalida (FORA DO TABULEIRO)!");
    } while (!valida || !livre);
    int peca = (jogador->id == ID_JOGADOR_1 ? PECA_1 : PECA_2);
    MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);
}

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    int peca = (jogador->id == ID_JOGADOR_1 ? PECA_1 : PECA_2);
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca))
    {
        return 1;
    }
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca))
    {
        return 1;
    }
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca))
    {
        return 1;
    }
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca))
    {
        return 1;
    }
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca))
    {
        return 1;
    }
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca))
    {
        return 1;
    }
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca))
    {
        return 1;
    }
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca))
    {
        return 1;
    }
    return 0;
}
