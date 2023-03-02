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
	 mov bx,strIn
	 mov ah,1
	 int 21h
	 mov byte[bx+2],al
	 int 21h
	 mov byte[bx+3],al
	 int 21h
	 mov byte[bx+4],al	 
	 mov dx, strIn
     mov ah, 0x09
     int 21h
     ; -----------------------SAIDA DO PROGRAMA----------------------
	 mov ah,0X4c
     int 0X21
segment data
     ; -----------------DEF. VAR,CONST E ALOCACAO-------------------
     LF EQU  0x0A ;caracter Line Feed como LF
     CR EQU  0x0D ;caracter Carriage return como CR
	 strIn DB CR,LF
	       RESB 3
	       DB '$'   
segment stack stack
     ; ------------------------DEF. PILHA---------------------------
     resb 256 ; definição da pilha com total de 256 bytes
stacktop: