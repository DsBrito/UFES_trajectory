#include <stdlib.h>
#include <string.h>

#include "list_page.h"

struct listpage
{
    tListPage *previous;
    tListPage *next;
    char *page;
};

tListPage *insertList(tListPage *list, const char *page)
{
    tListPage *new = (tListPage *)malloc(sizeof(tListPage));

    new->page = page;
    new->previous = NULL;
    new->next = list;

    if (list != NULL)
        list->previous = new;
    return new;
};

void removePage(tListPage *node)
{
    if (node == NULL)
        return;
    tListPage *previous = node->previous;
    tListPage *next = node->next;
    if (previous != NULL)
        previous->next = next;
    if (next != NULL)
        next->previous = previous;
    free(node->page);
    free(node);
}

void printListPage(tListPage *list, FILE *file)
{
    tListPage *p = NULL;

    for (p = list; p != NULL; p = p->next)
    {
        fprintf(file, "%s ", p->page);
    }
    fprintf(file, "\n");
};

void destroyListPage(tListPage *lista)
{
    tListPage *p = lista;
    tListPage *t = NULL;

    while (p != NULL)
    {
        t = p->next;
        free(p->page);
        free(p);
        p = t;
    }
};

tListPage *nextPage(tListPage *p)
{
    return p->next;
}

tListPage *previousPage(tListPage *p)
{
    return p->previous;
}

char *getPage(tListPage *p)
{
    return p->page;
}

int sizeListPage(tListPage *p)
{
    int n_pages = 0;
    for (p; p != NULL; p = p->next)
        n_pages++;

    return n_pages;
}
