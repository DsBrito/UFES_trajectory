#include <stdio.h>

int main(){
	int i, n, m, div, mult, param;

	scanf ("%d%d", &n, &m);

	for(n = n+1; n<m; n++){
		div=0;
		for(i=1; i<=n; i++){
			if(n%i ==0){
				div++;
			}
		}
		if(div==2){
			printf("%d\n", n);
            mult=n+1;
            param=0;
            while(mult<m){
                if(mult%n==0){
                    printf("%d ", mult);
                    param++;
                }
                mult++;
            }
            if(param==0){ printf("*");}            
            printf("\n");
		}
	}
	return 0;
}
