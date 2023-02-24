

#ifndef ALUNO_H
#define ALUNO_H

/*Tipo que define o aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  -nome (string)
  -CR(int)
  -matricula(int)
 */
typedef struct aluno tAluno;

/*Aloca e inicia o aluno
 * inputs: nome,matricula e CR
 * output: ´aluno é iniciado;
 * pre-condicao: entrada valida;
 * pos-condicao: aluno iniciado;
 */
tAluno *IniciaAluno(int matricula, char *nome, float CR);

/*Imprime dados do al;uno
 * inputs:  aluno;
 * output:  nenhum ;
 * pre-condicao: aluno valido;
 * pos-condicao:  dados  do aluno  impresso;
 */
void ImprimeAluno(tAluno *aluno);

/*recupera matricula de um aluno
 * inputs: aluno;
 * output: inteiro correspondente a matricula;
 * pre-condicao:  professor valido;
 * pos-condicao: matricula retornada
 */
int RetornaMatricula(tAluno *aluno);

/*recupera nome de um aluno
 * inputs: aluno;
 * output: string correspondente ao nome do aluno;
 * pre-condicao:  professor valido;
 * pos-condicao: nome retornado
 */
char *RetornaNomeAluno(tAluno *aluno);

/*recupera CR do aluno
 * inputs: aluno;
 * output: float correscondente ao CR;
 * pre-condicao:  professor valido;
 * pos-condicao: siape retornado
 */
float RetornaCR(tAluno *aluno);

/* libera aluno
 * inputs: aluno
 * output: memoria do aluno alocada  liberada;
 * pre-condicao: aluno valido;
 * pos-condicao:  memoria do aluno liberada;
 */
void DestroiAluno(tAluno *aluno);

#endif /* ALUNO_H */
