#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>










/*  
COMENTARIOS:
    Apenas implementei e não fiz as duas ultimas.
    
    OK- O processo pai, P0, lê do teclado um valor X inteiro entre 1-5.
    OK- O processo pai, P0, lê do teclado um segundo valor Y inteiro entre 6 e 10.
    OK- P0 cria três filhos, P1, P2 e P3.
    OK- P0 envia para o filho P1 via pipe (pipe1) o valor de X.
    OK- P0 envia para o filho P2 via pipe (pipe2) o valor de Y.
    OK- P0 envia para P1, pelo mesmo pipe1, a seguinte mensagem (string): "Meu filho, crie e envie para o seu irmão P3 um array de tamanho randômico entre 100 e 200, preenchido completamente com o valor X" (obs: ele envia o valor de X e não a letra 'X').
    OK- P0 envia para P2, pelo mesmo pipe2, a seguinte mensagem (string): "Meu filho, crie e envie para o seu irmão P3 um array de tamanho randômico entre 100 e 200, preenchido completamente com o valor Y" (obs: ele envia o valor de Y e não a letra 'Y').
    OK- P1 e P2 recebem e imprimem a mensagem enviada pelo pai (identifique se é P1 ou P2 quem printa cada mensagem).
    OK- P1 e P2 criam seus arrays de tamanho randômico, entre 100 e 200, preenchendo-os com valores X (no caso de P1) e Y (no caso de P2), conforme solicitado pelo pai.
    NÃO FIZ- P1 e P2 enviam os arrays para o irmão P3, via pipe3 (sim... eles usarão o mesmo pipe!! mas cuidado! as escritas podem se embaralhar.... resolvam isso!).
    NÃO FIZ- P3 lê os dois arrays enviados e printa os arrays na saída padrão. 
*/






int main(){

    //#Variaveis para o pipe 
    int pid1, pid2,pid3;
    int p_desc[4][3], flag = 0,
    int  x,y;

    //#Criando os 3 PIPES
    for (size_t i = 0; i < 4; i++){
        if (pipe(p_desc[i]) < 0){
            perror("Error pipe");
            exit(1);
        }
    }

    //#Criando o primeiro filho
    pid1 = fork();
    if (pid1 < 0){
        perror("Error fork");
        return 1;
    }
    if (pid1 == 0){
        char *msg;
        int z;
        int array[200];  //Array de até 200
        char str[300];
        int tam_str;
        srand(time(NULL));

        int SIZE = 100 + rand() % 200; // numero de elementos do array,pode ser de 100 a 200 random    
        if(SIZE>200){
            SIZE = SIZE - 100;
        }

        close(p_desc[2][0]);
        close(p_desc[2][1]);
        close(p_desc[1][0]);
        close(p_desc[0][1]);

        read(p_desc[0][0],&tam_str,sizeof(int));
        read(p_desc[0][0],&str,sizeof(char) * tam_str);
        printf("%s\n",str);

        read(p_desc[0][0], &z, sizeof(int));
        close(p_desc[0][0]);

        printf("P1 quem printa -> Array do filho 1:");
        for (int i = 0; i < SIZE; i++){ //escreve numeros random no array
            array[i] = rand() % z + 1;
            printf(" %d ", array[i]);
        }
        printf("\n");
        write(p_desc[1][1], &SIZE, sizeof(int));
        write(p_desc[1][1], array, sizeof(array)); //escreve o array 1
        close(p_desc[1][1]);
        return 0;
    }

    //#Criando o segundo filho
    pid2 = fork();
    if (pid2 < 0){
        perror("Error fork");
        return 2;
    }

    if (pid2 == 0){
        int arr[200];
        int tam;
        int sum = 0;

        read(p_desc[1][0], &tam, sizeof(int));
        read(p_desc[1][0], &arr, sizeof(int) * tam);
        close(p_desc[1][0]);

        close(p_desc[0][0]);
        close(p_desc[0][1]);
        close(p_desc[1][1]);
        close(p_desc[2][0]);

        for (int i = 0; i < tam; i++) {
            sum = sum + arr[i];
        }

        write(p_desc[2][1], &sum, sizeof(int));
        close(p_desc[2][1]);
        return 0;
    }




    //#Criando o terceiro filho (usando a mesma lógica do filho 1)
    pid1 = fork();
    if (pid1 < 0){
        perror("Error fork");
        return 1;
    }
    if (pid1 == 0){
        char *msg;
        int z;
        int array[200];  //array de até 200
        char str[300];
        int tam_str;
        srand(time(NULL));

        int SIZE = 100+ rand() % 200; // numero de elementos do array,pode ser de 100 a 200 random    
        if(SIZE>200){
            SIZE = SIZE - 100;
        }

        close(p_desc[2][0]);
        close(p_desc[2][1]);
        close(p_desc[1][0]);
        close(p_desc[0][1]);

        read(p_desc[3][3],&tam_str,sizeof(int));
        read(p_desc[3][3],&str,sizeof(char) * tam_str);
        printf("%s\n",str);

        read(p_desc[3][3], &z, sizeof(int));
        close(p_desc[3][3]);

        printf("P2 quem printa -> Array do filho 3");
        for (int i = 0; i < SIZE; i++){ //escreve numeros random no array
            array[i] = rand() % z + 1;
            printf(" %d ", array[i]);
        }
        printf("\n");
        write(p_desc[3][3], &SIZE, sizeof(int));
        printf("P2 quem printa:\n");
        write(p_desc[3][3], array, sizeof(array)); //escreve o array do filho 3
        close(p_desc[3][3]);
        return 0;
    }

//#Criando o pai 

    close(p_desc[0][0]);
    close(p_desc[1][0]);
    close(p_desc[1][1]);
    close(p_desc[2][1]);


    char str1[] = "Meu filho, crie e envie para o seu irmão P3 um array de tamanho randômico entre 100 e 200, preenchido completamente com o valor X";
    int tam1 = (strlen(str1) + 1);
    printf("Digite um numero de 1 a 5: ");    //#- O processo pai, P0, lê do teclado um valor y inteiro entre 1-5
    scanf("%d", &x);
    write(p_desc[0][1], &tam1, sizeof(int));
    write(p_desc[0][1], str1, strlen(str) + 1);
    write(p_desc[0][1], &x, sizeof(int));
    close(p_desc[0][1]);


    char str2[] = "Meu filho, crie e envie para o seu irmão P3 um array de tamanho randômico entre 100 e 200, preenchido completamente com o valor Y"; 
    int tam2 = (strlen(str2) + 1);
    printf("Digite um numero de 6 a 10: ");   //#- O processo pai, P0, lê do teclado um valor y inteiro entre 6-10
    scanf("%d", &y);
    write(p_desc[2][3], &tam2, sizeof(int));
    write(p_desc[2][3], str2, strlen(str) + 1);
    write(p_desc[2][3], &y, sizeof(int));
    close(p_desc[2][3]);
}