/*
   Matricula: 2017100584
   Nome: Agnes Tereza Lenker Ribeiro
   turma: Engenharia Civil 2017/1
   Periodo: 1º

Fazer uma função em C que receba uma frase de 25 caracteres e retorne um vetor de estruturas que represente a posição das vogais desta frase e a vogal correspondente.
Ex.:
Frase = “Ola Mundo!”.
Retorno = [{vPos=0;vog=O},{vPos=2;vog=a},{vPos=5;vog=u},{vPos=8;vog=o}]
*/
#include <stdio.h>
#include <stdlib.h>

struct vogalPos{
		char vogal;
		int pos;

};

int ehVogal(char ch){
	if (ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U'){
		return 1;
	}
	return 0;
}




int main (){
	char frase [25];
	int i,k;
	struct vogalPos vet[25];

	printf("Informe a frase: ");
	scanf("%[^\n]", frase);

	k=0;
	for (i=0 ; frase[i] != '\0' ; i++){
		if(ehVogal(frase[i])){
			vet[k].vogal = frase[i];
			vet[k].pos = i;
			k++;
		}
	}

	for(i=0 ; i<k ; i++){
		printf("{vPos=%d,vog=%c} \n",vet[i].pos,vet[i].vogal );
	}

	printf("\n");
	return 0;
}
