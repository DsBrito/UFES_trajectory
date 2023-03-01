#ifndef PAGE_H
#define PAGE_H

#include "rb_tree.h"

#include <stdio.h>

typedef struct graphPageList tGraphPageList;
typedef struct graphPage tGraphPage;

struct graphPageList
{
    tGraphPage *page;
    tGraphPageList *next;
};

struct graphPage
{
    char *name;
    int n_links_out;
    tRBT *pages_out; // a tree of page names

    int n_links_in;
    tGraphPageList *pages_in; // a simple list of all pages that poits to this page

    double old_page_rank;
    double new_page_rank;
};

tGraphPage *createGraphPage(char *key, int n_links_out, FILE *name_file);

void printTreeGraphPage(tRBT *tree_graph_page, FILE *file);

int compareGraphPage(void *page1, void *page2);

int compareGraphPageToString(void *string, void *graph_page);

void updateTreeGraphPageIn(tRBT *node, tRBT *root_tree_graph_page);

void destroyTreeGraphPage(tRBT *root_tree_graph_page);

void destroyGraphPage(void *graph_page);

#endif