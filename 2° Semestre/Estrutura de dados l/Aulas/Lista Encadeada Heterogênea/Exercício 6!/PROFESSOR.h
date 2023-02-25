/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PROFESSOR.h
 * Author: diona
 *
 * Created on 21 de Março de 2021, 18:13
 */

#ifndef PROFESSOR_H
#define PROFESSOR_H

/*Tipo que define o professor (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  -nome (string)
  -siape(int)
  -salario(float)
 */
typedef struct professor tProfessor;






/*Aloca e inicia o professor
* inputs: nome,siape e salario
* output: ´professor é iniciado;
* pre-condicao: entrada valida;
* pos-condicao: professor iniciado;
*/
tProfessor* IniciaProfessor(int siape,char* nome, float salario);






 
 /*Imprime dados do professsor;
* inputs:  professor;
* output:  nenhum ;
* pre-condicao: professor valido;
* pos-condicao:  dados  do professor  impresso;
*/
void ImprimeProfessor(tProfessor* p);



/*recupera siape de um professor
* inputs: professor;
* output: inteiro correspondente ao siape;
* pre-condicao:  professor valido;
* pos-condicao: siape retornado
*/
int RetornaSiape (tProfessor* p);



/*recupera nome de um professor
* inputs: professor;
* output: nome  correspondente ao professor;
* pre-condicao:  professor valido;
* pos-condicao: nome retornado
*/
char* RetornaNomeProfessor (tProfessor* p);


/*recupera salario de um professor
* inputs: professor;
* output: float correspondente ao salario;
* pre-condicao:  professor valido;
* pos-condicao: salario retornado
*/
float RetornaSalario (tProfessor* p);




 /* libera professor
* inputs: professor
* output: memoria do professor alocada  liberada;
* pre-condicao: professor valido;
* pos-condicao:  memoria do professor liberada;
*/

void DestroiProfessor (tProfessor* p);

#endif /* PROFESSOR_H */

