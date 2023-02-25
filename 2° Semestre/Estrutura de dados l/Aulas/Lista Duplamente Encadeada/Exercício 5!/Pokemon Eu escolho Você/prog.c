/*
*********************************
* Programa testador do TAD Lista
*********************************
*/
#include <stdio.h>
#include "listadpl.h"

int main()
{
    // criando a lista vazia
	TipoListaDpl *lista;
        lista= NULL;
        int id;

	// criando alguns pokemon apenas para testar
	
        //primeira geração
         TipoPokemon* Charmander  = InicializaTipoPokemon("Charmander",004, "fogo",1,"Kanto");
	 TipoPokemon* Squirtle = InicializaTipoPokemon("Squirtle",007, "agua",1,"Kanto");
	 TipoPokemon* Bulbassauro = InicializaTipoPokemon("Bulbassauro",001, "grama-venenoso",1,"Kanto");
         
         //segunda geração
         TipoPokemon* Chikorita  = InicializaTipoPokemon("Chikorita",152, "grama",2,"Johto");
	 TipoPokemon* Cyndaquil = InicializaTipoPokemon("Cyndaquil",155, "fogo",2,"Johto");
	 TipoPokemon* Totodile  = InicializaTipoPokemon("Totodile",158, "agua",2,"Johto");
         
         //terceira geração
         TipoPokemon* Mudkip  = InicializaTipoPokemon("Mudkip",258, "agua-terrestre",3,"Hoenn");
	 TipoPokemon* Torchic  = InicializaTipoPokemon("Torchic",255, "fogo-lutador",3,"Hoenn");
	 TipoPokemon* Treecko = InicializaTipoPokemon("Treecko",252, "grama",3,"Hoenn");
         
         //quarta geração
         TipoPokemon* Piplup  = InicializaTipoPokemon("Piplup",393, "agua",4,"Sinnoh");
	 TipoPokemon* Chimchar  = InicializaTipoPokemon("Chimchar",290, "fogo-lutador",4,"Sinnoh");
	 TipoPokemon* Turtwig = InicializaTipoPokemon("Turtwig",387, "grama",4,"Sinnoh");
         
         //quinta geração
         TipoPokemon* Snivy   = InicializaTipoPokemon("Snivy",495, "grama",5,"Unova");
	 TipoPokemon* Tepig   = InicializaTipoPokemon("Tepig",498, "fogo",5,"Unova");
	 TipoPokemon* Oshawott  = InicializaTipoPokemon("Oshawott",501, "agua",5,"Unova");
         
         //sexta geração
         TipoPokemon* Chespin   = InicializaTipoPokemon("Chespin",650, "grama",6,"Kalos");
	 TipoPokemon* Fennekin  = InicializaTipoPokemon("Fennekin",654, "fogo",6,"Kalos");
	 TipoPokemon* Froakie  = InicializaTipoPokemon("Froakie",656, "agua",6,"Kalos");
         
       
         
         
	

	 //Insere os pokemon na lista
	 lista = Insere(Charmander, lista);
	 lista = Insere(Squirtle, lista);
	 lista = Insere(Bulbassauro, lista);
         
	 lista = Insere(Chikorita, lista);
	 lista = Insere(Cyndaquil, lista);
         lista = Insere(Totodile, lista);
         
	 lista = Insere(Mudkip, lista);
	 lista = Insere(Torchic, lista);
	 lista = Insere(Treecko, lista);
         
	 lista = Insere(Piplup, lista);
         lista = Insere(Chimchar, lista);
	 lista = Insere(Turtwig, lista);
         
	 lista = Insere(Snivy, lista);
	 lista = Insere(Tepig, lista);
	 lista = Insere(Oshawott, lista);
         
         lista = Insere(Chespin, lista);
	 lista = Insere(Fennekin, lista);
	 lista = Insere(Froakie, lista);


	 //Imprime a lista com todos os pokemon
         printf("\n-Professor: Temos apenas pokemon da 1/2/3/4/5/6 geracae sao esses:\n");
	 Imprime(lista);
         
         printf("\n-Professor: Qual dos pokemon citados voce escolhe para iniciar a sua jornada pokemon?\n");
         printf("Insira o numero da pokedex:");
         scanf("%d",&id);
         
	 lista = Retira(lista,id);
         printf("\n-Treinador pokemon: eh acho que ele tambem me escolheu!!\n");
         printf("-Pofessor: otimo e boa sorte meu rapaz, pode mandar chamar o proximo\n");
      
         printf("\nProfessor: Temos apenas esses pokemon disponiveis no momento:\n");
	 Imprime(lista);
         printf("\n-Narrador:CONTINUA NO PROXIMO EPISODIO....\n");

         libera (lista);

}