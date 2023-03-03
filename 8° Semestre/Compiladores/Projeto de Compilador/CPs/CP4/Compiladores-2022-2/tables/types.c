
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

//                                      INT_TYPE  REAL_TYPE  CHAR_TYPE  INT_VET_TYPE  REAL_VET_TYPE  CHAR_VET_TYPE
static const Type type_plus[6][6]/*INT_TYPE*/={{INT_TYPE, NO_TYPE, INT_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_TYPE*/       {REAL_TYPE, REAL_TYPE, REAL_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*CHAR_TYPE*/       {INT_TYPE, NO_TYPE, REAL_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*INT_VET_TYPE*/    {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_VET_TYPE*/   {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},                                
                    /*CHAR_VET_TYPE*/   {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE}};

//                                       INT_TYPE  REAL_TYPE  CHAR_TYPE  INT_VET_TYPE  REAL_VET_TYPE  CHAR_VET_TYPE
static const Type type_comp[6][6]/*INT_TYPE*/={{OK_TYPE, OK_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_TYPE*/       {OK_TYPE, OK_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*CHAR_TYPE*/       {OK_TYPE, OK_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*INT_VET_TYPE*/    {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_VET_TYPE*/   {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},                                
                    /*CHAR_VET_TYPE*/   {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE}};

//                                              INT_TYPE  REAL_TYPE  CHAR_TYPE  INT_VET_TYPE  REAL_VET_TYPE  CHAR_VET_TYPE
static const Type type_atrb[6][6]/*INT_TYPE*/={{OK_TYPE, NO_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_TYPE*/              {OK_TYPE, OK_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*CHAR_TYPE*/              {OK_TYPE, NO_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*INT_VET_TYPE*/           {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_VET_TYPE*/          {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},                                
                    /*CHAR_VET_TYPE*/          {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE}};

//                                              INT_TYPE  REAL_TYPE  CHAR_TYPE  INT_VET_TYPE  REAL_VET_TYPE  CHAR_VET_TYPE
static const Type type_param[6][6]/*INT_TYPE*/={{OK_TYPE, NO_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_TYPE*/               {OK_TYPE, OK_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*CHAR_TYPE*/               {OK_TYPE, NO_TYPE, OK_TYPE, NO_TYPE, NO_TYPE, NO_TYPE},
                    /*INT_VET_TYPE*/            {NO_TYPE, NO_TYPE, NO_TYPE, INT_VET_TYPE, NO_TYPE, NO_TYPE},
                    /*REAL_VET_TYPE*/           {NO_TYPE, NO_TYPE, NO_TYPE, REAL_VET_TYPE, REAL_VET_TYPE, NO_TYPE},                                
                    /*CHAR_VET_TYPE*/           {NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, CHAR_VET_TYPE}};

Type unify_plus (Type a, Type b){
    return type_plus[a][b];
}

Type unify_comp (Type a, Type b){
    return type_comp[a][b];
}

Type unify_atribution (Type a, Type b){
    return type_atrb[a][b];
}

Type unify_param (Type a, Type b){
    return type_param[a][b];
}

const char* get_text(Type type) {
    return TYPE_STRING[type];
}

Type get_vet(Type type) {
    return type + 3;
}

Type get_elem(Type type) {
    return type - 3;
}