#include <stdio.h>
#include <stdlib.h>

#include "stop_word_list.h"

tRBT *insertStopWord(tRBT *tree, const char *stop_word)
{
    return setNode(tree, (void *)stop_word, compareStrings, destroyString);
}

void printStopWords(tRBT *node, FILE *file)
{
    printRB(node, printString, file);
}

void destroyStopWords(tRBT *node)
{
    destroyTree(node, destroyString);
}
