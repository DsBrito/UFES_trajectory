/**/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>



/* Funcao principal*/
int main(){
    setlocale(LC_ALL,"Portuguese");

    //VARIAVEIS
    float loop;
    int numx;
    int num;
    int x;
    float a,b,exponencial;
    float igual1,igual2;
    float soma1,soma2;
    float n1,n2,n3;
    int num1, num2, num3, num4, num5;
    int aux;

    /* Loop infitinito ate o usuario mandar interromper, saindo por um comando break*/
    while(1)
    {
        /*Questione se eh para continuar no loop*/
        printf("\n\nDigite (1) para dar inicio ao programa e (0) para sair  ): ");
        scanf("%f", &loop);

        /**/
        if(loop == 1){
                printf("\n (1)- Quest�o ? \n (2)- Quest�o ? \n (3)- Quest�o ?\n (4)- Quest�o ? \n (5)- Quest�o ?\n (6)- Quest�o ? \n (7)- Quest�o ? \n (8) -Quest�o ? \n (9)- Quest�o ? \n (10)- Quest�o?\n\n");
                printf("\n insira o numero da quest�o que deseja execultar:\t");
                scanf("%d",&numx);

            {
            switch (numx)
            {
                case 1:
                    printf("\n# PAR OU �MMPAR ?\t");
                    printf("\nDigite o Numero:\t");
                    scanf("%d",&num);
                    if (num%2==0) {
                    printf(" Este numero � par");
                    break;}
                    else{
                        printf(" Este numero � impar");
                    break;}
                case 2:
                    printf("\n# IGUAIS ?:\t");
                    printf("\nDigite o Numero:\t");
                    scanf("%f",&igual1);
                    printf("\nDigite o Numero:\t");
                    scanf("%f",&igual2);
                    if (igual1==igual2){
                        printf("os numeros  s�o iguais");
                    break;}
                    else{
                        printf("os numeros n�o s�o iguais");
                    break;}
                case 3:
                    printf("\n# SOMA ?\t");
                    printf("\nDigite o numero:\t");
                    scanf("%f",&soma1);
                    printf("\nDigite o segundo numero:\t");
                    scanf("%f",&soma2);
                    printf("%f", soma1 + soma2);
                    break;
                case 4:
                    printf("\n# MENOR QUE 25 ou MAIOR QUE 80 ou IGUAL A 40?:\t");
                    printf("\nDigite o numero:\t");
                    scanf("%f",&num);
                    if(num<25){
                    printf("o valor � menor que 25");
                    break;}
                    else if (num==40){
                    printf("o numero � igual 40");
                    break;}
                    else if (num>80){
                    printf("o numero � maior que 80");
                    break;}
                    else{
                    printf("o numero n�o � menor que 25, nem igual 40 e n�o � maior que 80");
                    break;}


                case 5:
                    printf("\n# DIVISIVEL POR 10 ou 5 ou 2?:\t");
                    printf("\nDigite o numero:\t");
                    scanf("%d",&num);
                    if (num%10==0 && num%5==0 && num%10==0){
                        printf("esse numero � divisivel ao mesmo tempo por 10,5 e 2");
                    }
                    else if (num%10==0 && num%5==0){
                        printf("esse numero � divisivel ao mesmo tempo por 10 e 5 ");
                        break;}
                    else if (num%10==0 && num%2==0){
                        printf("esse numero � divisivel ao mesmo tempo por 10 e 2 ");
                        break;}
                    else if (num%5==0 && num%2==0){
                    printf("esse numero � divisivel ao mesmo tempo por 5 e 2 ");
                        break;}
                    else if (num%5==0){
                        printf("esse numero � divisivel apenas por 5 ");
                        break;}
                    else if (num%2==0){
                        printf("esse numero � divisivel apenas por 2 ");
                        break;}
                    else{
                        printf("N�o � divisivel por 10 nem por 5 e nem por 2");
                        break;}

                case 6:
                    printf("\n# ESTA CONTIDO NO INTERVALO ?\t");
                    printf("\nDigite o numero:\t");
                    scanf("%d",&num);
                    if (num<=30){
                        printf("esse numero esta no intervalo de ]-10,30]");
                        break;}
                    else{
                        printf("esse numero n�o est�o no intervalo de ]-10,30]");break;}
                case 7:
                    printf("\n# QUE M�S ?\t");
                    printf("\nDigite o numero:\t");
                    scanf("%d",&x);
                         switch (x) {
                           case 1:printf(" M�s de janeiro");break;
                           case 2:printf(" M�s de fervereiro");break;
                           case 3:printf(" M�s de mar�o");break;
                           case 4:printf(" M�s de abril");break;
                           case 5:printf(" M�s de maio");break;
                           case 6:printf(" M�s de junho");break;
                           case 7:printf(" M�s de julho");break;
                           case 8:printf(" M�s de agosto");break;
                           case 9:printf(" M�s de setembro");break;
                           case 10:printf(" M�s de outrubro");break;
                           case 11:printf(" M�s de novembro");break;
                           case 12:printf(" M�s de dezembro");break;
                           default: printf(" este numero n�o corresponde a um m�s");}break;
                case 8:
                printf("\n# QUAL � O MAIOR ?\t");
                printf("\nDigite o primeiro numero:\t");
                scanf("%f",&n1);
                printf("\nDigite o segundo numero:\t");
                scanf("%f",&n2);
                printf("\nDigite o terceiro numero:\t");
                scanf("%f",&n3);
                if (n1==n2 && n1==n3){
                    printf("os numeros s�o todos iguais");break;}
                else if (n1==n2&& n1>n3){
                    printf(" o primeiro e o segundo numero s�o iguais e maiores que o terceiro");break;}
                else if (n1==n3&& n1>n2){
                    printf(" o primeiro e o terceiro numero s�o  iguais e maiores que o segundo");break;}
                else if (n2==n3&& n2>n1){
                    printf("   o segundo e o terceiro numero s�o iguais e maiores que o primeiro"); break;}

                else if (n1==n2&& n1<n3){
                    printf(" primeiro e o segundo numero s�o iguais e menores que terceiro");break;}
                else if (n1==n3&& n1<n2){
                    printf("primeiro e o terceiro numero s�o iguais e menores que o segundo");break;}
                else if (n2==n3&& n2<n1){
                    printf("o segundo e o terceiro  numero s�o iguais e menores que o primeiro");break;}

                else if (n1>n3 && n1>n2){
                    printf("o priemeiro numero � maior:");break;}
                else if  (n2>n1 && n2>n3){
                    printf("o segundo numero  � o maior:");break;}
                else if (n3>n2 && n3>n1){
                    printf("o terceiro numero � o maior");break;}


                case 9:
printf("      ORDENA��O DE NUMEROS   \n\n");
   printf("Informe 5 (cinco) numeros inteiros:\t");
   scanf("%d %d %d %d %d",&num1, &num2, &num3,
                          &num4, &num5);

   if (num2 < num1) {
      aux = num2;
      num2 = num1;
      num1 = aux;
   }

   if (num3 < num1) {
      aux = num3;
      num3 = num1;
      num1 = aux;
   }

   if (num4 < num1) {
      aux = num4;
      num4 = num1;
      num1 = aux;
   }

   if (num5 < num1) {
      aux = num5;
      num5 = num1;
      num1 = aux;
   }

   if (num2 > num5) {
      aux = num2;
      num2 = num5;
      num5 = aux;
   }

   if (num3 > num5) {
      aux = num3;
      num3 = num5;
      num5 = aux;
   }

   if (num4 > num5) {
      aux = num4;
      num4 = num5;
      num5 = aux;
   }
   if (num3 < num2) {
      aux = num2;
      num2 = num3;
      num3 = aux;
   }

   if (num4 < num2) {
      aux = num2;
      num2 = num4;
      num4 = aux;
   }

   if (num3 > num4) {
      aux = num3;
      num3 = num4;
      num4 = aux;
   }
   printf("\n\n");
   printf("Ordem CRESCENTE: %d  %d  %d  %d  %d\n",num1,num2,num3,num4,num5);


   printf("Ordem DECRESCENTE: %d  %d  %d  %d  %d\n\n",num5,num4,num3,num2,num1);break;


       case 10:
                printf("\n# EXPONENCIAL ?\t");
                printf("\nDigite o numerador:\t");
                    scanf("%f",&a);
                    printf("\nDigite o expoente:\t");
                    scanf("%f",&b);
                    exponencial = pow(a,b);
                    printf("o resultado � %f",exponencial);












}











            printf("\n\n\nInsira qualquer tecla para continuar");

            getch();
            setbuf(stdin, NULL);
            system("cls || clear");



 }}else if (loop==0){
                        break;
            }
}}


