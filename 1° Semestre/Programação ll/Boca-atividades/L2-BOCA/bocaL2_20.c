#include <stdio.h>

float CalcularResultado(float a, float b, float c, float d, int e){
    float resultado;
    
    resultado = a*(e*e*e) + b*(e*e) + c*(e) + d;
    
    return resultado;
    
}

int main(){
    float g, h, i; //variaveis para verificar se tem a equacao tem vale ou pico
    float a, b, c, d; //variaveis dos coeficientes
    int e, f; //variaveis do intervalo
    float resultado; //variavel para o resultado da equacao com as variaveis anteriores
    int parametro1=0, parametro2=0;
    
    scanf("%f%f%f%f%d%d", &a, &b, &c, &d, &e, &f);
    
    while(e<=f){ //vai executar esse while até usar todos os valores do intervalo "e, f"

        g=CalcularResultado(a,b,c,d,e);
        e++;
        
        h=CalcularResultado(a,b,c,d,e);
        e++;
        
        i=CalcularResultado(a,b,c,d,e);
        e++;
        
        if((h>i && h>g)||(h<i && h<g)){
            if(h>g){
                printf("Pico em x=%d\n", e-2);
                parametro1++;
            }
            if(h<g){
                printf("Vale em x=%d\n", e-2);
                parametro2++;
            }
        }
        else{
            while(e<=f){
                g=h;
                h=i;
                i=CalcularResultado(a,b,c,d,e);
                e++;
                
                if((h>i && h>g)||(h<i && h<g)){
                    if(h>g){
                        printf("Pico em x=%d\n", e-2);
                        parametro1++;
                    }
                    if(h<g){
                        printf("Vale em x=%d\n", e-2);
                        parametro2++;
                    }
                }
            }
        }
        
    }
    if(parametro1==0){
        printf("Nao ha pico\n");
    }
    if(parametro2==0){
        printf("Nao ha vale");
    }
    return 0;
}