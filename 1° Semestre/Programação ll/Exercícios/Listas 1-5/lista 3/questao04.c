/*
   Matricula: 2017100584
   Nome: Agnes Tereza Lenker Ribeiro
   turma: Engenharia Civil 2017/1
   Periodo: 1º

Crie uma estrutura representando os alunos de uma turma. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova (matricula = int, nome = char[25], nota p1 = float, nota p2 = float, nota p3 = float). Lei um vetor com as informações dos 5 alunos da turma. Após isso faça:
(a) Uma função que receba o vetor de alunos e retorne o aluno com maior nota da primeira prova.
(b) Uma função que receba o vetor de alunos e retorne o aluno com maior média geral.
(c) Uma função que receba o vetor de alunos e retorne o aluno com menor média geral
(d) Uma função que receba o vetor de alunos e para cada aluno diga se ele foi aprovado ou reprovado, considerando 7.0 como média final para aprovação.
Imprima os resultados.
*/

typedef struct{

    int matricula;

    char nome[26];

    float p1;

    float p2;

    float p3;

}TipoAluno;


char maiorNotaP1(TipoAluno alunos[]){

    int i, n;;

    float maior = 0;

    for(i = 0; i < 5; i++){

        if(maior < alunos[i].p1){

            maior = alunos[i].p1;

            n = i;

        }

    }

    printf("O aluno com maior nota na p1 e: %s, com nota: %f\n", alunos[n].nome, alunos[n].p1);

}


char maiorMedia(TipoAluno alunos[]){

    int i, n;

    float media[5], maiorM;

    for(i = 0; i < 5; i++){

        media[i] = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3)/3;

        if(i == 0){

            maiorM = media[i];

            n = i;

        }

        else{

            if(maiorM < media[i]){

                maiorM = media[i];

                n = i;

            }

        }

    }

    printf("O aluno com maior media e: %s, com media de: %f\n", alunos[n].nome, media[n]);

}


void menorMedia(TipoAluno alunos[]){

    int i, n;

    float media[5], menorM;

    for(i = 0; i < 5; i++){

        media[i] = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3)/3;

        if(i == 0){

            menorM = media[i];

            n = i;

        }

        else{

            if(menorM > media[i]){

                menorM = media[i];

                n = i;

            }

        }

    }

    printf("O aluno com menor media e: %s, com media de: %f\n", alunos[n].nome, media[n]);

}


void AprovadoOuReprovado(TipoAluno alunos[]){

    int i;

    float media[5];

    for(i = 0; i < 5; i++){

        printf("\n");

        media[i] = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3)/3;

        if(media[i] >= 7){

            printf("Nome do aluno: %s\n", alunos[i].nome);

            printf("Matricula do aluno: %d\n", alunos[i].matricula);

            printf("Nota da p1: %f\n", alunos[i].p1);

            printf("Nota da p2: %f\n", alunos[i].p2);

            printf("Nota da p3: %f\n", alunos[i].p3);

            printf("Media do aluno:%f\n", media[i]);

            printf("O Aluno foi aprovado.\n");

        }

        else{

            printf("Nome do aluno: %s\n", alunos[i].nome);

            printf("Matricula do aluno: %d\n", alunos[i].matricula);

            printf("Nota da p1: %f\n", alunos[i].p1);

            printf("Nota da p2: %f\n", alunos[i].p2);

            printf("Nota da p3: %f\n", alunos[i].p3);

            printf("Media do aluno:%f\n", media[i]);

            printf("O Aluno foi reprovado.\n");

        }

    }

}


int main(int argc, char** argv) {

    TipoAluno alunos[5];

    char alunoMN[26], alunoMaM[26], alunoMeM[26];

    int i;

    for(i = 0; i < 5; i++){
        printf("\nAluno %d \nDigite o nome :", i+1);
        scanf("%s", alunos[i].nome);
        printf("Digite a matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Digite a nota da p1: ");
        scanf("%f", &alunos[i].p1);
        printf("Digite a nota da p2: ");
        scanf("%f", &alunos[i].p2);
        printf("Digite a nota da p3: ");
        scanf("%f", &alunos[i].p3);
    }
    AprovadoOuReprovado(alunos);
    maiorNotaP1(alunos);
    maiorMedia(alunos);

    menorMedia(alunos);

    return 0;

}

