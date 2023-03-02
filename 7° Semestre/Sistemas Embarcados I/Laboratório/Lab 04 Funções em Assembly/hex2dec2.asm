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
     mov ax,num  ;input   
     call imprimenumero
     ; -----------------------SAIDA DO PROGRAMA----------------------
     mov ah,0X4c
     int 0X21
	 ; --------------------------SUBROTINAS--------------------------
	 imprimenumero:
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
		;------------------------------------------------------------
        push ax ; salva os registradores que serão alterados
		push bx
		push cx	
		push dx
		push di
		;------------------------------------------------------------
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
	     push ax
			   
		 mov bx,4
         sub bx,cx ; bx<-bx-cx		 
		 cmp bx,0  ; bx==0
		 je pula1
		 	mov cx,bx
			loop3: mov ax,30h
			       push ax
				   loop loop3 
		 
        pula1: mov cx,5		 
		loop2: pop ax			   
			   mov [di],al
			   inc di
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
     num EQU 0xffff
	 saida: db '00000',13,10,'$'
segment stack stack
     ; ------------------------DEF. PILHA---------------------------
     resb 256 ; definição da pilha com total de 256 bytes
stacktop: