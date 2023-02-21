#include <stdio.h>
#include <stdlib.h>

int EhProduto(char prd){
    if(prd>='A' && prd<='Z'){
        return 1;
    }
    else{
        return 0;
    }
}

int AcabaramOsProdutos(char prd){
    if(prd=='0'){
        return 1;
    }
    else{
        return 0;
    }
}

int QtdDoProdutoMaisComprado(){
    char produto, produtoX;
    int quantidade=0, maiorQuantidade=0;
    
    while(scanf("%c", &produto)==1){
        if(EhProduto(produto)==1){
            if(quantidade==0){
                produtoX= produto;
            }
            if(produto==produtoX){
                quantidade++;
            }
            if(produto != produtoX){
                if(quantidade>maiorQuantidade){
                    maiorQuantidade= quantidade;
                }
                produtoX=produto;
                quantidade=1;
            } 
        }
        else{
            if(AcabaramOsProdutos(produto)==1){
                if(quantidade>maiorQuantidade){
                    maiorQuantidade= quantidade;
                }
                return maiorQuantidade;
            }
        }
    }
}

int main(int argc, char** argv) {
    int numPessoa, quantidade, maiorQuantidade=0, guloso;
    
    scanf("%d", &numPessoa);
    while(numPessoa != -1){
        quantidade= QtdDoProdutoMaisComprado();
        if(quantidade>maiorQuantidade){
            maiorQuantidade=quantidade;
            guloso=numPessoa;
        }
        scanf("%d", &numPessoa);
    }
    printf("CLIENT:%d QTD:%d", guloso, maiorQuantidade);
    return (EXIT_SUCCESS);
}

