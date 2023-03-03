#include <stdlib.h>
#include <stdio.h>
#include "code.h"
#include "instruction.h"
#include "tables.h"

// ----------------------------------------------------------------------------
// Tables ---------------------------------------------------------------------

extern StrTable *st;
extern VarTable *vt;

// ----------------------------------------------------------------------------
// Code memory ----------------------------------------------------------------

Instr code[INSTR_MEM_SIZE];
int next_instr;

// ----------------------------------------------------------------------------
// Emits ----------------------------------------------------------------------

void emit(OpCode op, int o1, int o2, int o3) {
    code[next_instr].op = op;
    code[next_instr].o1 = o1;
    code[next_instr].o2 = o2;
    code[next_instr].o3 = o3;
    next_instr++;
}

#define emit0(op) \
    emit(op, 0, 0, 0)

#define emit1(op, o1) \
    emit(op, o1, 0, 0)

#define emit2(op, o1, o2) \
    emit(op, o1, o2, 0)

#define emit3(op, o1, o2, o3) \
    emit(op, o1, o2, o3)

void backpatch_jump(int instr_addr, int jump_addr) {
    code[instr_addr].o1 = jump_addr;
}

void backpatch_branch(int instr_addr, int offset) {
    code[instr_addr].o2 = offset;
}

// ----------------------------------------------------------------------------
// Prints ---------------------------------------------------------------------

#define LINE_SIZE 80
#define MAX_STR_SIZE 128

void get_instruction_string(Instr instr, char *s) {
    OpCode op = instr.op;
    s += sprintf(s, "%s", OpStr[op]);
    int op_count = OpCount[op];
    if (op_count == 1) {
        sprintf(s, " %d", instr.o1);
    } else if (op_count == 2) {
        sprintf(s, " %d, %d", instr.o1, instr.o2);
    } else if (op_count == 3) {
        sprintf(s, " %d, %d, %d", instr.o1, instr.o2, instr.o3);
    }
}

void write_instruction(int addr) {
    Instr instr = code[addr];
    char instr_str[LINE_SIZE];
    get_instruction_string(instr, instr_str);
    printf("%s\n", instr_str);
}

void dump_program() {
    for (int addr = 0; addr < next_instr; addr++) {
        write_instruction(addr);
    }
}

void dump_str_table() {
    int table_size = get_str_table_size(st);
    for (int i = 0; i < table_size; i++) {
        printf("SSTR %s\n", get_string(st, i));
    }
}

// ----------------------------------------------------------------------------
// AST Traversal --------------------------------------------------------------

int int_regs_count;
int float_regs_count;

#define new_int_reg() \
    int_regs_count++

#define new_float_reg() \
    float_regs_count++

int rec_emit_code(AST *ast);

// ----------------------------------------------------------------------------

// TODO
int emit_assign(AST *ast) {
    return -1; // This is not an expression, hence no value to return.
}

// TODO
int emit_eq(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_block(AST *ast) {
    return -1; // This is not an expression, hence no value to return.
}

// TODO
int emit_bool_val(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_if(AST *ast) {
    return -1; // This is not an expression, hence no value to return.
}

// TODO
int emit_int_val(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_lt(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_minus(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_over(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_plus(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

int emit_program(AST *ast) {
    rec_emit_code(get_child(ast, 0)); // var_list
    rec_emit_code(get_child(ast, 1)); // block
    return -1;  // This is not an expression, hence no value to return.
}

// TODO
int emit_read(AST *ast) {
    return -1;  // This is not an expression, hence no value to return.
}

int emit_real_val(AST *ast) {
    int x = new_float_reg();
    // We need to read as an int because the TM cannot handle floats directly.
    // But we have a float stored in the AST, so we just read it as an int
    // and magically we have a float encoded as an int... :P
    int c = get_data(ast);
    emit2(LDIf, x, c);
    return x;
}

// TODO
int emit_repeat(AST *ast) {
    return -1;  // This is not an expression, hence no value to return.
}

int emit_str_val(AST *ast) {
    int x = new_int_reg();
    int c = get_data(ast);
    emit2(LDIi, x, c);
    return x;
}

// TODO
int emit_times(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

int emit_var_decl(AST *ast) {
    // Nothing to do here.
    return -1;  // This is not an expression, hence no value to return.
}

int emit_var_list(AST *ast) {
    // Nothing to do here.
    return -1;  // This is not an expression, hence no value to return.
}

// TODO
int emit_var_use(AST *ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_write(AST *ast) {
    return -1;  // This is not an expression, hence no value to return.
}

// TODO
int emit_b2i(AST* ast) {
    return -1; // FIXME Return a proper value here.
}

// TODO
int emit_b2r(AST* ast) {
    return -1; // FIXME Return a proper value here.
}

int emit_b2s(AST* ast) {
    int x = new_int_reg();
    int y = rec_emit_code(get_child(ast, 0));
    emit2(B2Ss, x, y);
    return x;
}

// TODO
int emit_i2r(AST* ast) {
    return -1; // FIXME Return a proper value here.
}

int emit_i2s(AST* ast) {
    int x = new_int_reg();
    int y = rec_emit_code(get_child(ast, 0));
    emit2(I2Ss, x, y);
    return x;
}

int emit_r2s(AST* ast) {
    int x = new_int_reg();
    int y = rec_emit_code(get_child(ast, 0));
    emit2(R2Ss, x, y);
    return x;
}

// ----------------------------------------------------------------------------

int rec_emit_code(AST *ast) {
    switch(get_kind(ast)) {
        case ASSIGN_NODE:   return emit_assign(ast);
        case EQ_NODE:       return emit_eq(ast);
        case BLOCK_NODE:    return emit_block(ast);
        case BOOL_VAL_NODE: return emit_bool_val(ast);
        case IF_NODE:       return emit_if(ast);
        case INT_VAL_NODE:  return emit_int_val(ast);
        case LT_NODE:       return emit_lt(ast);
        case MINUS_NODE:    return emit_minus(ast);
        case OVER_NODE:     return emit_over(ast);
        case PLUS_NODE:     return emit_plus(ast);
        case PROGRAM_NODE:  return emit_program(ast);
        case READ_NODE:     return emit_read(ast);
        case REAL_VAL_NODE: return emit_real_val(ast);
        case REPEAT_NODE:   return emit_repeat(ast);
        case STR_VAL_NODE:  return emit_str_val(ast);
        case TIMES_NODE:    return emit_times(ast);
        case VAR_DECL_NODE: return emit_var_decl(ast);
        case VAR_LIST_NODE: return emit_var_list(ast);
        case VAR_USE_NODE:  return emit_var_use(ast);
        case WRITE_NODE:    return emit_write(ast);

        case B2I_NODE:      return emit_b2i(ast);
        case B2R_NODE:      return emit_b2r(ast);
        case B2S_NODE:      return emit_b2s(ast);
        case I2R_NODE:      return emit_i2r(ast);
        case I2S_NODE:      return emit_i2s(ast);
        case R2S_NODE:      return emit_r2s(ast);

        default:
            fprintf(stderr, "Invalid kind: %s!\n", kind2str(get_kind(ast)));
            exit(EXIT_FAILURE);
    }
}

// ----------------------------------------------------------------------------

void emit_code(AST *ast) {
    next_instr = 0;
    int_regs_count = 0;
    float_regs_count = 0;
    dump_str_table();
    rec_emit_code(ast);
    emit0(HALT);
    dump_program();
}
