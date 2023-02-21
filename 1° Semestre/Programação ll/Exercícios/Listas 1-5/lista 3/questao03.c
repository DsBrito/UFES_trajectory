/*
   Matricula: 2017100584
   Nome: Agnes Tereza Lenker Ribeiro
   turma: Engenharia Civil 2017/1
   Periodo: 1�

Considerando a estrutura:
struct Ponto{
float x;
float y;
};
para representar um ponto em 2D, implemente uma fun��o que indique se um ponto P est� localizado dentro ou fora de um ret�ngulo. O ret�ngulo � definido por seus v�rtices inferior esquerdo v1 e superior direito v2. A fun��o deve retornar Verdadeiro caso o ponto esteja localizado dentro do ret�ngulo ou Falso caso n�o esteja.
Para testar, crie uma fun��o que leia do usu�rio os valores de X e Y e retorne um ponto instanciado com esses valores.

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

	printf ("Digite as coordenadas do v�rtice inferior esquerdo do seu ret�ngulo. \n X = ");
	scanf ("%f", &v1.x);
	printf ("\n Y = ");
	scanf ("%f", &v1.y);

	printf ("Digite as coordenadas do v�rtice superior direito do seu ret�ngulo. \n X = ");
	scanf ("%f", &v2.x);
	printf ("\n Y = ");
	scanf ("%f", &v2.y);

	if ((ponto.x >= v1.x && ponto.x <= v2.x && ponto.y >= v1.y && ponto.y <= v2.y ) || (ponto.x <= v1.x && ponto.x >= v2.x && ponto.y <= v1.y && ponto.y >= v2.y)){
		printf ("O ponto pertence ao ret�ngulo.");
		}else{
			printf ("O ponto n�o pertence ao ret�ngulo.");
		}
	return 0;
}
