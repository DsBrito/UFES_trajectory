#include<stdlib.h>
#include<math.h>
#include<stdio.h>


 /*//[QUESTÃO 2.1]
void calc_esfera(float r, float* area, float* volume){
    
    *area= (4*3.14*r*r);
    *volume=(4*3.14*r*r*r)/3;

};

 int main(){
 float r,area,volume;
    printf("Insira o valor do raio da esfera:\n");
    scanf("%f",&r);
    calc_esfera(r,&area,&volume);
    printf("\nA area dessa esfera eh:%.2f e o seu volume eh:%.2f\n\n",area,volume);
  }
*/                              






/*//[QUESTÃO 2.2]

int raizes(float a, float b, float c, float* x1, float* x2){

    float delta,conta;
    
    delta=sqrt(-4*a*c);
    if (delta >= 0){
        *x1= (((-b)+delta))/(2*a);
        *x2= (((-b)-delta))/(2*a);
        return 1;
    }
    else{
        return 0;
    
    }

};

int  main(){
    float a,b,c,x1,x2;
    int calculo;
    printf("\nInsira o valor de a:");
    scanf("%f",&a);
    printf("\nInsira o valor de b:");
    scanf("%f",&b);
    printf("\nInsira o valor de c:");
    scanf("%f",&c);
    calculo=raizes(a,b,c,&x1,&x2);
    if(calculo){
        printf("\n\n O valor de x1 eh :%.1f e o valor de x2  eh:%.1f",x1,x2);
    }
    else{
        printf("\n\n Os termos passados nao geram raizes reais !");

    }
}
*/
/*
//[QUESTÃO 2.3]
int pares (int n, int* vet){
    
    int i,cont=0;
    
    for(i=0;i<n;i++){
        if(vet[i]%2==0){
            cont = cont+1;
        }
    
    }
    return cont;

};

 int main(){ 
    int i,par,n;
    
    printf("\nInsira o tamanho do vetor:");
    scanf("%d",&n);
    
    int* vet;
    vet=malloc (n * sizeof (int));
    for(i=0;i<n;i++){
        printf("\nInsira o valor da posição [%d] do vetor:",i);
        scanf("%d",&vet[i]);
    
    }
    par = pares (n,vet);
    printf("\n a quantidade de numeros pares presentes nesse vetor eh :%d",par);
return 0;}
 */




/*
 //[QUESTÃO 2.4]
void inverte (int n, int* vet){
    int i;
    for(i=0;i<n;i++){
        printf("\nVetor Invertido:%d",vet[n-(i+1)]);
        }

};

void main(){
    
    int i,n; 
    printf("\nInsira o tamanho do vetor:");
    scanf("%d",&n);
    
    int* vet;
    vet=malloc (n * sizeof (int));
    for(i=0;i<n;i++){
        printf("\nInsira o valor da posição [%d] do vetor:",i+1);
        scanf("%d",&vet[i]);
    
    }
      inverte (n,vet);
}*/

/*
 //[QUESTÃO 2.5]
double avalia (double* poli, int grau, double x){
//12-2-3
    int i;
    double j=1.0;
    double result=0.0;

    for (int i = 0; i <(grau+1); i++) {
        result= result+ (poli[i]*j);
        
        //a variavel "j" o valor de x a medida que o grau vai aumentando
        j=j*x;
    }

        printf("resultado %lf\n", result);
        return result;





};


int main(){
    int grau,i;
    double* poli;
    double conta,x;

    printf("\nInsira o grau do polinomio:");
    scanf("%d",&grau);
    printf("\nInsira o valor de x:");
    scanf("%lf",&x);
    
    //alocando memoria para o vetor
    poli=malloc (grau * sizeof (double));
    
    for(i=0;i<(grau+1);i++){
        printf("\nInsira os termos no sentido do menor para o maior grau:");
        scanf("%lf",&poli[i]);
    }
    
    conta=avalia(poli,grau, x);
    
    free(poli);

}*/