/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fila.h
 * Author: diona
 *
 * Created on 20 de Novembro de 2020, 17:50
 */

#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include "aluno.h"

typedef  struct fila FILA;

FILA* iniciaFila(void);

//insere no final da fila

void insereFila(FILA* f,Aluno* a);


//retira sempre no inico
Aluno* retiraFila(FILA* f);

//imprime do inico ao fim da fila
void imprimeFila(FILA*  f);

//libera memoria da fila
void destroifila(FILA* f);

#endif /* FILA_H */

