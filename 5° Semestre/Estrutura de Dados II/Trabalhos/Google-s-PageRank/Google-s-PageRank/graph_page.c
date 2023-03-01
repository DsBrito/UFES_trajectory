#include "graph_page.h"

#include "list_page.h"

#include <stdlib.h>
#include <string.h>

tGraphPageList *createGraphPageList(tGraphPage *page)
{
    tGraphPageList *new = (tGraphPageList *)malloc(sizeof(tGraphPageList));
    new->page = page;
    new->next = NULL;
    return new;
}

tGraphPageList *setGraphPageList(tGraphPageList *root, tGraphPage *page)
{
    tGraphPageList *new = createGraphPageList(page);
    new->next = root;
    return new;
}

tGraphPage *createGraphPage(char *key, int n_links_out, FILE *name_file)
{
    tGraphPage *new = (tGraphPage *)malloc(sizeof(tGraphPage));

    new->name = strdup(key);

    new->n_links_out = n_links_out;
    new->pages_out = NULL;

    new->n_links_in = 0;
    new->pages_in = NULL;

    new->old_page_rank = 0.0;
    new->new_page_rank = 0.0;

    char page_out[100];
    for (size_t i = 0; i < n_links_out; i++)
    {
        fscanf(name_file, "%s", page_out);
        new->pages_out = setNode(new->pages_out, strdup(page_out), compareStrings, destroyString);
    }

    return new;
};

void printPageLink(void *str, FILE *file)
{
    fprintf(file, " %s", (const char *)str);
}

void printGraphPage(void *graph, FILE *file)
{
    tGraphPage *aux = (tGraphPage *)graph;

    fprintf(file, "%s %d", aux->name, aux->n_links_out);
    printRB(aux->pages_out, printPageLink, file);
    fprintf(file, " %d", aux->n_links_in);
    tGraphPageList *p = NULL;
    for (p = aux->pages_in; p != NULL; p = p->next)
    {
        fprintf(file, " %s", p->page->name);
    }
    fprintf(file, " %g %g", aux->old_page_rank, aux->new_page_rank);
    fprintf(file, "\n");
}

void printTreeGraphPage(tRBT *tree_graph_page, FILE *file)
{
    printRB(tree_graph_page, printGraphPage, file);
}

int compareGraphPage(void *page1, void *page2)
{
    return strcmp(((tGraphPage *)page1)->name, ((tGraphPage *)page2)->name);
}

int compareGraphPageToString(void *string, void *graph_page)
{
    return strcmp((const char *)string, ((tGraphPage *)graph_page)->name);
}

void updatePageInList(tRBT *node, tGraphPageList **page_in_list, int *n_links_in, const char *ref_page, tRBT *root)
{
    if (node == NULL)
        return;
    updatePageInList(getLeftRB(node), page_in_list, n_links_in, ref_page, root);

    tGraphPage *aux = (tGraphPage *)getInfoRB(node);
    if (searchNodes(aux->pages_out, compareStrings, (void *)ref_page) != NULL)
    {
        (*page_in_list) = setGraphPageList(*page_in_list, aux);
        (*n_links_in)++;
    }

    updatePageInList(getRightRB(node), page_in_list, n_links_in, ref_page, root);
}

void updateGraphPageIn(tGraphPage *graph_page, tRBT *root_tree_graph_page)
{
    if (root_tree_graph_page == NULL || graph_page == NULL)
        return;
    updatePageInList(root_tree_graph_page, &(graph_page->pages_in), &(graph_page->n_links_in), graph_page->name, root_tree_graph_page);
}

void updateTreeGraphPageIn(tRBT *node, tRBT *root_tree_graph_page)
{
    if (root_tree_graph_page == NULL || node == NULL)
        return;

    updateTreeGraphPageIn(getLeftRB(node), root_tree_graph_page);
    updateGraphPageIn((tGraphPage *)getInfoRB(node), root_tree_graph_page);
    updateTreeGraphPageIn(getRightRB(node), root_tree_graph_page);
}

void destroyGraphPage(void *graph_page)
{
    tGraphPage *aux = (tGraphPage *)graph_page;
    free(aux->name);
    destroyTree(aux->pages_out, destroyString);

    tGraphPageList *p = aux->pages_in;
    while (p != NULL)
    {
        tGraphPageList *aux_p = p;
        p = p->next;
        free(aux_p);
    }
    free(aux);
}

void destroyTreeGraphPage(tRBT *root_tree_graph_page)
{
    destroyTree(root_tree_graph_page, destroyGraphPage);
}
