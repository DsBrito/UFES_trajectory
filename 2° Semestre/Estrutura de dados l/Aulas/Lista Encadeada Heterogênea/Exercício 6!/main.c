/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: diona
 *
 * Created on 21 de Março de 2021, 18:12
 */

#include <stdio.h>
#include <stdlib.h>
#include "LISTA_HET.h"

/*
 * 
 */
int main() {

    
    tAluno* Musashi = IniciaAluno(2019666,"Musashi", 10);
    tAluno* Higor = IniciaAluno(2020343,"Higor", 6);
    tAluno* Pedro = IniciaAluno(2014111,"Pedro", 7);
    tAluno* Sabrina = IniciaAluno(2017123,"Sabrina", 8);
   
    tProfessor* Izac= IniciaProfessor(20203214,"Izac",99123.00);
    tProfessor* Leandro= IniciaProfessor(2015582,"Leandro",92133.00);

    
    ListaHet* churrasco= IniciaLista();
    
    InsereAluno(churrasco,Musashi);
    InsereAluno(churrasco,Higor);
    InsereAluno(churrasco,Pedro);
    InsereAluno(churrasco,Sabrina);
    InsereProfessor(churrasco,Izac);
    InsereProfessor(churrasco,Leandro);

    printf("\nImprimindo a lista:\n");
    ImprimeListaHet(churrasco);
    
    printf("\nVALOR: %.2f", ValorChurrasco(churrasco));
    
    DestroiLista(churrasco);
    
    DestroiAluno(Musashi);
    DestroiAluno(Higor);
    DestroiAluno(Pedro);
    DestroiAluno(Sabrina);
    
    DestroiProfessor(Izac);
    DestroiProfessor(Leandro);
    
    return 0;
}

