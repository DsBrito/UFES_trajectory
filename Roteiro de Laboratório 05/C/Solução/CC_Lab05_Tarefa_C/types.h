
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

typedef enum {  // Basic conversions between types.
    B2I,
    B2R,
    B2S,
    I2R,
    I2S,
    R2S,
    NONE,
} Conv;

typedef struct {
    Type type;
    Conv lc;  // Left conversion.
    Conv rc;  // Right conversion.
} Unif;

Unif unify_plus(Type lt, Type rt);
Unif unify_other_arith(Type lt, Type rt);
Unif unify_comp(Type lt, Type rt);

#endif // TYPES_H

