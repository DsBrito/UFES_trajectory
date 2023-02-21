#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int qtd, num, pos, i, menor;
    scanf("%d", &qtd);
    
    if(qtd==0){
    }
    else{
        for(i=1; i<=qtd; i++){
            scanf("%d", &num);
            if(i==1){
                menor= num;
                pos = i;
            }
            if(num<menor){
                menor= num;
                pos= i;
            }
        }
        printf("POS:%d", pos);
    }
    return (EXIT_SUCCESS);
}