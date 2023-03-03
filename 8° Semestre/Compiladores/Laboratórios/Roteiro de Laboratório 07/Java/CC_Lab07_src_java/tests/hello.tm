; Basic Hello World program in TM ASM.
; store string
SSTR "Hello, world!\n"
LDIi 0, 0		; i0 <- 0
CALL 7, 0		; write str in @i0 to stdout
HALT
