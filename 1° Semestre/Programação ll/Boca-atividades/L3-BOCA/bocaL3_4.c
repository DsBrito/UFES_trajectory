#include <stdio.h>
#include <stdlib.h>

int EhPrimo(int num){
    int i, p, div;
    p=0;
    
    for(i=1; i<=num; i++){
        div= num%i;
        
        if(div==0){
            p++;
        }
    }
    if(p==2){
        return (1);
    }
    else{
        return (0);
    }
}

void ImprimeMultiplos(int num, int max){
    int n=num, i=0;
    
    for(num++; num<max; num++){
        if(num%n==0){
            printf("%d ", num);
            i++;
        }
    }
    if(i==0){
        printf("*");
    }
    printf("\n");
}


int main(int argc, char** argv) {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    for(n++; n<m; n++){
        
        EhPrimo(n);
        
        if(EhPrimo(n)==1){
        printf("%d\n", n);
        ImprimeMultiplos(n, m);
        }
        
    }
                    
    return (EXIT_SUCCESS);
}

