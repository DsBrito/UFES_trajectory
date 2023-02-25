 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LISTA_HET.h
 * Author: diona
 *
 * Created on 21 de Março de 2021, 18:14
 */

#ifndef LISTA_HET_H
#define LISTA_HET_H

#include <stdio.h>
#include <stdlib.h>
#include "ALUNO.h"
#include "PROFESSOR.h"

/*Tipo que define a lista heterogenea (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.

 */
typedef struct listahet ListaHet;




/*inicia lista
* inputs:nenhum
* output: ´lista e criada NULL
* pre-condicao: nenhum
* pos-condicao:  lista com os seus campos (proximo e anterioir) apontando pra NULL
*/
ListaHet* IniciaLista();



/* Insere um aluno na lista
* inputs: lista e aluno
* output: nenhum
* pre-condicao: entrada valida;
* pos-condicao:  aluno inserido
*/
void InsereAluno(ListaHet* lista, tAluno* p);




/* Insere um professor na lista
* inputs: lista e professor
* output: nenhum
* pre-condicao: entrada valida;
* pos-condicao:  aluno inserido
*/
void InsereProfessor(ListaHet* lista, tProfessor* p );




/*Imprime dados do da lista heterogenea
* inputs:  lista;
* output:  nenhum ;
* pre-condicao: lista valida;
* pos-condicao:  dados  da lista  impresso;
*/
void ImprimeListaHet(ListaHet* lista);




 /* calcula churrasco
* inputs: lista
* output: valor do churrasco
* pre-condicao: lista valida;
* pos-condicao:  valor do churrasco calculado
*/
float ValorChurrasco(ListaHet* lista);




 /* libera lista
* inputs: lista
* output: memoria do lista alocada  liberada;
* pre-condicao: lista valido;
* pos-condicao:  memoria da lista liberada;
*/
void DestroiLista(ListaHet* lista);



#endif /* LISTA_HET_H */

