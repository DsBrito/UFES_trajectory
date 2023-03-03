#ifndef CODE_H
#define CODE_H

#include "ast.h"

// Traverses the given AST and emits the corresponding TM ASM code to STDOUT.
void emit_code(AST *ast);

#endif
