
#include <stdio.h>

int main (int argc, char const *argv[]) {
    int x;

	printf("Informe o numero desejado: ");
	scanf("%d", &x);
	while(x != -1){
            while (x<=0){
                printf( "digite um inteiro positivo\n");
                scanf("%d", &x);
            }
		if(x%2 == 0 || x%3 ==0){
			printf("1\n");
		}
        if(x%5 == 0 || x%7 ==0){
        printf("2\n");
        }
        if(x%2!=0 && x%3!=0 && x%5!=0 && x%7!=0){
		    printf ("0\n");
		    }

		printf("informe o numero desejado: ");
		scanf("%d", &x);
	}

	printf("\n");

    return 0;
}
