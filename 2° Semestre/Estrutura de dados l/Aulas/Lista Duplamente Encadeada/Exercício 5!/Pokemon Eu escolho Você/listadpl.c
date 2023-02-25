
#include <stdio.h>
#include "listadpl.h"
#include <stdlib.h>
#include <string.h>



struct tipolistadpl{
  TipoPokemon *pokemon;
  TipoListaDpl *prox;
  TipoListaDpl *ant;
};



/*Insere um pokemon na primeira posição da lista duplamente encadeada de pokemon
* inputs: pokemon a ser inserido na lista (do tipo TipoPokemon) e a lista
* output: lista duplamente encadeada com o item inserido na primeira posição
* pre-condicao: pokemon e lista não são nulos
* pos-condicao: lista contém o pokemon inserido na primeira posição
*/
TipoListaDpl* Insere (TipoPokemon* pokemon, TipoListaDpl* lista){
  TipoListaDpl *nova;
  nova=(TipoListaDpl*)malloc(sizeof(TipoListaDpl));
  nova->ant = NULL;
  nova->pokemon = pokemon;
  nova->prox=lista;

  if(lista!=NULL){
    lista->ant = nova;

  }
    return nova;
}





/*Imprime os dados de todos os pokemon da lista duplamente encadeada
* inputs: a lista de pokemon
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos pokemon impressos na saida padrao
*/
void Imprime (TipoListaDpl* lista){
  TipoListaDpl *Auxiliar;
  for(Auxiliar=lista;Auxiliar!=NULL;Auxiliar=Auxiliar->prox){
    imprimePokemon(Auxiliar->pokemon);
    printf("\n--\n");


  }
}

/*Retira um pokemon de nome "nome" da lista de pokemon
* inputs: a lista e o nome do pokemon a ser retirado da lista
* output: o pokemon (do TipoPokemon) retirado da lista ou NULL, se o pokemon não se encontrar na lista
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o pokemon de nome "nome"
*/
TipoListaDpl* Retira (TipoListaDpl* lista, int id){

  TipoListaDpl *p=lista;

  for(p=lista;p!=NULL;p=p->prox){
    if (recuperaPokemon(p->pokemon)==id) {
        PokemonEscolha(p->pokemon);
    break;
}}

    if(p==NULL){
        printf("\nO numero inserido ano corresponde a nenhum pokemon citado pelo professor!!!\n");
      return NULL;
    }

    //se p é o primeiro elemento da lista
    if(p==lista){
      //faz lista apontar pro proximo elemento
      lista=p->prox;
    }
    else{

      p->ant->prox = p->prox;
    }
    if(p->prox != NULL){
      p->prox->ant= p->ant;
    }

  //liberando o pokemon removido
    pokemonLibera(p->pokemon);
    free(p);

    return lista;

}


/*Libera toda a memória alocada para a lista 
* inputs: a lista duplamente encadeada de pokemon
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
TipoListaDpl* libera (TipoListaDpl* lista){
    TipoListaDpl *p=lista;
    while(p!=NULL){
      p=p->prox;
      free(lista);
      lista = p;
    }

}
