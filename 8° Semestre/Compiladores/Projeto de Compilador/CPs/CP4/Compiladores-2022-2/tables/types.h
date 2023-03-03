
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    INT_TYPE,
    REAL_TYPE,
    CHAR_TYPE,
    INT_VET_TYPE,
    REAL_VET_TYPE,
    CHAR_VET_TYPE,
    VOID_TYPE,
    NO_TYPE,
    OK_TYPE
} Type;

Type unify_plus (Type a, Type b);

Type unify_comp (Type a, Type b);

Type unify_atribution (Type a, Type b);

Type unify_param (Type a, Type b);

const char* get_text(Type type);

Type get_vet(Type type);

Type get_elem(Type type);

#endif // TYPES_H

