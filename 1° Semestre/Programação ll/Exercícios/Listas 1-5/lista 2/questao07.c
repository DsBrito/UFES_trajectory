
#include <stdio.h>

int main(){
int A[5], B[8], C[5],i,j,k,l,repetido=0;

printf("Digite os valores do vetor de tamanho 5\n");
for(i=0;i<5;i++){
	printf("A[%d]:",i+1);
	scanf("%d",&A[i]);
}
printf("Digite os valores do vetor de tamanho 8\n");
for(i=0;i<8;i++){
	printf("B[%d]:",i+1);
	scanf("%d",&B[i]);
}
for(i=0;i<5;i++){
	C[i]=0;
}

for(i=0;i<5;i++){
	for(j=0;j<8;j++){
		if(A[i]==B[j]){
			for(k=0;k<5;k++){
				if(A[i]==C[k]){
					repetido=1;
				}
			}
			if(repetido==0){
				C[l]=A[i];
				l++;
			}
		}
		repetido=0;
	}
}

printf("Os elementos em comum entre os vetores sao:\n");
for(i=0;i<l;i++){
	printf("%d  ",C[i]);
}


	return 0;
}
