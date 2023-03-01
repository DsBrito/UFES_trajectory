#include "leitura.h"

FILE *abreArquivo(FILE *file, char *nomeDoArquivo)
{
    file = fopen(nomeDoArquivo, "r"); /** Leitura do arquivo de entrada, retorna ponteiro para file */
    if (file == NULL)
    { /** Verifica se o arquivo é null */
        printf("Arquivo nao pode ser aberto\n");
        exit(0);
    }
    return file;
}

void leDimensao(FILE *file, Grafo *grafo)
{                          // le quantidade de vetorVertices e arestas
    const char s[2] = " "; /** Chave utilizada para separar os tokens, no caso o [espaço] */
    char *token1;          /** Tokens que irão auxiliar na leitura de cada item das linhas */
    char *token2;
    int numVertice, numAresta;
    size_t len = 100; /** Valor arbitrário para utilizar a função getLine*/
    char *linha = malloc(len);

    getline(&linha, &len, file); /** Lê a primeira linha do arquivo */

    token1 = strtok(linha, s);           /** Pega o primeiro item e coloca no token1 */
    numVertice = converteNumero(token1); /** Converte o item pra double e coloca no numVertice*/

    token2 = strtok(NULL, s);           /** Pega o segundo item e coloca no token2 */
    numAresta = converteNumero(token2); /** Converte o item pra double e coloca no numAresta*/

    free(linha);                             /** Libera a linha que foi alocada acima */
    inicGrafo(grafo, numVertice, numAresta); /** Inicializa o grafo e o vetor de ponteiro pra vértice */
}

double converteNumero(char *token)
{
    double numero = atof(token); /** Converte o token para double*/
    return numero;
}
