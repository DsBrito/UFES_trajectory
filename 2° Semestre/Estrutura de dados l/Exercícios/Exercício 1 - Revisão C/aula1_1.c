

/*
 1) No arquivo aula1_1.c: Elabore um programa que declare 4 variáveis do tipo inteiro e 4 do
tipo ponteiro para inteiro e faça com que as variáveis ponteiro apontem para as variáveis
do tipo inteiro. Coloque comandos que permitam modificar os valores das variáveis inteiras
através das variáveis ponteiro. Faça a simulação passo-a-passo para visualizar o que está
acontecendo em cada linha do programa.
 */

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int  main (){

    //declarando as 4 varaiveis do tipo inteiro;
    int a= 2;
    int b= 4;
    int c= 8;
    int d= 16;

    //printandos o valores anteriores;
    printf("variaveis anteriores: a=%d, b=%d, c=%d,d= %d\n",a,b,c,d);
    
    
    
    
    //declarando as 4 variaveis do tipo ponteiro para inteiro;
    
    int* num1;
    int* num2;
    int* num3;
    int* num4;

   //fazendo as variaveis  ponteiro apontem para as variaveis do tipo inteiro;
    
    num1= &a;
    num2= &b;
    num3= &c;
    num4= &d;
 
    
    //printando os valores que as variaveis do tipo ponteiro  estao apontando
    printf("ponteiros apontando: num1=%d, num2=%d, num3=%d,num4= %d\n",*num1,*num2,*num3,*num4);
    
    
    //alterando os valores das variaveis utilizando os ponteros
    
    *num1=3;
    *num2=9;
    *num3=81;
    *num4= 1;
    
    //printandos o valores após a alteração;
    printf("variaveis após alteração a=%d, b=%d, c=%d,d= %d",a,b,c,d);
    
    return 0;
}



*/