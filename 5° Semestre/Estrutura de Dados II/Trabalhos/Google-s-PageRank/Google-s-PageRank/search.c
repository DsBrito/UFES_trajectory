#include "search.h"

#include <stdlib.h>
#include <string.h>

struct pageRank
{
    char *page; // has no ownership, graph is the owner
    double page_rank;
};

typedef struct pageRank tPageRank;

tPageRank *createPageRank(char *page, double page_rank)
{
    tPageRank *pr = (tPageRank *)malloc(sizeof(tPageRank));
    pr->page = page;
    pr->page_rank = page_rank;
    return pr;
}

int comparePageRank(void *_pr, void *_ref_pr)
{
    tPageRank *ref_pr = (tPageRank *)_ref_pr;
    tPageRank *pr = (tPageRank *)_pr;
    const double dif = ref_pr->page_rank - pr->page_rank;
    const double epsilon = 1e-12;
    if (dif > epsilon)
        return 1;
    else if (dif < -epsilon)
        return -1;
    else
        return strcmp(pr->page, ref_pr->page);
}

void destroyPageRank(void *pr)
{
    free((tPageRank *)pr);
}

tRBT *sortPagesByRank(tListPage *docs, tRBT *graph)
{
    tRBT *sorted_docs = NULL;
    for (; docs != NULL; docs = nextPage(docs))
    {
        tGraphPage *graph_page = (tGraphPage *)searchNodes(graph, compareGraphPageToString, getPage(docs));
        if (graph_page != NULL)
        {
            tPageRank *pr = createPageRank(graph_page->name, graph_page->new_page_rank);
            sorted_docs = setNode(sorted_docs, pr, comparePageRank, destroyPageRank);
        }
    }

    return sorted_docs;
}

void searchTerms(tRBT *terms, tRBT *graph)
{
    searchTermsInFile(terms, graph, stdin);
}

struct pageRankArray
{
    tPageRank *array;
    int size;
};
typedef struct pageRankArray tPageRankArray;

void toPageRankArray(void *_pr, void *_array)
{
    tPageRankArray *array = (tPageRankArray *)_array;
    array->array[array->size++] = *((tPageRank *)_pr);
}

void searchTermsInFile(tRBT *terms, tRBT *graph, FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    while (1)
    {
        read = getline(&line, &len, file);
        if (read == EOF)
            break; // CTRL+D

        toLowerString(line);
        printf("search:%s", line);

        searchTermsFromLine(terms, graph, line, stdout);
    }
    free(line);
}

void searchTermsFromLine(tRBT *terms, tRBT *graph, char *line, FILE *file)
{
    tListPage *terms_to_search = splitLine(line);
    tListPage *docs = findDocuments(terms, terms_to_search);
    const int n_pages_found = sizeListPage(docs);

    tPageRankArray page_rank_array;
    page_rank_array.array = (tPageRank *)malloc(sizeof(tPageRank) * n_pages_found);
    page_rank_array.size = 0;

    tRBT *sorted_pages = sortPagesByRank(docs, graph);
    walkTree(sorted_pages, toPageRankArray, &page_rank_array);

    fprintf(file, "pages:");
    for (size_t i = 0; i < page_rank_array.size; i++)
    {
        if (i == 0)
            fprintf(file, "%s", page_rank_array.array[i].page);
        else
            fprintf(file, " %s", page_rank_array.array[i].page);
    }
    fprintf(file, "\npr:");
    for (size_t i = 0; i < page_rank_array.size; i++)
    {
        if (i == 0)
            fprintf(file, "%.16lf", page_rank_array.array[i].page_rank);
        else
            fprintf(file, " %.16lf", page_rank_array.array[i].page_rank);
    }
    fprintf(file, "\n");

    free(page_rank_array.array);
    destroyTree(sorted_pages, destroyPageRank);
    destroyListPage(docs);
    destroyListPage(terms_to_search);
}

tListPage *splitLine(char *line)
{
    tListPage *terms = NULL;
    const char *to_remove = " \n\r   ";
    char *token = strtok(line, to_remove);
    while (token != NULL)
    {
        terms = insertList(terms, strdup(token));
        token = strtok(NULL, to_remove);
    }

    return terms;
}

void setPageToList(void *_page, void *_list)
{
    char *page = (char *)_page;
    tListPage **list = (tListPage **)_list;
    *list = insertList(*list, strdup(page));
}

tListPage *findDocuments(tRBT *terms, tListPage *terms_to_search)
{
    if (terms_to_search == NULL || terms == NULL)
        return NULL;
    tListPage *docs = NULL;
    tTerm *searched_term = NULL;
    do
    {
        searched_term = (tTerm *)searchNodes(terms, compareTermToString, getPage(terms_to_search));
        terms_to_search = nextPage(terms_to_search);
    } while (searched_term == NULL && terms_to_search != NULL);

    if (searched_term != NULL)
    {
        walkTree(getTermPages(searched_term), setPageToList, &docs);
        for (terms_to_search; terms_to_search != NULL; terms_to_search = nextPage(terms_to_search))
        {
            const char *term = getPage(terms_to_search);
            tTerm *searched_term = (tTerm *)searchNodes(terms, compareTermToString, term);
            if (searched_term != NULL)
            {
                tListPage *p = docs;
                while (p != NULL)
                {
                    if (searchNodes(getTermPages(searched_term), compareStrings, getPage(p)) == NULL)
                    {
                        tListPage *aux = p;
                        p = nextPage(p);
                        if (aux == docs)
                            docs = p;
                        removePage(aux);
                    }
                    else
                        p = nextPage(p);
                }
            }
        }
    }

    return docs;
}
