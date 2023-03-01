#include "leitura.h"
#include "grafo.h"
#include "priorityQueue.h"
#include <stdio.h>

void printaRazoes(FILE *wfile, GuardaRazao *razoes, int n);

int main(int argc, char **argv)
{
    /** Cria um grafo vazio para ser passado como parâmetro para outras funções */
    Grafo *grafo = criaGrafoVazio();

    FILE *file = NULL;                 /** Ponteiro para ler entrada */
    file = abreArquivo(file, argv[1]); /** Verifica se é possível abrir o arquivo e se o mesmo não é nulo */

    FILE *arquivoSaida = fopen(argv[2], "w");
    ; /** Arquivo para gravar saida */

    leDimensao(file, grafo); /** Lê a quantidade de vértices e arestas e inicializa o grafo e o vetor de ponteiro */

    formaArestas(file, grafo); /** Grava as arestas e seus vértices no vetor de ponteiros para o estruturaGrafo */

    /** Calcula as distancias entre os vertices utilizando o algoritmo de dijkstra, tomando o cuidado de calcular distancias
     * entre servidores e monitores; monitores e clientes */
    double **distanciaServidorMonitor = calculaDistancias(grafo, retornaNumServidores(grafo), retornaVetorServidores(grafo),
                                                          retornaVetorMonitores(grafo), retornaNumMonitores(grafo));
    double **distanciaMonitorServidor = calculaDistancias(grafo, retornaNumMonitores(grafo), retornaVetorMonitores(grafo),
                                                          retornaVetorServidores(grafo), retornaNumServidores(grafo));
    double **distanciaClienteMonitor = calculaDistancias(grafo, retornaNumClientes(grafo), retornaVetorClientes(grafo),
                                                         retornaVetorMonitores(grafo), retornaNumMonitores(grafo));
    double **distanciaMonitorCliente = calculaDistancias(grafo, retornaNumMonitores(grafo), retornaVetorMonitores(grafo),
                                                         retornaVetorClientes(grafo), retornaNumClientes(grafo));
    double **distanciaServidorCliente = calculaDistancias(grafo, retornaNumServidores(grafo), retornaVetorServidores(grafo),
                                                          retornaVetorClientes(grafo), retornaNumClientes(grafo));
    double **distanciaClienteServidor = calculaDistancias(grafo, retornaNumClientes(grafo), retornaVetorClientes(grafo),
                                                          retornaVetorServidores(grafo), retornaNumServidores(grafo));

    /** Agora iremos calcular os Rtts entre os clientes e servidores, para que tenhamos no final a razão enter o "rttReal"
     * e o "rttAproximado", para isso utilizaremos como auxilo uma struct guarda razões, que terá a origem, o destino e o valor
     * da razao pra aquela origem e destino"*/
    GuardaRazao *razoes = calculaRazoesEntreRTT(grafo, distanciaServidorMonitor, distanciaMonitorServidor,
                                                distanciaClienteMonitor, distanciaMonitorCliente,
                                                distanciaServidorCliente, distanciaClienteServidor);

    /** Ordena razoes, da menor pra maior */
    qsort(razoes, retornaNumServidores(grafo) * retornaNumClientes(grafo), sizeof(GuardaRazao), compara);

    /** Liberando memória das matrizes distancias */
    destroiMatriz(distanciaServidorMonitor, retornaNumServidores(grafo));
    destroiMatriz(distanciaMonitorServidor, retornaNumMonitores(grafo));
    destroiMatriz(distanciaClienteMonitor, retornaNumClientes(grafo));
    destroiMatriz(distanciaMonitorCliente, retornaNumMonitores(grafo));
    destroiMatriz(distanciaServidorCliente, retornaNumServidores(grafo));
    destroiMatriz(distanciaClienteServidor, retornaNumClientes(grafo));

    /** Printa servidor e cliente e a razao de RTT/RTT* entre eles */
    printaRazoes(arquivoSaida, razoes, retornaNumServidores(grafo) * retornaNumClientes(grafo));

    /** Liberação de memória */
    free(razoes);
    destroiGrafo(grafo); /** Libera memória alocada pro grafo e os vetores auxiliares */
    fclose(file);

    return 0;
}

void printaRazoes(FILE *wfile, GuardaRazao *razoes, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(wfile, "%d %d %.16f\n", razoes[i].origem, razoes[i].destino, razoes[i].razao);
    }
}