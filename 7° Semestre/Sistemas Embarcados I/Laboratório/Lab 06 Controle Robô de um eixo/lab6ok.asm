segment code
..start:
	; Inicializacao
	mov     ax, data
	mov     ds, ax 
	mov     ax, pilha
	mov     ss, ax
	mov     sp, topo
	; Zera todos os bits da porta 319h, inclusive 
	; o bit 7 para acertar direcao da porta 318h
	mov     al, 0
	mov     dx, 319h
	out     dx, al
	mov byte [teste], 0  ; O motor já começa a se mover para a direita
volta:  mov     dx, 319h
	in      al, dx
	test    al, 4        ; Chave de fim de curso BRANCA inativa
	jz      esq
	test    al, 1        ; Chave de fim de curso VERMELHA inativa
	jz      dir
	test    al, 2        ; PUSH BUTTON ativa
	jnz     vaza
	jmp		verifica
esq:
	jmp		esquerda
dir:	
	jmp 	direita
vaza:
	jmp		sair
verifica:
	cmp 	byte[b1],1
	je		ligado
segue:
	mov		byte[b1],0
	and     byte[p1],3  ; Mantem os dois bits menos significativos de p1
	mov     al, [p1]
	mov     bx, fasesoff; sequencia de led desligado
	xlatb               ; Usa al (p1) como offset (indice) na tabela de fases e retorna dado em al
	jmp 	cont
ligado:
	mov 	byte[b1],1
	and     byte[p1],3  ; Mantem os dois bits menos significativos de p1
	mov     al, [p1]
	mov     bx, faseson ; sequencia de led ligado
	xlatb               ; Usa al (p1) como offset (indice) na tabela de fases e retorna dado em al
cont:
	and     al, 00011111b	
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
		je              volta ; Se nenhuma tecla foi pressionada, repete programa
	mov     ah, 08
		int     21h
		cmp             al, 's'
	je      sair     ; Se tecla s foi pressionada, sai do programa
		cmp             al, 'e'
	je      esquerda  ; Se tecla e foi pressionada, motor deve se mover para a esquerda
		cmp             al, 'd'
	je      direita ; Se tecla d foi pressionada, motor deve se mover para a direita
		cmp				al, 'o'
	je		ligado
		cmp				al, 'i'
	je		segue
	jmp             volta
direita:
	mov     byte[teste], 0
	cmp		byte[b1],1
	je		ligado
	jmp     segue
esquerda:
	mov     byte[teste], 1
	cmp		byte[b1],1
	je		ligado
	jmp     segue
sair:
	mov     dx, 318h
	xor     ax, ax
	out     dx, al
	mov     ah,4ch
	int     21h

delay:
	push    cx
	mov     cx, 3          ; Carrega o valor 3 no registrador cx (contador para loop)
	del2:
		push    cx                      ; Coloca cx na pilha para usa-lo em outro loop
		mov     cx, 0           ; Zera cx
	del1:
		loop    del1            ; No loop del1, cx eh decrementado seguidamente ate que volte a ser zero
		pop     cx                      ; Recupera cx da pilha
		loop    del2            ; No loop del2, cx eh decrementado seguidamente ate que seja zero
	pop             cx
	ret

segment data
faseson db 01010b, 00110b, 00101b, 01001b                                     ; Tabela de fases
fasesoff db 11010b, 10110b, 10101b, 11001b									  	
p1 db 0                                                                 ; Indice para tabela de fases motor1
teste db 0;
b1 db 0
segment pilha stack
resb 100h
topo:

