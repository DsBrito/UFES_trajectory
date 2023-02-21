#include <stdio.h> //pra tudo
#include <stdlib.h> //para usar a funcao malloc()
#include <math.h> // para usar a funcao pow();

struct dados_fisicos{
	float altura, peso, imc;
	int situacao_imc;
};

struct informacoes_pessoais{
	char nome[25];
	char genero;
};

struct pessoa{
	struct dados_fisicos dados;
	struct informacoes_pessoais infPessoais;
};

struct pessoa *criaAgenda(int qntPessoas){
	struct pessoa *pessoas;

	pessoas = malloc(qntPessoas * sizeof(struct pessoa));

	return pessoas;
}

int pegaPositivo(){
	int x;

	printf("Informe um valor positivo: ");
	scanf("%d", &x);

	while(x <= 0){
		printf("Informe um valor positivo!: ");
		scanf("%d", &x);
	}

	return x;
}

void lerPessoas(struct pessoa *pessoas, int qntPessoas){
	int i;
	char lixo;

	printf("Informe os dados dos pessoas: \n");
	for(i = 0; i < qntPessoas; i++){
		printf("Nome: \n");
		scanf("%s", pessoas[i].infPessoais.nome);

		printf("Genero: \n");
		scanf("%c", &lixo);
		scanf("%c", &(pessoas[i].infPessoais.genero));

		printf("Dados Fisicos: \n");
		printf("Peso: ");
		scanf("%f", &(pessoas[i].dados.peso));
		printf("Altura: ");
		scanf("%f", &(pessoas[i].dados.altura));
	}
}

void imprimirPessoa(struct pessoa pessoa){
	printf("\nInformacoes Pessoais: \n");
	printf("\tNome: %s\n", pessoa.infPessoais.nome);
	printf("\tGenero: ");
	if(pessoa.infPessoais.genero == 'M'){
		printf("Masculino\n");
	}else if(pessoa.infPessoais.genero == 'F'){
		printf("Feminino\n");
	}else{
		printf("Não Informado\n");
	}
	printf("Dados Fisicos: \n");
	printf("\tPeso: %.2f\n", pessoa.dados.peso);
	printf("\tAltura: %.2f\n", pessoa.dados.altura);
	printf("\tIMC: %.2f\n", pessoa.dados.imc);
	printf("\tSituacao: ");
	if(pessoa.dados.situacao_imc > 0){
		printf("Acima que a media\n");
	}else{
		printf("Abaixo que a media\n");
	}
}

void imprimirAgenda(struct pessoa *pessoas, int qntPessoas){
	int i;

	printf("\n==============================\n");
	printf("Agenda: \n");
	for(i = 0; i < qntPessoas; i++){
		imprimirPessoa(pessoas[i]);
	}
}

void contarGeneros(struct pessoa *pessoas, int qntPessoas){
	int contM, contF, contI, i;

	contM = 0;
	contF = 0;
	contI = 0;
	for(i = 0; i < qntPessoas; i++){
		if(pessoas[i].infPessoais.genero == 'M'){
			contM++;
		}else if(pessoas[i].infPessoais.genero == 'F'){
			contF++;
		}else{
			contI++;
		}
	}

	printf("\n==============================\n");
	printf("Generos: \n");
	printf("Masculinos: %d\n", contM);
	printf("Femininos: %d\n", contF);
	printf("Nao Informado: %d\n", contI);
}

void calcularIMCPessoas(struct pessoa *pessoas, int qntPessoas){
	int i;

	for(i = 0; i < qntPessoas; i++){
		pessoas[i].dados.imc = pessoas[i].dados.peso / pow(pessoas[i].dados.altura, 2);
	}
}

float calcularMediaIMC(struct pessoa *pessoas, int qntPessoas){
	int i;
	float mediaIMC, somatorio;

	somatorio = 0;
	for(i = 0; i < qntPessoas; i++){
		somatorio += pessoas[i].dados.imc;
	}
	mediaIMC = somatorio / qntPessoas;

	return mediaIMC;
}

void contarAcimaEAbaixoMediaIMC(struct pessoa *pessoas, int qntPessoas){
	int i, contAcima, contAbaixo;
	float mediaIMC;

	mediaIMC = calcularMediaIMC(pessoas, qntPessoas);

	contAbaixo = 0;
	contAcima = 0;
	for(i = 0; i < qntPessoas; i++){
		if(pessoas[i].dados.imc >= mediaIMC){
			pessoas[i].dados.situacao_imc = 1;
			contAcima++;
		}else{
			pessoas[i].dados.situacao_imc = -1;
			contAbaixo++;
		}
	}

	imprimirAgenda(pessoas, qntPessoas);
	printf("\n========================\n");
	printf("Total acima da media IMC %.2f eh: %d\n", mediaIMC, contAcima);
	printf("Total abaixo da media IMC %.2f eh: %d\n", mediaIMC, contAbaixo);
}

int main(){
	int n;
	struct pessoa *pessoas;

	n = pegaPositivo();
	pessoas = criaAgenda(n);
	lerPessoas(pessoas, n);

	contarGeneros(pessoas, n);
	calcularIMCPessoas(pessoas, n);

	imprimirAgenda(pessoas, n);
	contarAcimaEAbaixoMediaIMC(pessoas, n);

	return 0;
}













