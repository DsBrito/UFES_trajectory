#include <stdio.h>

int main(){
int dia,hora,min1, min2, r1, r2,a=0,b=0,c=0;

	scanf("%d:%d%d", &hora, &min1, &min2);
	
r1= (min1+min2)%60; //quantos minutos ficarao no relogio depois da soma com os minutos
r2= (hora+(min1+min2)/60)%24; // quantas horas ficarao no relogio depois da soma dos minutos mais as horas
dia= (hora+(min1+min2)/60)/24; //quantidade de dias

	if(dia=='1'){a++;} else{a=0;}
	if(r2=='1'){b++;} else{b=0;}
	if(r1=='1'){c++;} else{c=0;}

	if(a=='1' && b=='1' && c=='1'){
	printf("(%d dia)(%d hora)(%d minuto)\n", dia, r2, r1);

}else if (dia){
	if(r2){
	if(r1){
	printf("(%d dias)(%d horas)(%d minutos)\n", dia, r2, r1);

}else{printf("(%d dias)(%d horas)\n", dia, r2);}

}else if(r1){
	printf("(%d dias)(%d minutos)\n", dia, r1);
} else{printf("(%d dias)\n", dia);}

}else if(r2){
	if(r1){
printf("(%d horas)(%d minutos)\n",r2, r1);
} else {printf("(%d horas)\n", r2);}
} else {printf("(%d minutos)\n", r1);}
return 0;
}