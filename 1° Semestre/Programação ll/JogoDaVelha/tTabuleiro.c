#include "tTabuleiro.h"
#include "tMessage.h"

void CriaTabuleiro(tTabuleiro *tab){
    int i, j;
    
    tab->peca1 = 'X';
    tab->peca2 = '0';
    tab->pecaVazio = '-';
    for (i = 0; i < TAM_TABULEIRO; i++){
        for (j = 0; j < TAM_TABULEIRO; j++){
            tab->posicoes[i][j] = tab->pecaVazio;
        }
    }
}

void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y){
    if (peca == PECA_1){
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    } else if (peca == PECA_2){
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
    } else {
        MsgErro("Jogador invalido!");
    }
    
}

int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro){
    int i, j;
    for (i = 0; i < TAM_TABULEIRO; i++){
        for (j = 0; j < TAM_TABULEIRO; j++){
            if ( tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio )
                return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca){
    if (peca == PECA_1)
        return tabuleiro->posicoes[y][x] == tabuleiro->peca1;
    else if (peca == PECA_2)
        return tabuleiro->posicoes[y][x] == tabuleiro->peca2;

    MsgErro("Jogador Invalido!");
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y){
    return tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio;
}

int EhPosicaoValidaTabuleiro(tTabuleiro *tabuleiro, int x, int y){
    return  0 <= y && y < TAM_TABULEIRO &&
            0 <= x && x < TAM_TABULEIRO;
}

int ImprimeTabuleiro(tTabuleiro *tabuleiro){
    int i, j;
    char linha[4] = "   ";
    char linhaSaida[5] = "\t   ";
    for (i = 0; i < TAM_TABULEIRO; i++){
        for (j = 0; j < TAM_TABULEIRO; j++){
            linha[j] = tabuleiro->posicoes[i][j];
        }
        linhaSaida[1] = linha[0]; 
        linhaSaida[2] = linha[1]; 
        linhaSaida[3] = linha[2]; 
        MsgSaida(linhaSaida);
    }
}
