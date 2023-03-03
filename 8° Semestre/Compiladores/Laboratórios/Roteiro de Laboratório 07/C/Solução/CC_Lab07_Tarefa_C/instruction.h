
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

// Basic arch: 32 int registers and 32 float registers.
#define INT_REGS_COUNT   32     // i0 to i31: int registers.
#define FLOAT_REGS_COUNT 32     // f0 to f31: float registers.
// The machine also has a dedicated program counter (PC) register.

// Memory is split between data and instruction memory.
// This is called the Harvard architecture, in contrast to the von Neumann
// (stored program) architecture.
#define INSTR_MEM_SIZE  1024    // instr_mem[]
#define DATA_MEM_SIZE   1024    // data_mem[]
// The machine also has a string table str_tab[] for storing strings with
// the command SSTR. Maximum size for each string is 128 chars.

// Opcodes.
typedef enum {
    // Basic ops
    HALT,
    NOOP,

    // Arith ops
    ADDi,           // ADDi ix, iy, iz      ; ix <- iy + iz
    ADDf,           // ADDf fx, fy, fz      ; fx <- fy + fz
    SUBi,           // SUBi ix, iy, iz      ; ix <- iy - iz
    SUBf,           // SUBf fx, fy, fz      ; fx <- fy - fz
    MULi,           // MULi ix, iy, iz      ; ix <- iy * iz
    MULf,           // MULf fx, fy, fz      ; fx <- fy * fz
    DIVi,           // DIVi ix, iy, iz      ; ix <- iy / iz
    DIVf,           // DIVf fx, fy, fz      ; fx <- fy / fz
        // Widen to float
    WIDf,           // WIDf fx, iy          ; fx <- (float) iy

    // Logic ops
        // Logical OR
    OROR,            // OROR ix, iy, iz     ; ix <- (bool) iy || (bool) iz
        // Equality
    EQUi,            // EQUi ix, iy, iz     ; ix <- iy == iz ? 1 : 0
    EQUf,            // EQUf ix, fy, fz     ; ix <- fy == fz ? 1 : 0
    EQUs,            // EQUs ix, iy, iz     ; ix <- str_tab[iy] == str_tab[iz] ? 1 : 0
        // Less than
    LTHi,            // LTHi ix, iy, iz     ; ix <- iy < iz ? 1 : 0
    LTHf,            // LTHi ix, fy, fz     ; ix <- iy < iz ? 1 : 0
    LTHs,            // LTHs ix, iy, iz     ; ix <- str_tab[iy] < str_tab[iz] ? 1 : 0

    // Branches and jumps
        // Absolute jump
    JUMP,           // JUMP addr            ; PC <- addr
        // Branch on true
    BOTb,           // BOTb ix, off         ; PC <- PC + off, if ix == 1
        // Branch on false
    BOFb,           // BOFb ix, off         ; PC <- PC + off, if ix == 0

    // Loads and stores
        // Load word (from address)
    LDWi,           // LDWi ix, addr        ; ix <- data_mem[addr]
    LDWf,           // LDWf fx, addr        ; fx <- data_mem[addr]
        // Load immediate (constant)
    LDIi,           // LDIi ix, int_const   ; ix <- int_const
    LDIf,           // LDIf fx, float_const ; fx <- float_const (must be inside an int)
        // Store word (to address)
    STWi,           // STWi addr, ix        ; data_mem[addr] <- ix
    STWf,           // STWf addr, fx        ; data_mem[addr] <- fx

    // Strings
    // (These strings instructions are obviously not present in real archs.
    //  The rationale for creating and using them here is simply for convenience:
    //  Normally, these are handled by a low level language lib or OS system call
    //  such as those present in 'libc', etc. However, involving real OS interfaces
    //  here will complicate the game considerably. Thus, we cheat by creating
    //  this high level interface for string handling.)
        // Store string
    SSTR,           // SSTR str_const       ; str_tab <- str_const
        // Catenate
    CATs,           // CATs ix, iy, iz      ; str_tab[ix] <- str_tab[iy] + str_tab[iz]
        // Bool to String
    B2Ss,           // B2Ss ix, iy          ; ix <- @str_tab <- register iy (as str)
        // Integer to String
    I2Ss,           // I2Ss ix, iy          ; ix <- @str_tab <- register iy (as str)
        // Real to String
    R2Ss,           // R2Ss ix, fy          ; ix <- @str_tab <- register fy (as str)

    // System calls, for I/O (see below)
    CALL            // CALL code, x
} OpCode;

// CALL (very basic simulation of OS system calls)
//   . code: sets the operation to be called.
//   . x: register involved in the operation.
// List of calls:
// ----------------------------------------------------------------------------
// code | x  | Description
// ----------- -----------------------------------------------------------
//  0   | ix | Read int:   register ix <- int  from stdin
//  1   | fx | Read real:  register fx <- real from stdin
//  2   | ix | Read bool:  register ix <- bool from stdin (as int)
//  3   | ix | Read str:   str_tab[ix] <- str from stdin
//  4   | ix | Write int:  stdout <- register ix (as str)
//  5   | fx | Write real: stdout <- register fx (as str)
//  6   | ix | Write bool: stdout <- register ix (as str)
//  7   | ix | Write str:  stdout <- str_tab[ix]
// ----------------------------------------------------------------------------
// OBS.: All strings in memory are null ('\0') terminated, like in C.
// ----------------------------------------------------------------------------

// String representations of opcodes.
static char* OpStr[] = {
    "HALT", "NOOP",
    "ADDi", "ADDf", "SUBi", "SUBf", "MULi", "MULf", "DIVi", "DIVf", "WIDf",
    "OROR", "EQUi", "EQUf", "EQUs", "LTHi", "LTHf", "LTHs",
    "JUMP", "BOTb", "BOFb",
    "LDWi", "LDWf", "LDIi", "LDIf", "STWi", "STWf",
    "SSTR", "CATs", "B2Ss", "I2Ss", "R2Ss",
    "CALL"
};

// Number of arguments for each opcode.
static int OpCount[] = {
    0,  // HALT
    0,  // NOOP
    3,  // ADDi
    3,  // ADDf
    3,  // SUBi
    3,  // SUBf
    3,  // MULi
    3,  // MULf
    3,  // DIVi
    3,  // DIVf
    2,  // WIDf
    3,  // OROR
    3,  // EQUi
    3,  // EQUf
    3,  // EQUs
    3,  // LTHi
    3,  // LTHf
    3,  // LTHs
    1,  // JUMP
    2,  // BOTb
    2,  // BOFb
    2,  // LDWi
    2,  // LDWf
    2,  // LDIi
    2,  // LDIf
    2,  // STWi
    2,  // STWf
    1,  // SSTR
    3,  // CATs
    2,  // B2Ss
    2,  // I2Ss
    2,  // R2Ss
    2,  // CALL
};

// Instruction quadruple.
typedef struct {
    OpCode op;
    int o1;     // Operands, which can be int or float registers,
    int o2;     // int addresses or offsets, or
    int o3;     // integer or float constants (must be in an integer repr.)
} Instr;

#endif
