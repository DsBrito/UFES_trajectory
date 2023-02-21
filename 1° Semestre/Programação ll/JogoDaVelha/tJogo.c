#include "tJogo.h"
#include <stdio.h>

int AcabouJogo(tJogo *jogo);

void CriaJogo(tJogo *jogo)
{

    CriaTabuleiro(&(jogo->tabuleiro));
    CriaJogador(&(jogo->jogador1), ID_JOGADOR_1);
    CriaJogador(&(jogo->jogador2), ID_JOGADOR_2);
}

void ImprimeT()
{
    printf("                          (0,0)  (1,0)  (2,0)\n");
    printf("                          (0,1)  (1,1)  (2,1)\n");
    printf("                          (0,2)  (1,2)  (2,2)\n");
}

void ComecaJogo(tJogo *jogo)
{
    int jogador1Venceu = 0, jogador2Venceu = 0;
    printf("Posições do Tabuleiro: (x,y)\n");
    ImprimeT();

    while (1)
    {

        JogaJogador(&(jogo->jogador1), &(jogo->tabuleiro));
        jogador1Venceu = VenceuJogador(&(jogo->jogador1), &(jogo->tabuleiro));
        ImprimeTabuleiro(&(jogo->tabuleiro));
        if (jogador1Venceu || AcabouJogo(jogo))
            break;
        JogaJogador(&(jogo->jogador2), &(jogo->tabuleiro));
        jogador2Venceu = VenceuJogador(&(jogo->jogador2), &(jogo->tabuleiro));
        ImprimeTabuleiro(&(jogo->tabuleiro));
        if (jogador2Venceu || AcabouJogo(jogo))
            break;
    }

    if (jogador1Venceu)
        MsgSaida("JOGADOR 1 Venceu!");
    else if (jogador2Venceu)
        MsgSaida("JOGADOR 2 Venceu!");
    else
        MsgSaida("Sem vencedor!");
}

int AcabouJogo(tJogo *jogo)
{
    return !TemPosicaoLivreTabuleiro(&(jogo->tabuleiro));
}
