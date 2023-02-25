/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pokemon.h
 * Author: diona
 *
 * Created on 8 de Novembro de 2020, 15:17
 */

#ifndef POKEMON_H
#define POKEMON_H

/*TipoPokemon pokemon (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - numero (int)
  - geração (int)
  - regiao (string)
  */
typedef struct tipoPokemon TipoPokemon;

/*Inicia o tipo pokemon os dados
* inputs: nome, numero, tipo, geração, região do pokemon
* output: pokemon inicializado
* pre-condicao: um pokemon ter nome, numero, tipo , geração e região
* pos-condicao: um pokemon criado com os dados passados
*/
TipoPokemon* InicializaTipoPokemon(char* nome, int numero, char* tipo,int geracao, char* regiao);



/*recupera oo numero do pokemon
* inputs: um pokemon do TipoPokemon
* output: numero do pokemon
* pre-condicao: numero ser inteiro
* pos-condicao: numero do pokemon retornado
*/
int recuperaPokemon(TipoPokemon* pokemon);

/*Escolha de pokemon 
* inputs: um pokemon
* output: nenhum
* pre-condicao: pokemon existir
* pos-condicao: pokemon escolhido
*/
void PokemonEscolha(TipoPokemon* pokemon);


/*Imprime os dados de todos os pokemon 
* inputs: um pokemon
* output: nenhum
* pre-condicao: pokemon existir
* pos-condicao: dados dos pokemon impressos na saida padrao
*/
void imprimePokemon(TipoPokemon* pokemon);

/*libera os dados de todos os pokemon 
* inputs: um pokemon
* output: nenhum
* pre-condicao: pokemon existir
* pos-condicao: pokemon liberado
*/
void pokemonLibera(TipoPokemon* pokemon);

#endif /* POKEMON_H */

