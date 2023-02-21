#include <stdio.h>

int main(){
int x1,y1,x2,y2;

	scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
	if((x1<x2)&&(y1<y2)){
	printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",x1,y2,x1,y1,x2,y1,x2,y2);
}
	if((x2<x1)&&(y2<y1)){
	printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",x2,y1,x2,y2,x1,y2,x1,y1);
}
	if((x1<x2)&&(y1>y2)){
	printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",x1,y1,x1,y2,x2,y2,x2,y1);
}
	if((x2<x1)&&(y2>y1)){
	printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",x2,y2,x2,y1,x1,y1,x1,y2);
}
	return 0;
}
