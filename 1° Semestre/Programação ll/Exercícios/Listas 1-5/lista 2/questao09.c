
#include <stdio.h>


int main(){
int A[10],B[10],i,produtoEscalar;
printf ("Digite os valores do vetor A\n");
for(i=0;i<10;i++){
	printf("A[%d]:",i+1);
	scanf("%d",&A[i]);
}
printf("Digite os valores do vetor B\n");
for(i=0;i<10;i++){
	printf("B[%d]:",i+1);
	scanf("%d",&B[i]);
}
for(i=0;i<10;i++){
	produtoEscalar=produtoEscalar+(A[i]*B[i]);
}
printf("O produto escalar eh %d ",produtoEscalar);

	return 0;
}
