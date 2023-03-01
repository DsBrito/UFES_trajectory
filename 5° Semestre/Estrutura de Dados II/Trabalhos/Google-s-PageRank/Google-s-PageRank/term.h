#ifndef TERMO_H
#define TERMO_H

#include "rb_tree.h"

typedef struct term tTerm;

tRBT *insertTerm(tRBT *terms, char *term, const char *page);
void printTerms(tRBT *terms, FILE *file);
void destroyTerms(tRBT *terms);

int compareTerm(void *term1, void *term2);
int compareTermToString(void *string, void *term);

void printTerm(void *sw1, FILE *file);

tRBT *getTermPages(tTerm *term);

void toLowerString(char *str);

#endif /* TERM_H */