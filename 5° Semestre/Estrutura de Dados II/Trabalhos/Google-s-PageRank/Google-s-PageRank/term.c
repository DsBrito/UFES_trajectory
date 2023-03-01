
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "term.h"
#include "rb_tree.h"

#define RED true    // 1
#define BLACK false // 0

struct term
{
    char *key;
    tRBT *pages;
};

tTerm *createTerm(const char *key, const char *page)
{
    tTerm *new = (tTerm *)malloc(sizeof(tTerm));
    new->key = strdup(key);
    new->pages = setNode(NULL, (void *)strdup(page), compareStrings, destroyString);
    return new;
}

tRBT *insertTerm(tRBT *terms, char *term, const char *page)
{
    tTerm *info = (tTerm *)searchNodes(terms, compareTermToString, term);
    if (info == NULL)
        return setNode(terms, (void *)createTerm(term, page), compareTerm, NULL);
    info->pages = setNode(info->pages, (void *)strdup(page), compareStrings, destroyString);
    return terms;
}

void printPageTerm(void *str, FILE *file)
{
    fprintf(file, " %s", (const char *)str);
}

void printTerm(void *sw1, FILE *file)
{
    tTerm *aux = (tTerm *)sw1;
    fprintf(file, "%s", aux->key);

    printRB(aux->pages, printPageTerm, file);
    fprintf(file, "\n");
}

void printTerms(tRBT *terms, FILE *file)
{
    printRB(terms, printTerm, file);
}

void destroyTerm(void *term)
{
    tTerm *aux = (tTerm *)term;
    free(aux->key);
    destroyTree(aux->pages, destroyString);
    free(aux);
}

void destroyTerms(tRBT *terms)
{
    destroyTree(terms, destroyTerm);
}

int compareTerm(void *term1, void *term2)
{
    return strcmp(((tTerm *)term1)->key, ((tTerm *)term2)->key);
}

int compareTermToString(void *string, void *term)
{
    return strcmp((char *)string, ((tTerm *)term)->key);
}

tRBT *getTermPages(tTerm *term)
{
    return term->pages;
}

void toLowerString(char *str)
{
    for (; *str; ++str)
        *str = tolower(*str);
}