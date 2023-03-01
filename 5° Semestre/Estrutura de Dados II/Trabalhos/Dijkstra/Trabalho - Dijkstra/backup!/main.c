#include "leitura.h"
#include "grafo.h"
#include "priorityQueue.h"
#include <stdio.h>

void escreveSaida(FILE * arquivoSaida, GuardaRazao * razoes, int n);

int main(int argc, char** argv){
    /** Cria um grafo vazio para ser passado como parâmetro para outras funções */
    Grafo * grafo = criaGrafoVazio();

    FILE *file = NULL; /** Ponteiro para ler entrada */
    file = abreArquivo(file, argv[1]); /** Verifica se é possível abrir o arquivo e se o mesmo não é nulo */

    FILE *arquivoSaida = fopen(argv[2], "w");; /** Arquivo para gravar saida */

    leDimensao(file, grafo); /** Lê a quantidade de vértices e arestas e inicializa o grafo e a lista de adjacencias */
    formaArestas(file, grafo); /** Grava as arestas e seus vértices na lista de adjacências */

    /** Vamos calcular agora as distancias entre servidores, clientes e monitores e colocar em matrizes (double**)
     * para isso iremos alocar o espaço para cada matriz, e iremos chamar o algoritmo de dijstra "tamanho do vetor auxiliar"
     * vezes, se tivermos 3 servidores por exemplo, o for irá chamar dijkstra 3 vezes...
     * Repetimos o procedimento para cada um dos 3 tipos de vetores auxiliares
     * */
    //matriz de servidores na "linha" && clientes e monitores na "coluna"
    int* vetorServidores = retornaVetorServidores(grafo);
    double** distanciasServidores = malloc(sizeof(double) * retornaNumServidores(grafo));
    for (int i = 0; i < retornaNumServidores(grafo); i++) {
        distanciasServidores[i] = dijkstra(grafo, vetorServidores[i], retornaVetorClientes(grafo), retornaVetorMonitores(grafo),
                                           retornaNumClientes(grafo), retornaNumMonitores(grafo));
    }

    //matriz de clientes na "linha" && servidores e monitores na "coluna"
    int* vetorClientes = retornaVetorClientes(grafo);
    double** distanciasClientes = malloc(sizeof(double) * retornaNumClientes(grafo));
    for (int i = 0; i < retornaNumClientes(grafo); i++) {
        distanciasClientes[i] = dijkstra(grafo, vetorClientes[i], retornaVetorServidores(grafo), retornaVetorMonitores(grafo),
                                         retornaNumServidores(grafo), retornaNumMonitores(grafo));
    }

    //matriz de monitores na "linha" && servidores e clientes na "coluna"
    int* vetorMonitores = retornaVetorMonitores(grafo);
    double** distanciasMonitores = malloc(sizeof(double) * retornaNumMonitores(grafo));
    for (int i = 0; i < retornaNumMonitores(grafo); i++) {
        distanciasMonitores[i] = dijkstra(grafo, vetorMonitores[i], retornaVetorServidores(grafo), retornaVetorClientes(grafo),
                                          retornaNumServidores(grafo), retornaNumClientes(grafo));
    }

    /** Agora com as distancias calculadas, vamos calcular os RTT* e RTT e fazer a razão entre eles */
    GuardaRazao* razoes = calculaRazoesEntreRTT(grafo, distanciasServidores, distanciasClientes, distanciasMonitores);

    /** Com as razões calculadas podemos ordenar esse vetor do menor pro maior */
    qsort(razoes, retornaNumServidores(grafo) * retornaNumClientes(grafo), sizeof(GuardaRazao), compara);

    /** Liberando as matrizes auxiliares acima */
    destroiMatriz(distanciasClientes, retornaNumClientes(grafo));
    destroiMatriz(distanciasMonitores, retornaNumMonitores(grafo));
    destroiMatriz(distanciasServidores, retornaNumServidores(grafo));

    /** Escreve no arquivo de saida */
    escreveSaida(arquivoSaida, razoes, retornaNumServidores(grafo)*retornaNumClientes(grafo));

    /** Impressões de teste */
//    imprimeVetores(grafo);
//    imprimeGrafoLista(grafo, arquivoSaida);
//    imprimeLista(grafo);

    /** Liberação de memória */
    destroiListaComAdjacencias(grafo); /** Destroi a lista de vértices assim como suas listas de adjacencias */
    destroiVetoresAuxiliares(grafo); /** Destrói os vetores auxiliares e o grafo */
    free(grafo); /** Libera memória alocada pro grafo */
    fclose(file);

    return 0;
}

void escreveSaida(FILE * arquivoSaida, GuardaRazao * razoes, int n){
    // n = |S||C|
    for (int i = 0; i < n; i++) {
        fprintf(arquivoSaida, "%d %d %.16lf\n", razoes[i].servidor, razoes[i].cliente, razoes[i].razao);
    }
}