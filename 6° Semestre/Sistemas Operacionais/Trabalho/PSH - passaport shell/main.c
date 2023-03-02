#include <stdlib.h>
#include "psh.h"
#include "cmd.h"

int main (int argc, char** argv) {

    configuraMascaraSinais(-1);

    pid_t* gpidVacinados = malloc(sizeof(pid_t));                           //formado o pid para o grupo de vacinados.
    *gpidVacinados = -1;
    int ehPrimeiroVacinado = 1;                                             //variável usada como "flag" para saber se há ou nao um grupo de vacinados, em caso de nao haver, é criado um. 

    while (1) {
        char input[TAM_BUFFER_INPUT];
        printPrompt();
        liberaZombies();        
        if (!leitorEntrada(input)) continue;

        if (tratadorOperacoesInternas(input, *gpidVacinados)) continue;  

        tLista* lstCmds = iniciaListaVazia();
        lstCmds = preencheLstCmds(lstCmds, input);                          //todos os comandos inseridos no prompt são passados para uma lista (lstCmds).
        if (contaCmds(lstCmds) > 1) {
            if (*gpidVacinados == getpid()) {
                ehPrimeiroVacinado = 1;
                *gpidVacinados = -1;
            }
            if (!ehPrimeiroVacinado) {
                seta_gpidLst(lstCmds, *gpidVacinados);                     //caso  seja um processo "Vacinado", ele é craido e colocado no mesmo process group.
                executaVacinados(lstCmds);
            } else {
                executaVacinados(lstCmds);
                *gpidVacinados = retorna_gpidLst(lstCmds);
                ehPrimeiroVacinado = 0;
            }
        } else {
            executaNaoVacinados(lstCmds);                                   //caso seja um processo "Não Vacinado", ele é criado isoladamente, cada um em seu process group  
        }
        destroiLista(lstCmds);
    }
    free(gpidVacinados);
    return 0;
}
