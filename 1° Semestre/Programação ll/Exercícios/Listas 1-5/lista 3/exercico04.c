/*Crie uma estrutura representando os alunos de uma turma. A estrutura deve conter a matr�cula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova (matricula = int, nome = char[25], nota p1 = float, nota p2 = float, nota p3 = float). Lei um vetor com as informa��es dos 5 alunos da turma. Ap�s isso fa�a:
(a) Uma fun��o que receba o vetor de alunos e retorne o aluno com maior nota da primeira prova.
(b) Uma fun��o que receba o vetor de alunos e retorne o aluno com maior m�dia geral.
(c) Uma fun��o que receba o vetor de alunos e retorne o aluno com menor m�dia geral
(d) Uma fun��o que receba o vetor de alunos e para cada aluno diga se ele foi aprovado ou reprovado, considerando 7.0 como m�dia final para aprova��o.
Imprima os resultados.
*/
struct informacoes_pessoais{
	char nome[25];
	int matricula;
	int notaP1;
	int notaP2;
	int notaP3;
};
float maiorP1(struct informacoes_pessoais){
	int i;
	float maiornotaP1;

	maiornotaP1 = informacoes_pessoais
	for(i = 0; i < 5; i++){
		if (maiornotaP1 < informacoes_pessoais){
            maiornotaP1 = informacoes_pessoais
		}
	}

	return maiornotaP1;
}
float calcularMediaAlunos(struct informacoes_pessoais){
	int i;
	float mediaAlunos, somatorioAlunos;

	somatorio = 0;
	for(i = 0; i < 5; i++){
		somatorio += informacoes_pessoais[i].notaP1;
	}
	mediaIMC = somatorio / qntPessoas;

	return mediaIMC;
}
