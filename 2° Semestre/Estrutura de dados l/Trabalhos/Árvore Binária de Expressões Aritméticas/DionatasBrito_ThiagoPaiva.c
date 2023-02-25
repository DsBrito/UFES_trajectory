#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arvore.h"
#include "ListaComSentinela.h"
#include "ED.h"




void main(int argc, char** argv)
{
    char comando;
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%d] :%s\n",i, argv[i]);
    }
    FILE * f;
    FILE * SaidaArquivo;
    FILE * graphviz;
    char * CaminhoEntrada;
    CaminhoEntrada=strdup(argv[1]);
    SaidaArquivo = fopen("saida.txt","w+");
    graphviz = fopen("graphviz.txt", "w+");
    f = fopen(CaminhoEntrada, "r");
    
    while ((comando = fgetc(f)) != EOF){
        if(comando == '('){
        Arv* a = arv_cria(0.0, arv_criavazia(), arv_criavazia(), PLACEHOLDER);
        ED* pilha = inicED();
        while((comando = fgetc(f)) != '\n' && (comando != EOF))
        {
            if(comando == '(')
            {
                if(retornaTipo(a) == PLACEHOLDER)
                {
                    a = arv_insere(a, 0, PLACEHOLDER);
                    inserePilha(pilha, a);
                    a = retornaEsq(a);
                }
                else
                {
                    a = arv_insere(a, 0, PLACEHOLDER);
                    inserePilha(pilha, a);
                    a = retornaDir(a);
                }
            }
                if(comando == ')')
                {
                    if(retornaTamanho(pilha) > 0)
                    {
                        a = retiraPilha(pilha); 
                        printf("\n");
                    }
                }
            if(comando == '+' || comando == '-' || comando == '*' || comando == '/'){
                insereSimbolo(a, (float)comando, OPERADOR);
            }
            if(comando >= '0' && comando <= '9'){      
            int i = 1;
            ED* fila = inicED();
            int n = comando - '0';
            insereFila(fila, n);
                while((comando = fgetc(f)) != ')'){            
                    int n = comando - '0'; 
                    insereFila(fila, n);      
                    i++;
                }
            float numero = ConverteFilaPraInt(fila, i);
            insereSimbolo(a, numero, OPERANDO);
            if(retornaTamanho(pilha) > 0){
                a = retiraPilha(pilha);
                }
            destroiED(fila);
            }
        }
        fprintf(graphviz,"digraph G{\n graph [ordering=""out""];\n");
        imprimeArvore(graphviz, a);
        fprintf(graphviz,"\n}\n");
        fprintf(SaidaArquivo, "%f\n",calculaArvore(a));
        arv_libera(a);
        destroiED(pilha);
    }
}
fclose(f);
fclose(SaidaArquivo);
fclose(graphviz);
}