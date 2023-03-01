#include <stdio.h>
#include <string.h>

#include "../check_files.h"
#include "stop_word_list.h"
#include "graph_page.h"
#include "calculo_pr.h"

int main(int argc, char** argv){

    tListPage* index = readIndex(argv[1]);
    const int n_pages = sizeListPage(index);
    destroyListPage(index);

    tRBT* tree_graph= readGraph(argv[2]);
    calculatePageRank(tree_graph, n_pages);

    const char* out = "./out_file_calc.txt";
    FILE* out_file = openFile(out, false);

    printTreeGraphPage(tree_graph, out_file);    

    fclose(out_file);
    destroyTreeGraphPage(tree_graph);

    const char* test[] = {
        "a.txt" ,"3", "b.txt", "d.txt", "e.txt", "0", "0.03", "0.03",
        "b.txt", "1", "c.txt",  "3", "e.txt", "d.txt", "a.txt", "0.0954144", "0.0954136",
        "c.txt", "0", "1", "b.txt", "0.740671", "0.740673",
        "d.txt", "2", "b.txt", "e.txt", "2", "e.txt", "a.txt", "0.0669572", "0.0669568",
        "e.txt", "2" ,"b.txt", "d.txt", "2", "d.txt", "a.txt", "0.0669572", "0.0669568",
        };

    const int num = 41;
    check_file(out, test, num);    
    return 0;
}
