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
     ;mov al,0010b
     mov al,1001b
	 ;IF(bit 4 AL é 1)
	 test al, 1000b ;AL AND 1000b
     jnz bit4Ativo
     ;ELSEIF(bit 3 AL é 0)
	 test al, 0100b ;AL AND 0100b
     jz bit3Inativo  
	 jmp sair
     ;THEN1
     bit4Ativo: mov dx,stringBit4Ativo
			    jmp fim	 
	 ;THEN2
     bit3Inativo: mov dx,stringBit3Inativo
  	              jmp fim	 		  			  
     fim: mov ah,0x9
		  int 21h
; -----------------------SAIDA DO PROGRAMA----------------------
     sair: mov ah,0X4c
           int 0X21
segment data
     ; -----------------DEF. VAR,CONST E ALOCACAO-------------------
     stringBit4Ativo   db 'bit 4 ativo',13,10,'$'
     stringBit3Inativo db 'bit 3 nao ativo',13,10,'$'	 
segment stack stack
     ; ------------------------DEF. PILHA---------------------------
     resb 256 ; definição da pilha com total de 256 bytes
stacktop: