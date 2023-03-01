#ifndef READ_INPUT_H
#define READ_INPUT_H

#include <stdio.h>
#include <stdbool.h>

#include "list_page.h"
#include "rb_tree.h"

FILE *openFile(const char *file_name, bool is_read);

tListPage *readIndex(const char *file_name);

tRBT *readStopWords(const char *file_name);

tRBT *readTerm(tListPage *index, tRBT *node_stop_words, const char *current_dir);

tRBT *readGraph(const char *name_file);

#endif /* READ_INPUT_H */