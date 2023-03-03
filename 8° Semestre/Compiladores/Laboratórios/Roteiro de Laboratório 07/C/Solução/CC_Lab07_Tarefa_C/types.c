
#include "types.h"

static const char *TYPE_STRING[] = {
    "int",
    "real",
    "bool",
    "str"
};

const char* get_text(Type type) {
    return TYPE_STRING[type];
}

static const Unif plus[4][4] = {
    { {INT_TYPE, NONE, NONE}, {REAL_TYPE, I2R, NONE},  {INT_TYPE, NONE, B2I},   {STR_TYPE, I2S, NONE}  },
    { {REAL_TYPE, NONE, I2R}, {REAL_TYPE, NONE, NONE}, {REAL_TYPE, NONE, B2R},  {STR_TYPE, R2S, NONE}  },
    { {INT_TYPE, B2I, NONE},  {REAL_TYPE, B2R, NONE},  {BOOL_TYPE, NONE, NONE}, {STR_TYPE, B2S, NONE}  },
    { {STR_TYPE, NONE, I2S},  {STR_TYPE, NONE, R2S},   {STR_TYPE, NONE, B2S},   {STR_TYPE, NONE, NONE} }
};

Unif unify_plus(Type lt, Type rt) {
    return plus[lt][rt];
}

static const Unif other[4][4] = {
    { {INT_TYPE, NONE, NONE}, {REAL_TYPE, I2R, NONE},  {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },
    { {REAL_TYPE, NONE, I2R}, {REAL_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },
    { {NO_TYPE, NONE, NONE},  {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },
    { {NO_TYPE, NONE, NONE},  {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} }
};

Unif unify_other_arith(Type lt, Type rt) {
    return other[lt][rt];
}

static const Unif comp[4][4] = {
    { {BOOL_TYPE, NONE, NONE}, {BOOL_TYPE, I2R, NONE},  {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE}   },
    { {BOOL_TYPE, NONE, I2R},  {BOOL_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE}   },
    { {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE}   },
    { {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE}, {BOOL_TYPE, NONE, NONE} }
};

Unif unify_comp(Type lt, Type rt) {
    return comp[lt][rt];
}
