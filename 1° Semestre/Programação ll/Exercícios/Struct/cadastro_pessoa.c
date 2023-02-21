
#include <stdio.h>

// registro de uma pessoa
typedef struct
{
    int Dia, Mes, Ano;
} DATA;

typedef struct pessoa
{
    char Nome[100];
    int Idade;
    float Salario;
    DATA Nascimento;
} PESSOA;

// CARREGAR A ESTRUTURA
void Ler(PESSOA *ponteiro) // conteudo apontado por ponteiro
{
    printf("Qual o Nome   :");
    gets((*ponteiro).Nome);
    printf("Qual a Idade     :");
    /*scanf("%d",& (*ponteiro).Idade);*/
    scanf("%d", &ponteiro->Idade);
    printf("Qual o Salario   :");
    scanf("%f", &(*ponteiro).Salario);
    printf("Qual a Data de Nascimeneto   :");
    scanf("%d,%d,%d", &(*ponteiro).Nascimento.Dia, &(*ponteiro).Nascimento.Mes, &(*ponteiro).Nascimento.Ano);
}
void Mostrar(struct pessoa x)
{
    printf("Nome : %s     \n", x.Nome);
    printf("Idade : %d    \n", x.Idade);
    printf("Salario : %.2f    \n", x.Salario);
    printf("Data de Nascimento:    %d/%d/%d \n", x.Nascimento.Dia, x.Nascimento.Mes, x.Nascimento.Ano);
}

int main()
{

    struct pessoa p = {"Carlos", 23, 12312313.43, {23, 5, 1954}};
    Mostrar(p);
    puts("%\n");
    Ler(&p);
    puts("\n");
    Mostrar(p);
}
