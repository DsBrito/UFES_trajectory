#include <stdio.h>
#include <string.h>

#include "../check_files.h"
#include "stop_word_list.h"

int main(int argc, char** argv){
    tRBT* stop_words = readStopWords(argv[1]);

    const char* out = "./out_stop_words.txt";
    FILE* out_file = fopen(out, "w");
    printStopWords(stop_words, out_file);    
    fclose(out_file);

    const char* test[] = {"de", "e", "eu", "o", "que", "uma"};
    const int num = 6;
    check_file(out, test, num);
    destroyStopWords(stop_words);
    return 0;
}