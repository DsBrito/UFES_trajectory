#include "leitura.h"

FILE* abreArquivo(FILE* file, char* nomeDoArquivo){
    file = fopen(nomeDoArquivo, "r"); /** Leitura do arquivo de entrada, retorna ponteiro para file */
    if (file == NULL){ /** Verifica se o arquivo é null */
        printf("Arquivo nao pode ser aberto\n");
        exit(0);
    }
    return file;
}

void leDimensao(FILE* file, Grafo* grafo){ //le quantidade de vetorVertices e arestas
    const char s[2] = " "; /** Chave utilizada para separar os tokens, no caso o [espaço] */
    char* token1; /** Tokens que irão auxiliar na leitura de cada item das linhas */
    char* token2;
    int numVertice, numAresta;
    size_t len= 100; /** Valor arbitrário para utilizar a função getLine*/
    char *linha= malloc(len);

    getline (&linha, &len, file); /** Lê a primeira linha do arquivo */

    token1 = strtok(linha,s); /** Pega o primeiro item e coloca no token1 */
    numVertice = converteNumero(token1); /** Converte o item pra double e coloca no numVertice*/

    token2 = strtok(NULL,s); /** Pega o segundo item e coloca no token2 */
    numAresta = converteNumero(token2); /** Converte o item pra double e coloca no numAresta*/

    free(linha); /** Libera a linha que foi alocada acima */
    inicGrafo(grafo, numVertice, numAresta); /** Inicializa o grafo*/
    criaLista(grafo, numVertice);
}

double converteNumero (char * token){
    double numerete = atof(token); /** Converte o token para double*/
    return numerete;
}

void formaArestas (FILE * file, Grafo * grafo){ //grava as arestas e seus vértices na matriz de adjacencias e na lista de adjacencias
    const char s[2] = " "; /** Chave utilizada para separar os tokens, no caso o [espaço] */
    char* token1;   /** Tokens que irão auxiliar na leitura de cada item das linhas */
    char* token2;
    char* token3;
    int quantServidores, quantClientes, quantMonitores;
    int verticeOrigem, verticeDestino;
    double valorAresta;
    int i;  /** Contador para os whiles */
    size_t len= 100; /** Valor arbitrário para utilizar a função getLine*/
    char *linha= malloc(len);

    /** Pega a segunda linha e lê a quantidade de servidores, clientes e monitores colocando nas
     * suas devidas variáveis */
    getline (&linha, &len, file);
    token1 = strtok(linha,s);
    quantServidores = converteNumero(token1);
    token2 = strtok(NULL,s);
    quantClientes = converteNumero(token2);
    token3 = strtok(NULL,s);
    quantMonitores = converteNumero(token3);

    /** Inicializa os vetores referentes a servidores, clientes e monitores, alocando eles */
    inicVetoresGrafo(grafo, quantServidores, quantClientes, quantMonitores);

    i = 0;
    int servidor;
    while(i < quantServidores){ /** While para ler e inserir no grafo todos os servidores */
        getline (&linha, &len, file);
        servidor = converteNumero(strtok(linha,s));
        insereServidor(grafo, i, servidor);
        i++;
    }
    i = 0;
    int cliente;
    while(i < quantClientes){ /** While para ler e inserir no grafo todos os clientes */
        getline (&linha, &len, file);
        cliente = converteNumero(strtok(linha,s));
        insereCliente(grafo, i, cliente);
        i++;
    }
    i = 0;
    int monitor;
    while(i < quantMonitores){ /** While para ler e inserir no grafo todos os monitores */
        getline (&linha, &len, file);
        monitor = converteNumero(strtok(linha,s));
        insereMonitor(grafo, i, monitor);
        i++;
    }
    i = 0;
    /** While para ler e inserir no grafo as arestas e seus valores, os vertices são as linhas
     * e colunas da matriz adjacência e as arestas são os itens da matriz em si */
    while(i < retornaNumAresta(grafo)){
        getline (&linha, &len, file);
        verticeOrigem = strtok(linha,s);
        verticeOrigem = converteNumero(token1);

        verticeDestino = strtok(NULL,s);
        verticeDestino = converteNumero(token2);

        token3 = strtok(NULL,s);
        valorAresta = converteNumero(token3);
        /** Insere a aresta na matriz */
        insereArestasLista(grafo,verticeOrigem, verticeDestino, valorAresta);
        i++;
    }
    free(linha);
}
