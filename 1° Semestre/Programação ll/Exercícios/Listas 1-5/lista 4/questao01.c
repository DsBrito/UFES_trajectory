
Considere um arquivo chamado matrizes.txt que armazena 5 matrizes quadradas de dimensão 4 × 4
de números inteiros. Faça um programa para ler as matrizes do arquivo e criar um arquivo chamado
transp.txt que conterá as matrizes transpostas das matrizes lidas.
*/

#include <stdio.h>
#include <stdlib.h>

struct dados_pacientes{
char nome[25];
int idade;
float peso, altura;
};

struct dados_pacientes *lerdadadospacientes(){
int i;
struct dados_pacientes *vet;
vet = malloc (10*sizeof(struct dados_pacientes));
FILE* paciente;

paciente = fopen("paciente.txt", "r");
if (paciente == NULL){
    printf("Erro\n");
    exit(1);
}
for (i=0; i<10; i++){
	printf("lendo dados...\n");
	fscanf (paciente, "%s %d %f %f", vet[i].nome, &(vet[i].idade), &(vet[i].peso), &(vet[i].altura) );
	printf("%s %d %.2f %.2f\n", vet[i].nome, vet[i].idade, vet[i].peso, vet[i].altura );
}
fclose(paciente);
return vet;
}

void calcularpesoIdealPessoas (struct dados_pacientes *vet) {
int i, cont;
float pesoIdeal;
cont = 0;
 FILE *acimadopeso;

           acimadopeso = fopen("acimadopeso.txt", "w");
for (i=0; i<10 ; i++){
        pesoIdeal = 0;
        pesoIdeal = ((vet[i].altura - 1)*100);
if (pesoIdeal < vet[i].peso){

           if (acimadopeso == NULL){
           	printf ("Erro\n");
           	exit(1);
		   }
		 fprintf(acimadopeso, "%s %d\n", vet[i].nome, vet[i].idade);
		 printf("%s %d\n", vet[i].nome, vet[i].idade) ;

        }
       ;
	}
}

int main() {
	struct dados_pacientes *vet;
	vet = lerdadadospacientes();
	calcularpesoIdealPessoas(vet);

	return 0;
}
