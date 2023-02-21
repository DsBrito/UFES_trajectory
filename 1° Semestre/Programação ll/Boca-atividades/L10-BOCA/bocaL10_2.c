#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int l, c, e, i, j, count=0;
    int qtdDeX=0;
    int a;
    char t;
    
    scanf("%d", &e);
    scanf("%c", &t);
    
    scanf("%d %d", &l, &c);
    scanf("%*c");
    char matriz[l][c+1];
    
    for(i=0; i<l; i++){
        for(j=0; j<c+1; j++){
            scanf("%c", &matriz[i][j]);
        }
    }
    
    if(t== 'H'){
        for(i=0; i<l; i++){
            for(j=0; j<c+1; j++){
                for(a=0; a<e; a++){
                    if(matriz[i][j+a]=='X')
                        qtdDeX++;
                }
                if(qtdDeX==e){
                    count++;
                }
                qtdDeX=0;
            }
        }
    }
    

    int b;
    if(t== 'V'){
        for(i=0; i<l; i++){
            for(j=0; j<c+1; j++){
                for(a=0; a<e; a++){
                    if(matriz[i+a][j]=='X')
                        qtdDeX++;
                }
                if(qtdDeX==e){
                    count++;
                }
                qtdDeX=0;
            }
        }
    }
    
    printf("CONT: %c %d", t, count);
    return (EXIT_SUCCESS);
}
