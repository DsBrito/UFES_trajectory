/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaMat.h
 * Author: diona
 *
 * Created on 22 de Outubro de 2020, 16:03
 */

#ifndef LISTAMAT_H
#define LISTAMAT_H


#include<stdio.h>
#include"matriz.h"

typedef struct lista Lista;

Lista* IniciaLista();

void InsereLista(Lista* lista,Matriz* mat);

void ImprimeLista(Lista* lista);

Matriz* Retira(Lista* lista, int busca);

void DestroiLista(Lista* lista);





#endif /* LISTAMAT_H */

