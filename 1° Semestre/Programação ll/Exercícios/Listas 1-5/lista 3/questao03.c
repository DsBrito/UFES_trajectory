/*
   Matricula: 2017100584
   Nome: Agnes Tereza Lenker Ribeiro
   turma: Engenharia Civil 2017/1
   Periodo: 1º

Considerando a estrutura:
struct Ponto{
float x;
float y;
};
para representar um ponto em 2D, implemente uma função que indique se um ponto P está localizado dentro ou fora de um retângulo. O retângulo é definido por seus vértices inferior esquerdo v1 e superior direito v2. A função deve retornar Verdadeiro caso o ponto esteja localizado dentro do retângulo ou Falso caso não esteja.
Para testar, crie uma função que leia do usuário os valores de X e Y e retorne um ponto instanciado com esses valores.

*/
#include <stdio.h>
#include <stdlib.h>

struct Ponto{
	float x;
	float y;
};


int main (){
	struct Ponto ponto;
	struct Ponto v1, v2;

	printf ("Digite as coordenadas do seu ponto. \n X = ");
	scanf ("%f", &ponto.x);
	printf ("\n Y = ");
	scanf ("%f", &ponto.y);

	printf ("Digite as coordenadas do vértice inferior esquerdo do seu retângulo. \n X = ");
	scanf ("%f", &v1.x);
	printf ("\n Y = ");
	scanf ("%f", &v1.y);

	printf ("Digite as coordenadas do vértice superior direito do seu retângulo. \n X = ");
	scanf ("%f", &v2.x);
	printf ("\n Y = ");
	scanf ("%f", &v2.y);

	if ((ponto.x >= v1.x && ponto.x <= v2.x && ponto.y >= v1.y && ponto.y <= v2.y ) || (ponto.x <= v1.x && ponto.x >= v2.x && ponto.y <= v1.y && ponto.y >= v2.y)){
		printf ("O ponto pertence ao retângulo.");
		}else{
			printf ("O ponto não pertence ao retângulo.");
		}
	return 0;
}
