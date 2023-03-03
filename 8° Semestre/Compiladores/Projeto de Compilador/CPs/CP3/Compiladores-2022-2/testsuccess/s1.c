//primeiro teste
//testa:
//int

#include <stdio.h>

int main(void) {
  int i = 0;
  float f;

  //Entrada de dados
  //A princípio loop está feito para repetir 10 vezes
  while(i < 10){
    if (i == 4) {                                                   //forçando a saída interrompendo o loop
      printf("\nSaida do break interrompendo o comando while\n");
      break;                                                        //força a saída imediata do loop
    }
    else {
      printf("i = %d \n",i);
    }
    i = i + 1;
  }

  int a;

  return 0;
}