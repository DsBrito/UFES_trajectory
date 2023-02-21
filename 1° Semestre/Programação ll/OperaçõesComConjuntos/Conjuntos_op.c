

// Importa��o de Bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

// programa principal.
int main()
{

    // declara��o de variaveis.
    int opcao = 0, conjunto, posicao, subconjunto;
    int busca, encontrado;                  // variaveis auxiliares na busca de um elemento em um conjunto;
    int contA = 0, opcaoA;                  // variaveis contadora e tomada de decis�o para o conjunto A;
    int contB = 0, opcaoB;                  // variaveis contadora e tomada de decis�o para o conjunto B;
    int contC = 0, opcaoC;                  // variaveis contadora e tomada de decis�o para o conjnto C;
    int contAB = 0, contAC = 0, contBC = 0; // contadores de intera��es entre dois conjuntos;

    int A[100], B[100], C[100];    // conjuntos definitivos;
    int AB[100], BC[100], AC[100]; // vetores que armazenam a intera��o entre dois conjuntos;
    int elemento;                  // variavel para armazenar o elemento antes de adicionar no conjunto;
    bool elementoRepetido = false; // variavel boleana para tomada de decis�o;

    int Aaux[100], Baux[100], Caux[100]; // vetores auxiliares;
    int i, j, k;                         // variaveis contadoras auxiliares;

    setlocale(LC_ALL, "Portuguese"); // fun��o nativa do C para aceitar caracteres e acentua��o da l�ngua portuguesa;
    while (opcao != 10)
    {
        system("CLS");                     // fun��o nativa do C para limpar a tela de comando;
        printf("\nBem Vindo ao Menu!!\n"); // interface do menu;
        printf("\n1- Inserir um elemento em algum conjunto");
        printf("\n2- Remover um elemento de algum conjunto");
        printf("\n3- Verificar se um elemento pertence ao conjunto");
        printf("\n4- Verificar se um conjunto � subconjunto");
        printf("\n5- Realizar a uni�o de dois conjuntos");
        printf("\n6- Realizar a intersec��o entre dois conjuntos");
        printf("\n7- Realizar diferen�a entre dois conjuntos");
        printf("\n8- Realizar produto cartesiano entre dois conjuntos");
        printf("\n9- Imprimir os elementos de um conjunto");
        printf("\n10- SAIR");
        printf("\nInsira a op��o escolhida: ");
        scanf("%d", &opcao);
        fflush(stdin); // fu��o nativa do C para limpar o buffer;
        system("CLS");

        switch (opcao)
        {
        case 1:
            printf("\nEscolha um dos 3 conjuntos abaixo para inserir os elementos: ");
            printf("\n1- Conjunto A");
            printf("\n2- Conjunto B");
            printf("\n3- Conjunto C\n");
            printf("\nInsira a op��o escolhida: ");
            scanf("%d", &conjunto);
            fflush(stdin);
            if (conjunto > 3)
            { // tratamento de erro para entrada de dados invalidos.
                printf("\nInsira dados validos para as op��es !!\n\n");
            }
            else
            {
                if (conjunto == 1)
                {
                    opcaoA = 0; // reinicia��o de variavel;
                    while (opcaoA != 1)
                    {                             // la�o para continuar a inser��o de elementos no conjunto;
                        elementoRepetido = false; // reinicia��o da variavel boleana de tomade de decis�o;
                        printf("A[%d]<--- = ", contA + 1);
                        scanf("%d", &elemento);
                        fflush(stdin);
                        for (i = 0; i < contA; i++)
                        { // la�o para corrigir o erro de ter repeti��o de elemento em um conjunto;
                            if (A[i] == elemento)
                            {                            // se inserir um elemento que ja esta contido no conjunto,
                                elementoRepetido = true; // a variavel boleana ira assumir o valor verdadeiro;
                                printf("\nOps, o elemento ja esta no conjunto!!");
                            }
                        }
                        if (elementoRepetido == false)
                        {                        // se a variavel boleana estiver com o valor falso
                            A[contA] = elemento; // significa que o elemento de entrada n�o � repeti��o
                            contA++;             // o valor do elemento � atribuido ao conjunto
                        }                        // o contador do conjunto A recebe : contador +1;

                        printf("\n\nConjunto: A["); // imprime o conjunto inserido;
                        for (i = 0; i < contA; i++)
                        {
                            printf("%d ", A[i]);
                        }
                        printf("]\n\n\n");
                        printf("\n1- Ir para o menu\n2- Inserir outro elemento no conjunto\n"); // tomada de decis�o;
                        printf("\nInsira a op��o escolhida: ");
                        scanf("%d", &opcaoA);
                        fflush(stdin);
                    }
                    system("pause"); // fun��o nativa do C para pausar a tela ( pare cer o resultado );
                }

                else if (conjunto == 2)
                {
                    opcaoB = 0;
                    while (opcaoB != 1)
                    {
                        elementoRepetido = false;
                        printf("B[%d]<--- = ", contB + 1); // REPETI��O DO C�DIGO PARA O CONJUNTO B;
                        scanf("%d", &elemento);
                        fflush(stdin);
                        for (i = 0; i < contB; i++)
                        {
                            if (B[i] == elemento)
                            {
                                elementoRepetido = true;
                                printf("\nOps, o elemento ja esta no conjunto!!");
                            }
                        }
                        if (elementoRepetido == false)
                        {
                            B[contB] = elemento;
                            contB++;
                        }

                        printf("\n\nConjunto: B[");
                        for (i = 0; i < contB; i++)
                        {
                            printf("%d ", B[i]);
                        }
                        printf("]\n\n\n");
                        printf("\n1- Ir para o menu\n2- Inserir outro elemento no conjunto\n");
                        printf("\nInsira a op��o escolhida: ");
                        scanf("%d", &opcaoB);
                        fflush(stdin);
                    }
                    system("pause");
                }

                else if (conjunto == 3)
                {
                    opcaoC = 0;
                    while (opcaoC != 1)
                    {
                        elementoRepetido = false;
                        printf("C[%d]<--- = ", contC + 1);
                        scanf("%d", &elemento);
                        fflush(stdin); // REPETI��O DO C�DIGO PARA O CONJUNTO C;
                        for (i = 0; i < contC; i++)
                        {
                            if (C[i] == elemento)
                            {
                                elementoRepetido = true;
                                printf("\nOps, o elemento ja esta no conjunto!!");
                            }
                        }
                        if (elementoRepetido == false)
                        {
                            C[contC] = elemento;
                            contC++;
                        }

                        printf("\n\nConjunto: C[");
                        for (i = 0; i < contC; i++)
                        {
                            printf("%d ", C[i]);
                        }
                    }
                    printf("]\n\n\n");
                    printf("\n1- Ir para o menu\n2- Inserir outro elemento no conjunto\n");
                    printf("\nInsira a op��o escolhida: ");
                    scanf("%d", &opcaoC);
                    fflush(stdin);
                }
                system("pause");
            }
            break;
        case 2:
            conjunto = 0; // reinicia��o de variavel;
            opcao = 1;
            while (opcao == 1)
            { // la�o para que o usuario entre nesse caso novamente, caso queira.
                printf("\nEscolha um dos 3 conjuntos abaixo para remover um elemento: ");
                printf("\n1- Conjunto A");
                printf("\n2- Conjunto B");
                printf("\n3- Conjunto C\n");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (conjunto > 3)
                { // tratamento de erro para entrada de dados invalidos.
                    printf("\nInsira dados validos para as op��es !!\n\n");
                }
                else
                {
                    if (conjunto == 1)
                    {
                        if (contA == 0)
                        {                                                                                       // verifica��o se tem ou nao elemento no conjunto;
                            printf("\n\nOps, este � um conjunto vazio! N�o h� elemento para ser retirado\n\n"); // contA se refere ao numero de elementos do conjunto A;
                        }
                        else
                        {
                            printf("Conjunto A["); // imprime todos elementos de A
                            for (i = 0; i < contA; i++)
                            { // para ver as posi�oes de cada elemento;
                                printf("%d ", A[i]);
                            }
                            printf("]");
                            printf("\nInsira a posi��o que est� o elemento que deseja retirar (a POSI��O vai de 0 at� N-1): ");
                            scanf("%d", &posicao); // variavel posi��o assume a posi��o que esta
                            fflush(stdin);         // o elemento que o usu�rio deseja remover;

                            for (i = 0; i < contA; i++)
                            {
                                if (i < posicao)
                                { // conjunto Auxiliar recebe todo o conjutno A at� a posi��o desejada;
                                    Aaux[i] = A[i];
                                }
                                else
                                {                       // quando chegar na posi��o do elemento que ira ser removido
                                    Aaux[i] = A[i + 1]; // o conjunto Auxiliar recebe o elemento que esta na proxima posic�o de A( i +1 )
                                }                       // pulando assim o elemento da posi��o que o usu�rio quer remover;
                            }
                            for (i = 0; i < contA; i++)
                            {
                                A[i] = Aaux[i]; // o conjunto A recebe cada elemento do vetor auxiliar;
                            }
                            contA = (contA - 1); // como foi removido um elemento, eh necessario atualizar a variavel de tamanho;
                            printf("O novo conjunto A �: A[");
                            for (i = 0; i < contA; i++)
                            {
                                printf("%d ", A[i]); // imprimindo o novo conjunto A;
                            }
                            printf("]\n\n\n");
                        }
                    }

                    else if (conjunto == 2)
                    {
                        if (contB == 0)
                        {
                            printf("\n\nOps, este � um conjunto vazio! N�o h� elemento para ser retirado\n\n");
                        }
                        else
                        {
                            printf("Conjunto B[");
                            for (i = 0; i < contB; i++)
                            { // REPETI��O DO C�DIGO PARA O CONJUNTO B;
                                printf("%d ", B[i]);
                            }
                            printf("]");
                            printf("\nInsira a posi��o que est� o elemento que deseja retirar (a POSI��O vai de 0 at� N-1): ");
                            scanf("%d", &posicao);
                            fflush(stdin);

                            for (i = 0; i < contB; i++)
                            {
                                if (i < posicao)
                                {
                                    Baux[i] = B[i];
                                }
                                else
                                {
                                    Baux[i] = B[i + 1];
                                }
                            }
                            for (i = 0; i < contB; i++)
                            {
                                B[i] = Baux[i];
                            }

                            contB = (contB - 1);
                            printf("O novo conjunto B �: B[");
                            for (i = 0; i < contB; i++)
                            {
                                printf("%d ", B[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }

                    else if (conjunto == 3)
                    {
                        if (contC == 0)
                        {
                            printf("\n\nOps, este � um conjunto vazio! N�o h� elemento para ser retirado\n\n");
                        }
                        else
                        {
                            printf("Conjunto C["); // REPETI��O DO C�DIGO PARA O CONJUNTO C;
                            for (i = 0; i < contC; i++)
                            {
                                printf("%d ", C[i]);
                            }
                            printf("]");
                            printf("\nInsira a posi��o que est� o elemento que deseja retirar (a POSI��O vai de 0 at� N-1): ");
                            scanf("%d", &posicao);
                            fflush(stdin);

                            for (i = 0; i < contC; i++)
                            {
                                if (i < posicao)
                                {
                                    Caux[i] = C[i];
                                }
                                else
                                {
                                    Caux[i] = C[i + 1];
                                }
                            }
                            for (i = 0; i < contC; i++)
                            {
                                C[i] = Caux[i];
                            }

                            contC = (contC - 1);
                            printf("O novo conjunto C �: C[");
                            for (i = 0; i < contC; i++)
                            {
                                printf("%d ", C[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-realizar outra remo��o em algum conjunto\n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }

            break;

        case 3:
            conjunto = 0; // reinicia��o de variavel;
            opcao = 1;
            while (opcao == 1)
            { // la�o para que o usuario entre nesse caso novamente, caso queira.
                printf("\nEscolha um dos 3 conjuntos abaixo para verificar se ah o elemento que deseja buscar: ");
                printf("\n1- Conjunto A");
                printf("\n2- Conjunto B");
                printf("\n3- Conjunto C\n");
                printf("\nInsira a opcao escolhida: ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (conjunto > 3)
                { // tratamento de erro para entrada de dados invalidos.
                    printf("\nInsira dados validos para as op��es !!\n\n");
                }
                else
                {
                    if (conjunto == 1)
                    {
                        if (contA == 0)
                        { // se o conjunto escolhido for vazio.
                            printf("\n\nOps,este � um conjunto vazio! N�o ha elementos para serem  encontrados\n\n\n");
                        }
                        else
                        {
                            printf("\nInsira o n�mero que deseja verificar se est� no conjunto: ");
                            scanf("%d", &busca);
                            fflush(stdin);
                            elementoRepetido = false; // reinicia��o da variavel boleana de tomade de decis�o;
                            for (i = 0; i < contA; i++)
                            { // la�o para comparar cada elemento do conjunto com o valor buscado;
                                if (A[i] == busca)
                                { // se encontrar a variavel boleana (elementoRepetido) ira assumir o valor verdadeiro;
                                    elementoRepetido = true;
                                }
                            }
                            if (elementoRepetido == true)
                            { // bloco de instru��es se o elementoRepetido for verdadeiro;
                                printf("Elemento %d encontrado no conjunto A!\n", busca);
                            }
                            else if (elementoRepetido == false)
                            { // bloco de instru��es se o elementoRepetido for falso;
                                printf("Elemento %d n�o encontrado no conjunto A!\n", busca);
                            }

                            printf("Conjunto A[");
                            for (i = 0; i < contA; i++)
                            {
                                printf("%d ", A[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }

                    else if (conjunto == 2)
                    {
                        if (contB == 0)
                        {
                            printf("\n\nOps,este � um conjunto vazio! N�o h� elementos para serem encontrados\n\n\n");
                        }

                        else
                        { // REPETI��O DO C�DIGO PARA O CONJUNTO B;
                            elementoRepetido = false;
                            printf("\nInsira o numero que deseja verificar se esta no conjunto:\t");
                            scanf("%d", &busca);
                            fflush(stdin);
                            for (i = 0; i < contB; i++)
                            {
                                if (B[i] == busca)
                                {
                                    elementoRepetido = true;
                                }
                            }
                            if (elementoRepetido == true)
                            {
                                printf("Elemento %d encontrado no conjunto!\n", busca);
                            }
                            else if (elementoRepetido == false)
                            {
                                printf("Elemento %d n�o encontrado no conjunto!\n", busca);
                            }
                            printf("Conjunto B[");
                            for (i = 0; i < contB; i++)
                            {
                                printf("%d ", B[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }

                    else if (conjunto == 3)
                    {
                        if (contC == 0)
                        {
                            printf("\n\nOps,este eh um conjunto vazio!! n�o ha elementos para sererem encontrados\n\n\n");
                            system("pause");
                        }
                        else
                        {
                            elementoRepetido = false; // REPETI��O DO C�DIGO PARA O CONJUNTO C;
                            printf("\nInsira o numero que deseja verificar se esta no conjunto:\t");
                            scanf("%d", &busca);
                            fflush(stdin);
                            for (i = 0; i < contC; i++)
                            {
                                if (C[i] == busca)
                                {
                                    elementoRepetido = true;
                                }
                            }
                            if (elementoRepetido == true)
                            {
                                printf("Elemento %d encontrado no conjunto!\n", busca);
                            }
                            else if (elementoRepetido == false)
                            {
                                printf("Elemento %d n�o encontrado no conjunto!\n", busca);
                            }
                            printf("Conjunto C[");
                            for (i = 0; i < contC; i++)
                            {
                                printf("%d ", C[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-realizar busca em um dos conjuntos\n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }

            break;

        case 4:
            opcao = 1; // reinicia��o de variavel;

            while (opcao == 1)
            {
                printf("\n\nPara n�o ser um subconjunto deve conter pelo menos um elemento que n�o esteja contido no conjunto.\n\n");
                printf("\nQual  subconjunto voc� quer analisar: ");
                printf("\n1- subconjunto A");
                printf("\n2- subconjunto B");
                printf("\n3- subconjunto C\n");
                printf("\nEm qual conjunto voc� quer analisar se h� esse subconjunto: "); // escolhendo quem � conjunto e quem � subconjunto;
                printf("\n1- Conjunto A");
                printf("\n2- Conjunto B");
                printf("\n3- Conjunto C\n");
                printf("\nInsira dois valores maiores que 3 de entrada para voltar ao Menu !\n");
                printf("\nInsira a op��o escolhida para o subconjunto:\t ");
                scanf("%d", &subconjunto);
                fflush(stdin);
                printf("\nInsira a op��o escolhida para o conjunto:\t ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (subconjunto > 3 || conjunto > 3)
                { // tratamento de erro caso o usu�rio insira dados que nao estejam nas op��es.
                    printf("Insira dados validos para as op��es!!\n\n");
                }
                else
                {
                    if ((conjunto == 1 && subconjunto == 1) || (conjunto == 2 && subconjunto == 2) || (conjunto == 3 && subconjunto == 3))
                    {
                        printf("Todo conjunto eh � subconjunto dele mesmo.\n\n\n"); // se o usu�rio escolher o mesmo conjunto para testar se eh subconjunto;
                    }
                    else if ((subconjunto == 1 && contA == 0) || (subconjunto == 2 && contB == 0) || (subconjunto == 3 && contC == 0))
                    { // se o subconjunto escolhido for um conjunto vazio.
                        printf("\n\nComo o conjunto vazio nao possui nenhum elemento,ele esta contido em todo conjunto, logo ele eh um subconjunto\n\n\n");
                    }
                    else if (subconjunto == 1)
                    {
                        if (conjunto == 2)
                        {
                            encontrado = 0; // reinicia��o de variavel;
                            for (i = 0; i < contA; i++)
                            {
                                for (j = 0; j < contB; j++)
                                { // se todos elementos do conjunto  A for igual a todos/parte do conjunto B
                                    if (A[i] == B[j])
                                    {                 // significa que A esta contido em B, logo A eh subconjunto de B;
                                        encontrado++; // se forem iguais, encontrado recebe um acr�scimo de +1;
                                    }
                                }
                            }
                            if (encontrado == contA)
                            {                                         // se a variavel encontrado(que ganhou o seu valor na instru��o acima)
                                printf("A � subconjunto de B\n\n\n"); // for do mesmo valor que o tamanho do conjunto A, A e subconjunto de B;
                            }
                            else
                            {
                                printf("A n�o � subconjunto de B\n\n\n"); // se nao tiver tamanho igual,quer dizer qeu o conjunto A tem pelo menos um elemento
                                                                          // que nao esta contido em B, logo n�o eh subconjunto de B;
                            }
                        }
                        else if (conjunto == 3)
                        {
                            encontrado = 0;
                            for (i = 0; i < contA; i++)
                            {
                                for (j = 0; j < contC; j++)
                                {
                                    if (A[i] == C[j])
                                    { // REPETI��O DO C�DIGO ( sendo A subconjunto e C sendo o conjunto testado )
                                        encontrado++;
                                    }
                                }
                            }
                            if (encontrado == contA)
                            {
                                printf("A � subconjunto de C\n\n\n");
                            }
                            else
                            {
                                printf("A n�o � subconjunto de C\n\n\n");
                            }
                        }
                    }

                    else if (subconjunto == 2)
                    {
                        if (conjunto == 1)
                        {
                            encontrado = 0;
                            for (i = 0; i < contB; i++)
                            {
                                for (j = 0; j < contA; j++)
                                { // REPETI��O DO C�DIGO ( sendo B o subconjunto e A o conjunto testado );
                                    if (B[i] == A[j])
                                    {
                                        encontrado++;
                                    }
                                }
                            }
                            if (encontrado == contB)
                            {
                                printf("B � subconjunto de A\n\n\n");
                            }
                            else
                            {
                                printf("B n�o � subconjunto de A\n\n\n");
                            }
                        }
                        else if (conjunto == 3)
                        {
                            encontrado = 0;
                            for (i = 0; i < contB; i++)
                            {
                                for (j = 0; j < contC; j++)
                                { // REPETI��O DO C�DIGO( sendo B o subconjunto e C o conjunto testado );
                                    if (B[i] == C[j])
                                    {
                                        encontrado++;
                                    }
                                }
                            }
                            if (encontrado == contB)
                            {
                                printf("B � subconjunto de C\n\n\n");
                            }
                            else
                            {
                                printf("B n�o � subconjunto de C\n\n\n");
                            }
                        }
                    }
                    else if (subconjunto == 3)
                    {
                        if (conjunto == 1)
                        {
                            encontrado = 0; // REPETI��O DO C�DIGO( sendo C o subconjunto e A o conjunto testado );
                            for (i = 0; i < contC; i++)
                            {
                                for (j = 0; j < contA; j++)
                                {
                                    if (C[i] == A[j])
                                    {
                                        encontrado++;
                                    }
                                }
                            }
                            if (encontrado == contC)
                            {
                                printf("C � subconjunto de A\n\n\n");
                            }
                            else
                            {
                                printf("C n�o � subconjunto de A\n\n\n");
                            }
                        }
                        else if (conjunto == 2)
                        {
                            encontrado = 0; // REPETI��O DO C�DIGO( sendo C o subconjunto e B o conjunto testado );
                            for (i = 0; i < contC; i++)
                            {
                                for (j = 0; j < contB; j++)
                                {
                                    if (C[i] == B[j])
                                    {
                                        encontrado++;
                                    }
                                }
                            }
                            if (encontrado == contC)
                            {
                                printf("C � subconjunto de B\n\n\n");
                            }
                            else
                            {
                                printf("C n�o � subconjunto de B\n\n\n");
                            }
                        }
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-realizar teste de subconjunto\n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }

            break;
        case 5:
            conjunto = 0; // reinicia��o de variavel;
            opcao = 1;
            while (opcao == 1)
            { // la�o para fazer a opera��o novamente, caso o usu�rio queira.
                printf("O resultado � um novo conjunto com elementos que pertencem a pelo menos um dos conjuntos");
                printf("\nQual  uni�o voc� quer fazer: ");
                printf("\n1- AUB\n");
                printf("\n2- AUC\n");
                printf("\n3- BUC\n");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (conjunto > 3)
                { // tratamento de erro para entrada de dados invalidos.
                    printf("\nInsira dados validos para as op��es !!\n\n");
                }

                else
                {
                    if (conjunto == 1)
                    {
                        if ((contA == 0) && (contB == 0))
                        { // se A e B forem conjuntos vazios a sua uni�o tamb�m ir� ser um conjunto vazio;
                            printf("\n\nUni�o: [ ] Conjunto Vazio \n\n\n");
                        }
                        else if ((contA == 0) && (contB != 0))
                        {
                            printf("\nUni�o AB[");
                            for (i = 0; i < contB; i++)
                            {                        // se A for vazio e B conter elementos
                                printf("%d ", B[i]); // a sua uni�o ir� ser todos os elementos de B;
                            }
                            printf("]\n\n\n");
                        }
                        else if ((contA != 0) && (contB == 0))
                        {
                            printf("\nUni�o AB[");
                            for (i = 0; i < contA; i++)
                            {                        // se B for vazio e A conter elementos
                                printf("%d ", A[i]); // a sua uni�o ir� ser todos os elementos de A;
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {               // se A e B conterem valores;
                            contAB = 0; // inicializa��o de uma variavel de intera��o entre A e B ( contadora );
                            for (i = 0; i < contA; i++)
                            {          // la�o para preencher o conjunto uni�o de A e B;
                                j = 0; // inicializa��o de duas variaveis contadora (j) e (i);
                                while (j < contAB && A[i] != AB[j])
                                {
                                    j = j + 1; // como a variavel j e contAB inicialmente possuem o mesmo valor;
                                }              // ira cair na condi��o "(j>=contAB)" , onde contAB vai levar um
                                if (j >= contAB)
                                {                        // acr�scimo de +1"(contAB = contAB+1)" e o "AB[contAB]" ira receber "A[i]"
                                    AB[contAB] = A[i];   // como esta dentro do for, ir� de novo testar as condi��es, onde ,
                                    contAB = contAB + 1; // se j for menor que contAB e ao mesmo tempo A na posi��o "i" for diferente de
                                }                        // AB na posi��o "j" ira cair na condi��o do while "(j<contAB && A[i]!=AB[j]) e o j ira receber acrescimo de +1,
                            }                            // ira ficar alternado nessas duas condi��es at� que tenha pecorrido todo conjunto A;
                            for (i = 0; i < contB; i++)
                            {
                                j = 0; // esse comando do "la�o for" eh necess�ria para retirar possiveis numeros
                                while (j < contAB && B[i] != AB[j])
                                { // que estao contidos em A e tamb�m em B, para que a uni�o de ambos n�o tenha numeros repetidos;
                                    j = j + 1;
                                }
                                if (j >= contAB)
                                {
                                    AB[contAB] = B[i];   // REPETI��O DO LA�O FOR com o mesmo intuito do la�o de cima,para pecorrer todo o conjunto B e adicionar os restantes;
                                    contAB = contAB + 1; //(ADICIONAR somente os elementos que nao estao em AB);
                                }                        // EX:  A uni�o B = ( (conjunto A + conjunto B) - numeros repetidos de A e B);
                            }

                            printf("\nUniao AB[ ");
                            for (i = 0; i < (contAB); i++)
                            { // Exibe Vetor de Saida UNI�O;
                                printf("%d ", AB[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }

                    else if (conjunto == 2)
                    {
                        if ((contA == 0) && (contC == 0))
                        {
                            printf("\n\nUni�o: [ ] Conjunto Vazio\n\n\n");
                        }
                        else if ((contA == 0) && (contC != 0))
                        {
                            printf("\nUni�o AC[");
                            for (i = 0; i < contB; i++)
                            { // REPETI��O DO C�DIGO PARA UNI�O DO CONJUNTO A e C;
                            }
                            printf("]\n\n\n");
                        }
                        else if ((contA != 0) && (contC == 0))
                        {
                            printf("\nUni�o[");
                            for (i = 0; i < contA; i++)
                            {
                                printf("%d ", A[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contAC = 0;
                            for (i = 0; i < contA; i++)
                            {
                                j = 0;
                                while (j < contAC && A[i] != AC[j])
                                {
                                    j = j + 1;
                                }
                                if (j >= contAC)
                                {
                                    AC[contAC] = A[i];
                                    contAC = contAC + 1;
                                }
                            }
                            for (i = 0; i < contC; i++)
                            {
                                j = 0;
                                while (j < contAC && C[i] != AC[j])
                                {
                                    j = j + 1;
                                }
                                if (j >= contAC)
                                {
                                    AC[contAC] = C[i];
                                    contAC = contAC + 1;
                                }
                            }
                            /* Exibe Vetor de Saida UNI�O */
                            printf("\nUniao AC[ ");
                            for (i = 0; i < (contAC); i++)
                            {
                                printf("%d ", AC[i]);
                            }
                            printf("]\n");
                        }
                    }

                    else if (conjunto == 3)
                    {
                        if ((contB == 0) && (contC == 0))
                        {
                            printf("\n\nUni�o: [ ] Conjunto Vazio\n\n\n");
                        }
                        else if ((contC == 0) && (contB != 0))
                        { // REPETI��O DO C�DIGO PARA UNI�O DO CONJUNTO B e C;
                            printf("\nUni�o[");
                            for (i = 0; i < contB; i++)
                            {
                                printf("%d ", B[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else if ((contC != 0) && (contB == 0))
                        {
                            printf("\nUni�o[");
                            for (i = 0; i < contC; i++)
                            {
                                printf("%d ", C[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contBC = 0;
                            for (i = 0; i < contB; i++)
                            {
                                j = 0;
                                while (j < contBC && B[i] != BC[j])
                                {
                                    j = j + 1;
                                }
                                if (j >= contBC)
                                {
                                    BC[contBC] = B[i];
                                    contBC = contBC + 1;
                                }
                            }
                            for (i = 0; i < contC; i++)
                            {
                                j = 0;
                                while (j < contBC && C[i] != BC[j])
                                {
                                    j = j + 1;
                                }
                                if (j >= contBC)
                                {
                                    BC[contAB] = BC[i];
                                    contBC = contBC + 1;
                                }
                            }
                            /* Exibe Vetor de Saida UNI�O */
                            printf("\nUniao BC[ ");
                            for (i = 0; i < (contBC); i++)
                            {
                                printf("%d ", BC[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-realizar outra uni�o entre conjuntos\n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }
            break;

        case 6:
            conjunto = 0; // reinicia��o de variavel;
            opcao = 1;
            while (opcao == 1)
            { // la�o para fazer a opera��o novamente, caso o usu�rio queira.
                printf("\nQual  intersec��o voc� quer fazer: ");
                printf("\n1- A  com B\n");
                printf("\n2- A  com C\n");
                printf("\n3- B  com C\n");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (conjunto > 3)
                { // tratamento de erro para entrada de dados invalidos.
                    printf("\nInsira dados validos para as op��es !!\n\n");
                }
                else
                {
                    if (conjunto == 1)
                    {
                        if ((contA == 0) || (contB == 0))
                        {
                            if (contA != 0)
                            { // como B eh um conjunto vazio, a interse��o s� pode ser ser um conjunto vazio;
                                printf("(B = conjunto vazio)a interse��o entre A e B eh o conjunto vazio\n\n\n");
                            }
                            else if (contB != 0)
                            { // como A eh  um conjunto vazio a interse��o tamb�m eh um conjunto vazio;
                                printf("(A = conjunto vazio)a interse��o entre A e B eh o conjunto vazio\n\n\n");
                            }
                            else
                            {
                                printf("\n\nIntersec��o: [ ] Conjunto Vazio\n\n\n"); // se A e B forem conjuntos vazios, a sua interse��o tamb�m eh um conjunto vazio;
                            }
                        }
                        else
                        {
                            contAB = 0; // inicializa��o da variavel de intera��o entre A e B;
                            for (i = 0; i < contA; i++)
                            {
                                for (j = 0; j < contB; j++)
                                { // com o de um for duplo, cada valor de A eh comparado com todos elementos do conjunto B;
                                    if (A[i] == B[j])
                                    {                      // se no meio do processo encontrar elementos comuns entre A e B, o conjunto interse��o(AB) recebe esse elemento;
                                        AB[contAB] = A[i]; // e em seguida contAB recebe um acr�scimo de +1 ( contAB++);
                                        contAB++;
                                    }
                                }
                            }
                            if (contAB == 0)
                            {                                                      // se depois od for, contAB tiver o valor 0, significa que n�o encontrou nenhum elemento comum entre A e B;
                                printf("\nIntersec��o: [ ] Conjunto Vazio\n\n\n"); // ent�o o unico possivel conjunto interse��o entre A e B eh o conjunto vazio.
                            }
                            else
                            {
                                printf("\nInterse��o AB[");
                                for (i = 0; i < contAB; i++)
                                {
                                    printf("%d ", AB[i]); // caso contAB maior que 0, significa que encontrou algum elemento comum;
                                }                         // eh impresso na tela o conjunto Interse��o;
                                printf("]\n\n\n");
                            }
                        }
                    }
                    else if (conjunto == 2)
                    {
                        if ((contA == 0) || (contC == 0))
                        {
                            if (contC != 0)
                            {
                                printf("(A = conjunto vazio)a interse��o entre A e C eh o conjunto vazio\n\n\n");
                            }
                            else if (contA != 0)
                            {
                                printf("(C = conjunto vazio)a interse��o entre A e C eh o conjunto vazio\n\n\n");

                            } // REPETI��O DO C�DIGO PARA INTERSE��O DO CONJUNTO B e C;
                            else
                            {
                                printf("\n\nIntersec��o: [ ] Conjunto Vazio\n\n\n");
                            }
                        }
                        else
                        {
                            contAC = 0;
                            for (i = 0; i < contA; i++)
                            {
                                for (j = 0; j < contC; j++)
                                {
                                    if (A[i] == C[j])
                                    {
                                        AC[contAC] = A[i];
                                        contAC++;
                                    }
                                }
                            }
                            if (contAC == 0)
                            {
                                printf("\nN�o h� interse��o entre os conjuntos A e C\n");
                            }
                            else
                            {
                                printf("\nInterse��o AC[");
                                for (i = 0; i < contAC; i++)
                                {
                                    printf("%d ", AC[i]);
                                }
                                printf("]\n");
                            }
                        }
                    }
                    else if (conjunto == 3)
                    {
                        if ((contB == 0) && (contC == 0))
                        {
                            if (contC != 0)
                            {
                                printf("(B = conjunto vazio)a interse��o entre B e C eh o conjunto vazio\n\n\n");
                            }
                            else if (contB != 0)
                            {
                                printf("(C = conjunto vazio)a interse��o entre B e C eh o conjunto vazio\n\n\n");
                            }
                            else
                            {
                                printf("\n\nInterse��o: [ ] Conjunto Vazio\n\n\n");
                                // REPETI��O DO C�DIGO PARA INTERSE��O DO CONJUNTO A e C;
                            }
                        }

                        else
                        {
                            contBC = 0;
                            for (i = 0; i < contB; i++)
                            {
                                for (j = 0; j < contC; j++)
                                {
                                    if (B[i] == C[j])
                                    {
                                        BC[contBC] = B[i];
                                        contBC++;
                                    }
                                }
                            }
                            if (contBC == 0)
                            {
                                printf("\nN�o h� intersec��o entre os conjuntos B e C\n\n\n");
                            }
                            else
                            {
                                printf("\nIntersec��o BC[");
                                for (i = 0; i < contBC; i++)
                                {
                                    printf("%d ", BC[i]);
                                }
                                printf("]\n\n\n");
                            }
                        }
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-Reealizar outra interse��o entre conjuntos \n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }

            break;
        case 7:
            opcao = 1; // reinicia��o de variavel;
            while (opcao == 1)
            { // la�o para fazer a opera��o novamente, caso o usu�rio queira.
                printf("\n O resultado de (X - Y) eh um novo conjunto com elementos que pertencem ao conjunto X, mas n�o pertencem ao conjunto Y.");
                printf("\nQual  diferen�a voc� quer fazer: ");
                printf("\n1- A  - B\n");
                printf("\n2- A  - C\n");
                printf("\n3- B  - A\n");
                printf("\n4- B  - C\n");
                printf("\n5- C  - A\n");
                printf("\n6- C  - B\n");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (conjunto > 6)
                { // tratamento de erro para entrada de dados invalidos.
                    printf("\nInsira dados validos para as op��es !!\n\n");
                }
                else
                {

                    if (conjunto == 1)
                    { // OS COMENT�RIOS DESSA CONDICIONAL TBM S�O APLICADOS AS PR�XIMAS CONDICIONAIS DESTE CASE 7
                        if ((contA == 0) && (contB == 0))
                        {
                            printf(" A-B = Conjunto Vazio[]"); // Caso os dois conjuntos a serem analisados forem vazios, ent�o a diferen�a tbm ser� vazia
                        }

                        else if ((contB != 0) && (contA == 0))
                        {
                            printf(" A-B = Conjunto Vazio[]"); // Caso apenas o primeiro conjunto da diferen�a seja vazio, o conjunto resultado tbm ser� vazio
                        }
                        else if ((contB == 0) && (contA != 0))
                        { // Caso apenas o segudo conjunto da diferen�a seja vazio, o resultado da diferen�a ser�o todos os elementos do primeiro conjunto da difenre�a
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contA; i++)
                            {
                                printf("%d ", A[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contAB = 0; // Vari�vel para encontrar o tamanho do conjunto resultado da diferen�a entre 2 conjuntos
                            for (i = 0; i < contA; i++)
                            {          // O la�o ir� analizar todos os elementos do primeiro conjunto
                                k = 0; // Esta vari�vel � para ser reinicializada sempre que o la�o rodar
                                for (j = 0; j < contB; j++)
                                {
                                    if (A[i] != B[j])
                                    {
                                        k++; // Aqui a vari�vel receber� +1 caso a condicional acima seja aceita
                                    }
                                }
                                if (k == contB)
                                {                      // Caso a vari�vel k for igual ao tamanho do conjunto B, logo ela n�o � igual a nenhum elemento do conjunto B...
                                    AB[contAB] = A[i]; //...ent�o o elemento analisado ocupar� a posi��o contAB do novo conjunto resultado AB
                                    contAB++;
                                }
                            }
                            printf("\n\nDiferen�a: ["); // Imprimindo na tela o conjunto resultado AB de tamanho contAB
                            for (i = 0; i < contAB; i++)
                            {
                                printf("%d ", AB[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }

                    else if (conjunto == 2)
                    {
                        if ((contA == 0) && (contC == 0))
                        {
                            printf(" A-C = Conjunto Vazio[]");
                        }

                        else if ((contC != 0) && (contA == 0))
                        {
                            printf(" A-C = Conjunto Vazio[]");
                        }
                        else if ((contC == 0) && (contA != 0))
                        {
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contA; i++)
                            {
                                printf("%d ", A[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contAC = 0;
                            for (i = 0; i < contA; i++)
                            {
                                k = 0;
                                for (j = 0; j < contC; j++)
                                {
                                    if (A[i] != C[j])
                                    {
                                        k++;
                                    }
                                }
                                if (k == contC)
                                {
                                    AC[contAC] = A[i];
                                    contAC++;
                                }
                            }
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contAC; i++)
                            {
                                printf("%d ", AC[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                    else if (conjunto == 3)
                    {
                        if ((contB == 0) && (contA == 0))
                        {
                            printf(" B-A = Conjunto Vazio[]");
                        }

                        else if ((contA != 0) && (contB == 0))
                        {
                            printf(" B-A = Conjunto Vazio[]");
                        }
                        else if ((contA == 0) && (contB != 0))
                        {
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contB; i++)
                            {
                                printf("%d ", B[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contAB = 0;
                            for (i = 0; i < contB; i++)
                            {
                                k = 0;
                                for (j = 0; j < contA; j++)
                                {
                                    if (B[i] != A[j])
                                    {
                                        k++;
                                    }
                                }
                                if (k == contA)
                                {
                                    AB[contAB] = B[i];
                                    contAB++;
                                }
                            }
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contAB; i++)
                            {
                                printf("%d ", AB[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                    else if (conjunto == 4)
                    {
                        if ((contB == 0) && (contC == 0))
                        {
                            printf(" B-C = Conjunto Vazio[]");
                        }

                        else if ((contC != 0) && (contB == 0))
                        {
                            printf(" B-C = Conjunto Vazio[]");
                        }
                        else if ((contC == 0) && (contB != 0))
                        {
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contB; i++)
                            {
                                printf("%d ", B[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contBC = 0;
                            for (i = 0; i < contB; i++)
                            {
                                k = 0;
                                for (j = 0; j < contC; j++)
                                {
                                    if (B[i] != C[j])
                                    {
                                        k++;
                                    }
                                }
                                if (k == contC)
                                {
                                    BC[contBC] = B[i];
                                    contBC++;
                                }
                            }
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contBC; i++)
                            {
                                printf("%d ", BC[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                    else if (conjunto == 5)
                    {
                        if ((contC == 0) && (contA == 0))
                        {
                            printf(" C-A = Conjunto Vazio[]");
                        }

                        else if ((contA != 0) && (contC == 0))
                        {
                            printf(" C-A = Conjunto Vazio[]");
                        }
                        else if ((contA == 0) && (contC != 0))
                        {
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contC; i++)
                            {
                                printf("%d ", C[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contAC = 0;
                            for (i = 0; i < contC; i++)
                            {
                                k = 0;
                                for (j = 0; j < contA; j++)
                                {
                                    if (C[i] != A[j])
                                    {
                                        k++;
                                    }
                                }
                                if (k == contA)
                                {
                                    AC[contAC] = C[i];
                                    contAC++;
                                }
                            }
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contAC; i++)
                            {
                                printf("%d ", AC[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                    else if (conjunto == 6)
                    {
                        if ((contC == 0) && (contB == 0))
                        {
                            printf(" C-B = Conjunto Vazio[]");
                        }

                        else if ((contB != 0) && (contC == 0))
                        {
                            printf(" C-B = Conjunto Vazio[]");
                        }
                        else if ((contB == 0) && (contC != 0))
                        {
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contC; i++)
                            {
                                printf("%d ", C[i]);
                            }
                            printf("]\n\n\n");
                        }
                        else
                        {
                            contBC = 0;
                            for (i = 0; i < contC; i++)
                            {
                                k = 0;
                                for (j = 0; j < contB; j++)
                                {
                                    if (C[i] != B[j])
                                    {
                                        k++;
                                    }
                                }
                                if (k == contB)
                                {
                                    BC[contBC] = C[i];
                                    contBC++;
                                }
                            }
                            printf("\n\nDiferen�a: [");
                            for (i = 0; i < contBC; i++)
                            {
                                printf("%d ", BC[i]);
                            }
                            printf("]\n\n\n");
                        }
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-realizar outra diferen�a entre conjuntos\n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }
            break;
        case 8:
            opcao = 1; // reinicia��o de variavel;
            while (opcao == 1)
            { // la�o para fazer a opera��o novamente, caso o usu�rio queira.
                printf(" produto cartesiano  de conjuntos nao vazios (X�Y) � formado por pares ordenados (a,b) tais que a � um elemento de X e b � um elemento de Y.");
                printf("\n se pelo menos um dos conjuntos for o conjunto vazio, o seu produto cartesiano ser� obrigatoriamente vazio");
                system("color 9");
                printf("\nQual  produto cartesiano voc� quer fazer: ");
                printf("\n1- A  � B\n");
                printf("\n2- A  � C\n");
                printf("\n3- B  � A\n");
                printf("\n4- B  � C\n");
                printf("\n5- C  � A\n");
                printf("\n6- C  � B\n");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (conjunto > 6)
                { // tratamento de erro para entrada de dados invalidos.
                    printf("\nInsira dados validos para as op��es !!\n\n");
                }
                else
                {

                    if (conjunto == 1)
                    { // A � B = (x, y)
                        printf("Produto Cartesiano: A�B = [");
                        for (i = 0; i < contA; i++)
                        {
                            for (j = 0; j < contB; j++)
                            {
                                printf("(%d,%d)", A[i], B[j]);
                            }
                        }
                        printf("]\n\n\n");
                    }

                    else if (conjunto == 2)
                    {
                        printf("Produto Cartesiano: A�C = [");
                        for (i = 0; i < contA; i++)
                        {
                            for (j = 0; j < contC; j++)
                            {
                                printf("(%d,%d)", A[i], C[j]);
                            }
                        }
                        printf("]\n\n\n");
                    }
                    else if (conjunto == 3)
                    {
                        printf("Produto Cartesiano: B�A = [");
                        for (i = 0; i < contB; i++)
                        {
                            for (j = 0; j < contA; j++)
                            {
                                printf("(%d,%d)", B[i], A[j]);
                            }
                        }
                        printf("]\n\n\n");
                    }
                    else if (conjunto == 4)
                    {
                        printf("Produto Cartesiano: B�C = [");
                        for (i = 0; i < contB; i++)
                        {
                            for (j = 0; j < contC; j++)
                            {
                                printf("(%d,%d)", B[i], C[j]);
                            }
                        }
                        printf("]\n\n\n");
                    }
                    else if (conjunto == 5)
                    {
                        printf("Produto Cartesiano: C�A = [");
                        for (i = 0; i < contC; i++)
                        {
                            for (j = 0; j < contA; j++)
                            {
                                printf("(%d,%d)", C[i], A[j]);
                            }
                        }
                        printf("]\n\n\n");
                    }
                    else if (conjunto == 6)
                    {
                        printf("Produto Cartesiano: C�B = [");
                        for (i = 0; i < contA; i++)
                        {
                            for (j = 0; j < contB; j++)
                            {
                                printf("(%d,%d)", A[i], B[j]);
                            }
                        }
                        printf("]\n\n\n");
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-realizar outro produto cartesiano\n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }
            break;

        case 9:
            conjunto = 0; // reinicia��o de variavel;
            opcao = 1;
            while (opcao == 1)
            { // la�o para fazer a opera��o novamente, caso o usu�rio queira.
                printf("\nQual dos 3 conjuntos voc� quer ver?");
                printf("\n1- Conjunto A");
                printf("\n2- Conjunto B");
                printf("\n3- Conjunto C");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &conjunto);
                fflush(stdin);

                if (conjunto > 3)
                { // tratamento de erro para entrada de dados invalidos.
                    printf("\nInsira dados validos para as op��es !!\n\n");
                }
                else
                {

                    if (conjunto == 1)
                    { // com o uso do la�o for imprime o conjunto A;
                        printf("\n\nConjunto: A[");
                        for (i = 0; i < contA; i++)
                        {
                            printf("%d ", A[i]);
                        }
                        printf("]\n\n\n");
                    }
                    else if (conjunto == 2)
                    {
                        printf("\n\nConjunto: B["); // com o uso do la�o for imprime o conjunto B;
                        for (i = 0; i < contB; i++)
                        {
                            printf("%d ", B[i]);
                        }
                        printf("]\n\n\n");
                    }
                    else if (conjunto == 3)
                    {
                        printf("\n\nConjunto: C["); // com o uso do la�o for imprime o conjunto C;
                        for (i = 0; i < contC; i++)
                        {
                            printf("%d ", C[i]);
                        }
                        printf("]\n\n\n");
                    }
                }
                printf("Oque deseja fazer?");
                printf("\n1-Imprimir outro vetor\n2-Voltar ao menu(obs: se a entrada for superior a 2 tambem ir� voltar ao menu!)");
                printf("\nInsira a op��o escolhida: ");
                scanf("%d", &opcao);
                fflush(stdin);
                system("CLS");
            }

            break;
        case 10: // saindo do programa;
            printf("Finalizando....");
            break;
        default:
            printf("Op��o invalida! Tente novamente\n\n"); // mensagem de erro, caso o usu�rio insira um numero diferente d2 [ 1, 2 , 3 , 4 , 5, 6 , 7 , 8 , 9 , 10];
            system("pause");
            break;
        }
    }

    return 0;
}
