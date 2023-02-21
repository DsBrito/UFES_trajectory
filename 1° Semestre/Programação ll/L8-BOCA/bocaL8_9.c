#include <stdio.h>

int main(){
char c1,c2,c3,esp,c4,c5,c6, r1=0,r2=0,r3=0;

	scanf("%c%c%c%c%c%c%c", &c1,&c2,&c3,&esp,&c4,&c5,&c6);

	if(esp == ' '){
	if((c1>='0' && c1<='9') && (c4>='0' && c4<='9')){
	if((c2>='a' && c2<='z') && (c5>='a' && c5<='z')){
	if(((c3>='a' && c3<='z') || (c3>='A' && c3<='Z')) && ((c6>='a' && c6<='z') || (c6>='A' && c6<='Z'))){
if(c1==c4){
r1++;
} else {r1=0;}

 if(c2==c5){
r2++;
} else {r2=0;}

if(c3==c6){
r3++;
}else if(((c3-'a')==(c6-'A')) || ((c3-'A')==(c6-'a'))){
r3=2;
}else {r3=0;}

if (r1==1 && r2 ==1 && r3 ==1){
	printf("III");
}else if(r1==0 && r2 ==1 && r3 ==1){
	printf("DII");
}else if(r1==1 && r2 ==0 && r3 ==1){
	printf("IDI");
}else if(r1==1 && r2 ==1 && r3 ==0){
	printf("IID");
}else if(r1==0 && r2 ==0 && r3 ==1){
	printf("DDI");
}else if(r1==0 && r2 ==1 && r3 ==0){
	printf("DID");
}else if(r1==1 && r2 ==0 && r3 ==0){
	printf("IDD");
}else if(r1==0 && r2 ==0 && r3 ==0){
	printf("DDD");
}else if(r1==1 && r2 ==1 && r3 ==2){
	printf("IIC");
}else if(r1==0 && r2 ==1 && r3 ==2){
	printf("DIC");
}else if(r1==1 && r2 ==0 && r3 ==2){
	printf("IDC");
}else if(r1==0 && r2 ==0 && r3 ==2){
	printf("DDC");
}

}	else {printf("Codigo invalido!");}
}	else {printf("Codigo invalido!");}
}	else {printf("Codigo invalido!");}
}	else {printf("Codigo invalido!");}

return 0;
}