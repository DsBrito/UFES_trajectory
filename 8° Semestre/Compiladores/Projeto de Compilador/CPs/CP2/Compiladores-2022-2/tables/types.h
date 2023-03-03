
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    INT_TYPE,
    REAL_TYPE,
    CHAR_TYPE,
    INT_VET_TYPE,
    REAL_VET_TYPE,
    CHAR_VET_TYPE,
    VOID_TYPE
} Type;

const char* get_text(Type type);

const char* get_text_vet(Type type);

#endif // TYPES_H

