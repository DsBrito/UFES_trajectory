
#include <stdio.h>

int main (int argc, char const *argv[]) {
    int i, n,k, somaM, qtsM;

	somaM = 0;
	qtsM = 0;
	printf("digite o numero desejado\n");
	scanf("%d",&k);

	printf("digite quantos multiplos de %d deseja somar\n", k);
	scanf("%d",&n);

	for (i=0; qtsM<=(n+1); i++){
        if (i%k == 0){
            somaM = (somaM+i);
            qtsM = (qtsM+1);
        }
	}
	somaM = (somaM-k);
	printf("a soma dos %d primeiros multiplos de %d eh %d\n", n,k,somaM);


    return 0;
}
