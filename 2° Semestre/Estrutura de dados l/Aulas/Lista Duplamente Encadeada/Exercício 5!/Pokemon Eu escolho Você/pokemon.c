


#include <stdio.h>
#include "pokemon.h"
#include<string.h>
#include<stdlib.h>



//estrutura
struct tipoPokemon{
  char *nome;
  char *tipo;
  int numero;
  int geracao;
  char *regiao;
};



//inicia pokemon


/*Inicializa um TipoPokemon pokemon
* inputs: o nome, o numero, a geração  e a regiao
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, o numero, a geração  e a regiao validos
* pos-condicao: tipo pokemon criado, com os campos nome, o numero, a geração  e a regiao copiados
*/
TipoPokemon* InicializaTipoPokemon(char* nome, int numero, char* tipo,int geracao, char* regiao){
  TipoPokemon* pokemon=(TipoPokemon*)malloc((strlen(nome)+1)*sizeof(TipoPokemon));

  pokemon->nome=strdup(nome);
//  strcpy(pokemon->nome,nome);
  pokemon->tipo=strdup(tipo);
 // strcpy(pokemon->tipo,tipo);
  pokemon->numero=numero;
  pokemon->geracao=geracao;
  pokemon->regiao=strdup(regiao);
//  strcpy(pokemon->regiao,regiao);
  return pokemon;

}

//recupera pokemon
int recuperaPokemon(TipoPokemon* pokemon){
    return pokemon->numero;
};



void imprimePokemon(TipoPokemon* pokemon){
    printf("    Nome Do Pokemon: %s\n",pokemon->nome);
    printf("    Numero da Pokedex: %d\n",pokemon->numero);
    printf("    Geracao: %d\n",pokemon->geracao);
    printf("    Tipo: %s\n",pokemon->tipo);
    printf("    Regiao: %s\n",pokemon->regiao);

}
 

void PokemonEscolha(TipoPokemon* pokemon){

    printf("\n############################################################################");
    printf("\n-Treinador pokemon: %s eu escolho voce!!\n",pokemon->nome);
    imprimePokemon(pokemon);
    printf("\n############################################################################\n");


};
      
void pokemonLibera(TipoPokemon* pokemon)
{
    free(pokemon->nome);
    free(pokemon->tipo);
    free(pokemon->regiao);
    free(pokemon);

    
};