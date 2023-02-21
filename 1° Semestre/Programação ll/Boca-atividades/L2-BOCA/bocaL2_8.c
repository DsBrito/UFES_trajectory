#include <stdio.h>

int main(){
	int i, n, m, div;

	scanf ("%d%d", &n, &m);
	printf("RESP:");
	for(n = n+1; n<m; n++){
		div=0;
		for(i=1; i<=n; i++){
			if(n%i ==0){
				div++;
			}
		}
		if(div==2){
			printf("%d ", n);
		}
	}
	return 0;
}