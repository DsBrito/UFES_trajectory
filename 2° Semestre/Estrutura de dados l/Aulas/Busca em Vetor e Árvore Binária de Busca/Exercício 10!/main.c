
#include <stdio.h>
#include <stdlib.h>
#include"abb.h"


int main() {
    
    tAluno* patricia = IniciaAluno(312,"patricia",10);
    tAluno* jayme = IniciaAluno(241,"jayme",5);
    tAluno* stive = IniciaAluno(453,"stive",6);
    tAluno* eduarda = IniciaAluno(892,"eduarda",9);

    
    Arv* f= abb_cria();
   
    f=abb_insere(f,patricia);
    f=abb_insere(f,jayme);
    f=abb_insere(f,stive);
    f=abb_insere(f,eduarda);

    printf("\nImprimindo fila f:\n");
    abb_imprime(f);
    
    
 
    
    DestroiAluno(patricia);
    DestroiAluno(jayme);
    DestroiAluno(stive);
    DestroiAluno(eduarda);
    
    abb_libera(f);
  
    
    
    
}

