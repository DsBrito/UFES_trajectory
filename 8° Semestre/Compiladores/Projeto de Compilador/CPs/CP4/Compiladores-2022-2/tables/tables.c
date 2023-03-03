
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tables.h"

// Strings Table
// ----------------------------------------------------------------------------

#define STRING_MAX_SIZE 128
#define STRINGS_TABLE_MAX_SIZE 100

struct str_table {
    char t[STRINGS_TABLE_MAX_SIZE][STRING_MAX_SIZE];
    int size;
};

StrTable* create_str_table() {
    StrTable *st = malloc(sizeof * st);
    st->size = 0;
    return st;
}

int add_string(StrTable* st, char* s) {
    for (int i = 0; i < st->size; i++) {
        if (strcmp(st->t[i], s) == 0) {
            return i;
        }
    }
    strcpy(st->t[st->size], s);
    int idx_added = st->size;
    st->size++;
    return idx_added;
}

char* get_string(StrTable* st, int i) {
    return st->t[i];
}

void print_str_table(StrTable* st) {
    printf("Strings table:\n");
    for (int i = 0; i < st->size; i++) {
        printf("Entry %d -- %s\n", i, get_string(st, i));
    }
}

void free_str_table(StrTable* st) {
    free(st);
}

// Variables Table
// ----------------------------------------------------------------------------

#define VARIABLE_MAX_SIZE 128
#define VARIABLES_TABLE_MAX_SIZE 100

typedef struct {
  char name[VARIABLE_MAX_SIZE];
  int line;
  int scope;
  Type type;
} Entry;

struct var_table {
    Entry t[VARIABLES_TABLE_MAX_SIZE];
    int size;
};

VarTable* create_var_table() {
    VarTable *vt = malloc(sizeof * vt);
    vt->size = 0;
    return vt;
}

int lookup_var(VarTable* vt, int scope, char* s) {
    for (int i = 0; i < vt->size; i++) {
        if ((strcmp(vt->t[i].name, s) == 0) && (vt->t[i].scope == scope)){
            return i;
        }
    }
    return -1;
}

int add_var(VarTable* vt, char* s, int line, int scope, Type type) {
    strcpy(vt->t[vt->size].name, s);
    vt->t[vt->size].line = line;
    vt->t[vt->size].type = type;
    vt->t[vt->size].scope = scope;
    int idx_added = vt->size;
    vt->size++;
    return idx_added;
}

char* get_var_name(VarTable* vt, int i) {
    return vt->t[i].name;
}

int get_var_line(VarTable* vt, int i) {
    return vt->t[i].line;
}

int get_var_scope(VarTable* vt, int i) {
    return vt->t[i].scope;
}

Type get_var_type(VarTable* vt, int i) {
    return vt->t[i].type;
}

void print_var_table(VarTable* vt) {
    printf("->Variables table:\n");
    for (int i = 0; i < vt->size; i++) {
         printf("Entry %d -- name: %s, line: %d, scope: %d, type: %s\n", i,
                get_var_name(vt, i), get_var_line(vt, i), get_var_scope(vt, i), get_text(get_var_type(vt, i)));
    }
}

void free_var_table(VarTable* vt) {
    free(vt);
}

#define FUNCTION_MAX_SIZE 128
#define FUNCTION_TABLE_MAX_SIZE 100

typedef struct {
  char name[FUNCTION_MAX_SIZE];
  int line;
  Type type;
  int nargs;
  Type args[VARIABLES_TABLE_MAX_SIZE];
} Function;

struct func_table {
    Function t[FUNCTION_TABLE_MAX_SIZE];
    int size;
};

FuncTable* create_func_table(){
    FuncTable *ft = malloc(sizeof * ft);
    ft->size = 0;
    return ft;
}

int add_func(FuncTable* ft, char* s, int line, Type type){
    strcpy(ft->t[ft->size].name, s);
    ft->t[ft->size].line = line;
    ft->t[ft->size].type = type;
    ft->t[ft->size].nargs = 0;
    int idx_added = ft->size;
    ft->size++;
    return idx_added;
}

void add_args (FuncTable* ft, int i, Type argtype){
    ft->t[i].args[ft->t[i].nargs] = argtype;
    //printf("%s %d\n", get_text (ft->t[i].args[ft->t[i].nargs]), ft->t[i].nargs);
    //printf ("%s %d\n", get_text (ft->t[i].args[ft->t[i].nargs]), ft->t[i].nargs);
    ft->t[i].nargs++;
}

int get_func_nargs (FuncTable* ft, int i){
    return ft->t[i].nargs;
}

void print_args (FuncTable* ft, int i){
    //printf("%d\n", ft->t[i].nargs);
    for (int j = 0; j < ft->t[i].nargs; j++)
        printf ("%s %d\n", get_text (ft->t[i].args[j]), j);
}

Type get_args (FuncTable* ft, int i, int j){
    //print_args (ft, i);
    if (j >= ft->t[i].nargs)
        return NO_TYPE;
    else{
        //printf ("%s\n", get_text (ft->t[i].args[j]));
        return ft->t[i].args[j];
    }
}

int lookup_func(FuncTable* ft, char* s){
    for (int i = 0; i < ft->size; i++) {
        if (strcmp(ft->t[i].name, s) == 0)  {
            return i;
        }
    }
    return -1;
}

char* get_func_name(FuncTable* ft, int i){
    return ft->t[i].name;
}

int get_func_line(FuncTable* ft, int i){
    return ft->t[i].line;
}

Type get_func_type(FuncTable* ft, int i){
    return ft->t[i].type;
}

void print_func_table(FuncTable* ft){
    printf("->Functions table:\n");
    for (int i = 0; i < ft->size; i++) {
        printf("Entry %d -- name: %s, line: %d, type: %s, arguments: %d\n", i,
                get_func_name(ft, i), get_func_line(ft, i), get_text(get_func_type(ft, i)), get_func_nargs(ft, i));
    }
}

void free_func_table(FuncTable* ft){
    free (ft);
}
