
#include<stdio.h>

int main(){
char frase[15];
int i;
printf("Digite a frase:\n");
scanf("%[^\n]",frase);
for(i=0;i<15;i++){
	if((frase[i]=='a')||(frase[i]=='e')||(frase[i]=='i')||(frase[i]=='o')||(frase[i]=='u')||(frase[i]=='A')||(frase[i]=='E')||(frase[i]=='I')||(frase[i]=='O')||(frase[i]=='U')){
		printf("%c",frase[i]);
	}
}

	return 0;
}
