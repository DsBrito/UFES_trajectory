/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilha.h
 * Author: diona
 *
 * Created on 4 de Abril de 2021, 11:38
 */

#ifndef PILHA_H
#define PILHA_H


/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - peso (float)
  - altura (float)
  - endereco (string)
  - genero (string)
  */

typedef struct pessoa tPessoa;


// struct de pilha
typedef struct indice IndicePilha;
typedef struct pilha tPilhaDupla;


/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P está definida e vazia
*/
tPilhaDupla* cria_pilha();

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa) + INDICE ( se é feminino ou masculino )
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da função, a pilha tem E como o elemento
do topo
*/
void push(tPessoa* pessoa, tPilhaDupla* pilha,int indice);


/*Retira uma Pessoa do topo da Pilha (se pilha não vazia)
* inputs: a Pilha e o indice  (feminino ou masculino)
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha não é nula e não é vazia
* pos-condicao: pilha não contém o elemento retirado do topo
*/
tPessoa* pop(tPilhaDupla* pilha, int indice);


/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha não é nula
* pos-condicao: Toda memoria eh liberada
*/
tPilhaDupla* destroi_pilha(tPilhaDupla* pilha);




/*Recupera genero 
* inputs: pessoa
* output: um numero inteiro para identificação
* pre-condicao: pessoa valida
* pos-condicao: numero inteiro retornado
*/
int recuperaGenero(tPessoa* pessoa);




/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco, peso , altura  e genero da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: dados de entrada validos 
* pos-condicao: tipo item criado, com os campos nome, idade, peso ,altura, genero   e endereco copiados
*/
tPessoa* inicializaPessoa(char* nome, int idade,float peso,float altura, char* endereco, char* genero);


/*Imprime as pessoas da pilha
* inputs: a pilha
* output: nenhum
* pre-condicao: pilha P não vazia
* pos-condicao: Pilha permanece inalterada
*/
void imprime_pilha (tPilhaDupla* pilha);


#endif /* PILHA_H */

