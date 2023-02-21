#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    float preco;
    int quantidade_em_estoque;
}tProduto;

tProduto LeProduto(){
    tProduto produto;
    scanf("%d;%f;%d", &produto.codigo, &produto.preco, &produto.quantidade_em_estoque);
    
    return produto;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
    if(p2.preco > p1.preco){
        return 1;
    }
    else{
        return 0;
    }
}

int EhProduto1MenorQ2(tProduto p1,tProduto p2){
        if(p2.preco < p1.preco){
        return 1;
    }
    else{
        return 0;
    }
}

int TemProdutoEmEstoque(tProduto p){
    return p.quantidade_em_estoque;
}

void ImprimeProduto(tProduto p){
    printf("COD %d, PRE %.2f, QTD %d\n", p.codigo, p.preco, p.quantidade_em_estoque);
}

int main(int argc, char** argv) {
    int numProdutos, i;
    tProduto atual, maior, menor, produto;
        
    scanf("%d", &numProdutos);
    
    for(i=0; i<numProdutos; i++){
        atual= LeProduto();
        
        if(i==0){
            maior= atual;
            menor= atual;
        }
        
        if(TemProdutoEmEstoque(atual)){
            if (EhProduto1MaiorQ2(maior, atual)){
                maior= atual;
            }
            if(EhProduto1MenorQ2(menor, atual)){
                menor = atual;
            }
        }
        else{
            printf("FALTA:");
            ImprimeProduto(atual);
            
            if (EhProduto1MaiorQ2(maior, atual)){
                maior= atual;
            }
            if(EhProduto1MenorQ2(menor, atual)){
                menor = atual;
            }
        }
    }
    
    printf("MAIOR:");
    ImprimeProduto(maior);
    
    printf("MENOR:");
    ImprimeProduto(menor);

    return (EXIT_SUCCESS);
}

