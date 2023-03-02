segment code
..start:
        mov ax, dados
        mov ds, ax
        mov ax, pilha
        mov ss, ax
        mov sp, topo
l1:

        mov al, 10100110b
        mov dx, 319h
        out dx, al
        call    delay

        mov al, [endereco]
        mov dx, 318h
        out dx, al
        call    delay

        mov al, 00000111b
        mov dx, 319h
        out dx, al
        call    delay

        mov al, 00000110b
        out dx, al
        call    delay

        mov al, 10000110b
        out dx, al
        call    delay

        mov al, 10000100b
        out dx, al
        call    delay

        mov     dx,318h
        in      al,dx
        mov     [dadomem],al

        mov     al, 10000110b
        mov     dx,319h
        out     dx, al
        call    delay

        mov     al, 10100110b
        out     dx, al
        call    delay
        mov     ah,0bh
        int     21h
        cmp     al,0
        jne     sai
        jmp     l1

sai:
        mov     ah,01
        int     21h
        mov     ah,4ch
        int     21h

delay:
        mov     cx,100
del1:
        loop del1
        ret

segment dados
endereco      db      0xaa
dadomem       resb      1
segment pilha stack
resb 100h
topo:



