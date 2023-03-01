#ifndef RB_TREE_H
#define RB_TREE_H

#include <stdio.h>

typedef struct no tRBT;

tRBT *setNode(tRBT *node, void *info, int (*cb)(void *, void *), void (*cbDestroyInfo)(void *));

void printRB(tRBT *node, void (*cb)(void *, FILE *), FILE *file);

tRBT *destroyTree(tRBT *node, void (*cb)(void *));

void *searchNodes(tRBT *node, int (*cb)(void *, void *), void *key);

tRBT *rotateLeft(tRBT *node);

tRBT *rotateRight(tRBT *node);

void walkTree(tRBT *node, void (*cb)(void *, void *), void *);

// Auxiliary access functions

tRBT *getRightRB(tRBT *node);
tRBT *getLeftRB(tRBT *node);
void *getInfoRB(tRBT *node);

// Auxiliary callback functions

int compareStrings(void *, void *);

void printString(void *, FILE *);

void destroyString(void *);

#endif /* RB_TREE_H */
