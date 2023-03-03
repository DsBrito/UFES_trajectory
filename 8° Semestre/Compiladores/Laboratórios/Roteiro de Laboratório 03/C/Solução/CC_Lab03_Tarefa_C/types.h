
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    INT_TYPE,
    REAL_TYPE,
    BOOL_TYPE,
    STR_TYPE
} Type;

const char* get_text(Type type);

#endif // TYPES_H

