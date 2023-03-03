
// The Tiny Machine (TM) Simulator

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instruction.h"
#include "tables.h"

// ----------------------------------------------------------------------------
// Structures -----------------------------------------------------------------

typedef enum {
    OKAY,
    HALTED,
    IMEM_ERR,
    DMEM_ERR,
    DIV_ZERO
} StepResult;

typedef union {
    int   as_int;
    float as_float;
} Word;

// ----------------------------------------------------------------------------
// Memory ---------------------------------------------------------------------

int   pc;                   // Program counter.
int   is[INT_REGS_COUNT];   // Integer registers.
float fs[FLOAT_REGS_COUNT]; // Float registers.

Instr instr_mem[INSTR_MEM_SIZE];    // Instruction memory.
Word  data_mem[DATA_MEM_SIZE];      // Data memory.

StrTable *st; // Strings table.
// We are cheating big time by using this table. But, strings are normally
// handled by system calls to the OS, so we need a way to simulate that.
// (See additional comments in file 'instruction.h'.)

// ----------------------------------------------------------------------------
// Init -----------------------------------------------------------------------

void init_memory() {
    // Clear Registers
    pc = 0;
    for (int x = 0; x < INT_REGS_COUNT; x++) {
        is[x] = 0;
    }
    for (int x = 0; x < FLOAT_REGS_COUNT; x++) {
        fs[x] = 0.0;
    }
    // Clear Instruction Memory
    Instr noop = {NOOP, 0, 0, 0};
    for (int addr = 0; addr < INSTR_MEM_SIZE; addr++) {
        instr_mem[addr] = noop;
    }
    // Clear Data Memory
    for (int addr = 0; addr < DATA_MEM_SIZE; addr++) {
        data_mem[addr].as_int = 0;
    }
}

// ----------------------------------------------------------------------------
// Read and Write ASM ---------------------------------------------------------

#define LINE_SIZE 80
#define OP_ERR "Undefined operation in ASM line above!"

#define MAX_STR_SIZE 128
static char str_buf[MAX_STR_SIZE];
#define clear_str_buf() str_buf[0] = '\0'

void parse_error(char *line, char *msg) {
    fprintf(stderr, "ERROR in line: %s\n TM says: %s\n", line, msg);
    exit(EXIT_FAILURE);
}

bool read_line(char *line) {
    return !fgets(line, LINE_SIZE, stdin);
}

bool is_empty(char *line) {
    return line[0] == ';' || line[0] == ' ' || line[0] == '\n';
}

OpCode get_opcode(char *line) {
    // Very naive way of parsing, but it does the job...
    for (OpCode op = HALT; op <= CALL; op++) {
        if (strncmp(OpStr[op], line, 4) == 0) {
            return op;
        }
    }
    parse_error(line, OP_ERR);
    return NOOP; // Dummy return, never reached.
}

void read_string(char *line) {
    line += 5; // Length of opcode string.
    clear_str_buf();
    sscanf(line, "%[^\n]", str_buf);   // Did anyone say Buffer Overflow..? ;P
    // We don't need to store the index here because the compiler issues the
    // string in the same order from its own string table. Thus, the compiler
    // already knows the string index and will issue a proper LDIi command when
    // a string literal is used in the program.
    add_string(st, str_buf);
}

void read_params(char *line, OpCode op, int *o1, int *o2, int *o3) {
    *o1 = 0;
    *o2 = 0;
    *o3 = 0;
    int op_count = OpCount[op];
    line += 5; // Length of opcode string.
    if (op_count == 1) {
        sscanf(line, "%d", o1);
    } else if (op_count == 2) {
        sscanf(line, "%d, %d", o1, o2);
    } else if (op_count == 3) {
        sscanf(line, "%d, %d, %d", o1, o2, o3);
    }
}

int next_instr; // For program loading.

void parse_line(char *line) {
    OpCode op;

    if (is_empty(line)) return;

    op = get_opcode(line);
    if (op == SSTR) {
        read_string(line);
        // The SSTR instruction is not "executable", it just stores the
        // string in the table, so don't need to store instruction in memory.
    } else {
        int o1, o2, o3;
        read_params(line, op, &o1, &o2, &o3);
        // Store instruction.
        instr_mem[next_instr].op = op;
        instr_mem[next_instr].o1 = o1;
        instr_mem[next_instr].o2 = o2;
        instr_mem[next_instr].o3 = o3;
        next_instr++;
    }
}

 void read_program() {
    bool done;
    char line[LINE_SIZE];
    done = false;
    next_instr = 0;
    done = read_line(line);
    while (!done) {
        parse_line(line);
        done = read_line(line);
    }
}

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
    Instr instr = instr_mem[addr];
    char instr_str[LINE_SIZE];
    get_instruction_string(instr, instr_str);
    printf("%5d: %s\n", addr, instr_str);
}

void dump_program() {
    printf("*** Instruction Memory:\n\n");
    for (int addr = 0; addr < next_instr; addr++) {
        write_instruction(addr);
    }
    printf("\n");
}

void dump_iregs() {
    printf("*** Integer registers:\n\n");
    for (int x = 0; x < INT_REGS_COUNT; x++) {
        printf("\t%2d: %d", x, is[x]);
        if ((x+1) % 4 == 0) printf("\n");
    }
    printf("\n");
}

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
    n[j++] = '\0';
}

// ----------------------------------------------------------------------------
// Run ------------------------------------------------------------------------

StepResult run_halt(Instr instr) {
    return HALTED;
}

StepResult run_noop(Instr instr) {
    pc++;
    return OKAY;
}

StepResult run_addi(Instr instr) {
    is[instr.o1] = is[instr.o2] + is[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_addf(Instr instr) {
    fs[instr.o1] = fs[instr.o2] + fs[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_subi(Instr instr) {
    is[instr.o1] = is[instr.o2] - is[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_subf(Instr instr) {
    fs[instr.o1] = fs[instr.o2] - fs[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_muli(Instr instr) {
    is[instr.o1] = is[instr.o2] * is[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_mulf(Instr instr) {
    fs[instr.o1] = fs[instr.o2] * fs[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_divi(Instr instr) {
    int d = is[instr.o3];
    if (d == 0) return DIV_ZERO;
    is[instr.o1] = is[instr.o2] / d;
    pc++;
    return OKAY;
}

StepResult run_divf(Instr instr) {
    float d = fs[instr.o3];
    if (d == 0.0) return DIV_ZERO;
    fs[instr.o1] = fs[instr.o2] / d;
    pc++;
    return OKAY;
}

StepResult run_widf(Instr instr) {
    fs[instr.o1] = (float) is[instr.o2];
    pc++;
    return OKAY;
}

StepResult run_oror(Instr instr) {
    is[instr.o1] = is[instr.o2] || is[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_equi(Instr instr) {
    is[instr.o1] = is[instr.o2] == is[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_equf(Instr instr) {
    is[instr.o1] = fs[instr.o2] == fs[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_equs(Instr instr) {
    char *l = get_string(st, is[instr.o2]);
    char *r = get_string(st, is[instr.o3]);
    is[instr.o1] = ( strcmp(l, r) == 0 );
    pc++;
    return OKAY;
}

StepResult run_lthi(Instr instr) {
    is[instr.o1] = is[instr.o2] < is[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_lthf(Instr instr) {
    is[instr.o1] = fs[instr.o2] < fs[instr.o3];
    pc++;
    return OKAY;
}

StepResult run_lths(Instr instr) {
    char *l = get_string(st, is[instr.o2]);
    char *r = get_string(st, is[instr.o3]);
    is[instr.o1] = ( strcmp(l, r) < 0 );
    pc++;
    return OKAY;
}

StepResult run_jump(Instr instr) {
    pc = instr.o1;
    return OKAY;
}

StepResult run_botb(Instr instr) {
    if (is[instr.o1] == 1) {
        pc += instr.o2;
    } else {
        pc++;
    }
    return OKAY;
}

StepResult run_bofb(Instr instr) {
    if (is[instr.o1] == 0) {
        pc += instr.o2;
    } else {
        pc++;
    }
    return OKAY;
}

StepResult run_ldwi(Instr instr) {
    int addr = instr.o2;
    if (addr < 0 || addr >= DATA_MEM_SIZE) return DMEM_ERR;
    is[instr.o1] = data_mem[addr].as_int;
    pc++;
    return OKAY;
}

StepResult run_ldwf(Instr instr) {
    int addr = instr.o2;
    if (addr < 0 || addr >= DATA_MEM_SIZE) return DMEM_ERR;
    fs[instr.o1] = data_mem[addr].as_float;
    pc++;
    return OKAY;
}

StepResult run_ldii(Instr instr) {
    is[instr.o1] = instr.o2;
    pc++;
    return OKAY;
}

StepResult run_ldif(Instr instr) {
    Word word;
    word.as_int = instr.o2; // The float was encoded as an int in the command.
    fs[instr.o1] = word.as_float; // Convert back to float.
    pc++;
    return OKAY;
}

StepResult run_stwi(Instr instr) {
    int addr = instr.o1;
    if (addr < 0 || addr >= DATA_MEM_SIZE) return DMEM_ERR;
    data_mem[addr].as_int = is[instr.o2];
    pc++;
    return OKAY;
}

StepResult run_stwf(Instr instr) {
    int addr = instr.o1;
    if (addr < 0 || addr >= DATA_MEM_SIZE) return DMEM_ERR;
    data_mem[addr].as_float = fs[instr.o2];
    pc++;
    return OKAY;
}

StepResult run_cats(Instr instr) {
    char *l = get_string(st, is[instr.o2]);
    char *r = get_string(st, is[instr.o3]);
    clear_str_buf();
    strcat(str_buf, l);
    strcat(str_buf, r);
    is[instr.o1] = add_string(st, str_buf);
    pc++;
    return OKAY;
}

StepResult run_b2ss(Instr instr) {
    clear_str_buf();
    is[instr.o2] == 0 ? sprintf(str_buf, "false") : sprintf(str_buf, "true");
    is[instr.o1] = add_string(st, str_buf);
    pc++;
    return OKAY;
}

StepResult run_i2ss(Instr instr) {
    clear_str_buf();
    sprintf(str_buf, "%d", is[instr.o2]);
    is[instr.o1] = add_string(st, str_buf);
    pc++;
    return OKAY;
}

StepResult run_r2ss(Instr instr) {
    clear_str_buf();
    sprintf(str_buf, "%f", fs[instr.o2]);
    is[instr.o1] = add_string(st, str_buf);
    pc++;
    return OKAY;
}

StepResult read_int(int x) {
    int integer;
    printf("read (int): ");
    scanf("%d", &integer);
    is[x] = integer;
    pc++;
    return OKAY;
}

StepResult read_real(int x) {
    float real;
    printf("read (real): ");
    scanf("%f", &real);
    fs[x] = real;
    pc++;
    return OKAY;
}

StepResult read_bool(int x) {
    int boolean;
    do {
        printf("read (bool - 0 = false, 1 = true): ");
        scanf("%d", &boolean);
    } while (boolean != 0 && boolean != 1);
    is[x] = boolean;
    pc++;
    return OKAY;
}

StepResult read_str(int x) {
    printf("read (str): ");
    clear_str_buf();
    scanf("%s", str_buf);   // Did anyone say Buffer Overflow..? ;P
    is[x] = add_string(st, str_buf);
    pc++;
    return OKAY;
}

StepResult write_int(int x) {
    printf("%d\n", is[x]);
    pc++;
    return OKAY;
}

StepResult write_real(int x) {
    printf("%f\n", fs[x]);
    pc++;
    return OKAY;
}

StepResult write_bool(int x) {
    is[x] == 0 ? printf("false\n") : printf("true\n");
    pc++;
    return OKAY;
}

StepResult write_str(int x) {
    clear_str_buf();
    escape_str(get_string(st, is[x]), str_buf);
    printf(str_buf);
    pc++;
    return OKAY;
}

StepResult run_call(Instr instr) {
    switch(instr.o1) {
        case 0: return read_int(instr.o2);
        case 1: return read_real(instr.o2);
        case 2: return read_bool(instr.o2);
        case 3: return read_str(instr.o2);
        case 4: return write_int(instr.o2);
        case 5: return write_real(instr.o2);
        case 6: return write_bool(instr.o2);
        case 7: return write_str(instr.o2);
        default:
            fprintf(stderr, "ERROR: Invalid code in CALL!\n");
            return HALTED;
    }
}

// #define TRACE

StepResult step() {
    if (pc < 0 || pc >= INSTR_MEM_SIZE) return IMEM_ERR;

    #ifdef TRACE
        //dump_iregs();
        printf("TRACE: Next instruction is - ");
        write_instruction(pc);
    #endif

    Instr instr = instr_mem[pc];

    switch(instr.op) {
        case HALT: return run_halt(instr);
        case NOOP: return run_noop(instr);
        case ADDi: return run_addi(instr);
        case ADDf: return run_addf(instr);
        case SUBi: return run_subi(instr);
        case SUBf: return run_subf(instr);
        case MULi: return run_muli(instr);
        case MULf: return run_mulf(instr);
        case DIVi: return run_divi(instr);
        case DIVf: return run_divf(instr);
        case WIDf: return run_widf(instr);
        case OROR: return run_oror(instr);
        case EQUi: return run_equi(instr);
        case EQUf: return run_equf(instr);
        case EQUs: return run_equs(instr);
        case LTHi: return run_lthi(instr);
        case LTHf: return run_lthf(instr);
        case LTHs: return run_lths(instr);
        case JUMP: return run_jump(instr);
        case BOTb: return run_botb(instr);
        case BOFb: return run_bofb(instr);
        case LDWi: return run_ldwi(instr);
        case LDWf: return run_ldwf(instr);
        case LDIi: return run_ldii(instr);
        case LDIf: return run_ldif(instr);
        case STWi: return run_stwi(instr);
        case STWf: return run_stwf(instr);
        case CATs: return run_cats(instr);
        case B2Ss: return run_b2ss(instr);
        case I2Ss: return run_i2ss(instr);
        case R2Ss: return run_r2ss(instr);
        case CALL: return run_call(instr);
        default:
            fprintf(stderr, "ERROR: Unknown opcode: %d!\n", instr.op);
            return HALTED; // Dummy return, should not be reached.
    }
}

void run() {
    StepResult result;
    do {
        result = step();
    } while (result == OKAY);

    switch(result) {
        case HALTED:
            printf("HALTED: Execution finished!\n");
            break;
        case IMEM_ERR:
            fprintf(stderr, "ERROR: Invalid access to Instruction Memory!\n");
            break;
        case DMEM_ERR:
            fprintf(stderr, "ERROR: Invalid access to Data Memory!\n");
            break;
        case DIV_ZERO:
            fprintf(stderr, "ERROR: Division by zero!\n");
            break;
        default:
            fprintf(stderr, "ERROR: Fall-through in run..?\n");
    }
}

// ----------------------------------------------------------------------------
// Main -----------------------------------------------------------------------

//#define DEBUG

int main(void) {
    init_memory();
    st = create_str_table();
    read_program(); // From STDIN
    #ifdef DEBUG
        dump_program();
    #endif
    stdin = fopen(ctermid(NULL), "r"); // Reset STDIN so IN commands will work.
    run();
    fclose(stdin);
    free_str_table(st);
    return 0;
}
