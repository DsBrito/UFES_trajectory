


/*
 2) No arquivo aula1_2.c: Implemente funções em C para cada um dos problemas abaixo
(todas as funções devem estar em um único arquivo aula1_2.c). Para cada uma das
funções, implemente uma função main diferente (comente as outras para conseguir
rodar):
 * 
 * 
 * 
 * 
2.1) Implemente uma função que calcule a área da superfície e o volume de uma esfera
de raio r. A área da superfície e o volume são dados, respectivamente, por e
. Essa função deve obedecer ao seguinte protótipo: void calc_esfera
(float r, float* area, float* volume);
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*

void calc_esfera(float r, float* area, float* volume);

int main(){

    float r,a,v;
    
    printf("\nInsira o raio da esfera a ser calculado:");
    scanf("%f",&r);
    
    calc_esfera(r,&a,&v);

    printf(" \nAh area da esfera eh: %.2f e o seu volume eh de:%.2f\n",a,v);
    return 0;
}


void calc_esfera(float r, float* area, float* volume){


    *area= (4*3.14*r*r);         //-> area é dado por 4 * pi * r²
    
    
    *volume=(4*3.14*r*r*r)/3;     //-> volume é dado por 4 * pi * r³


};
 * 
 * */


/**
 2.2) Implemente uma função que calcule as raízes de uma equação do segundo grau, do
tipo ax2 + bx + c = 0. Essa função deve obedecer o seguinte protótipo: int raizes
(float a, float b, float c, float* x1, float* x2);
 */

/*
 
int raizes(float a, float b, float c, float* x1, float* x2);

int main(){

    float a,b,c;
    int real;
    float x1,x2;
    
    printf("\nInsira o coeficiente a:");
    scanf("%f",&a);
    printf("\nInsira o coeficiente b:");
    scanf("%f",&b);
    printf("\nInsira o coeficiente c:");
    scanf("%f",&c);
     
    real= raizes(a,b,c,&x1,&x2);

    if(real==0 )
         printf("\n Essa equação nao possui raizes reais \n");
    
    else{
        printf(" \nX1= %f\nX2=%f",x1,x2);
    }
    return 0;
}




int raizes(float a, float b, float c, float* x1, float* x2){

  //calculando o delta;
    // b² – 4ax
    
    float delta,raiz;
    
    delta= (b*b) - (4*a*c);
    
    if (delta<0){
        return 0;
    }
    
    raiz= sqrt(delta);
    
    //calculando a equação se o delta for positivo;
        //iniciando por X1
    *x1 = ((-b) + raiz )/(2*a);
    
       //calculando x2
    
    *x2 = ((-b) - raiz )/(2*a);
    
      return 1;



};
*/



/*2.3)
 Implemente uma função que receba como parâmetro um vetor de números inteiros
(vet) de tamanho n e retorne quantos números pares estão armazenados nesse
vetor. Essa função deve obedecer ao protótipo: int pares (int n, int* vet);
 */


/*
int pares (int n, int* vet);

int main(){

    int* vet;
    int i;
    int tamanho,quantidade;
    
    printf("Insira o tamanho do veto:");
    scanf("%d",&tamanho);
    
    vet=(int*)malloc(tamanho*sizeof(int));
    
    for(i=0;i<tamanho;i++){
        printf("\nInsira o valor a posição [%d]:",i+1);
        scanf("%d",&vet[i]);
    }
    
    quantidade=pares(tamanho,vet);
 
    printf("\n A quantidade de numero par presente no vetor eh de : %d",quantidade);
 
    free(vet);
}

int pares (int n, int* vet){
    
    int contador=0;
    int i;
    
    for(i=0;i<n;i++){
        if(vet[i]%2==0)
            contador=contador+1;
    }
    
    return contador;

};

*/

/*
 
 2.4) Implemente uma função que receba como parâmetro um vetor de números inteiros
(vet) de tamanho n e inverta a ordem dos elementos armazenados nesse vetor.
Essa função deve obedecer ao protótipo: void inverte (int n, int* vet);
 
 */

/*
 
void inverte (int n, int* vet);

int main(){

    int* vet;
    int i;
    int tamanho;
    
    printf("Insira o tamanho do veto:");
    scanf("%d",&tamanho);
    
    vet=(int*)malloc(tamanho*sizeof(int));
   
    
    
    for(i=0;i<tamanho;i++){
        printf("\nInsira o valor a posição [%d]:",i+1);
        scanf("%d",&vet[i]);
    }
    
    inverte(tamanho,vet);
 
    free(vet);
}


void inverte (int n, int* vet){
    
    int i;
    int* vetorInverso=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        vetorInverso[i]=vet[(n-1)-i];
    }
    

    for(i=0;i<n;i++){
        printf("\n[%d]",vetorInverso[i]);
    }

}
 */


/*
 
 2.5) Implemente uma função que permita a avaliação de polinômios. Cada polinômio é
definido por um vetor que contém seus coeficientes. Por exemplo, o polinômio de
grau 2, 3x2 + 2x+ 12, terá um vetor de coeficientes igual a vet[] = {12, 2, 3}. A
função deve obedecer o seguinte protótipo: double avalia (double* poli, int
grau, double x);
 
 */

/*
 
double avalia (double* poli, int grau, double x);
int main(){

    double* polinomio;
    int i;
    int grau;
    double incognita;
    double conta;
    
    printf("Insira o grau do polinomio:");
    scanf("%d",&grau);
  
    printf("\nInsira o valor do x:");
    scanf("%lf",&incognita);
    
    
    polinomio=(double*)malloc(grau*sizeof(double));
   
    
    
    for(i=0;i<(grau);i++){
        printf("\nInsira o valor a posição [%d]:",i+1);
        scanf("%lf",&polinomio[i]);
    }
    
   conta=avalia(polinomio,grau,incognita);
   
    printf("o resultado do polinomio eh %lf:",conta);
    free(polinomio);
}


double avalia (double* poli, int grau, double x){

    int i;
    
    double conta=0.0;
    
    double GrauAux=1.0;
    
    for(i=0;i<(grau+1);i++){
        
        conta= conta + (poli[i]*GrauAux);//para o termo elevado a zero
        
        GrauAux=GrauAux*x;//para os seguintes termos;
     

    }

    return conta;



};*/