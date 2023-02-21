#include <stdio.h>
#include <stdlib.h>

int ContaVogalConsoante(char palavra[]);
void ImprimePalavraVogal(char palavra[]);
void ImprimePalavraTotal(char palavra[]);
void ImprimePalavraConsoante(char palavra[]);

int main(int argc, char** argv) {
    char palavra[201];
    int i=0, num;
    
    while(scanf("%s", palavra)==1){
        num= ContaVogalConsoante(palavra);
        if(num==0){
            ImprimePalavraTotal(palavra);
        }
        if(num==1){
            ImprimePalavraConsoante(palavra);
        }
        if(num==2){
            ImprimePalavraVogal(palavra);
        }
            
    }
    
    return (EXIT_SUCCESS);
}

int ContaVogalConsoante(char palavra[]){
    int vogal=0, consoante=0, i=0;
    
    while(palavra[i]!='\0'){
        if(palavra[i]>='a' && palavra[i]<='z' || palavra[i]>='A' && palavra[i]<='Z'){
            if(palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u'){
                vogal++;
            }
            else
                consoante++;
        }
        i++;
    }
    if(vogal==consoante)
        return 0;
    if(vogal<consoante)
        return 1;
    if(vogal>consoante)
        return 2;
}

void ImprimePalavraVogal(char palavra[]){
    int i=0;
    
    while(palavra[i]!='\0'){
        if(palavra[i]>='a' && palavra[i]<='z' || palavra[i]>='A' && palavra[i]<='Z'){
            if(palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u' ||
                palavra[i]=='A' || palavra[i]=='E' || palavra[i]=='I' || palavra[i]=='O' || palavra[i]=='U'){
                printf("%c", palavra[i]);
            }
        }
        i++;
    }
    printf("\n");
}

void ImprimePalavraTotal(char palavra[]){
    int i=0;
    
    while(palavra[i]!='\0'){
        printf("%c", palavra[i]);
        i++;
    }
    printf("\n");
}

void ImprimePalavraConsoante(char palavra[]){
    int i=0;
    
    while(palavra[i]!='\0'){
        if(palavra[i]>='a' && palavra[i]<='z' || palavra[i]>='A' && palavra[i]<='Z'){
            if(!(palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u'||
                    palavra[i]=='A' || palavra[i]=='E' || palavra[i]=='I' || palavra[i]=='O' || palavra[i]=='U')){
                printf("%c", palavra[i]);
            }
        }
        i++;
    }
    printf("\n");
}