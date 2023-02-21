
#include <stdio.h>

int main (int argc, char const *argv[]) {
    float notat, media, n;
    int i, notac;

    notac = 0;
    notat = 0;
    for (i=0; i<10; i++) {
        printf("digite a nota do aluno %d\n ", (i+1));
        scanf("%f",&n);
        while (n<0) {
        	printf("digita uma nota valida\n");
         	scanf ("%f", &n);
		}
        notat = (notat+n);
        if (n>5) {
            notac = (notac+1);
        }
    }
    media = (notat/10);
    if (notac==0) {
        printf ("A media eh %0.3f e nao ha aluno acima de 5.0 \n", media);
    }else{
    printf("A media eh %0.3f e o numero de alunos acima de 5.0 foi %d \n", media, notac);
    }

    return 0;
}
