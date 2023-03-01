#ifndef STOP_WORD_LIST_H
#define STOP_WORD_LIST_H

#include "rb_tree.h"

tRBT *insertStopWord(tRBT *tree, const char *stop_word);
void printStopWords(tRBT *node, FILE *file);
void destroyStopWords(tRBT *node);

#endif /* STOP_WORD_LIST_H */