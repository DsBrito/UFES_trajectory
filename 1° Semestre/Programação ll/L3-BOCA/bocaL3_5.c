#include <stdio.h>
#include <stdlib.h>

int Propriedade(int num){
    int ab, cd, ef;
    
    ab=num/100;
    cd=num%100;
    ef= ab + cd;
    
    if(ef*ef==num){
        return(1);
    }
    else{
        return(0);
    }
}

int main(int argc, char** argv) {
    int n, m;
    
    scanf("%d%d", &n,&m);
    for(n++; n<m; n++){
        
        if(Propriedade(n)){
            printf("%d\n", n);
        }
    }
    
    return (EXIT_SUCCESS);
}

