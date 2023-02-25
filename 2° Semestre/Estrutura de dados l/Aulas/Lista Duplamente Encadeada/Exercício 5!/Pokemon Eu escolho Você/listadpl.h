#ifndef LISTA_H_
#define LISTA_H_


#include<stdio.h>
#include"pokemon.h"

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  Usar lista duplamente encadeada sem Sentinela
  */
typedef struct tipolistadpl TipoListaDpl;


/*Insere um pokemon na primeira posição da lista duplamente encadeada de pokemon
* inputs: pokemon a ser inserido na lista (do tipo TipoPokemon) e a lista
* output: lista duplamente encadeada com o item inserido na primeira posição
* pre-condicao: pokemon e lista não são nulos
* pos-condicao: lista contém o pokemon inserido na primeira posição
*/
TipoListaDpl* Insere (TipoPokemon* pokemon, TipoListaDpl* lista);




/*Retira um pokemon de nome "nome" da lista de pokemon
* inputs: a lista e o nome do pokemon a ser retirado da lista
* output: o pokemon (do tipo TipoPokemon) retirado da lista ou NULL, se o pokemon não se encontrar na lista
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o pokemon de nome "nome"
*/
TipoListaDpl* Retira (TipoListaDpl* lista, int id);




/*Imprime os dados de todos os pokemon da lista duplamente encadeada
* inputs: a lista de pokemon
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos pokemon impressos na saida padrao
*/
void Imprime (TipoListaDpl* lista);



/*Libera toda a memória alocada para a lista 
* inputs: a lista duplamente encadeada de pokemon
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
TipoListaDpl* libera (TipoListaDpl* lista);


#endif /* LISTA_H_ */