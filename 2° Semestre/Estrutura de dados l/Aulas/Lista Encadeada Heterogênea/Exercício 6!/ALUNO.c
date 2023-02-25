#include<stdio.h>
#include<stdlib.h>
#include"ALUNO.h"
#include<string.h>


struct aluno {
    int matricula;
    char* nome;
    float CR;
};



tAluno* IniciaAluno(int matricula, char* nome, float CR){
    tAluno* novo= (tAluno*)malloc(sizeof(tAluno));
    novo->nome= strdup(nome);
    novo->CR = CR;
    novo->matricula= matricula;
    return novo;

};

void ImprimeAluno(tAluno* aluno){
    printf("matricula: %d, nome: %s, CR %.2f\n",aluno->matricula, aluno->nome, aluno->CR);

};

int RetornaMatricula(tAluno* aluno){
    return aluno->matricula;
};


char* RetornaNomeAluno(tAluno* aluno){
    return aluno->nome;
};


float RetornaCR(tAluno* aluno){
    return aluno->CR;
};

void DestroiAluno(tAluno* aluno){

    free(aluno->nome);
    free(aluno);
};