#include <stdio.h>

int main(){
int n1,n2,n3;

	scanf("%d%d%d", &n1,&n2,&n3);

	if(n1<n2 && n2< n3){
	printf("crescente");
}
	else if(n3<n2 && n2<n1){
	printf("decrescente");
}
	else
 	printf("tudo doido");

return 0;

}
