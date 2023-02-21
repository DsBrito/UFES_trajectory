#include <stdio.h>

int main(){
	
	float n1, n2, n3;
	float media;

	scanf("%f %f %f", &n1, &n2, &n3);

	media = (n1 + n2 + n3)/3;
	
	printf("Notas acima da média:");
	if (n1 >= media){ 
		printf(" %.f", n1);
	}
	if (n2 >= media){ 
		printf(" %.f", n2);
	}
	if (n3 >= media){ 
		printf(" %.f", n3);
	}
	printf("!");
	
	return 0;
}
