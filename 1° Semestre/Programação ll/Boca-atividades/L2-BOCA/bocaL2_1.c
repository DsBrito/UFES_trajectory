#include <stdio.h>

int main(){
	int n,m;
    	scanf("%d%d", &n, &m);
    
    	n++;
	printf("RESP:");

    	while(n<m){
		if(!(n%2)){
    			printf("%d ",n);
			n++;
    		}else{n++;}
	}
	return 0;
}
