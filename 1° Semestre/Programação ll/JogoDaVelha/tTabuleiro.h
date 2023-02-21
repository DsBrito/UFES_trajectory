

#ifndef TTABULEIRO_H
#define TTABULEIRO_H

#define TAM_TABULEIRO 3

#define PECA_1 1
#define PECA_2 2

typedef struct
{
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;

void CriaTabuleiro(tTabuleiro *tabuleiro);

void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y);

int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro);

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca);

int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y);

int EhPosicaoValidaTabuleiro(tTabuleiro *tabuleiro, int x, int y);

int ImprimeTabuleiro(tTabuleiro *tabuleiro);

#endif /* TTABULEIRO_H */
