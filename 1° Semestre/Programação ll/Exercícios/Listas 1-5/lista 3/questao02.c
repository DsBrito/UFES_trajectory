#include <stdio.h>
#include <stdlib.h>

struct infA{
	char nome[25];
	int matricula;
	float media;
	char situacao;
};

int alunoAprovado (struct infA alunos){
	if (alunos.media >= 5.0){
		return 1;
	}
	return 0;
}
void imprimeInfA (struct infA alunos){
	printf ("Nome: %c \n", (alunos.nome));
	printf ("Matrícula: %d \n", (alunos.matricula));
	printf ("Média: %f \n", (alunos.media));
	printf ("Situação: %s \n", (alunos.situacao));
}

int main(){
	int n, aprovados, i;
	struct infA *alunos;
	printf ("Informe o numero de alunos da turma: \n");
	scanf ("%d", &n);

	alunos = malloc(n*sizeof(float));

	for (i = 0; i < n; i++){
		printf ("Digite o nome do aluno %d \n", i+1);
		scanf ("%[^\n]", alunos[i].nome);

		printf ("\n Digite a matrícula do aluno %d \n", i+1);
		scanf ("%d", alunos[i].matricula);

		printf ("\n Digite a media do aluno %d:\n ", i+1);
		scanf ("%f", alunos[i].media);
	}
	aprovados = 0;
	for (i = 0; i < n; i++){
		if (alunoAprovado(alunos[i])){
			alunos[i].situacao = "Aprovado";
			aprovados++;
		}else{
		alunos[i].situacao = "Reprovado";
		}
	}

 imprimeInfA(alunos[i]);


return 0;
}
