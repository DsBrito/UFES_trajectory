/*

Faça o exercício anterior considerando vários arquivos que armazenam as informações dos alunos de
várias turmas distintas. Considere que os nomes de todos os arquivos a serem processados encontra-se num
arquivo principal chamado arquivos.txt. Ao armazenar os nomes dos alunos aprovados no mesmo
arquivo aprovado2.txt, indique na frente do nome de qual arquivo este aluno veio.
*/
*/
#include <stdio.h>
#include<stdlib.h>

void pegaAluno(){
	char nomeDoArquivo[25],nome[25];
	float nota;
	FILE* arquivos;
	FILE* arquivo;
	FILE* saida;
	arquivos=fopen("arquivos.txt","r");
	saida=fopen("aprovado2.txt","w");
	fprintf(saida,"LISTA DE APROVADOS:\n");
	while(!feof(arquivos)){
		fscanf(arquivos,"%s",nomeDoArquivo);
		arquivo=fopen(nomeDoArquivo,"r");
		while(!feof(arquivo)){
			fscanf(arquivo,"%s %f",nome, &nota);
			if(nota>5.0){
				fprintf(saida,"%s: %s\n",nome,nomeDoArquivo);
				printf("%s: %s\n",nome,nomeDoArquivo);
			}
		}
	}
}

int main(){
	pegaAluno();
	return 0;
}
