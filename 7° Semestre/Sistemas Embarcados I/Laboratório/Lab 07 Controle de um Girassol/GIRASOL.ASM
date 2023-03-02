segment code
..start:
	; Inicializacao
        mov ax, data
        mov ds, ax
        mov ax, pilha
        mov ss, ax
        mov sp, topo
	; Zera todos os bits da porta 319h, inclusive 
	; o bit 7 para acertar direcao da porta 318h
        mov al, 0
        mov dx, 319h
        out dx, al

L1:     mov dx, 319h 
        in al, dx		; Le a porta 319h onde estao conectados os sensores
        and al, 00001111b	; Deixa em al somente os ultimos 4 bits (QC3C2C1)
        mov bx, decisao
        xlatb			; Usa al (QC3C2C1) como offset (indice) na tabela de decisao e retorna dado em al
        test al, 00001000b	; Testa primeiro bit de saida da tabela de decisao para o motor2
        ;m2 move
        jz testa_m1		; Se for zero, motor2 nao move
        test al, 00000100b	; Se for um, testa direcao (segundo bit do motor2)
        jz m2cw			; Se for zero, gira horario
        dec byte[p2]		; Se um: para girar anti-horario, decrementa p2 (indice da tabela de fases para motor2)
        jmp testa_m1		; Vai para teste motor1
m2cw:   inc byte[p2]		; Para girar horario, incrementa p2
testa_m1:
        test al, 10b		; Separa primeiro da saida da tabela de decisao para motor 1
        jz ajusta_ponteiros	; Se for zero, motor1 nao move
        ; m1 move
        test al, 1b		; Se for um, testa direcao (segundo bit motor1)
        jz m1cw			; Se zero, gira horario
        dec byte[p1]		; Se um: para girar anti-horario, decrementa p1 (indice da tabela de fases para motor1)
        jmp ajusta_ponteiros	; Vai para ajusta_ponteiros (escrever saidas na porta 318h)
m1cw:
        inc byte[p1]		; Para girar horario, incrementa p1
ajusta_ponteiros:
        and byte[p1],3		; Mantem os dois bits menos significativos de p1
        and byte[p2],3		; Mantem os dois bits menos significativos de p2
        mov al, [p1]		
        mov bx, fases
        xlatb			; Usa al (p1) como offset (indice) na tabela de fases e retorna dado em al
        mov cl, 4
        shl al, cl		; Desloca para esquerda os 4 bits lidos para o motor1
        mov cl, al		; Faz copia de al 
        mov al, [p2]		
        xlatb			; Usa al (p2) como offset (indice) na tabela de fases e retorna dado em al
        or al, cl		; Une dados para motor1 (A7-A4) com dados para motor2 (A3-A0)
        mov dx, 318h
        out dx, al		; Escreve na porta 318h
        call delay		; Pula para rotina que cria atraso
        mov     ah,0bh		
        int     21h		; Le buffer de teclado
        cmp     al,0
        jne     sai		; Se alguma tecla foi pressionada, finaliza programa
        jmp L1			; Se nenhuma tecla foi pressionada, repete programa
sai:
        mov     ah,4ch
        int     21h

delay:
        mov cx, 3		; Carrega o valor 3 no registrador cx (contador para loop)
del2:
        push cx			; Coloca cx na pilha para usa-lo em outro loop
        mov cx, 0		; Zera cx
del1:
        loop del1		; No loop del1, cx eh decrementado seguidamente ate que volte a ser zero
        pop cx			; Recupera cx da pilha
        loop del2		; No loop del2, cx eh decrementado seguidamente ate que seja zero
        ret

segment data
fases db 1010b, 0110b, 0101b, 1001b					; Tabela de fases
decisao db 1100b, 0011b, 1010b, 1000b, 1110b, 1100b, 0010b, 0000b	; Tabela de decisao
        db 1000b, 0010b, 1011b, 1000b, 1111b, 1100b, 0011b, 0000b
p1 db 0									; Indice para tabela de fases motor1
p2 db 0									; Indice para tabela de fases motor2

segment pilha stack
resb 100h
topo:



