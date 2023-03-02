segment code
..start:
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax
    mov sp,stacktop

        XOR     AX, AX
        MOV     ES, AX
        MOV     AX, [ES:int9*4];carregou AX com offset anterior
        MOV     [offset_dos], AX        ; offset_dos guarda o end. para qual ip de int 9 estava apontando anteriormente
        MOV     AX, [ES:int9*4+2]     ; cs_dos guarda o end. anterior de CS
        MOV     [cs_dos], AX
        CLI     
        MOV     [ES:int9*4+2], CS
        MOV     WORD [ES:int9*4],keyint
        STI
                
L1:
        mov     ax,[p_i]
        CMP     ax,[p_t]
        JE      L1
        inc     word[p_t]
        and     word[p_t],7
        mov     bx,[p_t]
        XOR     AX, AX
        MOV     AL, [bx+tecla]
        mov     [tecla_u],al
        MOV     BL, 16
        DIV     BL
        ADD     Al, 30h
        CMP     AL, 3Ah                                                                                              
        JB      continua
        ADD     AL, 07h

continua:        
        MOV     [teclasc], AL
        ADD     AH, 30h
        CMP     AH, 3Ah
        JB      continua1
        ADD     AH, 07h

continua1:
        MOV     [teclasc+1], AH
        MOV     DX,teclasc
        MOV     AH, 9 ;imprimir string dos
        int     21h
        CMP     BYTE [tecla_u], 81h
        JE      L2
        JMP     L1

L2:
        CLI
        XOR     AX, AX
        MOV     ES, AX
        MOV     AX, [cs_dos]
        MOV     [ES:int9*4+2], AX
        MOV     AX, [offset_dos]
        MOV     [ES:int9*4], AX 
        MOV     AH, 4Ch
        int     21h


keyint:
        PUSH    AX
        push    bx
        push    ds
        mov     ax,data
        mov     ds,ax
        IN      AL, kb_data
        inc     WORD [p_i]
        and     WORD [p_i],7
        mov     bx,[p_i]
        mov     [bx+tecla],al
        IN      AL, kb_ctl
        OR      AL, 80h
        OUT     kb_ctl, AL
        AND     AL, 7Fh
        OUT     kb_ctl, AL
        MOV     AL, eoi
        OUT     pictrl, AL
        pop     ds
        pop     bx
        POP     AX
        IRET

segment data
        kb_data EQU 60h  ;PORTA DE LEITURA DE TECLADO
        kb_ctl  EQU 61h  ;PORTA DE RESET PARA PEDIR NOVA INTERRUPCAO
        pictrl  EQU 20h
        eoi     EQU 20h
        int9    EQU 9h
        cs_dos  DW  1
        offset_dos  DW 1
        tecla_u db 0
        tecla   resb  8 
        p_i     dw  0   ;ponteiro p/ interrupcao (qnd pressiona tecla)  
        p_t     dw  0   ;ponterio p/ interrupcao ( qnd solta tecla)    
        teclasc DB  0,0,13,10,'$'
segment stack stack
    resb 256
stacktop:

