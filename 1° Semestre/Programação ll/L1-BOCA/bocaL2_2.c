#include <stdio.h>

int main(){

	int n, m;
	scanf("%d%d", &n, &m);
	
	n++;
	while(n<m){
		if(!(n%3) && !(n%4) && !(n%7)){
			printf("%d ", n);

		}else if(!(n%3) && !(n%4)){
			printf("%d ", n);

		}else if(!(n%3) && !(n%7)){
			printf("%d ", n);
		}else if(!(n%4) && !(n%7)){
			printf("%d ", n);
		
		}else if(!(n%3)){
			printf("%d ", n);

		}else if(!(n%4)){
			printf("%d ", n);
		
		}else if(!(n%7)){
			printf("%d ", n);
		}
		n++;
	}
	return 0;
}	