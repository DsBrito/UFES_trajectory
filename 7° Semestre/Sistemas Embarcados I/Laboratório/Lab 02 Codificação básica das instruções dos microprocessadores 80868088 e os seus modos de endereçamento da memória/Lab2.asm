segment code
..start:
; iniciar os registros de segmento DS e SS e o ponteiro de pilha SP
	mov ax,data
	mov ds,ax
	mov ax,stack
	mov ss,ax
	mov sp,stacktop
	mov ah,9
	mov dx,mensagem
	int 21h
; Terminar o programa e voltar para o sistema operacional
	mov ah,4ch
	int 21h
segment data
	CR equ 0x0d
	LF equ 0x0a
	mensagem db 'Oi, olha eu aqui',CR,LF,'$'
segment stack stack
	resb 256
stacktop: