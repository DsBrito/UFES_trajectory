#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<ctype.h>


//biblioteca ctyp

// a função ira contar quantos digitos tem em um texto e o retornar seu valor, o texto vai ser insirido na main e irá imprimir o retorno da função cont
int cont(char*s)   //a entrada da função é um array
{
 int i;
 int conta=0;
for(i=0;s[i]!='\0';i++){    // enquanto nao encontrar o caractere limitador '\0' i irá ser acrescentado +1

    if (isdigit(s[i])){      // se o caractere for um numero, conta irá ser acrescentado +1
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

