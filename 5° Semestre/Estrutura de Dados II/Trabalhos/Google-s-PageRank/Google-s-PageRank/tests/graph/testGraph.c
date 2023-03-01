#include <stdio.h>
#include <string.h>

#include "../check_files.h"
#include "stop_word_list.h"
#include "graph_page.h"

int main(int argc, char** argv){

    tRBT* tree_graph= readGraph(argv[1]);

    const char* out = "./out_file_graph.txt";
    FILE* out_file = openFile(out, false);
    printTreeGraphPage(tree_graph, out_file);
    fclose(out_file);
    destroyTreeGraphPage(tree_graph);

    const char* test[] = {
        "a.txt" ,"3", "b.txt", "d.txt", "e.txt", "0", "0", "0",
        "b.txt", "1", "c.txt",  "3", "e.txt", "d.txt", "a.txt", "0", "0",
        "c.txt", "0", "1", "b.txt", "0", "0",
        "d.txt", "2", "b.txt", "e.txt", "2", "e.txt", "a.txt", "0", "0",
        "e.txt", "2" ,"b.txt", "d.txt", "2", "d.txt", "a.txt", "0", "0",
        };

    const int num = 41;
    check_file(out, test, num);    
    return 0;
}
