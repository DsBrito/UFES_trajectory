#include <stdio.h>

int main(){
    int ab, cd, ef, n, m;

    scanf("%d%d", &n, &m);

    if(n>1000 && m<9999){
        for(n++; n<m; n++){
            ab= n/100;
            cd= n%100;
            ef= ab + cd;
            if(ef*ef==n){
                printf("%d\n", n);
            }
        }
    }
    return 0;
}
            
