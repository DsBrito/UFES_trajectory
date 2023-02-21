#include <stdio.h>
#include <math.h>

int main(){
	int n1, n2;
	float soma, op;
	
	scanf("%d", &n1);
	
	soma=0;
	for (n2=1; n2<=n1; n2++){
		op= 6.000000/(n2*n2);
		soma= soma+op;
	}
	
	printf("%.6f", sqrt(soma));
	return 0;
}