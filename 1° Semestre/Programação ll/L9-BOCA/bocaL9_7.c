#include <stdio.h>
#include <stdlib.h>

double LeNotasECalculaMediaAluno (){
    int nota, menor, soma=0, i=0;
    while(scanf("%d", &nota)==1){
        if(i==0){
            menor=nota;
        }
        if(nota<menor){
            menor=nota;
        }
        i++;
        soma= soma + nota;
    }
    scanf("]");
    if(i==1){
        return soma;
    }
    else{
        return (soma-menor)/(i-1);
    }
}

int ContaAlunosAprovadosTurma (){
    int media, alunos, qtd=0, i;
    char letra1, letra2, nome;
    scanf("%d", &alunos);
    
    for(i=0; i<alunos; i++){
        scanf("\n");
        scanf("%c%c", &letra1, &letra2);
        scanf("[");
        nome= letra1;
        media= LeNotasECalculaMediaAluno();
        if(media>=70){
            printf("%c\n", nome);
            qtd++;
        }
    }
    return qtd;
}

int main(int argc, char** argv) {
    int turmas, i, qtd, maior, menor, menorTurma, maiorTurma;
    
    scanf("%d", &turmas);
    
    for(i=1; i<=turmas; i++){
        printf("TURMA:%d\n", i);
        qtd=ContaAlunosAprovadosTurma ();
        if(i==1){
            maior=qtd;
            menor=qtd;
            maiorTurma=i;
            menorTurma=i;
        }
        if(qtd>maior){
            maior=qtd;
            maiorTurma=i;
        }
        if(qtd<menor){
            menor=qtd;
            menorTurma=i;
        }
    }
    printf("MAIOR:TURMA %d MENOR:TURMA %d", maiorTurma, menorTurma);
    return (EXIT_SUCCESS);
}

