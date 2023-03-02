#include "psh.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>



//Função para a psh ignorar alguns sinais e identificar a nova cepa do virus (SIGUSR1).
void tratadorSinaisBloqueados_psh(int sig) {
    if (sig == SIGUSR1) {
        tratadorSIGUSR1();
    } else {
        char msgPsh[] = "Estou vacinada… desista!!\n";
        int tamMsg = sizeof(msgPsh);
        write(STDOUT_FILENO, msgPsh, tamMsg);
        printPrompt();
    }
}


//Como todos os processos (com exceção da psh) podem se contaminar com o virus SIGUSR1, essa função irá tratar desse virús e, como resultado, o processo afetado irá ser finalizado.
void tratadorSIGUSR1() {
    printMago();                                                //mensagem exibida pela psh ao encontrar a nova cepa 
    FILE *pgrepRes;
    char pgrepCmd[1024];
    pid_t psh_id = getpid();
    snprintf(pgrepCmd, 1024, "/usr/bin/pgrep -P %d", psh_id);
    pgrepRes = popen(pgrepCmd, "r");
    if (pgrepRes == NULL) {
        printf("ERROR opening popen\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(pgrepCmd, sizeof(pgrepCmd), pgrepRes) != NULL) {
        int pid = atoi(pgrepCmd);
        int gpid = getpgid(pid);
        if (gpid != psh_id) killpg(gpid, SIGKILL);          //Uma vez encontrada a presença da nova cepa do vírus (em processos Vacinados e Não Vacinados), o processo irá terminar.
    }
    fclose(pgrepRes);
}

////Após o usuário entrar uma linha de comando, essa a função fará a psh retornar (exibindo o prompt) imediatamente para receber novos comandos.
//Função responssável pela impressão do prompt da psh (passaport shell) no terminal.
void printPrompt() {
    printf("psh> ");
    fflush(stdout);
}

//Como diversos cepas de viírus estao habitando o ambiente do trabalho, essa função irá ficar responsável por tratar eles para a psh, grupo de vacinados e grupos de não vacinados.
void configuraMascaraSinais(int tipo) {
    if (tipo == -1) {                                                      //Tratamento de sinais para a Shell
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &tratadorSinaisBloqueados_psh;
        if ((sigemptyset(&sa.sa_mask) == -1)      ||
            (sigaction(SIGUSR1, &sa, NULL) == -1) ||
            (sigaction(SIGINT, &sa, NULL) == -1)  ||
            (sigaction(SIGQUIT, &sa, NULL) == -1) ||
            (sigaction(SIGTSTP, &sa, NULL) == -1) ) {
                printf("Erro ao configurar a máscara de sinais.\n");
                exit(EXIT_FAILURE);
        }
    } else if (tipo == 1) {                                                //Tratamento de sinais para o grupo de Vacinados
        struct sigaction sa;
        sa.sa_handler = SIG_IGN;
        sa.sa_flags = 0;
        if ((sigemptyset(&sa.sa_mask) == -1)  || 
        (sigaction(SIGINT, &sa, NULL) == -1)  || 
        (sigaction(SIGQUIT, &sa, NULL) == -1) ||
        (sigaction(SIGTSTP, &sa, NULL) == -1) ) {
            printf("Erro ao configurar a máscara de sinais.\n");
            exit(EXIT_FAILURE);
        }
    } else {                                                              //Tratamento de sinais para o grupo Não vacinados
        struct sigaction sa;
        sa.sa_handler = SIG_DFL;
        sa.sa_flags = 0;
        if ((sigemptyset(&sa.sa_mask) == -1)  || 
        (sigaction(SIGINT, &sa, NULL) == -1)  || 
        (sigaction(SIGQUIT, &sa, NULL) == -1) ||
        (sigaction(SIGTSTP, &sa, NULL) == -1) ) {
            printf("Erro ao configurar a máscara de sinais.\n");
            exit(EXIT_FAILURE);
        }
    }
}

//Quando houver o surto da SIGUSR1, a psh irá exibir a mensagem do Mago através dessa função.
void printMago () {
    const char* msg[] = {
 "\n                        ,---. \n",
 "                       /    | \n",
 "                      /     | \n",
 "                     /      | \n",
 "                    /       | \n",
 "               ___,'        | \n",
 "             <  -'          : \n",
 "              `-.__..--'``-,_\\_ \n",
 "                 |o/ ` :,.)_`> \n",
 "                 :/ `     ||/) \n",
 "                 (_.).__,-` |\\ \n"
 "                 /( `.``   `| : \n",
 "                 \'`-.)  `  ; ; \n",
 "                 | `       /-< \n",
 "                 |     `  /   `. \n",
 " ,-_-..____     /|  `    :__..-'\\ \n",
 "/,'-.__\\\\  ``-./ :`      ;       \\ \n",
 "`\\ `\\  `\\\\  \\ :  (   `  /  ,   `. \\ \n",
 "  \\` \\   \\\\   |  | `   :  :     .\\ \\ \n",
 "   \\ `\\_  ))  :  ;     |  |      ): : \n",
 "  (`-.-'\\ ||  |\\ \\   ` ;  ;       | | \n",
 "   \\-_   `;;._   ( `  /  /_       | | \n",
 "    `-.-.// ,'`-._\\__/_,'         ; | \n",
 "       \\:: :     /     `     ,   /  | \n",
 "        || |    (        ,' /   /   | \n",
 "        ||                ,'   /    | \n",
 "________ Unfortunately all process died!________\n",
 "___ Vaccination should be a social contract!____\n"
 "____Cooperation was the morally right choice!___\n"};
    fflush(stdout);
    int tam;
    for (int i = 0; i < 27; i++) {
        printf("%s", msg[i]);
    }
    printPrompt();
}