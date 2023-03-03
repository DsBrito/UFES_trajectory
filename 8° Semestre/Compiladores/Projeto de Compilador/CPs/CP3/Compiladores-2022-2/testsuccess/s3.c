#include <stdio.h>

static const float pi = 3.14;

int main(void) {
	float raio, area;
	
	printf("RAIO = "); 
	scanf("%f", &raio);
 
	area = pi * raio * raio;

	printf("AREA = %.2f m2 \n", area);

	return 0;
}
