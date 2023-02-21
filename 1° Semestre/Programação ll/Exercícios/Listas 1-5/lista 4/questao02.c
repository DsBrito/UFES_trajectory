/*


Faça um programa que leia o número de alunos de uma turma. O seu programa deverá ler os nomes e as
respectivas notas finais obtidas pelos alunos. A saída do seu programa será um arquivo chamado
aprovado.txt que conterá os nomes dos alunos que obtiveram nota final igual ou superior a 5. Monte o
arquivo com o formato que achar mais adequado.
*/
#include <stdio.h>
#include <stdlib.h>

struct dados_Alunos{
	char nome[25];
	float notaFinal;
};

void leAlunos(int *tam){
	int i;
	FILE *aprovado;
	struct dados_Alunos *vet;
	vet=malloc((*tam)*sizeof(struct dados_Alunos));
	for(i=0;i<(*tam);i++){
		printf("digite o nome dx %d alunx:\n",i+1);
		scanf("%s",vet[i].nome);
		printf("digite a nota final desse aluno:\n");
		scanf("%f",&(vet[i].notaFinal));
	}

	for(i=0;i<(*tam);i++){
		printf("nome: %s\nnotafinal: %.2f\n",vet[i].nome,vet[i].notaFinal);
	}
	aprovado= fopen("aprovado.txt","w");
	if(aprovado==NULL){
		printf("Erro\n");
		exit(1);
	}
	fprintf(aprovado,"Aprovados:\n");
	for(i=0;i<(*tam);i++){
		if(vet[i].notaFinal>=5.0){
			fprintf(aprovado,"%s\n",vet[i].nome);
			printf("%s\n",vet[i].nome);

		}
	}
}
int main(){
	int numAlunos;
	printf("digite o numero de alunos da turma\n");
	scanf("%d",&numAlunos);
	leAlunos(&numAlunos);
	return 0;
}

