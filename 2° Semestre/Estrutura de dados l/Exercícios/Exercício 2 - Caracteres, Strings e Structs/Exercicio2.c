

typedef struct Aluno{

    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
}tAluno;

void imprime_aprovados (int n, tAluno** turma);
float media_turma (int n, tAluno** turma);
void LiberaAluno(tAluno* aluno);
void LiberaTurma(int n, tAluno** turma);



int main(int argc, char** argv) {

    int n,i;
    float MediaTurma;
    char nomeTemporario[61];
    tAluno** turma;
     
    printf("\nInsira o numero de alunos:");
    scanf("%d",&n);
    
    turma = (tAluno**) malloc (n * sizeof(tAluno*));
    
    for(i=0;turma[i]!=NULL && i<n ;i++){
        turma[i]=(tAluno*)malloc(n * sizeof (tAluno));
       
        
               
        printf("\nInsira o nome do aluno[%d]:",i+1);
        scanf(" %60[^\n]",nomeTemporario); 
        turma[i]->nome=strdup(nomeTemporario);
        
        printf("\nInsira o numero de matricula:");
        scanf("%d", &turma[i]->matricula);

       
        printf("\nInsira o resultado da p1:");
        scanf("%f",&turma[i]->p1);
        printf("\nInsira o resultado da p2:");
        scanf("%f",&turma[i]->p2);
        printf("\nInsira o resultado da p3:");
        scanf("%f",&turma[i]->p3);
        

    }
    
    
    for(i=0;i<n;i++){
        printf("\n Nome:%s, Matricula:%d,Nota P1:%.2f,Nota P2:%.2f,Nota P3:%.2f",turma[i]->nome,turma[i]->matricula,turma[i]->p1,turma[i]->p2,turma[i]->p3);
        
    }
    
    printf("\n\n\n\n");
    imprime_aprovados(n,turma);

    MediaTurma= media_turma(n,turma);
    
    printf("\n A media da turma eh : %.2f",MediaTurma);
    
    LiberaTurma(n,turma);
    
    return (EXIT_SUCCESS);
}

void imprime_aprovados (int n, tAluno** turma){

    int i;
    float mediaAluno=0;0;
    
    
    for(i=0;i<n;i++){
        mediaAluno= (turma[i]->p1+turma[i]->p2+turma[i]->p3)/3;
        if(mediaAluno>=5)
            printf("\nO aluno %s esta Aprovado",turma[i]->nome);
    }


};

float media_turma (int n, tAluno** turma){

  int i;
  float MEDIA=0;0;
    
    
    for(i=0;i<n;i++){
       MEDIA= MEDIA + (turma[i]->p1+turma[i]->p2+turma[i]->p3)/3;
      
    }

  MEDIA = (MEDIA/n);
  return MEDIA;
};


//Liberando Memoria

void LiberaAluno(tAluno* aluno){

    printf("\n O aluno %s foi liberado com sucesso ",aluno->nome);
    free(aluno->nome);
};

void LiberaTurma(int n, tAluno** turma){

    int i;
    
    for(i=0;i<n;i++){
        LiberaAluno(turma[i]);
    }

    free(turma);

};



