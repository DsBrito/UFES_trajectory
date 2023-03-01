#include "grafo.h"

struct grafo
{
    int numVertice;
    int numAresta;
    Vertice **vertices;
    int *vetorServidores;
    int tamVetServidor;
    int *vetorClientes;
    int tamVetCliente;
    int *vetorMonitores;
    int tamVerMonitor;
};

/** Cria um grafo vazio para ser passado nas funções como parametro na main */
Grafo *criaGrafoVazio(void)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->numVertice = 0;
    grafo->numAresta = 0;

    return grafo;
}

/** Inicializa grafo já com numero de vertices, arestas e inicia o vetor de ponteiros pra vertice */
void inicGrafo(Grafo *grafo, int numVertice, int numAresta)
{
    grafo->numVertice = numVertice;
    grafo->numAresta = numAresta;
    grafo->vertices = inicVetorVertice(numVertice);
}

void formaArestas(FILE *file, Grafo *grafo)
{                          // grava as arestas e seus vértices na matriz de adjacencias e na lista de adjacencias
    const char s[2] = " "; /** Chave utilizada para separar os tokens, no caso o [espaço] */
    char *token1;          /** Tokens que irão auxiliar na leitura de cada item das linhas */
    char *token2;
    char *token3;
    int quantServidores, quantClientes, quantMonitores;
    int verticeOrigem, verticeDestino;
    double valorAresta;
    int i;            /** Contador para os whiles */
    size_t len = 100; /** Valor arbitrário para utilizar a função getLine*/
    char *linha = malloc(len);

    /** Pega a segunda linha e lê a quantidade de servidores, clientes e monitores colocando nas
     * suas devidas variáveis */
    getline(&linha, &len, file);
    token1 = strtok(linha, s);
    quantServidores = converteNumero(token1);
    token2 = strtok(NULL, s);
    quantClientes = converteNumero(token2);
    token3 = strtok(NULL, s);
    quantMonitores = converteNumero(token3);

    /** Inicializa os vetores referentes a servidores, clientes e monitores, alocando eles */
    inicVetoresGrafo(grafo, quantServidores, quantClientes, quantMonitores);

    i = 0;
    int servidor;
    while (i < quantServidores)
    { /** While para ler e inserir no grafo todos os servidores */
        getline(&linha, &len, file);
        servidor = converteNumero(strtok(linha, s));
        insereServidor(grafo, i, servidor);
        i++;
    }
    i = 0;
    int cliente;
    while (i < quantClientes)
    { /** While para ler e inserir no grafo todos os clientes */
        getline(&linha, &len, file);
        cliente = converteNumero(strtok(linha, s));
        insereCliente(grafo, i, cliente);
        i++;
    }
    i = 0;
    int monitor;
    while (i < quantMonitores)
    { /** While para ler e inserir no grafo todos os monitores */
        getline(&linha, &len, file);
        monitor = converteNumero(strtok(linha, s));
        insereMonitor(grafo, i, monitor);
        i++;
    }
    i = 0;
    /** While para ler e inserir no grafo as arestas e seus valores, os vertices são as linhas
     * e colunas da matriz adjacência e as arestas são os itens da matriz em si */
    while (i < retornaNumAresta(grafo))
    {
        getline(&linha, &len, file);
        verticeOrigem = strtok(linha, s);
        verticeOrigem = converteNumero(token1);

        verticeDestino = strtok(NULL, s);
        verticeDestino = converteNumero(token2);

        token3 = strtok(NULL, s);
        valorAresta = converteNumero(token3);
        /** Insere a aresta no grafo */
        adicionaVertice(grafo->vertices[verticeOrigem], verticeDestino, valorAresta);
        i++;
    }
    free(linha);
}

/** Destroi os vertices auxiliares de servidor, monitor e cliente do grafo e libera a memoria do grafo */
void destroiGrafo(Grafo *grafo)
{
    free(grafo->vetorClientes);
    free(grafo->vetorServidores);
    free(grafo->vetorMonitores);
    destroiVetorVertice(grafo->vertices, grafo->numVertice);
    free(grafo);
}

void inicVetoresGrafo(Grafo *grafo, int quantServidores, int quantClientes, int quantMonitores)
{
    /**O primeiro indice de cada um desses vetores irá armazenar os respectivos tamanhos deles*/
    grafo->vetorServidores = (int *)malloc((quantServidores) * sizeof(int));
    grafo->tamVetServidor = quantServidores;
    grafo->vetorClientes = (int *)malloc((quantClientes) * sizeof(int));
    grafo->tamVetCliente = quantClientes;
    grafo->vetorMonitores = (int *)malloc((quantMonitores) * sizeof(int));
    grafo->tamVerMonitor = quantMonitores;
}

double **calculaDistancias(Grafo *grafo, int tamVetor, int *origem, int *destino, int tamDestino)
{
    double **distancia = (double **)malloc(tamVetor * sizeof(double *));
    for (int i = 0; i < tamVetor; i++)
    {
        distancia[i] = dijkstra(grafo, origem[i], destino, tamDestino);
    }
    return distancia;
}

int retornaNumAresta(Grafo *grafo)
{
    return grafo->numAresta;
}

void insereServidor(Grafo *grafo, int posicao, int servidor)
{
    grafo->vetorServidores[posicao] = servidor;
}

void insereCliente(Grafo *grafo, int posicao, int cliente)
{
    grafo->vetorClientes[posicao] = cliente;
}

void insereMonitor(Grafo *grafo, int posicao, int monitor)
{
    grafo->vetorMonitores[posicao] = monitor;
}

int retornaNumServidores(Grafo *grafo)
{
    return grafo->tamVetServidor;
}

int retornaNumClientes(Grafo *grafo)
{
    return grafo->tamVetCliente;
}

int retornaNumMonitores(Grafo *grafo)
{
    return grafo->tamVerMonitor;
}

int *retornaVetorServidores(Grafo *grafo)
{
    return grafo->vetorServidores;
}
int *retornaVetorClientes(Grafo *grafo)
{
    return grafo->vetorClientes;
}

int *retornaVetorMonitores(Grafo *grafo)
{
    return grafo->vetorMonitores;
}

/**----- Source: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/ -----*/
double *dijkstra(Grafo *grafo, int origem, int *destino, int tamDestino)
{
    double distancias[grafo->numVertice];

    PQ *filaPrioridade = pqInicializa(grafo->numAresta);

    /** Inicializando as distancias com o valor máximo de um double (simulando infinito para o algoritmo) */
    for (int i = 0; i < grafo->numVertice; i++)
    {
        distancias[i] = DBL_MAX;
    }

    /** Insere a origem na fila de prioridade e inicializa seu valor como zero */
    pqInsere(filaPrioridade, origem, 0);
    distancias[origem] = 0;

    while (!pqVerificaVazia(filaPrioridade))
    {
        /** Extraindo vertice com distancia minima da fila e chamando de u*/
        int u = pqMinimo(filaPrioridade);
        /** Agora que estamos com o vertice em uma varíavel, podemos retirá-lo da lista */
        pqDeletaMinimo(filaPrioridade);

        /** Agora temos que fazer um loop para todos os vertices adjacentes à u, ou seja, temos que localizar o vertice
         * "u" e fazer um 'for' para toda sua lista de vertices adjacentes (andar pelas arestas)*/
        Vertice *vertice = grafo->vertices[u];
        Aresta *aresta = retornaAresta(vertice);
        for (aresta; aresta != NULL; aresta = retornaArestaProx(aresta))
        {
            /** Pega o vertice destino e o peso da aresta adjacente atual */
            int v = retornaDestino(aresta);
            double peso = retornaPeso(aresta);

            /** Verifica se tem um caminho mais curto */
            if (distancias[v] > (distancias[u] + peso))
            {
                /** Atualiza a distancia de v */
                distancias[v] = distancias[u] + peso;
                pqInsere(filaPrioridade, v, distancias[u] + peso);
                pqDecreaseKey(filaPrioridade, u, distancias[u]);
            }
        }
    }
    pqDestroi(filaPrioridade);

    /** O vetor de destino tem como valor os indices dos monitores, cliente ou servidores, dependendo do caso que entrou
     * nessa função */
    double *destinos = malloc(tamDestino * sizeof(double));
    for (int i = 0; i < tamDestino; i++)
    {
        /** Então vamos pegar esse valor de servidor, monitor ou cliente e usar como indice das distancias calculadas acima
         * para que cada distancia fique na posicao certa*/
        int pos = destino[i];
        destinos[i] = distancias[pos];
    }

    return destinos;
}

GuardaRazao *calculaRazoesEntreRTT(Grafo *grafo, double **distanciaServidoreMonitor, double **distanciaMonitorServidor,
                                   double **distanciaClienteMonitor, double **distanciaMonitorCliente,
                                   double **distanciaServidorCliente, double **distanciaClienteServidor)
{
    int contador = 0;
    double rttAproximado, rttReal, rttServMon, rttCliMon, rttMinimo, rttRazao;
    GuardaRazao razaoEntreRtt;
    GuardaRazao *vetorDeRazoes = (GuardaRazao *)malloc(grafo->tamVetCliente * grafo->tamVetServidor * sizeof(GuardaRazao));

    for (int i = 0; i < grafo->tamVetServidor; i++)
    {
        for (int j = 0; j < grafo->tamVetCliente; j++)
        {
            /** Calculo do rtt entre servidores e clientes sem obrigatoriamente passar por monitores */
            rttReal = distanciaServidorCliente[i][j] + distanciaClienteServidor[j][i];

            /** Aqui calculamos o rtt aproximado entre servidor e cliente passando por monitores */
            rttServMon = distanciaServidoreMonitor[i][0] + distanciaMonitorServidor[0][j];
            rttCliMon = distanciaClienteMonitor[j][0] + distanciaMonitorCliente[0][j];
            rttAproximado = rttServMon + rttCliMon;

            /** Fazemos isso para todos os monitores e comparamos com o primeiro, se for menor, trocar o valor de
             * rtt aproximado*/
            for (int k = 1; k < grafo->tamVerMonitor; k++)
            {

                rttServMon = distanciaServidoreMonitor[i][k] + distanciaMonitorServidor[k][i];
                rttCliMon = distanciaMonitorCliente[k][j] + distanciaClienteMonitor[j][k];
                rttMinimo = rttServMon + rttCliMon;

                if (rttAproximado > rttMinimo)
                {
                    rttAproximado = rttMinimo;
                }
            }
            /** Depois de ter um rttAproximado definido calculamos a razao entre ele e o rttReal e guardamos nao so
             * o valor da razao, como também o servidor e cliente que tem essa razao entre eles */
            rttRazao = rttAproximado / rttReal;
            razaoEntreRtt.origem = grafo->vetorServidores[i];
            razaoEntreRtt.destino = grafo->vetorClientes[j];
            razaoEntreRtt.razao = rttRazao;

            vetorDeRazoes[contador++] = razaoEntreRtt;
        }
    }
    return vetorDeRazoes;
}

int compara(const void *a, const void *b)
{
    GuardaRazao a1 = *(GuardaRazao *)a;
    GuardaRazao a2 = *(GuardaRazao *)b;

    if (a1.razao < a2.razao)
        return -1;
    if (a1.razao > a2.razao)
        return 1;

    if (a1.origem < a2.origem)
        return -1;
    if (a1.origem > a2.origem)
        return 1;

    if (a1.destino < a2.destino)
        return -1;
    if (a1.destino > a2.destino)
        return 1;

    return 0;
}

void destroiMatriz(double **matriz, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}