#include <stdio.h>
	
int main(){ 
int n1, n2, r1;
	scanf("%d%d", &n1, &n2);
r1= n2 % n1;
	if(r1 !=0){
	printf("RESP:%d", r1);
}
else{ 
	printf("RESP:%d", n1);
}
	return 0;
}
