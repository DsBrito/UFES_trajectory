#include <stdio.h>

int main(){
char c1,c2,c3,c4,espaco;

    scanf("%c%c%c%c%c", &c1,&c2,&espaco,&c3,&c4);
    
    if(espaco == ' '){
    if((c1>='a' && c1<='z') || (c1>='A' && c1<='Z')|| (c1>='0' && c1<='9')){
    if((c2>='a' && c2<='z') || (c2>='A' && c2<='Z')|| (c2>='0' && c2<='9')){
    if((c3>='a' && c3<='z') || (c3>='A' && c3<='Z')|| (c3>='0' && c3<='9')){
    if((c4>='a' && c4<='z') || (c4>='A' && c4<='Z')|| (c4>='0' && c4<='9')){
    if((c1-'a') == (c3-'a') || (c1-'A') == (c3-'a') || (c1-'a') == (c3-'A') || (c1-'A') == (c3-'A')){
    if((c2-'a') == (c4-'a') || (c2-'A') == (c4-'a') || (c2-'a') == (c4-'A') || (c2-'A') == (c4-'A')){
    printf("IGUAIS");
}   
    else{ printf("DIFERENTES");}
}   else{ printf("DIFERENTES");}
}   else{ printf("Invalido");}    
}   else{ printf("Invalido");}
}   else{ printf("Invalido");}
}   else{ printf("Invalido");}
}   else{ printf("Invalido");}
    return 0;
}

