;-----------------------------------------------------------------------------------;
;           SISTEMAS EMBARCADOS I - ELE 8575 - 2022/01 – DEL – CT – UFES            ;
;                           Projeto de Laboratório (PL)                             ;
;                                                                                   ;
;-----------------------------------------------------------------------------------;
;                           PROJETO DE LABORATÓRIO                                  ;
;                                                                                   ;
; Autor: DIONATAS SANTOS BRITO                                                      ;
; Turma: 0.5.1                                                                      ;
;-----------------------------------------------------------------------------------;
;Descrição:                                                                         ;
;       Deseja-se implementar um jogo de Ping Pong                                  ;
;                                                                                   ; 
;       Regras:                                                                     ;    
;                                                                                   ;    
;       1) Tamanho da Raquete deve ser uma reta de 50 pixels.                       ;
;       2) Movimentaçãoda bolinha apenas na vertical e com as teclas “u” e “d”      ;
;          para deslocar a raquete para cima e para baixo.                          ;                                
;       4) Velocidade da bolinha deve ser controlada pelas teclas “+” e “-“,        ;
;          do teclado numérico.                                                     ;
;       5) Cor da bola deve ser vermelha.                                           ;                    
;       6) Todas as vezes em que o jogador consegue rebater a bola,                 ;
;          deve-se adicionar 1 ponto ao placar do jogador.                          ;
;       7) Caso o jogador não consiga rebater a bola e ela se choca com a lateral   ;  
;          direita da tela, deve-se adicionar 1 ponto ao placar do computador.      ;
;       8) Implemente um placar de dois dígitos para contabilizar a pontuação.      ;
;       9) Para sair do jogo, deve-se pressionar a tecla “Esc”.                     ;
;       10) O fundo de tela deve ser na cor preta e as linhas na cor branca.        ;
;       11) Toda a leitura de teclas deve ser feita, por interrupção de hardware,   ;
;           tomando-se como base o programa “tecbuf.asm”                            ;
;       12) Deve ser implementado 5 diferentes velocidades da bolinha.              ;
;       13)O jogo deve ser iniciado na velocidade mais baixa.                       ;
;                                     												;
;                                                                                  	; 
;       Tabela 1:         Tabela de Cores modo VGA 640×480                          ;
;                            Preto 0    ~   Cinza 8                                 ;
;                            Azul 1     ~   Azul_claro 9                            ;
;                            Verde 2    ~   Verde_claro 10                          ;
;                            Cyan 3     ~   Cyan_claro 11                           ;
;                            Vermelho 4 ~   Rosa 12                                 ;
;                            Magenta 5  ~   Magenta_claro 13                        ;
;                            Marrom 6   ~   Amarelo 14                              ;
;                            Branco 7   ~   Branco_intenso 15                       ;
;                                                                                   ;
;      Para facilitar a programação, use o programa LINEC.ASM e TECBUF.ASM          ;
;                                                                                   ;
;-----------------------------------------------------------------------------------;

;-----------------------------------------------------------------------------------;
;                   {INICIALIZANDO O PROGRAMA}                                      ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve iniciar o Segment code como foi visto no laboratório                   ;                                                  
;   -2) deve salvar o modo corrente de video                                        ;
;   -3) deve alterar o modo de video para gráfico (640 x 480)   					;
;	-4) deve reprogramar a tabela de interrupção				                    ;
;-----------------------------------------------------------------------------------;
; FONTE: retirado do arquivo line.asm                                               ;
;-----------------------------------------------------------------------------------;

;-----------------------------------------------------------------------------------;
;                       Segment Code                                                ;    
;-----------------------------------------------------------------------------------;
segment code
..start:
                        
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax
    mov sp,stacktop
;-----------------------------------------------------------------------------------;
;                Reprogramando a tabela de Interrupção                              ;    
;																					;
; Comentários:                                                                      ;
;   -1) deve carregar o AX com o offset anterior		                            ;
;	-2) deve guardar o endereço para qual ip de int 9 estava apontando anteriormente;
;	-3) deve guardar o endereço anterior de CS										;
;-----------------------------------------------------------------------------------;	
; FONTE: baseado no tecbuf.asm								                        ;
;-----------------------------------------------------------------------------------;	
	CLI

	XOR     AX, AX
	MOV     ES, AX

	MOV     AX, [ES:int9*4]
	MOV     [offset_dos], AX       
	MOV     AX, [ES:int9*4+2]   
	MOV     [cs_dos], AX	
	
	MOV     [ES:int9*4+2], CS
	MOV     WORD [ES:int9*4],keyint

	
;-----------------------------------------------------------------------------------;
;                Salvando Modo Corrent de video                                     ;    
;-----------------------------------------------------------------------------------;
; FONTE: baseado no line.asm  								                        ;
;-----------------------------------------------------------------------------------;
    mov ah,0Fh                            
    int 10h
    mov [modo_anterior],al                                                      
                                                                       
;-----------------------------------------------------------------------------------;
;    Alterando Modo de video para Grafico 640x480 em 16 core                        ;    
;-----------------------------------------------------------------------------------;
; FONTE: baseado no line.asm  								                        ;
;-----------------------------------------------------------------------------------;
    mov al,12h                           
    mov ah,0
    int 10h

;-----------------------------------------------------------------------------------;
;       Inicialização da Interface Gráfica do Programa                              ; 
;                                                                                   ;   
; Comentários:                                                                      ;
;   -1) deve iniciar a interface na cor branco_intenso                              ;
;-----------------------------------------------------------------------------------;
; FONTE: baseado no código que criei para o Exercício de Programação    			;
;-----------------------------------------------------------------------------------;
    mov byte[cor],branco_intenso ;mudando a cor

	call interface_placar	;chamando rotinas para criar a interface do programa
	call interface_bordas
    call interface_cabecalho
	mov	byte[cor],vermelho
    call interface_raquete
    call interface_bolinha


;-----------------------------------------------------------------------------------;
;          Loop Principal do Programa - Animação da raquete e bolinha               ;    
;																					;
; Comentários:                                                                      ;
;   -1) deve incrementar o modo_frame atual (como um contador de ciclos)            ;
;	-2) deve possibilitar o teste das teclas/funções por interrup´ção de hardware 	;
;	-3) deve animar a bolinha na tela (apagando e ascedendo)						;
;	-4) deve animar a raquete na tela 												;
;	-5) deve animar o movimento da raquete na tela									;
;		ajustando na posicao da raquete no eixo x e y								;
; 	-6) deve animar a colisão da raquete com a bolinha na tela						;
;	-7) deve utilizar a interrupção int 15h 										;
;-----------------------------------------------------------------------------------;	
; FONTE: baseado no tecbuf.asm								                        ;
;-----------------------------------------------------------------------------------;	
	animacao:
		inc		word[modo_pixel]
		call 	testateclaHardware
		;____________________
		;animação da bolinha 
		mov			byte[cor],preto
		call		interface_bolinha	;irá criar a interface da bolinha na tela
		call		raqueteMover		;irá mover a raquete na tela
		call		interface_raquete	;ira criar a interface da raquete na tela

		;____________________________________________________________
		;ajustando a posicao da raquete no eixo X e Y  (ajusta X e Y)
		mov			dx,[raquete_posicaoY]		
		cmp			dx,371
		jb			raqueteAjustaPosicaoX

		raqueteAjustaPosicaoY:
			call		raqueteAjusta		
		raqueteAjustaPosicaoX:
		;____________________________________________________
		; Deslocamento da posição da bola em x (decrementa X)
			xor			ax,ax
			mov			cx,[bola_movimento]
			mov			al,[bola_velocidadeX]
			inc			ax
			cmp			al,0
			jbe			bolaDecrementaX
			add			word[bola_posicaoX],cx
			jmp			bolaIncrementaY

		bolaDecrementaX:
			sub			word[bola_posicaoX],cx	
			
		;_________________________________________________________________
		; Deslocamento da posição da bola em y (incrementa e decrementa Y)
		bolaIncrementaY:
			xor			ax,ax
			mov			al,[bola_velocidadeY]
			cmp			al,0
			js			bolaDecrementaY
			add			word[bola_posicaoY],cx			
			jmp			colisaoBR
		bolaDecrementaY:
			sub			word[bola_posicaoY],cx
		;_______________________________________________
		; Tratamento de colisao com a raquete e bolinha
		colisaoBR:
			mov			byte[cor],vermelho
			call		interface_bolinha
			call		colisao
			call 		interface_placar
			call 		int_15h
			jmp			animacao




;-----------------------------------------------------------------------------------;	
;                           Divisórias da Interface                                 ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve usar a dimensão de pares ordenados(x0,y0) e (x1,y1),                   ;               
;       os pares devem estar entre x<639 e y<479                                    ;
;   -2) deve plotar os pares com a função line:                                     ;
;   -3) deve seguir o padrão de coordenadas:                                        ;
;        (0,479) e (639,479) <= linha da borda superior                             ;
;        (0,0) e (0,479)     <= linha da borda esquerda                             ;
;        (639,0) e (639,479) <= linha da borda direita                              ;
;        (0,0) e (639,0)     <= linha da borda inferior                             ;
;        (0,431) e (639,431)  <= linha da borda do meio  						    ;
;                                                                                   ;
;	-4) deve criar uma rotina para a borda da direita de modo separado 				;	
;		(somente após a criação da borda da direita anterior)						;
;-----------------------------------------------------------------------------------;
; FONTE: criação de linha baseado no Lab05 Programas Assembly(Animação modo gráfico);
;        e arquivo line.asm (rotina line)                                           ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;

    interface_bordas:
			
		;______________________________________________
		; Preparação para começar a desenhar as bordas 
		xor			ax,ax
		mov			cx,639
		mov			dx,479
		mov			byte[cor],branco_intenso

		;________________
		; Borda inferior 
		push		ax
		push		ax
		push		cx
		push		ax
		
		;________________
		; Borda direita 
		push		cx
		push		ax
		push		cx
		push		dx
				
		;________________
		; Borda superior 
		push		cx
		push		dx
		push		ax
		push		dx
				
		;________________
		; Borda esquerda 
		push		ax
		push		dx
		push		ax
		push		ax
				
		;_______________
		; Borda do meio 
		mov			dx,431
		push		ax
		push		dx
		push		cx
		push		dx

				
		;______________________
		; Desenhando as bordas
		call		line 
		call		line
		call		line
		call		line
		call		line
		ret


	interface_bordaDireita:	
		;_____________________
		; Salvando o contexto
		push		ax
		push		bx
		push		cx
		push		dx
		
		;______________________________________________
		; Preparação para começar a desenhar as bordas 
		xor			ax,ax
		mov			cx,639
		mov			dx,479
		mov			byte[cor],branco

		;____________________________
		; Desenhando a borda direita
		push		cx
		push		ax
		push		cx
		push		dx
		call		line 

		;________________________
		; Recuperando o contexto
		pop			dx
		pop			cx
		pop			bx
		pop			ax
		ret
;-----------------------------------------------------------------------------------;	
;                     Construtor de Linhas                       					;
;                                                                 					;
; Comentários:                                                    					;
;   -1) deve construir as linhas da interface                     					;
;-----------------------------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina line)                           					;
;-----------------------------------------------------------------------------------;	

	;
	;   fun��o line
	;
	; push x1; push y1; push x2; push y2; call line;  (x<639, y<479)
	line:
			push		bp
			mov		bp,sp
			pushf                        ;coloca os flags na pilha
			push 		ax
			push 		bx
			push		cx
			push		dx
			push		si
			push		di
			mov		ax,[bp+10]   ; resgata os valores das coordenadas
			mov		bx,[bp+8]    ; resgata os valores das coordenadas
			mov		cx,[bp+6]    ; resgata os valores das coordenadas
			mov		dx,[bp+4]    ; resgata os valores das coordenadas
			cmp		ax,cx
			je		line2
			jb		line1
			xchg		ax,cx
			xchg		bx,dx
			jmp		line1
	line2:		; deltax=0
			cmp		bx,dx  ;subtrai dx de bx
			jb		line3
			xchg		bx,dx        ;troca os valores de bx e dx entre eles
	line3:	; dx > bx
			push		ax
			push		bx
			call 		plot_xy
			cmp		bx,dx
			jne		line31
			jmp		fim_line
	line31:		inc		bx
			jmp		line3
	;deltax <>0
	line1:
	; comparar m�dulos de deltax e deltay sabendo que cx>ax
		; cx > ax
			push		cx
			sub		cx,ax
			mov		[deltax],cx
			pop		cx
			push		dx
			sub		dx,bx
			ja		line32
			neg		dx
	line32:		
			mov		[deltay],dx
			pop		dx

			push		ax
			mov		ax,[deltax]
			cmp		ax,[deltay]
			pop		ax
			jb		line5

		; cx > ax e deltax>deltay
			push		cx
			sub		cx,ax
			mov		[deltax],cx
			pop		cx
			push		dx
			sub		dx,bx
			mov		[deltay],dx
			pop		dx

			mov		si,ax
	line4:
			push		ax
			push		dx
			push		si
			sub		si,ax	;(x-x1)
			mov		ax,[deltay]
			imul		si
			mov		si,[deltax]		;arredondar
			shr		si,1
	; se numerador (DX)>0 soma se <0 subtrai
			cmp		dx,0
			jl		ar1
			add		ax,si
			adc		dx,0
			jmp		arc1
	ar1:		sub		ax,si
			sbb		dx,0
	arc1:
			idiv		word [deltax]
			add		ax,bx
			pop		si
			push		si
			push		ax
			call		plot_xy
			pop		dx
			pop		ax
			cmp		si,cx
			je		fim_line
			inc		si
			jmp		line4

	line5:		cmp		bx,dx
			jb 		line7
			xchg		ax,cx
			xchg		bx,dx
	line7:
			push		cx
			sub		cx,ax
			mov		[deltax],cx
			pop		cx
			push		dx
			sub		dx,bx
			mov		[deltay],dx
			pop		dx



			mov		si,bx
	line6:
			push		dx
			push		si
			push		ax
			sub		si,bx	;(y-y1)
			mov		ax,[deltax]
			imul		si
			mov		si,[deltay]		;arredondar
			shr		si,1
	; se numerador (DX)>0 soma se <0 subtrai
			cmp		dx,0
			jl		ar2
			add		ax,si
			adc		dx,0
			jmp		arc2
	ar2:		sub		ax,si
			sbb		dx,0
	arc2:
			idiv		word [deltay]
			mov		di,ax
			pop		ax
			add		di,ax
			pop		si
			push		di
			push		si
			call		plot_xy
			pop		dx
			cmp		si,dx
			je		fim_line
			inc		si
			jmp		line6

	fim_line:
			pop		di
			pop		si
			pop		dx
			pop		cx
			pop		bx
			pop		ax
			popf
			pop		bp
			ret		8   
				




;-----------------------------------------------------------------------------------;	
;                    				 Plot XY                     					;
;                                                                 					;
; Comentários:                                                    					;
;   -1) deve construir o plot XY da interface                     					;
;-----------------------------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina plot_xy)                           				;
;-----------------------------------------------------------------------------------;	
	;   fun��o plot_xy
	;
	; push x; push y; call plot_xy;  (x<639, y<479)
	; cor definida na variavel cor
	plot_xy:
			push		bp
			mov		bp,sp
			pushf
			push 		ax
			push 		bx
			push		cx
			push		dx
			push		si
			push		di
			mov     	ah,0ch
			mov     	al,[cor]
			mov     	bh,0
			mov     	dx,479
			sub		dx,[bp+4]
			mov     	cx,[bp+6]
			int     	10h
			pop		di
			pop		si
			pop		dx
			pop		cx
			pop		bx
			pop		ax
			popf
			pop		bp
			ret		4

;-----------------------------------------------------------------------------------;	
;                    		 Mensagem do Cabeçalho  								;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve criar mensagem para a disciplina, nome, versus, computador, velocidad  ;
;   -2) deve seguir o padrão de:                                                    ;
;                              "n" caractéres (cx)                                  ;
;                              "y" linha variando de 0-29 (dh)                      ;
;                              "x" coluna variando de 0-79 (dl)						;
;   -3) deve incrementar o caractere e a coluna em um loop "escreve_mensagem"       ;
;-----------------------------------------------------------------------------------;
; FONTE: baseado no aquivo line.asm (escrever uma mensagem),                        ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------; 	
	interface_cabecalho:

		;______________________________________________________________
		; Mensagem da Disciplina : 58 caractéres, linha 1 e coluna 12
		mensagem_disciplina:
			mov			byte[cor],branco
			mov			bx,msg_disciplina ; mensagem
			mov			cx,58			  ; 58 caractéres
			mov			dh,1			  ; 01 posição linha
			mov			dl,7			  ; 07 posição coluna
			call		escreve_mensagem

		;__________________________________________________________________
		; Mensagem da nome do player 1 : 21 caractéres, linha 2 e coluna 8
		mensagem_nome:
			mov			bx,msg_meunome ; mensagem
			mov			cx,21		   ; 21 caractéres
			mov			dh,2		   ; 02 posição linha
			mov			dl,8		   ; 08 posição coluna
			call		escreve_mensagem

		;_________________________________________________________
		; Mensagem da Versus : 03 caractéres, linha 2 e coluna 35
		mensagem_versus:
			mov			byte[cor],branco
			mov			bx,msg_versus	; mensagem
			mov			cx,3 			; 03 caractéres
			mov			dh,2  			; 02 posição linha
			mov			dl,35  			; 35 posição coluna
			call		escreve_mensagem
		;______________________________________________________________
		; Mensagem da Disciplina : 58 caractéres, linha 1 e coluna 12
		mensagem_computador:
			mov			bx,msg_computador
			mov			cx,11
			mov			dh,2
			mov			dl,44
			call		escreve_mensagem
		;_____________________________________________________________
		; Mensagem da Velocidade : 17 caractéres, linha 2 e coluna 56
		; Mensagem Número da velocidade:: 1 caractéres, linha 2, coluna 74 
		mensagem_velocidade:
			mov			bx,msg_velocidade	; mensagem
			mov			cx,17				; 17 caractéres
			mov			dh,2				; 02 posição linha
			mov			dl,56				; 56 posição coluna
			call		escreve_mensagem
			
		mensagem_nvelocidade:
			mov			byte[cor],branco_intenso
			mov			dh,2	;02 posição linha
			mov			dl, 74	;74 posição coluna
			mov			cx,1 	;01 caractéres
			mov			bx,msg_velocidadeV1	;mensagem
			call		escreve_mensagem

		ret		
	;_____________________________________________________________
	; Rotina que auxilia a escrita de mensagens
	escreve_mensagem:
		call		cursor
		mov     	al,[bx]
		call		caracter
		inc     	bx			;proximo caracter
		inc			dl			;avanca a coluna
		loop    	escreve_mensagem
		ret



;-----------------------------------------------------------------------------------;	
;                 Construtor de Cursor                           					;
;                                                                 					;
; Comentários:                                                    					;
;   -1) deve seguir o padrão de:                                  					;
;                 dh = linha (0-29)                               					;
;                 dl=coluna  (0-79)                               					;  
;-----------------------------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina cursor)                         					;
;-----------------------------------------------------------------------------------;
        cursor:
            pushf
            push ax
            push bx
            push cx
            push dx
            push si
            push di
            push bp
            mov ah,2
            mov bh,0
            int 10h
            pop bp
            pop di
            pop si
            pop dx
            pop cx
            pop bx
            pop ax
            popf
            ret

;-----------------------------------------------------------------------------------;	
;                 Construtor de Caracteres                        					;
;                                                                					;
; Comentários:                                                    					;
;   -1) deve escrever o caractere em al                           					;  
;   -2) deve corresponder a mesma cor da variavel cor             					;
;-----------------------------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina caracter)                       					;
;-----------------------------------------------------------------------------------;
	caracter:
        pushf
        push ax
        push bx
        push cx
        push dx
        push si
        push di
        push bp
        mov ah,9
        mov bh,0
		mov cx,1
        mov bl,[cor]
        int 10h
        pop bp
        pop di
        pop si
        pop dx
        pop cx
        pop bx
        pop ax
        popf
        ret	               

;-----------------------------------------------------------------------------------;	
;                            Interface da Bolinha                                   ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve ser passado a posição (x,y) e o raio da bolinha para algum registrador ;                                                   
;   -2) deve desenhar o circulo com a função full cicle                             ;
;-----------------------------------------------------------------------------------;
; FONTE: criação da bolinha baseado no Programas Assembly(Animação modo gráfico)	;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;
    interface_bolinha:
		mov			cx,[bola_posicaoX]
		push		cx
		mov			cx,[bola_posicaoY]
		push		cx
		mov			cx,bola_raio
		push		cx
		call		full_circle
		ret


;-----------------------------------------------------------------------------------;	
;                     Construtor de Circulos                      					;
;                                                              					   	;
; Comentários:                                                  				  	;
;   -1) deve construir as circulo da bolinha		           					   	;
;-----------------------------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina full_circle)                    					;
;-----------------------------------------------------------------------------------;	
;push xc; push yc; push r; call full_circle;  (xc+r<639,yc+r<479)e(xc-r>0,yc-r>0)
; cor definida na variavel cor					  
	full_circle:
		push 	bp
		mov	 	bp,sp
		pushf                        ;coloca os flags na pilha
		push 	ax
		push 	bx
		push	cx
		push	dx
		push	si
		push	di

		mov		ax,[bp+8]    ; resgata xc
		mov		bx,[bp+6]    ; resgata yc
		mov		cx,[bp+4]    ; resgata r
		
		mov		si,bx
		sub		si,cx
		push    ax			;coloca xc na pilha			
		push	si			;coloca yc-r na pilha
		mov		si,bx
		add		si,cx
		push	ax		;coloca xc na pilha
		push	si		;coloca yc+r na pilha
		call line
		
			
		mov		di,cx
		sub		di,1	 ;di=r-1
		mov		dx,0  	;dx será a variável x. cx é a variavel y
	
	;aqui em cima a lógica foi invertida, 1-r => r-1
	;e as comparações passaram a ser jl => jg, assim garante 
	;valores positivos para d

	stay_full:				;loop
		mov		si,di
		cmp		si,0
		jg		inf_full       ;caso d for menor que 0, seleciona pixel superior (não  salta)
		mov		si,dx		;o jl é importante porque trata-se de conta com sinal
		sal		si,1		;multiplica por doi (shift arithmetic left)
		add		si,3
		add		di,si     ;nesse ponto d=d+2*dx+3
		inc		dx		;incrementa dx
		jmp		plotar_full
	inf_full:	
		mov		si,dx
		sub		si,cx  		;faz x - y (dx-cx), e salva em di 
		sal		si,1
		add		si,5
		add		di,si		;nesse ponto d=d+2*(dx-cx)+5
		inc		dx		;incrementa x (dx)
		dec		cx		;decrementa y (cx)
		
	plotar_full:	
		mov		si,ax
		add		si,cx
		push	si		;coloca a abcisa y+xc na pilha			
		mov		si,bx
		sub		si,dx
		push    si		;coloca a ordenada yc-x na pilha
		mov		si,ax
		add		si,cx
		push	si		;coloca a abcisa y+xc na pilha	
		mov		si,bx
		add		si,dx
		push    si		;coloca a ordenada yc+x na pilha	
		call 	line
		
		mov		si,ax
		add		si,dx
		push	si		;coloca a abcisa xc+x na pilha			
		mov		si,bx
		sub		si,cx
		push    si		;coloca a ordenada yc-y na pilha
		mov		si,ax
		add		si,dx
		push	si		;coloca a abcisa xc+x na pilha	
		mov		si,bx
		add		si,cx
		push    si		;coloca a ordenada yc+y na pilha	
		call	line
		
		mov		si,ax
		sub		si,dx
		push	si		;coloca a abcisa xc-x na pilha			
		mov		si,bx
		sub		si,cx
		push    si		;coloca a ordenada yc-y na pilha
		mov		si,ax
		sub		si,dx
		push	si		;coloca a abcisa xc-x na pilha	
		mov		si,bx
		add		si,cx
		push    si		;coloca a ordenada yc+y na pilha	
		call	line
		
		mov		si,ax
		sub		si,cx
		push	si		;coloca a abcisa xc-y na pilha			
		mov		si,bx
		sub		si,dx
		push    si		;coloca a ordenada yc-x na pilha
		mov		si,ax
		sub		si,cx
		push	si		;coloca a abcisa xc-y na pilha	
		mov		si,bx
		add		si,dx
		push    si		;coloca a ordenada yc+x na pilha	
		call	line
		
		cmp		cx,dx
		jb		fim_full_circle  ;se cx (y) está abaixo de dx (x), termina     
		jmp		stay_full		;se cx (y) está acima de dx (x), continua no loop
		
		
	fim_full_circle:
		pop		di
		pop		si
		pop		dx
		pop		cx
		pop		bx
		pop		ax
		popf
		pop		bp
		ret		6


;-----------------------------------------------------------------------------------;	
;                            Interface Raquete		                                ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve usar a função line para criar a raquete com as dimensões de:    		;           
;       posição X = aproximadamente 600 pixels                                  	;
;   	posição Y = aproximadamente 241 pixels                                		;
;   	tamanho  = aproximadamente 50 pixels                                        ;
;-----------------------------------------------------------------------------------;
; FONTE: criação da raquete baseado  no arquivo line.asm (rotina line)              ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;	

    interface_raquete:
	
		push		cx
		mov			byte[cor],branco_intenso
		push		word[raquete_posicaoX]
		push		word[raquete_posicaoY]
		mov			cx,[raquete_posicaoY]
		add			cx,raquete_tamanho
		push		word[raquete_posicaoX]
		push		cx
		call		line

		pop			cx
		ret		
;-----------------------------------------------------------------------------------;	
;                            Rotina ajustar a raquete		                        ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve usar a função line para posicionar a raquete em um lugar especifíco	;           
;       posição X = aproximadamente a posição 598 - 600 pixels                    	;
;   	posição Y = aproximadamente a posição 431 pixels                   			;
;-----------------------------------------------------------------------------------;
; FONTE: Laboratórios e Slides de aulas presenciais						            ;
;-----------------------------------------------------------------------------------;
	raqueteAjusta:
		mov			byte[cor],branco
		push		word 598
		push		word 431
		push		word 601
		push		word 431
		call 		line
		ret
;-----------------------------------------------------------------------------------;	
;                            Rotina para mover raquete		                        ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve usar a função line para mover a raquete para cima ou para baixo		;           
;       limite => aproximadamente a y: 1 < y < 380 pixels	                    	;
;   -2) deve apagar e ascender em uma posição nova (movimento)                  	;
;	-3) deve checar se pode mover ou nao a raquete (raquete_checa = 0 pode mover)	;
;-----------------------------------------------------------------------------------;
; FONTE: movimento da raquete baseado no movimento da bolinha do lab5	            ;
;-----------------------------------------------------------------------------------;
	raqueteMover:
		xor			ax,ax
		mov			al,byte[raquete_checa]		
		cmp			al,0
		ja			raquetePara
		mov			dx,[raquete_posicaoY]
		mov			cx,[raquete_movimento]
		mov			ah,[raquete_velocidade]
		inc			ah
		cmp			ah,1
		jz			raqueteFinal
		ja			raquetePosicao


		;___________________________________
		; invertendo o movimento da raquete 
		raqueteMoveInversamente:
			cmp			dx,10
			jb			raqueteFinal

			mov			byte[cor],preto 			;apagando a posição que estava anteriormente
			mov			ax,[raquete_posicaoY]
			add			ax,raquete_tamanho+1		;ascendendo em uma posição de 1 pixel a mais 
			push		word[raquete_posicaoX]
			push		ax
			sub			ax,[raquete_movimento]
			push		word[raquete_posicaoX]
			push		ax
			call 		line		
		;____________________________
		;mudando para a nova posição
			sub			[raquete_posicaoY],cx
			mov			byte[raquete_checa],1	; pode se mover a cada 1(+1) frames
			jmp			raqueteFinal
			
		raquetePosicao:
			cmp			dx,371
			ja			raqueteFinal

			mov			byte[cor],preto			;apagando a posição que estava anteriormente
			mov			ax,[raquete_posicaoY]
			push		word[raquete_posicaoX]
			push		ax
			add			ax,[raquete_movimento]
			dec			ax						;ascendendo em uma posição de 1 pixel a menos
			push		word[raquete_posicaoX]
			push		ax
			call 		line
		;____________________________
		;Mudando para a nova posição
			add			[raquete_posicaoY],cx
			mov			byte[raquete_checa],1
			jmp			raqueteFinal
		raquetePara:
			dec			byte[raquete_checa]
		raqueteFinal:
			mov			byte[raquete_velocidade],0
			ret
;-----------------------------------------------------------------------------------;	
;                            Tratamento da Colisão			                        ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve estabelecer uma faixa para a colisão:									;           
;       faixa em X => aproximadamente a 595 < x < 600 pixels	                  	;
;   	faixa em Y => aproximadamente a -7 < (y - raquete_posicaoY) < 57 pixels     ;
;	-3) deve considerar o raio da bola para calcular a posição de colisão			;
;-----------------------------------------------------------------------------------;
; FONTE: tratamento da colisão baseado no tratamento de colisao das bordas do lab5  ;
;-----------------------------------------------------------------------------------;

	colisao:		
		;________________________________
		; Verificando colisão com a bola
		mov 		bx,[bola_posicaoX]
		mov			dx,[bola_posicaoY]

		;________________________________________
		; Verificando colisão com a raquete em X
		cmp			bx,600-bola_raio
		jb			colisaoX
		cmp			bx,595	
		ja			colisaoX

		;________________________________________
		; Verificando colisão com a raquete em Y
		mov			ax,[raquete_posicaoY]
		cmp			ax,7
		jb	raqueteColisaoNegada		
		sub			ax,7	
		raqueteColisaoNegada:
			cmp			dx,ax
			jb			colisaoX
			add			ax,14+raquete_tamanho
			cmp			dx,ax
			ja			colisaoX
		raqueteColisaoEfetivada:
			inc			word[placar_atualJogador]
			neg			byte[bola_velocidadeX]
			inc			byte[raquete_colisao]
			jmp			colisaoY
		
		;____________________________________
		; Verificando colisão com as paredes
		colisaoX:
			cmp			bx,639-bola_raio
			jae			paredeDireitaColisaoEfetivada
			cmp			bx,1+bola_raio
			jbe			colisaoEfetivadaX
			jmp			colisaoY	
			
		paredeDireitaColisaoEfetivada:
			inc			word[placar_atualComputador]
			push		dx
			mov			byte[cor],preto
			call		interface_bolinha
			pop			dx
			mov			word[bola_posicaoX],23
			call		interface_bordaDireita
			jmp			colisaoY
			colisaoEfetivadaX:
			neg			byte[bola_velocidadeX]

		colisaoY:
			cmp			dx,429-bola_raio
			jae			colisaoEfetivadaY
			cmp			dx,1+bola_raio
			jbe			colisaoEfetivadaY
			mov			byte[bola_colisaoY],0
			jmp			colisaoRET
			colisaoEfetivadaY:
			neg			byte[bola_velocidadeY]
			mov			byte[bola_colisaoY],1
		colisaoRET:
			ret




;-----------------------------------------------------------------------------------;	
;                            Interface do Placar			                        ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve checar se o novo placar do jogador é o mesmo que o anterior			;           
;       caso seja igual => não altera o placar na interface	                  		;
;   	caso seja diferente => modifica o placar na interface somando +1    		;
;   -2) deve seguir o padrão para atualização do placar de:                         ;
;                              "n" caractéres (cx)                                  ;
;                              "y" linha variando de 0-29 (dh)                      ;
;                              "x" coluna variando de 0-79 (dl)						;
;-----------------------------------------------------------------------------------;
; FONTE:    Laboratórios e Slides de aulas presenciais         		                ;
;-----------------------------------------------------------------------------------;
	interface_placar:
		mov ax, [placar_atualJogador]
		cmp	ax,[placar_atualizadoJogador]
		je	placarInalteradoJogador

		mov	[placar_atualizadoJogador],ax
		mov cx,3				

		;_________________________________
		; Atualizando o placar do jogador
		placarAlteradoJogador:	
			mov			dl,10			
			mov			bx,msg_placarJogador
			div			dl				
			add			ah,030h			
			add			bx,cx			
			dec			bx				
			mov			[bx],ah			
			mov			ah,0			
			loop		placarAlteradoJogador

		mov			byte[cor],branco_intenso
		mov			dh,2				; 02 posição coluna
		mov			dl, 31				; 31 posição linha
		mov			cx,3					; 03 caractéres
		mov			bx,msg_placarJogador ;mensagem
		call		escreve_mensagem

		placarInalteradoJogador:
			mov			ax,[placar_atualComputador]	
			cmp			ax,[placar_atualizadoComputador]	
			je			placarInalteradoComputador		
			mov			[placar_atualizadoComputador],ax
			mov 		cx,3
		;____________________________________
		; Atualizando o placar do computador	
		placarAlteradoComputador:	
			mov			dl,10			
			mov			bx,msg_placarComputador
			div			dl				
			add			ah,030h			
			add			bx,cx
			dec			bx				
			mov			[bx],ah			
			mov			ah,0			
			loop		placarAlteradoComputador

		mov			byte[cor],branco_intenso
		mov			dh,2					; 2 posição coluna
		mov			dl,40					; 40 posição linha
		mov			cx,3					; 03 caractéres
		mov			bx,msg_placarComputador ; mensagem
		call		escreve_mensagem 

		placarInalteradoComputador:
			ret	
	

;-----------------------------------------------------------------------------------;
;                              Sair do Programa                                     ;                                                                                   
;-----------------------------------------------------------------------------------;


	sai:	
		;______________________________________
		; Restaurando a tabela de interrupções

		XOR     AX, AX
		MOV     ES, AX
		MOV     AX, [cs_dos]
		MOV     [ES:int9*4+2], AX
		MOV     AX, [offset_dos]
		MOV     [ES:int9*4], AX 

		;___________________
		; Saindo do progama
		mov    	ah,08h
		int     21h
	    mov  	ah,0   			; set video mode
	    mov  	al,[modo_anterior]   	; modo anterior
	    int  	10h
		mov     ax,4c00h
		int     21h				

;-----------------------------------------------------------------------------------;	
;                        		Uso do KeyInt	 		                            ;                                                                                                                                                                                
;-----------------------------------------------------------------------------------;
; FONTE: trecho retirado do tecbuf.asm				                                ;  
;-----------------------------------------------------------------------------------;

	keyint:
		PUSH    AX
		push    bx
		push    ds
		mov     ax,data
		mov     ds,ax
		IN      AL, kb_data
		inc     WORD [p_i]
		and     WORD [p_i],7
		mov     bx,[p_i]
		mov     [bx+tecla],al
		IN      AL, kb_ctl
		OR      AL, 80h
		OUT     kb_ctl, AL
		AND     AL, 7Fh
		OUT     kb_ctl, AL
		MOV     AL, eoi
		OUT     pictrl, AL
		pop     ds
		pop     bx
		POP     AX
		IRET

    
	

;-----------------------------------------------------------------------------------;	
;                  Testa a tecla via Interrupção de Hardware                        ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve seguir o padrão  escrita da atualização da velocidade da bolinha:      ;
;                              "n" caractéres (cx)                                  ;
;                              "y" linha variando de 0-29 (dh)                      ;
;                              "x" coluna variando de 0-79 (dl)						;                                                                                                                                                                                
;-----------------------------------------------------------------------------------;
; FONTE: rotina testatecla do laboratório 6 e trecho retirado do tecbuf.asm         ;  
;-----------------------------------------------------------------------------------;	

	testateclaHardware:	
		mov     ax,[p_i]
		CMP     ax,[p_t]
		JE      testateclaRetorna

		inc     word[p_t]
		and     word[p_t],7
		mov     bx,[p_t]

		XOR     AX, AX
		MOV     AL, [bx+tecla]

		;______________________________
		; Comparação Hardware para Sair
		cmp al, 1Fh
		je sai	

		;____________________________________________________
		; Comparação Hardware para mover a raquete para cima
		cmp al, 16h
		je 			testateclaU		;

		;_____________________________________________________
		; Comparação Hardware para mover a raquete para baixo
		cmp			al,20h
		je 			testateclaD		;

		;____________________________________________________________
		; Comparação Hardware aumentar em +1 a velocidade da bolinha
		cmp			al,4Eh
		je 			testateclaAdc		;
		
		;____________________________________________________________
		; Comparação Hardware diminuir em -1 a velocidade da bolinha
		cmp			al,4Ah	
		je 			testateclaSub


		;________________________________________________________
		; Rotina para retornar/ continuar a execução do programa 
		testateclaRetorna:
			ret

		;_______________________________________
		; Rotina para mover a raquete para cima 
		testateclaU:
			mov			byte[raquete_velocidade],1
			jmp			testateclaRetorna

		;________________________________________
		; Rotina para mover a raquete para baixo 
		testateclaD:
			mov			byte[raquete_velocidade],-1
			jmp			testateclaRetorna


		;______________________________________________
		; Rotina diminuir em -1 a velocidad da bolinha
		testateclaSub:
			cmp word[modo_velocidade],5000h
			je trocaV1;
			cmp word[modo_velocidade],2000h
			je trocaV2;
			cmp word[modo_velocidade],0900h
			je trocaV3
			cmp word[modo_velocidade],0001h
			je trocaV4		
			jmp			testateclaRetorna

		;______________________________________________
		; Rotina aumentar em +1 a velocidad da bolinha
		testateclaAdc:
			cmp word[modo_velocidade],9999h
			je trocaV2;
			cmp word[modo_velocidade],5000h
			je trocaV3;
			cmp word[modo_velocidade],2000h
			je trocaV4
			cmp word[modo_velocidade],0900h
			je trocaV5
			jmp			testateclaRetorna

		;_______________________________________________
		; Rotinas para a troca de velocidade da bolinha
		trocaV1:
			mov			word[modo_velocidade],9999h
			mov			byte[cor],branco_intenso
			mov			dh,2					; 02 posição coluna
			mov			dl, 74					; 74 posição linha
			mov			cx,1					; 01 caractéres
			mov			bx,msg_velocidadeV1 	; mensagem
			call		escreve_mensagem
			jmp			testateclaRetorna

		trocaV2:
			mov			word[modo_velocidade],5000h
			mov			byte[cor],branco_intenso
			mov			dh,2					; 02 posição coluna	
			mov			dl,	74					; 74 posição coluna	
			mov			cx,1					; 01 caractéres
			mov			bx,msg_velocidadeV2		; mensagem
			call		escreve_mensagem
			jmp			testateclaRetorna

		trocaV3:
			mov			word[modo_velocidade],2000h
			mov			byte[cor],branco_intenso
			mov			dh,2					; 02 posição coluna	
			mov			dl, 74 					; 74 posição linha
			mov			cx,1					; 01 caractéres
			mov			bx,msg_velocidadeV3		;mensagem
			call		escreve_mensagem
			jmp			testateclaRetorna

		trocaV4:
			mov			word[modo_velocidade],0900h
			mov			byte[cor],branco_intenso
			mov			dh,2					; 02 posição coluna	
			mov			dl, 74					; 74 posição linha
			mov			cx,1					; 01 caractéres
			mov			bx,msg_velocidadeV4
			call		escreve_mensagem
			jmp			testateclaRetorna
			
		trocaV5:
			mov			word[modo_velocidade],0001h
			mov			byte[cor],branco_intenso
			mov			dh,2					; 02 posição coluna	
			mov			dl,74 					; 74 posição linha	
			mov			cx,1					; 01 caractéres
			mov			bx,msg_velocidadeV5		;mensagem
			call		escreve_mensagem	
			jmp			testateclaRetorna
			


;-----------------------------------------------------------------------------------;	
;                        		Uso da Int 15h	 		                            ;                                                                                                                                                                                
;-----------------------------------------------------------------------------------;
;Comentários:																		;
;	INT 15h / AH = 86h - Função de espera do BIOS.									;
;		entrada:																	;
;			CX:DX = intervalo em microssegundos										;
;		retorna:																	;
;			CF limpo se for bem-sucedido (intervalo de espera decorrido)			;
;			CF definido em erro ou quando a função de espera já estiver em andamento;
;-----------------------------------------------------------------------------------;
; FONTE: trecho baseado no link 8086_bios_and_dos_interrupts		                ;  
;-----------------------------------------------------------------------------------;
	int_15h:		
		push		cx			
		xor cx,cx
		mov dx, [modo_velocidade]
		mov ah,86h
		int 15h
		pop		cx
		ret


segment data
;-----------------------------------------------------------------------------------;
;                       CONSTANTES DE CORES UTILIZADAS                              ;
;                                                                                   ;
;                               I R G B COR                                         ;
;                               0 0 0 0 preto                                       ;
;                               0 0 0 1 azul                                        ;
;                               0 0 1 0 verde                                       ;
;                               0 0 1 1 cyan                                        ;
;                               0 1 0 0 vermelho                                    ;
;                               0 1 0 1 magenta                                     ;
;                               0 1 1 0 marrom                                      ;
;                               0 1 1 1 branco                                      ;
;                               1 0 0 0 cinza                                       ;
;                               1 0 0 1 azul claro                                  ;
;                               1 0 1 0 verde claro                                 ;
;                               1 0 1 1 cyan claro                                  ;
;                               1 1 0 0 rosa                                        ;
;                               1 1 0 1 magenta claro                               ;
;                               1 1 1 0 amarelo                                     ;
;                               1 1 1 1 branco intenso                              ;
;                                                                                   ;
;-----------------------------------------------------------------------------------;
	cor		db		branco_intenso

	;	I R G B COR
	;	0 0 0 0 preto
	;	0 0 0 1 azul
	;	0 0 1 0 verde
	;	0 0 1 1 cyan
	;	0 1 0 0 vermelho
	;	0 1 0 1 magenta
	;	0 1 1 0 marrom
	;	0 1 1 1 branco
	;	1 0 0 0 cinza
	;	1 0 0 1 azul claro
	;	1 0 1 0 verde claro
	;	1 0 1 1 cyan claro
	;	1 1 0 0 rosa
	;	1 1 0 1 magenta claro
	;	1 1 1 0 amarelo
	;	1 1 1 1 branco intenso

	preto		equ		0
	azul		equ		1
	verde		equ		2
	cyan		equ		3
	vermelho	equ		4
	magenta		equ		5
	marrom		equ		6
	branco		equ		7
	cinza		equ		8
	azul_claro	equ		9
	verde_claro	equ		10
	cyan_claro	equ		11
	rosa		equ		12
	magenta_claro	equ		13
	amarelo		equ		14
	branco_intenso	equ		15

;______________________________________________________________________________________________________________
	
	;variaveis auxliares para o line.asm
	linha   	dw  		0
	coluna  	dw  		0
	deltax		dw		0
	deltay		dw		0	



;______________________________________________________________________________________________________________

	;variáveis para o modo de animação / tela
	modo_anterior		db		0
	modo_pixel			dw		0
	modo_pixelASCII  	db  '00000'
	modo_velocidadeCINCO 	dw	0001h
	modo_velocidadeQUATRO 	dw  0900h
	modo_velocidadeTRES 	dw	2000h
	modo_velocidadeDOIS 	dw	5000h
	modo_velocidadeUM 	dw	9999h
	modo_velocidade		dw	9999h
	modo_deltaX			dw	0
	modo_deltaY			dw	0
;______________________________________________________________________________________________________________

	;mensagem que irá ser escrita
	msg_disciplina         	    db    'Exercicio de Programacao de Sistemas Embarcados 1 - 2022/2'
	msg_meunome					db  'Dionatas Santos Brito '
	msg_placarJogador 			db	'000'	
	msg_versus 					db  ' x '
	msg_placarComputador		db  '000'	
	msg_computador 				db  ' Computador'
	msg_velocidade 				db 'Velocidade atual: 1'
	msg_velocidadeV1			db '1'
	msg_velocidadeV2			db '2'
	msg_velocidadeV3			db '3'
	msg_velocidadeV4			db '4'
	msg_velocidadeV5			db '5'
;______________________________________________________________________________________________________________

	;placar do computador e do jogador
	placar_atualJogador			dw  000	
	placar_atualComputador		dw	000	
	placar_atualizadoComputador	dw  1
	placar_atualizadoJogador	dw  1	

;______________________________________________________________________________________________________________

	;variáveis para a raquete
	raquete_posicaoX        dw  600 
	raquete_posicaoYASCII	db	'000'
	raquete_posicaoY        dw  241 
	raquete_tamanho		    equ	50
	raquete_velocidade		db  0
	raquete_movimento		db  10
	raquete_checa			db  0
	raquete_colisao			db	0	

;______________________________________________________________________________________________________________
	; variáveis para a bola
	bola_posicaoX			dw  23 ; Posição inicial 
	bola_posicaoXASCII		db	'000'
	bola_velocidadeX		db  1
	bola_colisaoX	db  0	; Bit que indica se houve colisão com parede em x no frame anterior
	bola_posicaoY			dw 	239 ; Posição inicial y
	bola_posicaoYASCII		db	'000'
	bola_velocidadeY		db  -1
	bola_colisaoY	db  0	; Bit que indica se houve colisão com parede em y no frame anterior

	bola_movimento      	dw  6
	bola_raio				equ 10

;______________________________________________________________________________________________________________
	;variáves para a rotina keyint
	kb_data EQU 	60h  ;PORTA DE LEITURA DE TECLADO
	kb_ctl  EQU 	61h  ;PORTA DE RESET PARA PEDIR NOVA INTERRUPCAO
	pictrl  EQU 	20h
	eoi     EQU 	20h
	int9    EQU 	9h
	cs_dos  DW  	1
	offset_dos  DW 	1
	tecla_u db 		0
	tecla   resb  	8 
	p_i     dw  	0   ;ponteiro p/ interrupcao (qnd pressiona tecla)  
	p_t     dw  	0   ;ponterio p/ interrupcao ( qnd solta tecla)    
	teclasc DB  	0,0,13,10,'$'

segment stack stack
    		resb 		512
stacktop:

