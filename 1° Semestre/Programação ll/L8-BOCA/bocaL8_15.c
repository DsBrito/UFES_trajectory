#include <stdio.h>

int main(){

int N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N11, X1, X2, X3, X4, V1, V2, V3, V4, A, B, DIG1, DIG2, VERIFICADOR10, VERIFICADOR11;
scanf("%d.%d.%d-%d", &X1, &X2, &X3, &X4);

N1 = X1 / 100;
V1 = X1 % 100;
N2 = V1 / 10;
N3 = V1 % 10;

N4 = X2 / 100;
V2 = X2 % 100;
N5 = V2 / 10;
N6 = V2 % 10;

N7 = X3 / 100;
V3 = X3 % 100;
N8 = V3 / 10;
N9 = V3 % 10;

N10 = X4 / 10;
N11 = X4 % 10;

VERIFICADOR10 = (N1*10) + (N2*9) + (N3*8) + (N4*7) + (N5*6) + (N6*5) + (N7*4) + (N8*3) + (N9*2);

A = VERIFICADOR10 % 11;

if(A < 2){
	DIG1 = 0;
}
else{
	DIG1 = 11 - A;
}

VERIFICADOR11 = (N1*11) + (N2*10) + (N3*9) + (N4*8) + (N5*7) + (N6*6) + (N7*5) + (N8*4) + (N9*3) + (DIG1*2);

B = VERIFICADOR11 % 11;

if(B < 2){
	DIG2 = 0;
}
else{
	DIG2 = 11 - B;
}


if(N1 == N2 && N1 == N3 && N1 == N4 && N1 == N5 && N1 == N6 && N1 == N7 && N1 == N8 && N1 == N9 && N1 == N10 && N1 == N11){
	printf("CPF invalido: digitos iguais!");
	return 0;
}

if(DIG1 == N10 && DIG2 == N11){
	printf("CPF valido!");
}
if(DIG1 != N10 && DIG2 != N11){
	printf("CPF invalido: dois digitos!");
}
if(DIG1 != N10 && DIG2 == N11){
	printf("CPF invalido: primeiro digito!");
}
if(DIG1 == N10 && DIG2 != N11){
	printf("CPF invalido: segundo digito!");
}


} 

