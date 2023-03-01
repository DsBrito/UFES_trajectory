#ifndef CHECK_FILES_H
#define CHECK_FILES_H

#include <stdlib.h>
#include "read_input.h"

void check_file(const char* file_name, const char** test, int num){
    FILE* file = openFile(file_name,true);

    int count = 0;

    char token[100];
    while (fscanf(file, "%s", token) != EOF) {
        //printf("%s & %s\n",test[count], token);
        if(strcmp(test[count++], token) != 0) exit(1);
    }

    if(count != num) {
        printf("It has %d against the expected %d", count, num);
        exit(1);
    }

    fclose(file);    
}

#endif