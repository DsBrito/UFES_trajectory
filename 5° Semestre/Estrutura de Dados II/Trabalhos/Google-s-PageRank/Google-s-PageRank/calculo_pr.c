#include "calculo_pr.h"

#include "graph_page.h"

#include <math.h>
#include <stdio.h>

void initializePageRankOnGraph(void *_graph_page, void *_n_pages)
{
    tGraphPage *graph_page = (tGraphPage *)_graph_page;
    int n_pages = *((int *)_n_pages);

    graph_page->new_page_rank = 1.0 / n_pages;
}

void calculatePageRankOnGraph(void *_graph_page, void *_n_pages)
{
    tGraphPage *graph_page = (tGraphPage *)_graph_page;
    int n_pages = *((int *)_n_pages);

    graph_page->new_page_rank = 0.15f / (double)n_pages;

    tGraphPageList *p = graph_page->pages_in;
    while (p != NULL)
    {
        tGraphPage *aux = p->page;
        graph_page->new_page_rank += 0.85f * aux->old_page_rank / (double)aux->n_links_out;
        p = p->next;
    }

    if (graph_page->n_links_out == 0)
        graph_page->new_page_rank += 0.85f * graph_page->old_page_rank;
}

void calculateErrorPageRankOnGraph(void *_graph_page, void *_error)
{
    tGraphPage *graph_page = (tGraphPage *)_graph_page;
    double *error = (double *)_error;
    (*error) += fabs(graph_page->new_page_rank - graph_page->old_page_rank);
}

double calculateErrorPageRank(tRBT *root, int n_pages)
{
    double error = 0.0;

    walkTree(root, calculateErrorPageRankOnGraph, &error);

    return error / n_pages;
}

void updateOldPageRankOnGraph(void *_page, void *_any)
{
    tGraphPage *page = (tGraphPage *)_page;
    page->old_page_rank = page->new_page_rank;
}

void calculatePageRank(tRBT *root, int n_pages)
{
    double error = 0.0;
    const double epsilon = 1e-6;
    int count = 0;

    walkTree(root, initializePageRankOnGraph, &n_pages);
    do
    {
        count++;
        walkTree(root, updateOldPageRankOnGraph, NULL);
        walkTree(root, calculatePageRankOnGraph, &n_pages);

        error = calculateErrorPageRank(root, n_pages);
    } while (error > epsilon && count <= 10000);
    // printf("calculatePageRank - Etapa: %d, error: %lf\n", count, error);
}
