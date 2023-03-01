#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "rb_tree.h"

#define RED true  //1
#define BLACK false //0

struct no{
    void* info;  //tipo de dado
    tRBT* left;
    tRBT* right;
    bool color; //bool cor;
};

tRBT* createNode(void* info, bool color)
{
    tRBT* new = (tRBT*)malloc(sizeof(tRBT));
    new->info = info;
    new->color = color;
    new->right = NULL;
    new->left = NULL;
    return new;
}

bool isRed(tRBT* node){
    if(node == NULL) return BLACK;
    return node->color; //RED == true
}

void flipColor(tRBT* arvRB){
    arvRB->color = RED;
    arvRB->left->color = BLACK;
    arvRB->right->color = BLACK;
}


/*Inserção numa árvore rubro negra : Se a "raiz" for NULL, necessário inserir um nó
 *                                   Se o elemento for menor que a raiz, é necessário adicionar na sub-arvore da esquerda
 *                                   Se o elemento for maior que a raiz, é necessário adicionar na sub-arvore da direita
 *                                   Após adicionar,é necessário verificar as propriedades de cada sub-arvore
 *                                   Se uma propriedade for violada, é necessário corrigir com rotação ou mudança de cor
 */
tRBT* setNode(tRBT* node, void* info, int (*cb)(void*, void*), void (*cbDestroyInfo)(void*)){
    
    if(node==NULL) return createNode(info, RED);
    else{
        const int cmp = cb(info, node->info);
        if(cmp < 0) node->left = setNode(node->left, info, cb, cbDestroyInfo);
        else if (cmp > 0) node->right = setNode(node->right, info, cb, cbDestroyInfo);
        else {
            if(node->info != NULL) cbDestroyInfo(node->info);
            node->info = info;
        }
    }
    
    if(isRed(node->right) && !isRed(node->left)) node = rotateLeft(node);
    if(isRed(node->left) && isRed(node->left->left)) node= rotateRight(node);
    if(isRed(node->left) && isRed(node->right)) flipColor(node);

    return node;
}

/*Rotação à esquerda: recebe um nó A com B como filho direito
 *                    troca o lugar entre eles
 *                    o A se torna filho esquerdo de B
 *                    o B recebe a cor de A, e o A fica vermelho
 */

tRBT* rotateLeft(tRBT* node){
    tRBT* aux_node = node->right;
    
    node->right = aux_node->left;
    aux_node->left= node;
    aux_node->color = node->color;
    node->color = RED;
    
    return aux_node;
}

/*Rotação à direita:  Recebe um nó A com B como filho esquerdo
 *                    Troca o lugar entre eles
 *                    O A se torna filho direito de B
 *                    O B recebe a cor de A, e o A fica vermelho
 */

tRBT* rotateRight(tRBT* node){
    tRBT* aux_node = node->left;
    
    node->left = aux_node->right;
    aux_node->right= node;
    aux_node->color = node->color;
    node->color = RED;
    
    return aux_node;
}

void printRB(tRBT* node, void (*cb)(void*, FILE*), FILE* file) {
    if (node != NULL) {
        printRB(node->left, cb, file);
        cb(node->info, file);
        printRB(node->right, cb, file);
    }
}

tRBT* destroyTree(tRBT* node, void (*cb)(void*)){
    if(node!=NULL){
        destroyTree(node->left, cb);
        destroyTree(node->right, cb);
        cb(node->info);
        free(node);
    }
    return NULL;
}

void* searchNodes(tRBT* node, int(*cb)(void*,void*), void* key){
   
    while(node != NULL){
        int cmp = cb(key, node->info);
        if (cmp < 0) node = node->left;
        else if (cmp > 0) node = node->right;
        else return node->info;
    }

    return NULL;
};

// Auxiliary access functions

tRBT* getRightRB(tRBT* node) {
    return node->right;
}

tRBT* getLeftRB(tRBT* node) {
    return node->left;
}

void* getInfoRB(tRBT* node) {
    return node->info;
}

void walkTree(tRBT* node, void (*cb)(void*, void*), void* any) {
    if (node != NULL) {
        walkTree(node->left, cb, any);
        cb(node->info, any);
        walkTree(node->right, cb, any);
    }
}

// Auxiliary callback functions

int compareStrings(void* str1, void* str2) {
    return strcmp((const char*)str1, (const char*)str2);
}

void printString(void* str, FILE* file) {
    fprintf(file, "%s\n", (const char*)str);
}

void destroyString(void* str) {
    free((char*)str);
}