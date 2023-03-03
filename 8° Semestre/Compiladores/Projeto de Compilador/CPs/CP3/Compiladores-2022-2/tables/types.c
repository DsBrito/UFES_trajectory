
#include "types.h"

static const char *TYPE_STRING[] = {
    "int",
    "real",
    "char",
    "int_vet",
    "real_vet",
    "char_vet",
    "void"
};

const char* get_text(Type type) {
    return TYPE_STRING[type];
}

const char* get_text_vet(Type type) {
    return TYPE_STRING[type + 3];
}