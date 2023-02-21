
#ifndef TJOGADOR_H
#define TJOGADOR_H

#include "tTabuleiro.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

typedef struct
{
    int id;
    char nome[1000]; // Para dar nome ao jogador
} tJogador;

void CriaJogador(tJogador *jogador, int idJogador);

void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro);

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro);

#endif /* TJOGADOR_H */
