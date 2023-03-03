
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

static const Type plus[4][4] = {
    { INT_TYPE,  REAL_TYPE, INT_TYPE,  STR_TYPE },
    { REAL_TYPE, REAL_TYPE, REAL_TYPE, STR_TYPE },
    { INT_TYPE,  REAL_TYPE, BOOL_TYPE, STR_TYPE },
    { STR_TYPE,  STR_TYPE,  STR_TYPE,  STR_TYPE }
};

Type unify_plus(Type lt, Type rt) {
    return plus[lt][rt];
}

static const Type other[4][4] = {
    { INT_TYPE,  REAL_TYPE, NO_TYPE, NO_TYPE },
    { REAL_TYPE, REAL_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE,   NO_TYPE,   NO_TYPE, NO_TYPE },
    { NO_TYPE,   NO_TYPE,   NO_TYPE, NO_TYPE }
};

Type unify_other_arith(Type lt, Type rt) {
    return other[lt][rt];
}

static const Type comp[4][4] = {
    { BOOL_TYPE, BOOL_TYPE, NO_TYPE, NO_TYPE },
    { BOOL_TYPE, BOOL_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE,   NO_TYPE,   NO_TYPE, NO_TYPE },
    { NO_TYPE,   NO_TYPE,   NO_TYPE, BOOL_TYPE}
};

Type unify_comp(Type lt, Type rt) {
    return comp[lt][rt];
}
