#include <stdlib.h>
#include <string.h>

#include "read_input.h"
#include "term.h"
#include "rb_tree.h"
#include "stop_word_list.h"
#include "graph_page.h"

FILE *openFile(const char *file_name, bool is_read)
{
    const char *r = is_read ? "r" : "w";
    FILE *f = fopen(file_name, r);

    if (f == NULL)
    {
        printf("file cannot be opened: %s\n", file_name);
        exit(1);
    }
    return f;
}

tListPage *readIndex(const char *file_name)
{
    tListPage *ListPage = NULL;
    FILE *file = openFile(file_name, true);

    char token[100];
    while (fscanf(file, "%s", token) != EOF)
    {
        ListPage = insertList(ListPage, strdup(token));
    }
    fclose(file);

    return ListPage;
};

tRBT *readStopWords(const char *file_name)
{
    FILE *file_stop_words = openFile(file_name, true);

    char token[200];
    tRBT *stop_words = NULL;
    while (fscanf(file_stop_words, "%s", token) != EOF)
    {
        toLowerString(token);
        stop_words = insertStopWord(stop_words, strdup(token));
    }
    fclose(file_stop_words);

    return stop_words;
}

tRBT *readTerm(tListPage *index, tRBT *node_stop_words, const char *current_dir)
{
    tRBT *terms = NULL;

    char word[200];
    char page[1000];
    tListPage *p = NULL;
    const char *pages_dir = "/pages/";
    char full_dir[1000];
    strcpy(full_dir, current_dir);
    strcat(full_dir, pages_dir);
    for (p = index; p != NULL; p = nextPage(p))
    {
        page[0] = 0;
        strcpy(page, full_dir);
        strcat(page, getPage(p));
        FILE *file_page = openFile(page, true);
        while (fscanf(file_page, "%s", word) != EOF)
        {
            // Se não estiver no stop words, insere item
            toLowerString(word);
            if (searchNodes(node_stop_words, compareStrings, word) == NULL)
                terms = insertTerm(terms, word, getPage(p));
        }
        fclose(file_page);
    }

    return terms;
}

tRBT *readGraph(const char *name_file)
{
    FILE *file_graph = openFile(name_file, true);

    tRBT *tree_graph = NULL;
    char page_name[100];
    int n_links_out;
    while (fscanf(file_graph, "%s", page_name) != EOF)
    {
        fscanf(file_graph, "%d", &n_links_out);
        tGraphPage *graph = createGraphPage(page_name, n_links_out, file_graph);
        tree_graph = setNode(tree_graph, graph, compareGraphPage, destroyGraphPage);
    }
    fclose(file_graph);

    updateTreeGraphPageIn(tree_graph, tree_graph);
    return tree_graph;
}
