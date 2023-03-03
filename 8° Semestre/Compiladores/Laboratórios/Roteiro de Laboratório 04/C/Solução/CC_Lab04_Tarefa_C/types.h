
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    INT_TYPE,
    REAL_TYPE,
    BOOL_TYPE,
    STR_TYPE,
    NO_TYPE, // Used when we need to pass a non-existing type to a function.
} Type;

const char* get_text(Type type);

Type unify_plus(Type lt, Type rt);
Type unify_other_arith(Type lt, Type rt);
Type unify_comp(Type lt, Type rt);


#endif // TYPES_H

