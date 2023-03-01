#include "grafo.h"

struct grafo{
    int numVertice;
    int numAresta;
    Lista* lista;
    int* vetorServidores;
    int tamVetServidor;
    int* vetorClientes;
    int tamVetCliente;
    int* vetorMonitores;
    int tamVerMonitor;
};

struct celula{
    int verticeDestino;
    double valorEntreVertices;
    Lista * listaAd;
    Celula * prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Grafo * criaGrafoVazio(void){
    Grafo * grafo = (Grafo *) malloc(sizeof(Grafo));
    grafo->numVertice = 0;
    grafo->numAresta = 0;

    return grafo;
}

//inicializando a Grafo já sabendo o numero de vertices
void inicGrafo(Grafo *grafo,int numVertice, int numAresta){
    grafo->numVertice = numVertice;
    grafo->numAresta = numAresta;
    grafo->lista = inicLista();
}

Lista* inicLista(void){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void criaLista (Grafo * grafo, int numVertice){
    //inicia lista com vértices de 1 até n
    for(int i = 0; i<numVertice; i++){
        Celula * nova = (Celula*) malloc (sizeof (Celula));
        nova->verticeDestino = i;
        nova->prox = NULL; //inserindo no fim da lista

        //inicializando lista que receberá vertices adjacentes
        nova->listaAd = inicLista();

        if(grafo->lista->ult == NULL){ //caso de lista vazia
            grafo->lista->prim = grafo->lista->ult = nova;
        }
        else{ //caso regular de inserção na lista
            grafo->lista->ult->prox = nova;
            grafo->lista->ult = nova;
        }
    }
}

void insereArestasLista(Grafo * grafo, int vertice1, int vertice2, int aresta){
    //procurando vertice1 na lista principal
    Celula * p = grafo->lista->prim; //ponteiro auxiliar que percorre a lista
    Celula * ant = NULL; //ponteiro anterior ao ponteiro auxiliar

    while(p != NULL && p->verticeDestino != vertice1){
        ant = p;
        p = p->prox;
    }
    if(p==NULL){ //vertice nao está na lista
        printf("Vertice nao encontrado\n");
        return;
    }
    //agora o p está no vertice1 correto, basta inserir a aresta e o vértice2
    //cadastrando a celula que será inserida
    Celula * nova = (Celula*) malloc (sizeof (Celula));
    nova->verticeDestino = vertice2;
    nova->valorEntreVertices = aresta;
    nova->prox = NULL;

    //inserindo celula na lista de vertices adjacentes de um vertice
    if(p->listaAd->ult == NULL){ //caso de lista vazia
        p->listaAd->prim = p->listaAd->ult = nova;
    }
    else{ //caso regular de inserção na lista
        p->listaAd->ult->prox = nova;
        p->listaAd->ult = nova;
    }
}

void destroiLista(Lista * lista){
    Celula * p = lista->prim; //ponteiro auxiliar que percorre a lista
    Celula * t = NULL; //ponteiro anterior ao ponteiro auxiliar

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    free(lista);
}

void destroiListaComAdjacencias (Grafo * grafo){
    Celula * p = grafo->lista->prim; //ponteiro auxiliar que percorre a lista
    Celula * t = NULL; //ponteiro anterior ao ponteiro auxiliar

    while(p != NULL){
        t = p->prox;
        if(p->listaAd != NULL){
            destroiLista(p->listaAd);
        }
        free(p);
        p = t;

    }
    free(grafo->lista);
}

void imprimeLista (Grafo * grafo){
    Celula * p;
    Celula * q;
    for(q = grafo->lista->prim; q != NULL; q = q->prox){
        printf("origem:%d\n", q->verticeDestino);
        for(p = q->listaAd->prim; p != NULL; p = p->prox){
            printf(" destino:%d || valor:%.2f \n", p->verticeDestino, p->valorEntreVertices);
        }
        printf("\n");
    }
}

void imprimeGrafoLista(Grafo* grafo, FILE* arquivoSaida){
    Celula * p = grafo->lista->prim;
    Celula * pant = NULL;
    Celula * q;
    Celula * qant;

    fprintf(arquivoSaida, "digrafo G\n{\n");

    while(p != NULL){
        q = p->listaAd->prim;
        qant = NULL;
        while (q != NULL){
            fprintf(arquivoSaida, "%d", p->verticeDestino);
            fprintf(arquivoSaida, " -> ");
            fprintf(arquivoSaida, "%d ", q->verticeDestino);
            fprintf(arquivoSaida, "[label = %.2f]", q->valorEntreVertices);
            fprintf(arquivoSaida, ";\n");

            qant = q;
            q = q->prox;
        }
        pant = p;
        p = p->prox;
    }
    fprintf(arquivoSaida,"}");
}

void destroiVetoresAuxiliares(Grafo* grafo){
    free(grafo->vetorClientes);
    free(grafo->vetorServidores);
    free(grafo->vetorMonitores);
}

void inicVetoresGrafo(Grafo* grafo, int quantServidores, int quantClientes, int quantMonitores){
    /**O primeiro indice de cada um desses vetores irá armazenar os respectivos tamanhos deles*/
    grafo->vetorServidores = (int*) malloc((quantServidores)* sizeof(int));
    grafo->tamVetServidor=quantServidores;
    grafo->vetorClientes = (int*) malloc((quantClientes)* sizeof(int));
    grafo->tamVetCliente=quantClientes;
    grafo->vetorMonitores = (int*) malloc((quantMonitores)* sizeof(int));
    grafo->tamVerMonitor=quantMonitores;
}

void imprimeVetores(Grafo * grafo){
    printf("\nVetor de servidores: ");
    for(int i=0; i<grafo->tamVetServidor; i++){
        printf("%d ", grafo->vetorServidores[i]);
    }
    printf("\nVetor de monitores: ");
    for(int i=0; i<grafo->tamVerMonitor; i++){
        printf("%d ", grafo->vetorMonitores[i]);
    }
    printf("\nVetor de clientes: ");
    for(int i=0; i<grafo->tamVetCliente; i++){
        printf("%d ", grafo->vetorClientes[i]);
    }
    printf("\n");
}

Celula* retornaVerticeOrigem(Grafo* grafo, int destino, double valor){
    Celula * p = grafo->lista->prim; //ponteiro auxiliar que percorre a lista
    Celula * ant = NULL; //ponteiro anterior ao ponteiro auxiliar

    while(p != NULL && p->verticeDestino != destino && p->valorEntreVertices != valor){
        ant = p;
        p = p->prox;
    }
    if(p==NULL){ //vertice nao está na lista
        printf("Vertice nao encontrado\n");
        return 0;
    }
    return p;
}

double retornaValorEntreVertices(Grafo* grafo, Celula* verticeOrigem){
    Celula * p = grafo->lista->prim; //ponteiro auxiliar que percorre a lista
    Celula * ant = NULL; //ponteiro anterior ao ponteiro auxiliar

    while(p != NULL && p != verticeOrigem){
        ant = p;
        p = p->prox;
    }
    if(p==NULL){ //vertice nao está na lista
        printf("Vertice nao encontrado\n");
        return 0;
    }
    return p->valorEntreVertices;
}

int retornaVerticeDestiono(Grafo* grafo, Celula* verticeOrigem){
    Celula * p = grafo->lista->prim; //ponteiro auxiliar que percorre a lista
    Celula * ant = NULL; //ponteiro anterior ao ponteiro auxiliar

    while(p != NULL && p != verticeOrigem){
        ant = p;
        p = p->prox;
    }
    if(p==NULL){ //vertice nao está na lista
        printf("Vertice nao encontrado\n");
        return 0;
    }
    return p->verticeDestino;
}


int retornaNumVertice(Grafo * grafo){
    return grafo->numVertice;
}

int retornaNumAresta(Grafo * grafo){
    return grafo->numAresta;
}

void insereServidor(Grafo* grafo, int posicao, int servidor){
    grafo->vetorServidores[posicao] = servidor;
}

void insereCliente(Grafo* grafo, int posicao, int cliente){
    grafo->vetorClientes[posicao] = cliente;
}

void insereMonitor(Grafo* grafo, int posicao, int monitor){
    grafo->vetorMonitores[posicao] = monitor;
}

int retornaNumServidores(Grafo * grafo){
    return grafo->tamVetServidor;
}

int retornaNumClientes(Grafo* grafo){
    return grafo->tamVetCliente;
}

int retornaNumMonitores(Grafo* grafo){
    return grafo->tamVerMonitor;
}

int* retornaVetorServidores(Grafo* grafo){
    return grafo->vetorServidores;
}
int* retornaVetorClientes(Grafo* grafo){
    return grafo->vetorClientes;
}

int* retornaVetorMonitores(Grafo* grafo){
    return grafo->vetorMonitores;
}

double* dijkstra(Grafo* grafo, int origem, int* destino1, int* destino2, int tamDestino1, int tamDestino2){
    double* destinos = malloc(sizeof(double) * (tamDestino1 + tamDestino2));
    double distancias[grafo->numVertice];

    PQ* heap = pqInicializa(grafo->numAresta);
    int bandeira = 0;

    for (int i = 0; i < grafo->numVertice; i++)
        distancias[i] = DBL_MAX;

    pqInsere(heap, origem, 0);
    distancias[origem] = 0;

    while (!pqVerificaVazia(heap)) {
        // valor do indice com menor peso
        int u = pqMinimo(heap);
        pqDeletaMinimo(heap);

        //Vertice* vertice = grafo->vertices[u];
        Celula* vertice = grafo->lista->prim;
        Celula * ant = NULL;
        int cont = 0;
        while(cont < u){
            ant = vertice;
            vertice = vertice->prox;
            cont++;
        }

        for (Celula* p = vertice->listaAd->prim; p != NULL; p = p->prox) {
            // recebe vertice destino e peso da aresta adjacente do no inicial
            int w = retornaVerticeDestiono(grafo, vertice);
            double valor = retornaValorEntreVertices(grafo, vertice);
            double distanciaU = distancias[u];
            double distanciaW = distancias[w];

            // verifica se a distancia ate w eh maior que de u + peso da aresta adjacente
            if (distanciaW > distanciaU + valor) {
                // atualiza a distancia de w
                distancias[w] = distanciaU + valor;
                pqInsere(heap, w, distanciaU + valor);
                pqDecreaseKey(heap, w, distanciaU);
            }
        }
    }

    pqDestroi(heap);

    // os vetores destino1 e destino2 possuem valores de indices
    for (int i = 0; i < tamDestino1; i++) {
        int pos = destino1[i];             // pega o valor de destino1[i] para ser usado como indice de distancias
        destinos[i] = distancias[pos];  // coloca em vetor destinos a distancia da posicao pos
    }

    for (int j = 0; j < tamDestino2; j++) {
        int pos = destino2[j];                       // pega o valor de destino2[i] para ser usado como indice de distancias
        destinos[j + tamDestino1] = distancias[pos];  // coloca em vetor destinos a distancia da posicao pos, apos os valores armazenados anteriores
    }

    return destinos;
}

GuardaRazao* calculaRazoesEntreRTT(Grafo* grafo,double** distanciasServidores,double** distanciasClientes,double** distanciasMonitores){
    GuardaRazao razaoEntreRtt;
    GuardaRazao * vetorDeRazoes = (GuardaRazao*)malloc(grafo->tamVetCliente * grafo->tamVetServidor * sizeof(GuardaRazao));

    int contador = 0;
    double rttAproximado, rttReal, rtt1, rtt2, rtt_min, rttRazao;

    for (int i = 0; i < grafo->tamVetServidor; i++) {
        for (int j = 0; j < grafo->tamVetCliente; j++) {
            rttReal = distanciasClientes[j][i] + distanciasServidores[i][j];  // Cj->Si + Si->Cj

            rtt1 = distanciasServidores[i][grafo->tamVetCliente] + distanciasMonitores[0][i];              // S->M + M->S
            rtt2 = distanciasClientes[j][grafo->tamVetServidor] + distanciasMonitores[0][j + grafo->tamVetServidor];  // M->C + C->M
            rttAproximado = rtt1 + rtt2;

            for (int k = 1; k < grafo->tamVerMonitor; k++) {
                rtt1 = distanciasServidores[i][k + grafo->tamVetCliente] + distanciasMonitores[k][i];              // S->M + M->S
                rtt2 = distanciasMonitores[k][j + grafo->tamVetServidor] + distanciasClientes[j][k + grafo->tamVetServidor];  // M->C + C->M
                rtt_min = rtt1 + rtt2;

                // verifica se rtt* eh menor que o anterior
                if (rttAproximado > rtt_min)
                    rttAproximado = rtt_min;
            }

            rttRazao = rttAproximado / rttReal;
            razaoEntreRtt.cliente = grafo->vetorClientes[j + 1];
            razaoEntreRtt.servidor = grafo->vetorMonitores[i + 1];
            razaoEntreRtt.razao = rttRazao;

            vetorDeRazoes[contador++] = razaoEntreRtt;
        }
    }

    return vetorDeRazoes;
}

int compara(const void* a, const void* b) {
    GuardaRazao a1 = *(GuardaRazao*)a;
    GuardaRazao a2 = *(GuardaRazao*)b;

    if (a1.razao < a2.razao) return -1;
    if (a1.razao > a2.razao) return 1;

    if (a1.servidor < a2.servidor) return -1;
    if (a1.servidor > a2.servidor) return 1;

    if (a1.cliente < a2.cliente) return -1;
    if (a1.cliente > a2.cliente) return 1;

    return 0;
}

void destroiMatriz(double** matriz, int tam) {
    for (int i = 0; i < tam; i++) {
        free(matriz[i]);
    }
    free(matriz);
}