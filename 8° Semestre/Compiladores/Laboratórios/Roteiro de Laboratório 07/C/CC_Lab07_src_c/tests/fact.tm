; This program reads an integer and output its factorial.

LDIi 0, 0       ; i0 <- 0
LDIi 1, 1       ; i1 <- 1
LDIi 2, 2       ; i2 <- 2
CALL 0, 3       ; i3 <- read int from stdin
LTHi 4, 3, 2    ; i4 <- i3 < i2
LDIi 5, 1       ; i5 <- 1
BOTb 4, 5       ; jump 5 instructions ahead if i3 < i2
MULi 5, 5, 3    ; i5 <- i5 * i3
SUBi 3, 3, 1    ; i3 <- i3 - i1
EQUi 6, 3, 0    ; i6 <- i3 == i0
BOFb 6, -3      ; jump 3 instructions back if i3 == i0
CALL 4, 5       ; stdout <- i5
HALT
