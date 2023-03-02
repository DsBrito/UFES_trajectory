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
     mov dx,mensini  ; mensagem de inicio 
     mov ah,9 
     int 21h 
     mov ax,0  ; AX<-x[-1] : primeiro elemento da série 
     mov bx,1  ; BX<-x[0]  : segundo elemento da série 
     L10: 
        mov dx,ax  ;DX<-x[-1]
        add dx,bx  ;DX<-x[-1]+x[0] calcula novo elemento da série 
        mov ax,bx  ;AX<-x[0]
        mov bx,dx  ;BX<-x[1]
		call imprimenumero
        cmp dx,NUMMAXFIB ;DX < NUMMAXFIB 
        jb  L10 
     ; -----------------------SAIDA DO PROGRAMA----------------------
     exit:
        mov dx,mensfim      ; mensagem de fim 
        mov ah,9 
        int 21h 
     quit: 
        mov ah,0x4c      ; retorna para o DOS com código 0 
        int 0x21 
	 ; --------------------------SUBROTINAS--------------------------
	 imprimenumero:
	 	; Recibe:  saida : string de caracteres
		;------------------------------------------------------------
        push ax ; salva os registradores que serão alterados
		push dx
		push di
		;------------------------------------------------------------
		mov di,saida
        call hex2ascii   
        ;print saida
        mov dx,saida
        mov ah,9
        int 21h 
		;------------------------------------------------------------
		pop di ; recupera registradores		
		pop dx
		pop ax
  	    ;-----------------------------------------------------------
        ret	 
	 hex2ascii:
	    ; Recibe:  DX : o numero HEX a convertir em uma string de ASCII  
        ; Retorna: DI : aponta à string de caracteres "saida"
		;------------------------------------------------------------
        push ax ; salva os registradores que serão alterados
		push bx
		push cx	
		push dx
		push di
		;------------------------------------------------------------
  	    mov ax,dx
		mov cx,0
        mov bx,10   
		loop1: mov dx,0
			   div bx      ; ax<-q(ax/bx)  dx<-r(ax/bx)
			   add dl,30h  ; dl<-dl+30h
			   push dx
			   inc cx	
			   cmp ax,9
			   jg loop1    ; ax>9
		 
	     add al,30h
	     mov [di],al
			 
		loop2: pop ax
			   inc di
			   mov [di],al
			   loop loop2
		;------------------------------------------------------------
		pop si ; recupera registradores		
		pop dx
		pop cx
		pop bx
		pop ax		
  	    ;-----------------------------------------------------------
        ret
segment data
     ; -----------------DEF. VAR,CONST E ALOCACAO-------------------
     NUMMAXFIB equ 0xF
	 mensini: db 'Programa que calcula a Serie de Fibonacci. ',13,10,'$' 
     mensfim: db 'bye',13,10,'$' 
     saida:   db '00000',13,10,'$'
segment stack stack
     ; ------------------------DEF. PILHA---------------------------
     resb 256 ; definição da pilha com total de 256 bytes
stacktop: