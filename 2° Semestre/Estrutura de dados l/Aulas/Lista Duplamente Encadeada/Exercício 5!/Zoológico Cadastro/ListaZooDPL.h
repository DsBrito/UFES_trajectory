/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaZooDPL.h
 * Author: diona
 *
 * Created on 21 de Março de 2021, 08:38
 */

#ifndef LISTAZOODPL_H


#include <stdio.h>
#include <stdlib.h>
#include "zoologico.h"

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  Usar lista duplamente encadeada sem Sentinela
  */
typedef struct tipoListaDPL  TipoListaDPL;


/*Insere um animal na primeira posição da lista duplamente encadeada do zoologico
* inputs: animal a ser inserido na lista  e a lista
* output: lista duplamente encadeada com o item inserido na primeira posição
* pre-condicao: animal e  lista não são nulos
* pos-condicao: lista contém o animal inserido na primeira posição
*/
TipoListaDPL* InsereLista(TipoListaDPL* lista, TipoZoo* animal);
TipoListaDPL* IniciaLista();


/*Retira um animal da lista de animais do zoologico
* inputs: a lista e o id do animal a ser retirado da lista
* output: o animal retirado da lista ou NULL, se o animal não se encontrar na lista
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o animal do id de entrada
*/
TipoListaDPL* RetiraLista(  TipoListaDPL* lista, int id);


/*Imprime os dados de todos os animais da lista duplamente encadeada do zoologico
* inputs: a lista do zoologico
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos animal impressos na saida padrao
*/
void ImprimeLista(TipoListaDPL* lista);



/*Libera toda a memória alocada para a lista 
* inputs: a lista duplamente encadeada de animais do zoologico
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
void DestroiLista(TipoListaDPL* lista);
 
  

#endif /* LISTAZOODPL_H */

