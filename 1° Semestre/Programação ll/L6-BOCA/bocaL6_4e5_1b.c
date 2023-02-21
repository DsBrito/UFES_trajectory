#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idMensagem;
    int idPacote;
    int tamanho;
    char mensagem[10];
    int codigoErro;
    
}tPacote;

tPacote LePacote();
void ImprimePacote(tPacote pacote);
int ConferePacote(tPacote pacote);

int main(int argc, char** argv) {
    int qtd, i;
    
    scanf("%d", &qtd);    
    tPacote pacote[qtd];
    
    for(i=0; i<qtd; i++){
        pacote[i]= LePacote();
    }
    
    for(i=0; i<qtd; i++){
        if(ConferePacote(pacote[i]))
            ImprimePacote(pacote[i]);
        else
            printf("FALHA!\n");
    }
    
    return (EXIT_SUCCESS);
}

tPacote LePacote(){
    tPacote pacote;
    int i;
    scanf("%d", &pacote.idMensagem);
    scanf("%d", &pacote.idPacote);
    scanf("%1d", &pacote.tamanho);
    
    for(i=0; i<9; i++){
        if(i<pacote.tamanho)
            scanf("%c", &pacote.mensagem[i]);
        else{
            scanf("%*c");
        }
    }
    scanf("%d", &pacote.codigoErro);
    
    return pacote;
}

void ImprimePacote(tPacote pacote){
    int i;
    
    printf("PCT: %d,%d,%d,", pacote.idMensagem, pacote.idPacote, pacote.tamanho);
    for(i=0; i<pacote.tamanho; i++){
        printf("%c", pacote.mensagem[i]);
    }
    printf(",%d\n", pacote.codigoErro);
}

int ConferePacote(tPacote pacote){
    int soma, i;
    
    soma= pacote.idMensagem+ pacote.idPacote + pacote.tamanho;
    
    for(i=0; i<pacote.tamanho; i++)
        soma= soma+pacote.mensagem[i];
    
    if(soma==pacote.codigoErro)
        return 1;
    
    return 0;
    
}