

#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;
Aluno *IniciaAluno(int matricula, char *nome, float CR);
void ImprimeAluno(Aluno *aluno);
int RetornaMatricula(Aluno *aluno);
char *RetornaNomeAluno(Aluno *aluno);
float RetornaCR(Aluno *aluno);
void DestroiAluno(Aluno *aluno);

#endif /* ALUNO_H */
