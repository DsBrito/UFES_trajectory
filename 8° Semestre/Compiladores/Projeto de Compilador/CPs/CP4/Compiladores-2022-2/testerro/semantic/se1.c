#include <stdio.h>


int main(void) {
	float raio, area;
	int a;

	a = 2.5;				//ERRO: erro de tipo

	printf("RAIO = ")       //ERRO: falta ponto e virgula
	scanf("%f", &raio);
 
	//area = pi * raio * raio;
 
	printf("AREA = %.2f m2 \n", area);

				//ERRO: não tem return
}
