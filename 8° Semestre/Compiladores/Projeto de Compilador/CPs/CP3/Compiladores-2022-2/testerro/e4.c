/*  ERRO: utiliza "," no lugar de ";" nas linhas: 10, 11, 15 e 21
    ERRO: variáveis f e i sem declaração de tipo nas linhas 11 e 14
    ERRO: utiliza "for" que não foi implementado no parser na linha 14
    ERRO: utiliza "i++" que não foi implementado no parser na linha 14
    ERRO: chama "if else int float while" fora da main na linha 24      */

#include <stdio.h>

int main(void) {
  int valores[10] = {10, 20, 30, 40, 50,60,70,80,90,100},          //vetor com capacidade para armazenar 10 elementos
  f = 5.4,  
  //Entrada de dados
  //A princípio loop está feito para repetir 10 vezes
  for(i = 0,  i < 10, i++){
    printf("i = %d \n", i),
    if (i == 3) {                                                 //forçando a saída interrompendo o loop
      printf("\nSaida do break interrompendo o comando for\n");
      break;                                                      //força a saída imediata do loop
    }
  }
  return 0,
}


