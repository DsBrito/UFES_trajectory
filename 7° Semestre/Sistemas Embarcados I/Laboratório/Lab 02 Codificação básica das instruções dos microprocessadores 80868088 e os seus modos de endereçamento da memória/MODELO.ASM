segment code
	..start:
	; -----------------INICIAR DS, SS e SP-------------------------
	; ds<-data
	mov ax,data
	mov ds,ax
	; ss<-stack
	mov ax,stack
	mov ss,ax
	; sp<-stacktop
	mov sp,stacktop
	; --------------------CODIGO DO PROGRAMA-----------------------

	; --------------------SAIDA	DO PROGRAMA------------------------	
	mov ah,0X4c
	int 0X21
segment data
	; -----------------DEF. VAR,CONST E ALOCACAO-------------------

segment stack stack
	; ------------------------DEF. PILHA---------------------------
	resb 256 ; definição da pilha com total de 256 bytes
stacktop: