/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listagen.h
 * Author: diona
 *
 * Created on 15 de Dezembro de 2020, 21:45
 */

#ifndef LISTAGEN_H
#define LISTAGEN_H

#include <stdio.h>

typedef struct listagen ListaGen;

//cria lista vazia
ListaGen* criaLista(void);

//insere 
ListaGen* insereLista(ListaGen* lista,void* item);

//retira
ListaGen* retiraLista(ListaGen* lista, int(*cb)(void*,void*) ,void* chave);

//pecorre
int  pecorreLista(ListaGen* lista, int(*cb)(void*,void*),void* dado);

//libera celulas
ListaGen* libera(ListaGen* lista);

#endif /* LISTAGEN_H */

