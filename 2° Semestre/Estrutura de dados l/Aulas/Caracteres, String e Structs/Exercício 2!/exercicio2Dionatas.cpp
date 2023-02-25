


#include<stdlib.h>
#include<string.h>
#include<stdio.h>


//definindo a estrutura de alunos.
typedef struct aluno {
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
}tAluno;

void AlunoLibera(tAluno * p)
{
    printf("o aluno %s foi liberado\n ",p->nome);
    free(p);
    
    
};




void LiberaTurma(int n, tAluno ** turma)
{
int i;
for (i=0; i<n; i++)
AlunoLibera(turma[i]);

printf("Todos os alunos foram liberados com sucesso\n");
free(turma);
};

/*
  //Retorna a média da turma inteira; n é o número
 */

float media_turma (int n,tAluno** turma){

    float mediaTURMA=0;
    int i;
 
    //soma todas as media
    for(i=0;i<n;i++){
    
        mediaTURMA= mediaTURMA + ((turma[i]->p1+turma[i]->p2+turma[i]->p3)/3);

    
    }
    
    //retorna o valor dividido pelo numero de alunos presente na turma.
    return (mediaTURMA/n);




};

/*mprime na tela os
alunos aprovados. O aluno é aprovado quando a média das 3 provas for maior ou
igual a 5; n é o números de alunos na turma.*/
void imprime_aprovados (int n, tAluno** turma){
    int i;
    float mediaA;
    
    
    for(i=0;i<n;i++){
                
    //calculando a media das 3 provas de um aluno.
        mediaA =((turma[i]->p1 + turma[i]->p2 +turma[i]->p3)/3);
        
        
        if(mediaA>=5){
            printf("\n\nO aluno %s esta aprovado e sua media foi:%.2f :)!!!!\n",turma[i]->nome,mediaA);
        
        
        }
        else{
            printf("\n\nO aluno %s esta reprovado e sua media foi:%.2f :( !!!!\n",turma[i]->nome,mediaA);
        }

    
    }
};




int  main(){
    
    int n,i;
    char nomeTemp[51];
    float mediaTURMA;
    tAluno** turma;
    
    printf("insira o numero de alunos:");
    scanf("%d",&n);
    turma= (tAluno**)malloc(n*sizeof(tAluno*));
    
    
    //pegando os dados para preencher a turma
    for(i=0; turma[i]!= NULL && i < n;i++){
        turma[i]=(tAluno*)malloc(n*sizeof(tAluno));
        printf("\n\nInsira a matricula do aluno %d: ",i+1);
        scanf("%d", &turma[i]->matricula);
        printf("\nInsira o nome do Aluno %d: ",i+1);
        scanf(" %50[^\n]", nomeTemp);
        turma[i]->nome = strdup(nomeTemp);
        printf("\nInsira a nota da prova 1:");
        scanf("%f",&turma[i]->p1);
        printf("\nInsira oa nota da prova 2:");
        scanf("%f",&turma[i]->p2);
        printf("\nInsira a nota da prova 3:");
        scanf("%f",&turma[i]->p3);
    
    
    
    }
    imprime_aprovados(n,turma);
    
    mediaTURMA= media_turma(n,turma);
    printf("A media da turma foi: %.2f\n",mediaTURMA);
    LiberaTurma(n,turma);
    
    return 0;
    


}