#ifndef LIST_PAGE_H
#define LIST_PAGE_H

#include <stdio.h>

typedef struct listpage tListPage;

tListPage* insertList(tListPage* list, const char* page);

void removePage(tListPage* node);

void printListPage(tListPage* list, FILE* file);

void destroyListPage(tListPage* list);
 
tListPage* nextPage(tListPage* p);
tListPage* previousPage(tListPage* p);

char* getPage(tListPage* p);

int sizeListPage(tListPage* p);

#endif /* LIST_PAGE_H */