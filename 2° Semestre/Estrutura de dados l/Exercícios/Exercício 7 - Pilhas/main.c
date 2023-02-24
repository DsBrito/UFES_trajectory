#include <stdio.h>
#include "pilha.h"

int main()
{

    // criando pilha vazia
    tPilhaDupla *pilha = cria_pilha();

    // inicializando o tipo pessoa (nome, idade , peso, altura, endereço, genero)
    tPessoa *Larissa = inicializaPessoa("Larissa", 15, 55, 1.5, "rua de Larissa", "feminino");
    tPessoa *Maria = inicializaPessoa("Maria", 10, 35, 1.3, "rua da Maria", "feminino");
    tPessoa *Joao = inicializaPessoa("Joao", 32, 95, 1.7, "rua de Joao", "masculino");
    tPessoa *Thiago = inicializaPessoa("Thiago", 21, 77, 1.8, "rua de Thiago", "masculino");
    tPessoa *Valentina = inicializaPessoa("Valentina", 27, 50, 1.4, "rua da Valentina", "feminino");
    tPessoa *Cleber = inicializaPessoa("Cleber", 24, 68, 1.5, "rua do Cleber", "masculino");
    tPessoa *Alice = inicializaPessoa("Alice", 30, 79, 1.6, "rua de Alice", "feminino");
    tPessoa *Saimon = inicializaPessoa("Saimon", 28, 78, 1.73, "rua do Saimon", "masculino");
    tPessoa *Eduarda = inicializaPessoa("Eduarda", 14, 56, 1.34, "rua da Eduarda", "feminino");
    tPessoa *Enzo = inicializaPessoa("Enzo", 25, 83, 2, "rua do Enzo", "masculino");

    // Insere os pessoas na pilha
    push(Larissa, pilha, recuperaGenero(Larissa));
    push(Maria, pilha, recuperaGenero(Alice));
    push(Joao, pilha, recuperaGenero(Joao));
    push(Thiago, pilha, recuperaGenero(Thiago));
    push(Valentina, pilha, recuperaGenero(Valentina));
    push(Cleber, pilha, recuperaGenero(Cleber));
    push(Alice, pilha, recuperaGenero(Alice));
    push(Saimon, pilha, recuperaGenero(Saimon));
    push(Eduarda, pilha, recuperaGenero(Eduarda));
    push(Enzo, pilha, recuperaGenero(Enzo));

    printf("---------- Imprime pilha-----------\n");
    // Imprime a pilha com todas as pessoas
    imprime_pilha(pilha);

    // Retira pessoa da pilha p com o indice como parametro (da pilha 1-Feminino ou 2-Masculino)

    pop(pilha, 1);
    // pop (pilha,2); retirar pessoa do genero masculino

    printf("---------- Imprime NOVA pilha-----------\n");
    imprime_pilha(pilha);

    // libera a memória ocupada pelas pilhas
    pilha = destroi_pilha(pilha);

    return 0;
}