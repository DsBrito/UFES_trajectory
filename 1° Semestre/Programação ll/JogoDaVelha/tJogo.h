

#ifndef TJOGO_H
#define TJOGO_H
#include "tTabuleiro.h"
#include "tJogador.h"

typedef struct
{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;

} tJogo;

void CriaJogo(tJogo *jogo);

void ComecaJogo(tJogo *jogo);

void ImprimeT();
#endif /* TJOGO_H */
