#include <stdio.h>

int main(){
    char l1,l2, dist;

    scanf("%c", &l1); //leitura de um caractere inserido
    dist= l1 - 'a'; //distancia entre o caractere inserido do primeiro caractere minusculo "a"
    l2= 'A' + dist;//o caractere maiusculo correspondente tem a mesma distancia em relacao ao primeiro "A" do que o inserido e o "a"

    if(l1>= 'a' && l1<= 'z')//verifica se é minusculo
    printf("%c(%d)", l2, l2);

    else
    if(l1>= 'A' && l1<= 'Z')//verifica se é maiusculo
    printf("A letra deve ser minuscula!");

    else //caso não seja letra
     printf("Nao e letra!");
    return 0;
}
