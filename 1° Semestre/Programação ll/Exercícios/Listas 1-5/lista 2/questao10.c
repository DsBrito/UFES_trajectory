

#include <stdio.h>

int main (int argc, char const *argv[]) {
    char frase[50];
	char frase2[50];
	char tab[0];
	int i, j, contEsp, finalj;

	contEsp = 0;
	j = 0;
	printf("Informe a frase: ");
	scanf("%[^\n]",frase);

	for(i = 0; frase[i] != '\0'; i++){
	    if (frase[i] == ' '){
            contEsp =(contEsp+1);
	    }else{
	    frase2[j]=frase[i];
	    j = (j+1);
	    }
	    finalj = j;
	}
	for(j = 0; j <= finalj; j++){
                printf("%c", frase2[j]);
	    }
	    printf("\n");
	    printf("a frase tem %d espacos", contEsp);

	printf("\n");
    return 0;
}
