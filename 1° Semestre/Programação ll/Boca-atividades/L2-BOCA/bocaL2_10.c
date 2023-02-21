#include <stdio.h>

int main(){
    int a,n,m;

    scanf("%d%d", &n, &m);

    for(n; n<=m; n++){
        for(a=1; a<=10; a++){
            printf("%d x %d = %d\n", n, a, (n*a));
        }
    }
    return 0;
}
