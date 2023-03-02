#include "cmd.h"
#include "psh.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

//struct tLista para armazenar os comandos passados pelo prompt do psh (passaport shell).
//contendo um comando, o pid e um ponteiro para o próximo.
struct tipoLista
{
    tLista* prox;
    tCmd* cmd;
    pid_t gpidVacinados;
};

//struct referente aos comandos que irão esta presente na lista de comandos.
//contendo o nome do comando, numero de argumentos e tipo (Vacinado ou Não Vacinado).
struct tipoComando
{
    char** comando;
    int numArgs;
    int tipo;
};

tLista* iniciaListaVazia() {
    return NULL;
}

tLista* insereCmdLista(tLista* lista, tCmd* cmd) {          //Inserindo uma novo comando na lista.
    tLista* nova = (tLista*)malloc(sizeof(tLista)); 
    nova->cmd = cmd;
    nova->prox = lista;
    nova->gpidVacinados = -1;
    return nova;
}

void destroiLista(tLista* lst) {                           //Liberando a memória alocada para a lista.
    if (lst == NULL) return;
    tLista* p;
    p = lst;
    tLista* t;
    while (p != NULL) {
        t = p->prox;
        liberaCmd(p->cmd);
        free(p);
        p = t;
    }
}

//Tratamento para passar os comandos em uma mesma linha de comando (pode variar de 1 a 5).
tLista* preencheLstCmds(tLista* lst, char* input) {
    char* vetStr[N_MAX_CMDS] = {};
    char* token;
    char* resto = input;
    int cont = 0;
    while ((token = strtok_r(resto, ";", &resto))) {
        if (cont == N_MAX_CMDS) {
            printf("Erro: Somente 5 comandos por linha sao permitidos!!");
            exit(EXIT_FAILURE);
        }
        vetStr[cont] = token;
        cont++;
    }
    if (cont > 1) {
        for (int i = 0; i < cont; i++) {
        lst = insereCmdLista(lst, stringParaCmd(vetStr[i], VAC));
        }
    } else {
        for (int i = 0; i < cont; i++) {
        lst = insereCmdLista(lst, stringParaCmd(vetStr[i], NVAC));
        }
    }
    return lst;
}

//Retorno do pid do grupo do tipo Vacinado.
pid_t retorna_gpidLst (tLista* lst) {
    return lst->gpidVacinados;
}

//Imprimindo o GPID do tipo Vacinado.
void printLstCmd (tLista* lst) {
    printf("GPID na lista: %d\n", lst->gpidVacinados);
    tLista* p;
    p = lst;
    tLista* t;
    while (p != NULL) {
        t = p->prox;
        printCmd(p->cmd);
        p = t;
    }
}

//Essa função irá retornar um novo comando com nome, tipo e tamanho dos argumentos.
tCmd* stringParaCmd(char* input, int tipo) {
    char** msg = malloc(N_ARGS_CMD*sizeof(char*));
    char* token;
    char* resto = input;
    int cont = 0;
    while ((token = strtok_r(resto, " ", &resto))) {
        if (cont == N_ARGS_CMD) {
            printf("Erro: Somente 2 argumentos por comando externo sao permitidos!!");
            exit(EXIT_FAILURE);
        }
        msg[cont] = token;
        cont++;
    }
    tCmd* novoCmd = (tCmd*)malloc(sizeof(tCmd));
    novoCmd->numArgs = cont;
    novoCmd->comando = msg;
    novoCmd->tipo = tipo;
    return novoCmd;
}


void liberaCmd(tCmd* cmd) {         //Liberando a memória alocada para um comando.
    free(cmd->comando);
    free(cmd);
}


void printCmd(tCmd* cmd) {          //Imprimindo o comando.
    printf("--------------Comando------------\n");
    for (int i = 0; i < cmd->numArgs; i++) {
        printf("{%s}", cmd->comando[i]);
    }
    printf("\nN args:%d\nTipo(0=Nao vacinado;1=Vacinado):%d\n", cmd->numArgs,cmd->tipo);
    printf("---------------------------------\n");
}


int leitorEntrada(char* msgLida) {          //lendo a entrada.
    if (fgets(msgLida, TAM_BUFFER_CMD, stdin)) {
        msgLida[strcspn(msgLida, "\n")] = '\0'; //retira o \n da mensagem.
        if (strlen(msgLida) == 0) return 0;
        return 1;
    }
    return 0;
}

//Tratamento das funções internas da  psh (passaport shell). 
int tratadorOperacoesInternas(char* input, pid_t gpidVacinados) {
    if (strcmp(input, "term") == 0) {                                                               //caso a operação seja "term".
        termCmd();
    }
    if (strcmp(input, "fg") == 0) {                                                                 //caso a operação seja "fg".
        if (gpidVacinados == -1) {
            printf("Não há grupo de processos vacinados para serem colocados em foreground!!\n");
            return 1;
        }

        // protege o shell contra sinais de uso ilegal de stdin e stdout
        signal(SIGTTOU, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);

        pid_t psh_gpid = getpgid(0);
        if (tcsetpgrp(STDIN_FILENO, gpidVacinados) < 0) {                               //colocando todos os processos do grupo de vacinados temporariamente em foreground.
            printf("Erro ao colocar os processos vacinados em foreground\n");
            exit(EXIT_FAILURE);
        }
        sleep(30);                                                                       //Eles permanecerão em foreground por 30 segundos, retornando para background em seguida.
                                                                                        //psh ficará em background esperando esses 30 segundos acabarem, retornando para foreground em seguida.
        if (tcsetpgrp(STDIN_FILENO, psh_gpid) < 0) {
            printf("Erro ao colocar a psh em foreground\n");
            exit(EXIT_FAILURE);
        }

        //encerramento da proteção contra sinais de uso ilegal de stdin e stdout.
        signal(SIGTTOU, SIG_DFL);
        signal(SIGTTIN, SIG_DFL);
        return 1;
    }
   return 0;
}

int contaCmds (tLista* lst) {       //contando quantos comandos tem na lista.
    tLista* p;
    p = lst;
    tLista* t;
    int cont = 0;
    while (p != NULL) {
        t = p->prox;
        cont++;
        p = t;
    }
    return cont;
}

tCmd* retornaCmdDaLista (tLista* lst) {     //retornando um cmd da lista.
    return lst->cmd;
}

tLista* removeCmdLista (tLista* lst) {      //removendo um cmd da lista.
    if (lst->prox == NULL) {
        free(lst);
        return NULL;
    } else {
        tLista* temp = lst->prox;
        lst->prox = temp->prox;
        free(lst);
        return temp;
    }
}

void seta_gpidLst(tLista* lst, pid_t gpid) {    // Salva o gpid dos vacinados na lista
    lst->gpidVacinados = gpid;
}

int ehSaidaRedirecionada(char** comando, int nArgs) {       // verifica se a saída do processo não vacinado para um arquivo vai ser redirecionada.
    for (int i = 0; i < nArgs; i++) {
        if (strcmp(comando[i], ">") == 0) return 1;
    }
    return 0;
}

//Comando para Executar processos do tipo Não Vacinados.
void executaNaoVacinados(tLista* lst) {
    pid_t procGerente = fork();
    verificaErroFork(procGerente);

    if (procEhFilho(procGerente)) {
        configuraMascaraSinais(NVAC);
        setpgid(0,0);                      //criando um novo grupo para cada comando do tipo Não Vacinado.
        pid_t pidCmd;
        int estadoExec;
        tCmd* cmd = retornaCmdDaLista(lst);
        pidCmd = fork();
        verificaErroFork(pidCmd);
        if (procEhFilho(pidCmd)) {
            if (ehSaidaRedirecionada(cmd->comando, cmd->numArgs)) {                     //caso seja necessário redirecionar a saída padrão para um arquivo.
                int arq = open(cmd->comando[2], O_WRONLY);
                if (arq < 0) {
                    printf("Erro ao abrir o arquivo do comando nao vacinado\n");
                    exit(1);
                }
                dup2(arq, STDOUT_FILENO);
                char* programa;
                strcpy(programa, cmd->comando[0]);
                char* args[2];
                args[0] = programa;
                args[1] = NULL;
                estadoExec = execvp(programa, args);
                if (estadoExec == -1) {
                    printf("Erro ao executar o comando:%s\n", cmd->comando[0]);
                    exit(EXIT_FAILURE);
                }
                close(arq);
            } else { 
                estadoExec = execvp(cmd->comando[0], cmd->comando);
                if (estadoExec == -1) {
                    printf("Erro ao executar o comando:%s\n", cmd->comando[0]);
                    exit(EXIT_FAILURE);
                }
            }
            liberaCmd(cmd);
            exit(0);
        }
        destroiLista(lst);
        int status;
        while (1) {
            if (((waitpid(-1, &status, WNOHANG)) == -1)) {
                break;
            }

            if (status == SIGUSR1) {            ////tratamento da nova cepa do virus SIGUSR1.
                kill(getppid(), SIGUSR1);
                sleep(3);
                break;
            }
        }
        exit(0);
    } else {
        lst->gpidVacinados = procGerente;
    }
}


//Comando para Executar processos do tipo Vacinado.
void executaVacinados(tLista* lst) {
    pid_t gpidVac = retorna_gpidLst(lst);
    pid_t procGerente = fork();
    verificaErroFork(procGerente);

    if (procEhFilho(procGerente)) {             //caso não exista um process group do tipo Vacinado é criado um, caso contrário, o comando do tipo Vacinado é adicionado a ele.
        if (gpidVac != -1) {
            setpgid(0,gpidVac);                 

        } else {
            setpgid(0,0);
        }
        configuraMascaraSinais(VAC);
        int numCmds = contaCmds(lst);
        pid_t pidsCmds[numCmds];
        int estadoExec[numCmds];

        for (int i = 0; i < numCmds; i++) {
            tCmd* cmd = retornaCmdDaLista(lst);
            lst = removeCmdLista(lst);
            pidsCmds[i] = fork();
            verificaErroFork(pidsCmds[i]);
            if (procEhFilho(pidsCmds[i])) {
                estadoExec[i] = execvp(cmd->comando[0], cmd->comando);
                if (estadoExec[i] == -1) {
                    printf("Erro ao executar o comando:%s\n", cmd->comando[0]);
                    exit(EXIT_FAILURE);
                }
                liberaCmd(cmd);
                exit(0);
            }
        }
        destroiLista(lst);
        int status;
        while (1) {
            if (((waitpid(-1, &status, WNOHANG)) == -1)) {
                break;
            }                

            if (status == SIGUSR1) {                //tratamento da nova cepa do virus SIGUSR1.
                kill(getppid(), SIGUSR1);
                sleep(3);
                break;
            }
        }
        exit(0);
    } else {
        if (gpidVac == -1) lst->gpidVacinados = procGerente;
    }
}

void liberaZombies() {                  //liberando processos em estado Z (Zumbi).
    int status;
    while (waitpid(-1, &status, WNOHANG) > 0);
}

void verificaErroFork(pid_t pid) {              //verificação de erro no fork.
    if (pid == -1) {
        printf("Erro: fork falhou!\n");
        exit(1);
    }
}

int procEhFilho(pid_t pid) {            //verifica se é  um filho.
    return (pid == 0);
}

//Função para auxiliar a operação interna da psh (passaport shell).
//Devendo terminar a operação da psh, e antes disso, matar todos os processos que foram criados (vacinados e não vacinados).
void termCmd(){
    FILE *pgrepRes;
    char pgrepCmd[200];
    pid_t psh_id = getpid();

    snprintf(pgrepCmd, 200, "/usr/bin/pgrep -P %d", psh_id);
    pgrepRes = popen(pgrepCmd, "r");

    if (pgrepRes == NULL) {
        printf("ERROR opening popen\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(pgrepCmd, sizeof(pgrepCmd), pgrepRes) != NULL) {   //matando todos os processos que foram criados pela psh (vacinados e não vacinados).
        int pid = atoi(pgrepCmd);
        int gpid = getpgid(pid);
        if (gpid != psh_id) killpg(gpid, SIGKILL);
    }
    fclose(pgrepRes);
    sleep(1);
    exit(0);            //terminando a operação da psh.
}