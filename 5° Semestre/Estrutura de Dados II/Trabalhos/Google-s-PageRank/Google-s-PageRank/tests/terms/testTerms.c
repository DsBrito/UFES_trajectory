#include <stdio.h>
#include <string.h>

#include "../check_files.h"
#include "stop_word_list.h"
#include "term.h"


int main(int argc, char** argv){
    tRBT* stop_words = readStopWords(argv[2]);
    tListPage* index = readIndex(argv[1]);
    tRBT* terms = readTerm(index, stop_words, "./");

    const char* out = "./out_terms.txt";
    FILE* out_file = fopen(out, "w");
    printTerms(terms, out_file);
    fclose(out_file);

    const char* test[] = {
        "abacate", "a.txt", "b.txt", "c.txt", "d.txt", "e.txt",
        "abacaxi", "c.txt",
        "boa", "a.txt",
        "fruta", "a.txt", "b.txt",
        "gosto", "c.txt",
        "maca", "e.txt",
        "melhor", "e.txt",
        "odeio", "d.txt",
        "ruim", "b.txt", "c.txt",
        };
    const int num = 24;
    check_file(out, test, num);
    destroyStopWords(stop_words);
    destroyTerms(terms);
    return 0;
}