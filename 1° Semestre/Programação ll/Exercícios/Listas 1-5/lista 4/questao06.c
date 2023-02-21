/*


Considere um arquivo chamado matrizes.txt que armazena 5 matrizes quadradas de dimensão 4 × 4
de números inteiros. Faça um programa para ler as matrizes do arquivo e criar um arquivo chamado
transp.txt que conterá as matrizes transpostas das matrizes lidas.
*/

#include <stdio.h>
#include <stdlib.h>

void leMatriz(){
	int i, j, k;
	int mat[5][4][4];
	FILE *matrizes;
	FILE *transp;
	matrizes = fopen("matrizes.txt","r");
	transp = fopen("transp.txt","w");
	if(matrizes==NULL){
		printf("Erro\n");
		exit(1);
	}
		for(k=0;k<5;k++){
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					fscanf(matrizes, "%d", &mat[k][i][j]);
			}
		}
	}
		for(k=0;k<5;k++){
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					fprintf(transp, "%d ", mat[k][j][i]);
			}
			fprintf(transp,"\n");
		}
			fprintf(transp,"\n");
	}

	fclose(transp);
	fclose(matrizes);
}


int main(){
	leMatriz();
	return 0;
}
