
#include "types.h"

static const char *TYPE_STRING[] = {
    "int",
    "real",
    "bool",
    "string"
};

const char* get_text(Type type) {
    return TYPE_STRING[type];
}
