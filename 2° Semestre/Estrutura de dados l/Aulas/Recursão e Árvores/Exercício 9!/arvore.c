

#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct arvore{

    tAluno* info;
    tArvore* esquerda;
    tArvore* direita;
            
};

tArvore* arv_criaVazia(void){
    return NULL;
};

tArvore* arv_cria(tAluno* aluno, tArvore* esquerda, tArvore* direita){

    tArvore* p=(tArvore*)malloc(sizeof(tArvore));
    p->info= aluno;
    p->direita=direita;
    p->esquerda=esquerda;
    return p;

};


int arv_vazia(tArvore* arvore){
    return arvore==NULL;
};

tArvore* arv_libera(tArvore* arvore){
    if(!arv_vazia(arvore)){
        arv_libera(arvore->esquerda);
        arv_libera(arvore->direita);
        free(arvore);
    }
    return NULL;


};


int arv_pertence(tArvore* arvore, char* nome){
    
   if(arv_vazia(arvore)){
        return 0;
    }
    return (!strcmp(nome,RetornaNomeAluno(arvore->info))||(arv_pertence (arvore->esquerda,nome))||(arv_pertence (arvore->direita,nome)));


};

void arv_imprime (tArvore* arvore){

    if(!arv_vazia(arvore)){
        
        ImprimeAluno(arvore->info);
        arv_imprime(arvore->esquerda);
        arv_imprime(arvore->direita);  
    }
};


static int  aux_altura(int a, int b){
       if (a > b) {
        return a;
    }
    else{
        return b;
    }
}

int altura (tArvore* arvore){
    if (arv_vazia(arvore))
        return -1;
    else
         return 1 + aux_altura(altura (arvore->esquerda),altura (arvore->direita));
}

 
 
//arvore paai
tArvore*  arvore_pai(tArvore* arvore, char* nome){

    if(arv_vazia(arvore))
        return NULL;
    if(((!arv_vazia(arvore->esquerda))&& (!strcmp(RetornaNomeAluno(arvore->esquerda->info),nome))) || 
            (!arv_vazia(arvore->direita))&& (!strcmp(RetornaNomeAluno(arvore->direita->info),nome)))
            return arvore;
    
    tArvore* aux = arvore_pai(arvore->esquerda,nome);
    
    if (aux=NULL)
        aux= arvore_pai(arvore->direita,nome);
    return aux;
    



};

//ocorrencia


int ocorrencias (tArvore* arvore, char* nome){

    if(arv_vazia(arvore)){
        return 0;
    }
    if(!strcmp(RetornaNomeAluno(arvore->info),nome)){
        return 1 + (ocorrencias (arvore->esquerda,nome) + ocorrencias (arvore->direita,nome));
    }
    else{
         return ocorrencias (arvore->esquerda,nome) + ocorrencias (arvore->direita,nome);

    }
}




 
 tAluno* info (tArvore* arvore){

    if(!arv_vazia(arvore))
        return arvore->info;

};
 

//folhas

int folhas (tArvore* arvore){
    
    if((arv_vazia(arvore->esquerda))&&(arv_vazia(arvore->direita))){
        return 1;
    }
    
    else if(!arv_vazia(arvore->esquerda)&& arv_vazia(arvore->direita))
        return folhas(arvore->esquerda);
    
     else if(arv_vazia(arvore->esquerda)&& !arv_vazia(arvore->direita))
        return folhas(arvore->direita);
    
    return folhas(arvore->esquerda) + folhas ( arvore->direita);
}