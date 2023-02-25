/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: diona
 *
 * Created on 18 de Abril de 2021, 19:49
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    
    tAluno* bruna = IniciaAluno(312,"bruna",10);
    tAluno* diego = IniciaAluno(241,"diego",5);
    tAluno* kassio = IniciaAluno(453,"kassio",6);
    tAluno* ezio = IniciaAluno(892,"ezio",9);
    tAluno* erika = IniciaAluno(333,"erika",9);
    tAluno* bruno = IniciaAluno(223,"bruno",9);

    
    tArvore* f =arv_cria(bruna,
                arv_cria(diego,
                arv_criaVazia(),
                arv_cria(ezio,arv_criaVazia(),
                arv_criaVazia())
                ),
                arv_cria(kassio,
                arv_cria(erika,arv_criaVazia(),
                arv_criaVazia()),
                arv_cria(bruno,arv_criaVazia(),
                arv_criaVazia())
                )
             );


    printf("\nImprimindo fila f:\n");
    arv_imprime(f);
    
 
    int pert;
    pert= arv_pertence(f,"kassio");
    printf("\n O aluno diego pertence? %d",pert);
 
    pert= arv_pertence(f,"thiago");
    printf("\n O aluno thiago pertence? %d",pert);
 
  
    
    int fol;
    fol= folhas(f);
    printf("\nNumero de folhas da arvore :%d\n",fol);
    
    int ocor= ocorrencias(f,"ezio");
    printf("\nNumero de ocorrencias de ezio na arvore :%d\n",ocor);

    
    tArvore* pai = arvore_pai(f,"kassio");
    printf("\nPai do no kassio eh :%s\n",RetornaNomeAluno(info(pai)));
   
    
    int alt = altura(f);
    
    printf(" a altura da arvore eh: %d", alt);
    
    DestroiAluno(bruna);
    DestroiAluno(diego);
    DestroiAluno(kassio);
    DestroiAluno(ezio);
    
    arv_libera(f);
    
    
    return 0;
}
