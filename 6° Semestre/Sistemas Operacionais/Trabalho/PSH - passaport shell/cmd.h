#ifndef CMD_H
#define CMD_H
#define NVAC 0
#define VAC 1
#define TAM_BUFFER_CMD 100
#define TAM_BUFFER_INPUT 500
#define N_MAX_CMDS 5
#define N_ARGS_CMD 4
#define NUM_MAX_NVAC 100
#define O_WRONLY 01
#include <unistd.h>

//Structs a  serem utilizadas 
typedef struct tipoLista tLista;       
typedef struct tipoComando tCmd;       

/**
 * @brief Retorna uma lista vazia
 * 
 * @return tLista* 
 */
tLista* iniciaListaVazia();             

/**
 * @brief Insere um tipoComando no início da Lista
 * 
 * @param lista 
 * @param cmd 
 * @return tLista* 
 */
tLista* insereCmdLista(tLista* lista, tCmd* cmd);

/**
 * @brief Cria os tipoComando resultante da entrada lida e insere-os na lista
 * 
 * @param lst 
 * @param input 
 * @return tLista* 
 */
tLista* preencheLstCmds(tLista* lst, char* input);

/**
 * @brief  Tratamento para argumentos de comandos externos.
 * 
 * @param input 
 * @param tipo 
 * @return tCmd* 
 */
tCmd* stringParaCmd(char* input, int tipo); //Essa função irá retornar um novo comando com nome, tipo e tamanho dos argumentos.

/**
 * @brief  Libera a memória ocupada por um comando.
 * 
 * @param cmd 
 * @return void* 
 */
void liberaCmd(tCmd* cmd);

/**
 * @brief  Imprime o comando contendo numero de argumentos e tipo (vacinado/não vacinado).
 * 
 * @param cmd 
 * @return void* 
 */
void printCmd(tCmd* cmd);

/**
 * @brief  Conta quantos comandos estão presentes na lista de comandos.
 * 
 * @param lst 
 * @return int 
 */
int contaCmds(tLista* lst);

/**
 * @brief  Retorna um comando presente na lista de comandos.
 * 
 * @param lst 
 * @return tCmd* 
 */
tCmd* retornaCmdDaLista (tLista* lst);

/**
 * @brief  Termina a operação da psh.
 * 
 * 
 * @return void 
 */
void termCmd();
 
 /**
 * @brief  Imprime o GPID que esta presente na lista de comandos.
 * 
 * @param lst 
 * @return void 
 */
void printLstCmd(tLista* lst);

/**
 * @brief  Retorna o pid da lista de vacinados.
 * 
 * @param lst 
 * @return pid_t
 */
pid_t retorna_gpidLst (tLista* lst);

/**
 * @brief  Libera a memória alocada para a lista.
 * 
 * @param lst 
 * @return void
 */
void destroiLista(tLista* lst);

/**
 * @brief  Remove um comando presente na lista.
 * 
 * @param lst 
 * @return tLista*
 */
tLista* removeCmdLista (tLista* lst);

/**
 * @brief  Executa comandos do tipo Vacinados.
 * 
 * @param lst 
 * @return void
 */
void executaVacinados(tLista* lst);

/**
 * @brief  Executa comandos do tipo Não Vacinados.
 * 
 * @param lst 
 * @return void
 */
void executaNaoVacinados(tLista* lst);

/**
 * @brief  Verifica se ocorreu um erro na criação de um fork.
 * 
 * @param pid_t 
 * @return void
 */
void verificaErroFork(pid_t pid);

/**
 * @brief  Verificase o processo é filho.
 * 
 * @param pid_t 
 * @return void
 */
int procEhFilho(pid_t pid);

/**
 * @brief Salva o gpid dos vacinados na lista
 * 
 * @param lst 
 * @param pid_t 
 * @return void
 */
void seta_gpidLst(tLista* lst, pid_t gpid);

/**
 * @brief  Libera processos em estado Z (Zumnbi). 
 * 
 * @return void
 */
void liberaZombies();

/**
 * @brief  Leitura de entrada da psh (passaport shell). 
 * 
 * @param char* 
 * @return int
 */
int leitorEntrada(char* msgLida);

/**
 * @brief  Tratamento das operações internas da psh (passaport shell). 
 * 
 * @param char* 
 * @param pid_t 
 * @return int
 */
int tratadorOperacoesInternas(char* input, pid_t gpidVacinados); //tratamento dos comandos "term" e "fg"

/**
 * @brief  Verifica se a saída do processo não vacinado para um arquivo vai ser redirecionada.
 * 
 * @param char** 
 * @param int 
 * @return int
 */
int ehSaidaRedirecionada(char** comando, int nArgs);

#endif