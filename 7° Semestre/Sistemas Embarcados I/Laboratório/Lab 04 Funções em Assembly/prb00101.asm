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
segment data
     ; -----------------DEF. VAR,CONST E ALOCACAO-------------------
     NUMMAXFIB equ 0x8000
	 mensini: db 'Programa que calcula a Serie de Fibonacci. ',13,10,'$' 
     mensfim: db 'bye',13,10,'$' 
     saida:   db '00000',13,10,'$'
segment stack stack
     ; ------------------------DEF. PILHA---------------------------
     resb 256 ; definição da pilha com total de 256 bytes
stacktop: