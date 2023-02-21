/*
   Matricula: 2017100584
   Nome: Agnes Tereza Lenker Ribeiro
   turma: Engenharia Civil 2017/1
   Periodo: 1�

   Fazer um programa em C para ler uma quantidade N de alunos (sendo N fornecido pelo usu�rio). Ler o nome, matricula e a m�dia de cada um dos N alunos (armazenar estes dados em uma estrutura; nome = char[25], matricula = int, m�dia = float, situa��o = int) e armazenar cada estrutura de aluno em um vetor de estruturas aluno. Ap�s a leitura:
a) Criar uma fun��o que receba um vetor de alunos e a quantidade de alunos. Esta fun��o ir� verificar se a m�dia do aluno � superior a 5.0 e definir sua situa��o como aprovado ou, caso m�dia for menor que 5.0, reprovado. Por fim, dever� retornar a quantidade de alunos que est�o com a nota acima de 5.0.
b) Crie uma fun��o que imprima as informa��es de um aluno, como no exemplo:
Nome: Victor Amorim
Matr�cula: 20131313
M�dia: 7.5
Situa��o: Aprovado
c) Criar uma fun��o que imprima o vetor de alunos. DICA: Utilize a fun��o da quest�o anterior para auxiliar na impress�o.
d) Crie uma fun��o para calcular a m�dia aritm�tica de todas as notas da turma e imprimir as informa��es de todos os alunos e o resultado da turma (�Todos est�o aprovados", �X alunos reprovados e Y alunos aprovados� ou �Todos os alunos est�o reprovados�).
*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char nome[25];
	int matricula, situacao;
	float media ;
}aluno;

int qt_alunos_aprovados (aluno* vetor, int qt_alunos);
void imprime_aluno (aluno a);
void imprime_vetor_alunos(aluno *alunos, int tamanho);
void calcula_media (aluno *alunos, int tamanho);

int main () {
	int numero_alunos,i;
	aluno *turmas;

	printf("insira o numero de alunos: \n");
	scanf("%d",&numero_alunos);
	turmas = malloc (numero_alunos * sizeof (aluno));

	for(i=0;i<numero_alunos;i++){
		printf("insira o nome do %d aluno: \n",i+1);
		scanf("%s", &turmas[i].nome);
		printf("insira a matricula do %d aluno: \n",i+1);
		scanf("%d", &turmas[i].matricula);
		printf("insira a media do %d aluno: \n",i+1);
		scanf("%f", &turmas[i].media);
	}

	i = qt_alunos_aprovados (turmas,numero_alunos);
	printf("numero de alunos aprovados: %d \n", i);
	imprime_vetor_alunos(turmas,numero_alunos);
	calcula_media(turmas,numero_alunos);
	return 0;
}

int qt_alunos_aprovados (aluno* vetor, int qt_alunos){
	int i,qt=0;

	for (i=0;i<qt_alunos;i++){
		if(vetor[i].media < 5){
			vetor[i].situacao = 0;
		}else{
			qt++;
			vetor[i].situacao = 1;
		}
	}
	return qt;
}

void imprime_aluno (aluno a){
	printf("Nome: %s \n",a.nome);
	printf("Matricula %d \n",a.matricula);
	printf("Media: %.3f \n",a.media);

	if(a.situacao == 0){
		printf("Situacao: Reprovado \n");
	}else{
		printf("Situacao: Aprovado \n");
	}
}

void imprime_vetor_alunos(aluno *alunos, int tamanho){
	int i;

	for(i=0;i<tamanho;i++){
		imprime_aluno(alunos[i]);
	}
}

void calcula_media (aluno *alunos, int tamanho){
	int i,contaaprovados=0,contareprovados=0;
	float media=0;

	for(i=0;i<tamanho;i++){
		media = media + alunos[i].media;
		if(alunos[i].situacao == 0){
			contaaprovados++;
		}else{
			contareprovados++;
		}
	}
	media = media / tamanho;
	if (contaaprovados == 0){
		printf("Todos os alunos estao reprovados \n");
	}else{
		if(contareprovados == 0){
			printf("Todos os alunos estao aprovados \n");
		}else{
			printf("%d alunos aprovados , %d alunos reprovados \n", contaaprovados,contareprovados);
		}
	}
}
