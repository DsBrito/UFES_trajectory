#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<ctype.h>


//biblioteca ctyp

// a fun��o ira contar quantos digitos tem em um texto e o retornar seu valor, o texto vai ser insirido na main e ir� imprimir o retorno da fun��o cont
int cont(char*s)   //a entrada da fun��o � um array
{
 int i;
 int conta=0;
for(i=0;s[i]!='\0';i++){    // enquanto nao encontrar o caractere limitador '\0' i ir� ser acrescentado +1

    if (isdigit(s[i])){      // se o caractere for um numero, conta ir� ser acrescentado +1
    conta++;}
    }

    return conta;

}
main(){
char texto[100];

printf("\nDigite o texto:");
gets(texto);

printf("%d", cont(texto));





getch();
return 1;
}

