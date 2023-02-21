/*Crie uma estrutura representando os alunos de uma turma. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova (matricula = int, nome = char[25], nota p1 = float, nota p2 = float, nota p3 = float). Lei um vetor com as informações dos 5 alunos da turma. Após isso faça:
(a) Uma função que receba o vetor de alunos e retorne o aluno com maior nota da primeira prova.
(b) Uma função que receba o vetor de alunos e retorne o aluno com maior média geral.
(c) Uma função que receba o vetor de alunos e retorne o aluno com menor média geral
(d) Uma função que receba o vetor de alunos e para cada aluno diga se ele foi aprovado ou reprovado, considerando 7.0 como média final para aprovação.
Imprima os resultados.
*/


struct informacoes_alunos{
	char nome[25];
	int matricula;
	float notaP1;
	float notaP2;
	float notaP3;
	float media;
};

void lerAlunos(struct aluno){
	int i;
	char lixo;

	printf("Informe os dados dos alunos: \n");
	for(i = 0; i < 4; i++){
		printf("Nome: \n");
		scanf("%s", informacoes_pessoais.nome[i]);

		printf("Matricula: \n");
		scanf("%c", &lixo);
		scanf("%d", &(informacoes_pessoais.matricula[i]));

		printf("Nota P1: ");
		scanf("%f", &(informacoes_pessoais.notaP1[i]));
		printf("Nota P2: ");
		scanf("%f", &(informacoes_pessoais.notaP2[i]));
		printf("Nota P1: ");
		scanf("%f", &(informacoes_pessoais.notaP2[i]));
	}
}
float maiorP1(struct informacoes_pessoais){
	int i;
	float maiorP1;

	maiorP1 = informacoes_pessoais.notaP1[0];
	for(i = 0; i < 4; i++){
            if (maiorP1 < informacoes_pessoais.notaP1[i]){
                maiorP1 = informacoes_pessoais.notaP1[i];
            }
	}


	return maiorP1;
}

void calcularMediaAluno(struct informacoes_pessoais){
	int i;

	for(i = 0; i < 4; i++){
		informacoes_alunos.media[i] = ((informacoes_alunos.notaP1[i]+informacoes_alunos.notaP2[i]+informacoes_alunos.notaP3[i])/3)
			}
}
void calcularMediaGeral(struct informacoes_alunos.media){
	int i;
	float media

	media = ((media[0]+media[1]+media[2]+media[3]+media[4])/5)
}
float maiorMedia(struct informacoes_alunos.media, media){
	int i;
	float media, maiorMediaAluno;

	maiorMediaAluno = informacoes_alunos.media[0];
	for(i = 0; i < 4; i++){
		if (maiorMediaAluno < informacoes_alunos.media[i]){
            maiorMediaAluno = informacoes_alunos.media[i];
		}
	}

	return maiorMediaAluno;
}
float menorMedia(struct informacoes_alunos.media, media){
	int i;
	float media, menorMediaAluno;

	menorMediaAluno = informacoes_alunos.media[0];
	for(i = 0; i < 4; i++){
		if (menorMediaAluno < informacoes_alunos.media[i]){
            menorMediaAluno = informacoes_alunos.media[i];
		}
	}

	return menorMediaAluno;
}

int main(){
	struct aluno;


	lerAlunos(alunos, 5);

	calcularIMCPessoas(alunos, 5);

	maiorP1(alunos, 5);
	maiorMedia(alunos,5);
	menorMedia(alunos, 5);

	return 0;
}
