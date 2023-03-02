segment code ; programa
..start:
; iniciar os registros de segmento DS e SS e o ponteiro de pilha SP
	; ds<-data
	mov ax,data
	mov ds,ax
	; ss<-stack
	mov ax,stack
	mov ss,ax
	; sp<-stacktop
	mov sp,stacktop
	;INICIO
	mov bx,three_chars
	mov ah,1
	int 21h ; função do dos de entrada de carcater. Retorna em AL
	dec	al
	mov	[bx],al
	inc	bx
	int	21h		
	dec	al
	mov	[bx],al
	inc	bx
	int	21h		
	dec	al
	mov	[bx],al
	;--------------------------------------------------------
	;PRINT
	;--------------------------------------------------------
	mov	dx,display_string
	;--------------------------------------------------------
	mov	ah,0x9 ;ah=9 - print string sub function
	int	21h
	; Terminar o programa e voltar para o sistema operacional
	mov	ah,0x4c ;terminate program sub function
	int 21h
	;--------------------------------------------------------		
segment data ; declaracao de variaveis e constantes
	CR equ 0x0d
	LF equ 0x0a
	display_string db CR,LF
	three_chars	resb 3
				db '$'
segment stack stack ; reserva de memoria para pilha
    resb 256
stacktop:

