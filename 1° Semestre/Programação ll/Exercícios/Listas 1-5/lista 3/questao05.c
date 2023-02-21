/*
   Matricula: 2017100584
   Nome: Agnes Tereza Lenker Ribeiro
   turma: Engenharia Civil 2017/1
   Periodo: 1º

Defina estrutura Data contendo o dia, mês e ano de um evento. Faça uma função que receba uma Data e um inteiro duração, que representa quantos dias um determinado evento irá durar. Está função deverá retornar a data final do evento. Utilize meses contendo 30 dias.
*/

 #include <stdio.h>
 #include <stdlib.h>

int main (){
	int duracao, i=0, dia, mes, ano;
	char choices='n',lixo;
	while (choices=='n'){
		printf ("Digite o dia do evento: ");
		scanf ("%d",&dia );
		printf("\n Digite o mês do evento: ");
		scanf ("%d", &mes);
		printf ("\n Digite o ano do evento: ");
		scanf ("%d", &ano);
		printf ("Eh esta a sua data? se nao, digite 'n', se sim, digite qualquer outra merda'' \n %d/%d/%d", dia, mes, ano);
		scanf("%c",&choices);
		scanf("%c",&lixo);
	}
	printf("agr quantos dias vai durar seu eventoh??\n");
	scanf("%d",&duracao);


	while(i<duracao){
		dia++;
		if(dia>30){
			mes++;
			dia=1;
			if(mes>12){
				mes=1;
				ano++;
			}
		}
	i++;
	}
	printf("o evento vai terminar dia %d/%d/%d",dia,mes,ano);
	return 0;
}
