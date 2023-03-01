#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rb_tree.h"
#include "read_input.h"
#include "list_page.h"
#include "term.h"
#include "graph_page.h"
#include "stop_word_list.h"
#include "calculo_pr.h"
#include "search.h"

void catFilePath(char *dest, const char *dir, const char *file)
{
    strcpy(dest, dir);
    strcat(dest, file);
}

int main(int argc, char **argv)
{
    char file_path[1000];

    const char *dir = argv[1];
    const char *index_filename = "/index.txt";
    catFilePath(file_path, dir, index_filename);
    tListPage *index = readIndex(file_path);

    const char *stopwords_filename = "/stopwords.txt";
    catFilePath(file_path, dir, stopwords_filename);
    tRBT *stop_words = readStopWords(file_path);

    tRBT *terms = readTerm(index, stop_words, dir);

    destroyStopWords(stop_words);

    const int n_pages = sizeListPage(index);
    destroyListPage(index);

    const char *graph_filename = "/graph.txt";
    catFilePath(file_path, dir, graph_filename);
    tRBT *tree_graph = readGraph(file_path);

    calculatePageRank(tree_graph, n_pages);

    searchTerms(terms, tree_graph);

    destroyTerms(terms);
    destroyTreeGraphPage(tree_graph);

    return (EXIT_SUCCESS);
}
