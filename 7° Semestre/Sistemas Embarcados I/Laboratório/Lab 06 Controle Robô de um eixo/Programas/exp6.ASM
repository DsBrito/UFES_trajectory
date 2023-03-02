segment code
..start:
	; Inicializacao
        mov 	ax, data
        mov 	ds, ax
        mov 	ax, pilha
        mov 	ss, ax
        mov 	sp, topo
	; Zera todos os bits da porta 319h, inclusive 
	; o bit 7 para acertar direcao da porta 318h
        mov 	al, 0
        mov 	dx, 319h
        out 	dx, al
        mov byte [teste], 0  ; O motor já começa a se mover para a direita
volta:  mov     dx, 319h
        in      al, dx
        test    al, 4        ; Chave de fim de curso BRANCA inativa
        jz      esquerda 
        test    al, 1        ; Chave de fim de curso VERMELHA inativa
        jz      direita
        test    al, 2        ; PUSH BUTTON ativa
        jnz     sair
segue:
        and     byte[p1],3  ; Mantem os dois bits menos significativos de p1
        mov     al, [p1]
        mov     bx, fases
        xlatb               ; Usa al (p1) como offset (indice) na tabela de fases e retorna dado em al
        and     al, 0x1f
        mov     dx, 318h
        out     dx, al      ; Escreve na porta 318h
        call    delay       ; Pula para rotina que cria atraso
        cmp     byte[teste], 0
        je      decrementa
        jmp     incrementa
incrementa:
        inc     byte[p1]
        jmp     testatecla
decrementa:
        dec     byte[p1]
testatecla:        
        mov     ah, 0bh
        int     21h
        cmp     al, 0
		je		volta ; Se nenhuma tecla foi pressionada, repete programa
        mov 	ah, 08
		int 	21h
		cmp		al, 's'
        je      sair     ; Se tecla s foi pressionada, sai do programa
		cmp		al, 'e'
        je      esquerda  ; Se tecla e foi pressionada, motor deve se mover para a esquerda
		cmp		al, 'd'
        je      direita ; Se tecla d foi pressionada, motor deve se mover para a direita  
        jmp		volta 
direita:
        mov     byte[teste], 0
        jmp     segue
esquerda:
        mov     byte[teste], 1
        jmp     segue
sair:
        mov     dx, 318h
        xor     ax, ax
        out     dx, al
        mov     ah,4ch
        int     21h

delay:
		push	cx
        mov 	cx, 15		; Carrega o valor 3 no registrador cx (contador para loop)
del2:
        push 	cx			; Coloca cx na pilha para usa-lo em outro loop
        mov 	cx, 0		; Zera cx
del1:
        loop 	del1		; No loop del1, cx eh decrementado seguidamente ate que volte a ser zero
        pop 	cx			; Recupera cx da pilha
        loop 	del2		; No loop del2, cx eh decrementado seguidamente ate que seja zero
		pop		cx
        ret

segment data
fases db 1010b, 0110b, 0101b, 1001b					; Tabela de fases
p1 db 0									; Indice para tabela de fases motor1
teste db 0;
segment pilha stack
resb 100h
topo:

