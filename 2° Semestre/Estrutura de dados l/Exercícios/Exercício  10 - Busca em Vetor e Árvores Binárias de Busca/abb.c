

#include "abb.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


struct arv {

    tAluno* info;
    Arv* esq;
    Arv* dir;

};

Arv* abb_cria(void){
    return NULL;
}
void abb_imprime (Arv* a){

    if(a!=NULL){
        abb_imprime(a->esq);
        ImprimeAluno(a->info);
        abb_imprime(a->dir); 
    }
}


Arv* abb_busca(Arv* r, int chave){
    if (r ==NULL)
        return NULL;
    if (RetornaMatricula(r->info) > chave)
        return abb_busca(r->esq,chave);
    if (RetornaMatricula(r->info) < chave)
        return abb_busca(r->dir,chave);
        
    else
        return r;
}

Arv* abb_insere (Arv* a,tAluno* al){
    

    if(a==NULL){
        a = (Arv*)malloc(sizeof(Arv));
        a->info=al;
        a->dir=NULL;
        a->esq=NULL;
    }
    
   
    else if((RetornaMatricula(al) < RetornaMatricula(a->info)))
        a->esq=abb_insere(a->esq, al);
    else
        a->dir=abb_insere(a->dir, al);
   
    return a; 
}




Arv* abb_retira(Arv* r, int v){
    
    if (r==NULL)
        return NULL;
    
    else if (RetornaMatricula(r->info)>v)
        r->esq= abb_retira(r->esq, v);
    
    else if (RetornaMatricula(r->info)<v)
        r->dir=abb_retira(r->dir, v);
    
    //achou ou vai pro else
    
    else{
        //no nó folha
        if(r->esq==NULL && r->dir==NULL){
            free (r);
            return NULL;
        }
        if(r->esq==NULL){
            // Filho da Direita
            Arv* t = r;  
            r=r->dir;
            free(t);
        }
        else if(r->dir==NULL){
            //Filho da Esquerda
            Arv* t=r;
            r=r->esq;
            free(t);
        }
        else{
            //Nos dois Filhos
            Arv*  f = r->esq;  
            while (f->dir!=NULL)
                f=f->dir;
            
            tAluno* t=f->info;
            f->info=t;
            r->esq=abb_retira(r->esq, v); //chamando novamente pra ver se ta na esquerda ou direita
        }
      
    return r;
    }
}

Arv* abb_libera(Arv* r){
    if(r!=NULL){
        abb_libera(r->esq);
        abb_libera(r->dir);
        free(r);
    }
    return NULL;
}



