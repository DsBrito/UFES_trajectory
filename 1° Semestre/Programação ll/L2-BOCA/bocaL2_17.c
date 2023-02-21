#include <stdio.h>

void CodificarFrase(int num, int letra){
    if(letra>='a' && letra<='z'){
        letra= num+letra;
        while(letra>'z'){
            letra= (letra -'z')+('a'-1);
        }
        printf("%c", letra);        
    }
    else{
        printf("%c", letra);
    }
}

void DecodificarFrase(int num, int letra){
    if(letra>='a' && letra<='z'){
        letra= letra - num;
        while(letra<'a'){
            letra= 'z' - ('a'-letra) +1;
        }
        printf("%c", letra);        
    }
    else{
        printf("%c", letra);
    }
}

int main(){
    int num;
    char letra;
    
    letra= '\0';
    
    scanf("%d", &num);
    
    if(num>2){
        printf("Operacao invalida.");
    }
    if(num<1){
        printf("Operacao invalida.");
    }
    
    switch(num){
        case 1:
            scanf("%d", &num);
            scanf("%*c");
            while(letra != '.'){
                scanf("%c", &letra);
                CodificarFrase(num, letra);
            }
            break;
            
        case 2:
            scanf("%d", &num);
            scanf("%*c");
            while(letra != '.'){
                scanf("%c", &letra);
                DecodificarFrase(num, letra);
            }
            break;
    }

    return 0;
}
    
    