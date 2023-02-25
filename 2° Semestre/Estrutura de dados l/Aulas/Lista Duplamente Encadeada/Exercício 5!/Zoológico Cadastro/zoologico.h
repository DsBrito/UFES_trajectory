/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   zoologico.h
 * Author: diona
 *
 * Created on 21 de Março de 2021, 08:36
 */

#ifndef ZOOLOGICO_H
#define ZOOLOGICO_H


/*TipoZoo  (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - classificacao (string)
  - genero (string)
  - id (int)
  */
typedef struct tipoZoo TipoZoo;


/*Inicia os dados de um animal
* inputs: nome, classificação, genero, id
* output: animal inicializado
* pre-condicao: um animal ter nome, classificacao, genero e id
* pos-condicao: um animal criado com os dados passados
*/
TipoZoo* InicializaAnimal(char* nome,char* classificacao,char* genero, int id);



/*Imprime os dados de todos os animais do zoologico 
* inputs: um animal
* output: nenhum
* pre-condicao: animal existir
* pos-condicao: dados dos animal impressos na saida padrao
*/
void imprimeAnimal(TipoZoo* animal);


/*destroi os dados do animal do zoologico
* inputs: um animal
* output: nenhum
* pre-condicao: animal existir
* pos-condicao: animal liberado
*/
void DestroiAnimal(TipoZoo* animal);


/*recupera oo numero de id de um animal
* inputs: um animal
* output: id do animal
* pre-condicao: numero ser inteiro
* pos-condicao: numero do animal retornado
*/
int buscaZoo(TipoZoo* animal);



#endif /* ZOOLOGICO_H */

