#include <stdio.h>
#include <string.h>

#include "../check_files.h"
#include "list_page.h"

int main(int argc, char** argv){
    tListPage* index = readIndex(argv[1]);

    const char* out = "./out_list_page.txt";
    FILE* out_file = fopen(out, "w");
    printListPage(index, out_file);
    fclose(out_file);

    const char* test[] = {"c.txt", "e.txt", "d.txt", "b.txt", "a.txt"};
    const int num = 5;
    check_file(out, test, num);
    destroyListPage(index);
    return 0;
}