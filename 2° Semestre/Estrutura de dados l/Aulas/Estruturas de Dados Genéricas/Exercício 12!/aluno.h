/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aluno.h
 * Author: diona
 *
 * Created on 8 de Novembro de 2020, 13:21
 */

#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;
Aluno* IniciaAluno(int matricula, char* nome, float CR);
void ImprimeAluno(Aluno* aluno);
int RetornaMatricula(Aluno* aluno);
char* RetornaNomeAluno(Aluno* aluno);
float RetornaCR(Aluno* aluno);
void DestroiAluno(Aluno* aluno);

#endif /* ALUNO_H */

