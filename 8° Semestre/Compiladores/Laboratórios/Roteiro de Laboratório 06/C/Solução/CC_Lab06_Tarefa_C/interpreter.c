
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "tables.h"

// ----------------------------------------------------------------------------

extern StrTable *st;
extern VarTable *vt;

typedef union {
    int   as_int;
    float as_float;
} Word;

// ----------------------------------------------------------------------------

// Data stack -----------------------------------------------------------------

#define STACK_SIZE 100

Word stack[STACK_SIZE];
int sp; // stack pointer

// All these ops should have a boundary check, buuuut... X_X

void pushi(int x) {
    stack[++sp].as_int = x;
}

int popi() {
    return stack[sp--].as_int;
}

void pushf(float x) {
    stack[++sp].as_float = x;
}

float popf() {
    return stack[sp--].as_float;
}

void init_stack() {
    for (int i = 0; i < STACK_SIZE; i++) {
        stack[i].as_int = 0;
    }
    sp = -1;
}

void print_stack() {
    printf("*** STACK: ");
    for (int i = 0; i <= sp; i++) {
        printf("%d ", stack[i].as_int);
    }
    printf("\n");
}

// ----------------------------------------------------------------------------

// Variables memory -----------------------------------------------------------

#define MEM_SIZE 100

Word mem[MEM_SIZE];

void storei(int addr, int val) {
    mem[addr].as_int = val;
}

int loadi(int addr) {
    return mem[addr].as_int;
}

void storef(int addr, float val) {
    mem[addr].as_float = val;
}

float loadf(int addr) {
    return mem[addr].as_float;
}

void init_mem() {
    for (int addr = 0; addr < MEM_SIZE; addr++) {
        mem[addr].as_int = 0;
    }
}

// ----------------------------------------------------------------------------

// #define TRACE
#ifdef TRACE
#define trace(msg) printf("TRACE: %s\n", msg)
#else
#define trace(msg)
#endif

#define MAX_STR_SIZE 128
static char str_buf[MAX_STR_SIZE];
#define clear_str_buf() str_buf[0] = '\0'

void rec_run_ast(AST *ast);

void read_int(int var_idx) {
    int x;
    printf("read (int): ");
    scanf("%d", &x);
    storei(var_idx, x);
}

void read_real(int var_idx) {
    float x;
    printf("read (real): ");
    scanf("%f", &x);
    storef(var_idx, x);
}

void read_bool(int var_idx) {
    int x;
    do {
        printf("read (bool - 0 = false, 1 = true): ");
        scanf("%d", &x);
    } while (x != 0 && x != 1);
    storei(var_idx, x);
}

void read_str(int var_idx) {
    printf("read (str): ");
    clear_str_buf();
    scanf("%s", str_buf);   // Did anyone say Buffer Overflow..? ;P
    storei(var_idx, add_string(st, str_buf));
}

void write_int() {
    printf("%d\n", popi());
}

void write_real() {
    printf("%f\n", popf());
}

void write_bool() {
    popi() == 0 ? printf("false\n") : printf("true\n");
}

// Helper function to write strings.
void escape_str(const char* s, char *n) {
    int i = 0, j = 0;
    char c;
    while ((c = s[i++]) != '\0') {
        if (c == '"') { continue; }
        else if (c == '\\' && s[i] == 'n') {
            n[j++] = '\n';
            i++;
        } else {
            n[j++] = c;
        }
    }
    n[j] = '\0';
}

void write_str() {
    int s = popi(); // String pointer
    clear_str_buf();
    escape_str(get_string(st, s), str_buf);
    printf(str_buf); // Weird language semantics, if printing a string, no new line.
}

#define run_bin_op()                \
    AST *lexpr = get_child(ast, 0); \
    AST *rexpr = get_child(ast, 1); \
    rec_run_ast(lexpr);             \
    rec_run_ast(rexpr)

void plus_int(AST *ast) {
    run_bin_op();
    int r = popi();
    int l = popi();
    pushi(l + r);
}

void plus_real(AST *ast) {
    run_bin_op();
    float r = popf();
    float l = popf();
    pushf(l + r);
}

void plus_bool(AST *ast) {
    run_bin_op();
    int r = popi();
    int l = popi();
    pushi(l || r); // Can't add l and r here because of overflow (>1).
}

void plus_str(AST *ast) {
    run_bin_op();
    int r = popi();
    int l = popi();
    clear_str_buf();
    strcat(str_buf, get_string(st, l));
    strcat(str_buf, get_string(st, r));
    pushi(add_string(st, str_buf));
}

void run_other_arith(AST *ast, int (*int_op)(int,int), float (*real_op)(float,float)) {
    run_bin_op();
    if (get_node_type(ast) == INT_TYPE) {
        int r = popi();
        int l = popi();
        pushi(int_op(l,r));
    } else { // Result must be REAL_TYPE.
        float r = popf();
        float l = popf();
        pushf(real_op(l,r));
    }
}

int int_minus(int l, int r) {
    return l - r;
}

float float_minus(float l, float r) {
    return l - r;
}

int int_over(int l, int r) {
    return l / r;
}

float float_over(float l, float r) {
    return l / r;
}

int int_times(int l, int r) {
    return l * r;
}

float float_times(float l, float r) {
    return l * r;
}

void run_cmp(AST *ast, int (*int_cmp)(int,int),
             int (*real_cmp)(float,float), int (*str_cmp)(char*,char*)) {
    run_bin_op();
    if (get_node_type(rexpr) == STR_TYPE) { // Could equally test 'lexpr' here.
        int r = popi();
        int l = popi();
        pushi(str_cmp(get_string(st, l), get_string(st, r)));
    } else if (get_node_type(rexpr) == INT_TYPE) {
        int r = popi();
        int l = popi();
        pushi(int_cmp(l, r));
    } else { // Result is REAL_TYPE.
        float r = popf();
        float l = popf();
        pushi(real_cmp(l,r));
    }
}

int int_eq(int l, int r) {
    return l == r;
}

int float_eq(float l, float r) {
    return l == r;
}

int str_eq(char *l, char *r) {
    return (strcmp(l, r) == 0);
}

int int_lt(int l, int r) {
    return l < r;
}

int float_lt(float l, float r) {
    return l < r;
}

int str_lt(char *l, char *r) {
    return (strcmp(l, r) < 0);
}

// ----------------------------------------------------------------------------

void run_assign(AST *ast) {
    trace("assign");
    AST *rexpr = get_child(ast, 1);
    rec_run_ast(rexpr);
    int var_idx = get_data(get_child(ast, 0));
    Type var_type = get_type(vt, var_idx);
    if (var_type == REAL_TYPE) {
        storef(var_idx, popf());
    } else {
        storei(var_idx, popi());
    }
}

void run_eq(AST *ast) {
    trace("eq");
    run_cmp(ast, int_eq, float_eq, str_eq);
}

void run_block(AST *ast) {
    trace("block");
    int size = get_child_count(ast);
    for (int i = 0; i < size; i++) {
        rec_run_ast(get_child(ast, i));
    }
}

void run_bool_val(AST *ast) {
    trace("bool_val");
    pushi(get_data(ast));
}

void run_if(AST *ast) {
    trace("if");
    rec_run_ast(get_child(ast, 0));
    int test = popi();
    if (test == 1) {
        rec_run_ast(get_child(ast, 1));
    } else if (test == 0 && get_child_count(ast) == 3) {
        rec_run_ast(get_child(ast, 2));
    }
}

void run_int_val(AST *ast) {
    trace("int_val");
    pushi(get_data(ast));
}

void run_lt(AST *ast) {
    trace("lt");
    run_cmp(ast, int_lt, float_lt, str_lt);
}

void run_minus(AST *ast) {
    trace("minus");
    run_other_arith(ast, int_minus, float_minus);
}

void run_over(AST *ast) {
    trace("over");
    run_other_arith(ast, int_over, float_over);
}

void run_plus(AST *ast) {
    trace("plus");
    Type plus_type = get_node_type(ast);
    switch(plus_type) {
        case INT_TYPE:  plus_int(ast);     break;
        case REAL_TYPE: plus_real(ast);    break;
        case BOOL_TYPE: plus_bool(ast);    break;
        case STR_TYPE:  plus_str(ast);     break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(plus_type));
            exit(EXIT_FAILURE);
    }
}

void run_program(AST *ast) {
    trace("program");
    rec_run_ast(get_child(ast, 0)); // run var_list
    rec_run_ast(get_child(ast, 1)); // run block
}

void run_read(AST *ast) {
    trace("read");
    int var_idx = get_data(get_child(ast, 0));
    Type var_type = get_type(vt, var_idx);
    switch(var_type) {
        case INT_TYPE:  read_int(var_idx);     break;
        case REAL_TYPE: read_real(var_idx);    break;
        case BOOL_TYPE: read_bool(var_idx);    break;
        case STR_TYPE:  read_str(var_idx);     break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(var_type));
            exit(EXIT_FAILURE);
    }
}

void run_real_val(AST *ast) {
    trace("real");
    pushf(get_float_data(ast));
}

void run_repeat(AST *ast) {
    trace("repeat");
    int again = 1;
    while (again) {
        rec_run_ast(get_child(ast, 0)); // Run body.
        rec_run_ast(get_child(ast, 1)); // Run test.
        again = !popi();
    }
}

void run_str_val(AST *ast) {
    trace("str_val");
    pushi(get_data(ast));
}

void run_times(AST *ast) {
    trace("times");
    run_other_arith(ast, int_times, float_times);
}

void run_var_decl(AST *ast) {
    trace("var_decl");
    // Nothing to do, memory was already cleared upon initialization.
}

void run_var_list(AST *ast) {
    trace("var_list");
    // Nothing to do, memory was already cleared upon initialization.
}

void run_var_use(AST *ast) {
    trace("var_use");
    int var_idx = get_data(ast);
    if (get_node_type(ast) == REAL_TYPE) {
        pushf(loadf(var_idx));
    } else {
        pushi(loadi(var_idx));
    }
}

void run_write(AST *ast) {
    trace("write");
    AST *expr = get_child(ast, 0);
    rec_run_ast(expr);
    Type expr_type = get_node_type(expr);
    switch(expr_type) {
        case INT_TYPE:  write_int();    break;
        case REAL_TYPE: write_real();   break;
        case BOOL_TYPE: write_bool();   break;
        case STR_TYPE:  write_str();    break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(expr_type));
            exit(EXIT_FAILURE);
    }
}

void run_b2i(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    // Nothing else to do, a bool already is stored as an int.
}

void run_b2r(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    pushf((float) popi());
}

void run_b2s(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    clear_str_buf();
    popi() == 0 ? sprintf(str_buf, "false") : sprintf(str_buf, "true");
    pushi(add_string(st, str_buf));
}

void run_i2r(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    pushf((float) popi());
}

void run_i2s(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    clear_str_buf();
    sprintf(str_buf, "%d", popi());
    pushi(add_string(st, str_buf));
}

void run_r2s(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    clear_str_buf();
    sprintf(str_buf, "%f", popf());
    pushi(add_string(st, str_buf));
}

void rec_run_ast(AST *ast) {
    switch(get_kind(ast)) {
        case ASSIGN_NODE:   run_assign(ast);    break;
        case EQ_NODE:       run_eq(ast);        break;
        case BLOCK_NODE:    run_block(ast);     break;
        case BOOL_VAL_NODE: run_bool_val(ast);  break;
        case IF_NODE:       run_if(ast);        break;
        case INT_VAL_NODE:  run_int_val(ast);   break;
        case LT_NODE:       run_lt(ast);        break;
        case MINUS_NODE:    run_minus(ast);     break;
        case OVER_NODE:     run_over(ast);      break;
        case PLUS_NODE:     run_plus(ast);      break;
        case PROGRAM_NODE:  run_program(ast);   break;
        case READ_NODE:     run_read(ast);      break;
        case REAL_VAL_NODE: run_real_val(ast);  break;
        case REPEAT_NODE:   run_repeat(ast);    break;
        case STR_VAL_NODE:  run_str_val(ast);   break;
        case TIMES_NODE:    run_times(ast);     break;
        case VAR_DECL_NODE: run_var_decl(ast);  break;
        case VAR_LIST_NODE: run_var_list(ast);  break;
        case VAR_USE_NODE:  run_var_use(ast);   break;
        case WRITE_NODE:    run_write(ast);     break;

        case B2I_NODE:      run_b2i(ast);       break;
        case B2R_NODE:      run_b2r(ast);       break;
        case B2S_NODE:      run_b2s(ast);       break;
        case I2R_NODE:      run_i2r(ast);       break;
        case I2S_NODE:      run_i2s(ast);       break;
        case R2S_NODE:      run_r2s(ast);       break;

        default:
            fprintf(stderr, "Invalid kind: %s!\n", kind2str(get_kind(ast)));
            exit(EXIT_FAILURE);
    }
}

// ----------------------------------------------------------------------------

void run_ast(AST *ast) {
    init_stack();
    init_mem();
    rec_run_ast(ast);
}
