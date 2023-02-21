#include <stdio.h>

int main(){
char l1,l2,l3,traco,n1,n2,n3,n4;
int rl, rn;

  scanf("%c%c%c%c%c%c%c%c", &l1,&l2,&l3,&traco,&n1,&n2,&n3,&n4);

  if((l1>='a' && l1<='z' || l1>='A' && l1<='Z') && (l2>='a' && l2<='z' || l2>='A' && l2<='Z') && (l3>='a' && l3<='z' || l3>='A' && l3<='Z')){
rl=1;
} else {rl=0;}

  if ((n1>='0' && n1<='9') && (n2>='0' && n2<='9') && (n3>='0' && n3<='9') && (n4>='0' && n4<='9')){
rn=1;
} else{rn=0;}

  if (rl==1 && rn==1){
  printf("Codigo valido!\n");
}
  if (rl==1 && rn==0){
    printf("Codigo invalido!Problema nos numeros!\n");
  }
  if (rl==0 && rn==1){
    printf("Codigo invalido!Problema nas letras!\n");
  }
  if (rl==0 && rn==0){
    printf("Codigo invalido!Problema nas letras e nos numeros!\n");
  }
  return 0;
}
