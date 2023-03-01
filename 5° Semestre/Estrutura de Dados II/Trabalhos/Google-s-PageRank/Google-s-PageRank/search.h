#ifndef SEARCH_H
#define SEARCH_H

#include "term.h"
#include "graph_page.h"
#include "list_page.h"

#include <stdio.h>

void searchTerms(tRBT *terms, tRBT *graph);
void searchTermsInFile(tRBT *terms, tRBT *graph, FILE *file);
void searchTermsFromLine(tRBT *terms, tRBT *graph, char *line, FILE *file);

tListPage *splitLine(char *line);
tListPage *findDocuments(tRBT *terms, tListPage *terms_to_search);

#endif