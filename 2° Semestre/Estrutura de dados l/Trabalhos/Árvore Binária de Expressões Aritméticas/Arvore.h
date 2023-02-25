#ifndef Arvore_h
#define Arvore_h

#define PLACEHOLDER -1
#define OPERADOR 0
#define OPERANDO 1

typedef struct arv Arv;

Arv* arv_criavazia(void);
Arv* arv_cria(float simbolo, Arv* e, Arv* d, int tipo);
int arv_vazia(Arv* a);
Arv* retornaEsq(Arv* a);
Arv* retornaDir(Arv* a);
Arv* arv_libera(Arv* a);
Arv* arv_insere(Arv* a, float simbolo, int tipo);
void insereSimbolo(Arv* a, float simbolo, int tipo);
int retornaTipo(Arv* a);
float calculaArvore(Arv* a);
float retornaSimbolo(Arv* a);
void imprimeArvore(FILE* graphviz, Arv* a);



#endif
 