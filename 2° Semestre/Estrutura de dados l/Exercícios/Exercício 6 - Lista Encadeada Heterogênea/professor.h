

#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct professor Professor;
Professor *IniciaProfessor(int siape, char *nome, float salario);
void ImprimeProfessor(Professor *professor);
int RetornaSiape(Professor *professor);
char *RetornaNomeProfessor(Professor *professor);
float RetornaSalario(Professor *professor);
void DestroiProfessor(Professor *professor);

#endif /* PROFESSOR_H */
