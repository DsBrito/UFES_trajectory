;-----------------------------------------------------------------------------------;
; SISTEMAS EMBARCADOS I - ELE 8575 - 2022/01 – DEL – CT – UFES                      ;
;                                                                                   ;
;-----------------------------------------------------------------------------------;
;                   EXERCICIO DE PROGRAMAÇÃO                                        ;
;                                                                                   ;
; Autor: DIONATAS SANTOS BRITO                                                      ;
; Turma: 0.5.1                                                                      ;
;-----------------------------------------------------------------------------------;
;Descrição:                                                                         ;
;        Deseja-se processar uma imagem digital (300×300 pixels                     ;
;        – 256 níveis de cinza), pixel a pixel,armazenada em um                     ;
;        arquivo texto.                                                             ;    
;                                                                                   ;    
;        Para tanto, você deve desenvolver um sistema com                           ;
;        interface gráfica cujo layout é mostrado na Figura 1.                      ;
;        Todo o controle da interface de ser feito usando o                         ;
;        mouse para realizar a ação desejada.                                       ;    
;                                                                                   ;
;        Todas as linhas da interface devem ser brancas e o                         ; 
;        fundo deve ser preto. Já para o menu de opções                             ;  
;        (menu superior), uma vez que uma opção seja selecionada                    ;
;        deve-se trocar a cor da legenda da opção de branco                         ;
;        para amarelo e assim permanecer até que uma outra opção                    ;
;        seja selecionada. A seleção deverá ser exclusivamente                      ;            
;        feita pelo uso do mouse.                                                   ;
;        Para tanto, deve-se posicionar o cursor do mouse em                        ;
;        qualquer parte do retângulo que contiver a função                          ;
;        desejada e clicar com o botão esquerdo do mouse para                       ;
;        executar a operação.                                                       ;
;                                                                                   ;
;        No menu, tem-se as opções:                                                 ;
;           Abrir: Abrir o arquivo contendo a imagem, chamado de                    ;
;                 ‘imagem.txt’ e a desenha na região reservada a                    ;
;                  a ela conforme mostrado na Figura 1                              ;
;           Sair: Sair do programa, retornando a janela DOS do                      ;
;                 dropbox para o modo original                                      ;
;                                                                                   ;
;           Passa-Baixas: Convolui a imagem original com o                          ;
;                         filtro passa-baixas.                                      ;
;                                           1 1 1                                   ;
;                           w(s,t)= 1/9     1 1 1                                   ;
;                                           1 1 1                                   ;
;                                                                                   ;
;           Passa-Altas: Convolui a imagem original com o                           ;
;                        filtro passa-altas.                                        ;
;                                        -1 -1 -1                                   ;
;                               w(s,t)=  -1  9 -1                                   ;
;                                        -1 -1 -1                                   ;
;                                                                                   ;
;           Gradiente: filtro derivativo aplicado sobre a                           ;
;                      imagem (seu módulo)                                          ;
;                                          -1 -2 -1                                 ;
;                           Gx=             0  0  0                                 ;
;                                           1 2   1                                 ;
;                                                                                   ;
;                                                                                   ;
;                                          -1  0  1                                 ;
;                           Gy=            -2  0  2                                 ;
;                                          -1  0  1                                 ;
;                                                                                   ;
;                           Gradiente ≈ |Gx|+|Gy|                                   ;
;                                                                                   ;
;        A qualquer instante você pode aplicar qualquer uma das                     ;  
;        funções do menu superior, desde que a imagem já esteja                     ;
;        carregada, a ação deve ser executada.                                      ;
;        Ao clicar em ‘Abrir’ com um arquivo já aberto, seu                         ;
;        código deve fechar o arquivo aberto para, novamente,                       ;
;        abri-lo, recarregando a imagem. As cores na tela são de                    ;
;        acordo com a Tabela 1. Observe que você vai ter que                        ;
;        requantizar os níveis de cinza da imagem, pois no modo                     ;
;        gráfico usado tem-se 640×480 pixels, cada pixel com um                     ;
;        máximo de 16 valores, conforme a Tabela1 (vai dar falso                    ;
;        coloreamento).                                                             ;
;                                                                                   ;
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
;      Para facilitar a programação, use o programa LINEC.ASM                       ;
;                                                                                   ;
;-----------------------------------------------------------------------------------;


;-----------------------------------------------------------------------------------;
;                   {INICIALIZANDO O PROGRAMA}                                      ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve iniciar o Segment code como foi visto no laboratório                   ;                                                  
;   -2) deve salvar o modo corrente de video                                        ;
;   -3) deve alterar o modo de video para gráfico (640 x 480)                       ;
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
;                Salvando Modo Corrent de video                                     ;    
;-----------------------------------------------------------------------------------;
; salvar modo corrente de video (vendo como está o modo de video da maquina)        
        mov ah,0Fh                            
        int 10h
        mov [modo_anterior],al                                                      
                                                                       
;-----------------------------------------------------------------------------------;
;    Alterando Modo de video para Grafico 640x480 em 16 core                        ;    
;-----------------------------------------------------------------------------------;
; alterar modo de video para gráfico 640x480 16 cores
        mov al,12h                           
        mov ah,0
        int 10h

;-----------------------------------------------------------------------------------;
;       Inicialização da Interface Gráfica do Programa                              ; 
;                                                                                   ;   
; Comentários:                                                                      ;
;   -1) deve iniciar a interface na cor branco_intenso                              ;
;-----------------------------------------------------------------------------------;
; FONTE: baseado no line.asm (desenha retas/linhas/circulos)                        ;
;-----------------------------------------------------------------------------------;
        mov byte[cor],branco_intenso 
        call interface_cria


;-----------------------------------------------------------------------------------;	
;                  Inicializando o Mouse no meio da Interface                       ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;	AX = 00                                                                         ;
;                                                                                   ;
;                                                                                   ;
;	on return:                                                                      ;
;   AX = 0000  mouse driver not installed                                           ;                                         
;	     FFFF  mouse driver installed                                               ;
;   BX = number of buttons                                                          ;
;                                                                                   ;
;	- resets mouse to default driver values:                                        ;
;                                                                                   ;
;	  .  mouse is positioned to screen center                                       ;
;	  .  mouse cursor is reset and hidden                                           ;
;	  .  no interrupts are enabled (mask = 0)                                       ;
;	  .  double speed threshold set to 64 mickeys per second                        ;
;	  .  horizontal mickey to pixel ratio (8 to 8)                                  ;
;	  .  vertical mickey to pixel ratio (16 to 8)                                   ;
;	  .  max width and height are set to maximum for video mode                     ;                                     
;                                                                                   ;
;-----------------------------------------------------------------------------------;
; FONTE: https://stanislavs.org/helppc/int_33-0.html                                ;
;        https://stanislavs.org/helppc/int_33-1.html                                ;                                             
;-----------------------------------------------------------------------------------;
        mov ax,0
        int 33h
        mov ax,1
        int 33h 


;-----------------------------------------------------------------------------------;	
;                     Detecção do Clique do Mouse na Interface                      ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
; 	AX = 5                                                                          ;
;	BX = 0 botão esquerdo                                                           ;
;	     1 botão direito                                                            ;
;                                                                                   ;
;	no retorno:                                                                     ;
;	BX = contagem de pressionamentos de botão (0-32767), recebe zero após a chamada ;
;	CX = posição horizontal na última pressão                                       ;
;	DX = posição vertical na última pressão                                         ;
;	AX = estado:                                                                    ;
;                                                                                   ;
;		|F-8|7|6|5|4|3|2|1|0| Status do botão                                       ;
;		  | | | | | | | | `---- botão esquerdo (1 = pressionado)                    ;
;		  | | | | | | | `----- botão direito (1 = pressionado)                      ;
;		  `------------------- não utilizado                                        ;
;                                                                                   ;
;-----------------------------------------------------------------------------------;
; FONTE: https://stanislavs.org/helppc/int_33-5.html                                ;
;                                                                                   ;
;-----------------------------------------------------------------------------------;
        clique_teste:
            mov ax,5              
            mov bx,0
            int 33h               
            cmp bx,0              
            jne clique_trata
        jmp clique_teste

;-----------------------------------------------------------------------------------;	
;                   Tratamento  do Clique do Mouse na Interface                     ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;    -se (dx) y<90 houve clique no menu                                             ;                                                                
;                                                                                   ;
;-----------------------------------------------------------------------------------;
; FONTE: fiz testes com y>90 e não deu muito certo :/                               ;                                                                                   
;-----------------------------------------------------------------------------------;
        clique_trata:
            cmp   dx, 90                                    
            jb    clique_opcao
            jmp   clique_teste

;-----------------------------------------------------------------------------------;	
;                           Opções  da Interface                                    ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;    -1) deve ocorrer o clique no menu                                              ;
;    -2) deve verifica qual botão foi selecionado                                   ;
;    -3) deve conter a posição (0,0) localizada na parte superior direita           ;
;       -Legenda>                                                                   ;
;            Abrir = x for menor que (<)80.                                         ;     
;            Sair  = x for entre (>)80 e (<)160.                                    ;
;            Gradiente = x for entre (>)160 e (<)320.                               ;
;            Filtro Passa Baixa = x for entre (>)320 e (<)480                       ;
;            Filtro Passa Alta  = x for entre (>)480 e (<)640                       ;                         
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: Mapeamento de possições (tentativa e erro)                                 ;                                                                                   
;-----------------------------------------------------------------------------------;
        clique_opcao:
            cmp cx,80
		    jb botao_abrir
	                
            cmp cx,160
		    jb botao_sair
	                
            cmp cx,320
            jb botao_filtroPassaBaixa

            cmp cx,480
            jb botao_filtroPassaAlta

            cmp cx,640
            jb botao_filtroGradiente
            jmp clique_teste

;-----------------------------------------------------------------------------------;	
;                       Opções para o Clique na Interface                           ;
;-----------------------------------------------------------------------------------;
            botao_abrir:
	            jmp b_abrir
	
            botao_sair:
	            jmp b_sair

	        botao_filtroPassaBaixa:
                jmp b_filtroPassaBaixa

            botao_filtroPassaAlta:
                jmp b_filtroPassaAlta

            botao_filtroGradiente:
                jmp b_filtroGradiente
;-----------------------------------------------------------------------------------;                
;                            Rotinas                                                ;  
;Legenda:                                                                           ;
;        interface_msgA   <= mensagem para abrir                                    ;
;        interface_msgS   <= mensagem para sair                                     ;
;        interface_msgFPB <= mensagem para filtro passa baixa                       ;
;        interface_msgFBA <= mensagem para filtro passa alta                        ;
;        interface_msgG   <= mensagem para o gradiente                              ;
;        interface_msgID  <= mensagem para o id                                     ;    
;-----------------------------------------------------------------------------------;

        interface_cria:     
            call interface_divisorias
            call interface_msgA   
            call interface_msgS   
            call interface_msgFPB 
            call interface_msgFBA 
            call interface_msgG  
            call interface_msgID 
            ret 

;-----------------------------------------------------------------------------------;	
;                           Divisórias da Interface                                 ;
;                                                                                   ;
; Comentários:                                                                      ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve usar a dimensão de pares ordenados(x0,y0) e (x1,y1),                   ;               
;       os pares devem estar entre x<639 e y<479                                    ;
;   -3) deve plotar os pares com a função line:                                     ;
;   -4) deve seguir o padrão de coordenadas:                                        ;
;        (0,479) e (639,479) <= linha da borda superior                             ;
;        (0,0) e (0,479)     <= linha da borda esquerda                             ;
;        (639,0) e (639,479) <= linha da borda direita                              ;
;        (0,0) e (639,0)     <= linha da borda inferior                             ;
;                                                                                   ;
;        (320,90) e (320,390)<= linha divisoria vertical                            ;                     
;        (0,89) e (639,89)   <= linha divisoria horizontal inferior                 ;
;        (0,390) e (640,390  <=linha divisoria horizontal superior                  ;
;                                                                                   ;
;        (80,480) e (80,390)  <= linha divisoria vertical (primeiro mini-quadrado)  ;
;        (160,480) e (160,390)<= linha divisoria vertical (segundo mini-quadrado)   ;
;        (320,480) e (320,390)<= linha divisoria vertical (terceiro mini-quadrado)  ;
;        (480,480) e (480,390)<= linha divisoria vertical (quarto mini-quadrado)    ;
;                                                                                   ;
;        (20,20) e (20,70)   <= linha divisoria vertical (primeira identificação)   ;
;        (620,20) e (620,70) <= linha divisoria vertical (segunda identificação)    ;
;        (20,70) e (620,70)  <= linha divisoria horizontal (terceira identificação) ;
;        (20,20) e (620,20)  <= linha divisoria horizontal (quarta identificação)   ;
;                                                                                   ;
;   -4) deve recuperar o contexto dos registradores utilizados                      ;                   
;-----------------------------------------------------------------------------------;
; FONTE: criação de linha baseado no Lab05 Programas Assembly(Animação modo gráfico);
;        e arquivo line.asm (rotina line)                                           ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;
        interface_divisorias:
            push ax ;salva contexto       
            push bx       
            push cx       
            push dx       
            push si       
            push di   

            ;BORDAS:                
            mov ax,0 ;linha da borda superior                        
            push ax
            mov ax,479
            push ax
            mov ax,639
            push ax
            mov ax,479
            push ax
            call line
	
            mov ax,0 ;linha da borda esquerda                  
            push ax
            mov ax,0
            push ax
            mov ax,0
            push ax
            mov ax,479
            push ax
            call line
	
            mov ax,639 ;linha da borda direita                 
            push ax
            mov ax,0
            push ax
            mov ax,639
            push ax
            mov ax,479
            push ax
            call line
                                        
            mov ax,0 ;linha da borda inferior                 
            push ax
            mov ax,0
            push ax
            mov ax,639
            push ax
            mov ax,0
            push ax
            call line

            ;DIVISÓRIAS:        
            mov ax, 320 ;divisoria vertical                       
            push ax
            mov ax,90
            push ax
            mov ax, 320
            push ax
            mov ax,390
            push ax
            call line

            mov ax, 0;divisoria horizontal inferior                       
            push ax
            mov ax,89
            push ax
            mov ax, 639
            push ax
            mov ax,89
            push ax
            call line
                    
            mov ax, 0 ;divisoria horizontal inferior                            
            push ax
            mov ax,390
            push ax
            mov ax, 640
            push ax
            mov ax,390
            push ax
            call line
                    
            ;MINI-DIVISÓRIAS:
            mov ax, 80 ;primeiro mini-quadrado                     
            push ax
            mov ax,480
            push ax
            mov ax, 80
            push ax
            mov ax,390
            push ax
            call line
		
            mov ax, 160 ;segundo mini-quadrado                   
            push ax
            mov ax,480
            push ax
            mov ax, 160
            push ax
            mov ax,390
            push ax
            call line
	
            mov ax, 320 ;terceiro mini-quadrado                   
            push ax
            mov ax,480
            push ax
            mov ax, 320
            push ax
            mov ax,390
            push ax
            call line
                    
            mov ax, 480 ;quanto mini-quadrado                   
            push ax
            mov ax,480
            push ax
            mov ax, 480
            push ax
            mov ax,390
            push ax
            call line
	
            mov ax, 480 ;quinto mini-quadrado                   
            push ax
            mov ax,480
            push ax
            mov ax, 480
            push ax
            mov ax,390
            push ax
            call line
	
            ;IDENTIFICAÇÃO:
            mov ax, 20 ;primeira identificação               
            push ax
            mov ax,20
            push ax
            mov ax, 20
            push ax
            mov ax,70
            push ax
            call line
	
            mov ax, 620 ;segunda identificação                 
            push ax
            mov ax,20
            push ax
            mov ax, 620
            push ax
            mov ax,70
            push ax
            call line
	
            mov ax, 20 ;terceira identificação                  
            push ax
            mov ax,70
            push ax
            mov ax, 620
            push ax
            mov ax,70
            push ax
            call line
	
            mov ax, 20 ;quarta identificação                 
            push ax
            mov ax,20
            push ax
            mov ax, 620
            push ax
            mov ax,20
            push ax
            call line
	  	
            pop di ;recupera contexto
            pop si
            pop dx
            pop cx
            pop bx
            pop ax
	        ret

;-----------------------------------------------------------------;	
;                     Construtor de Linhas                        ;
;                                                                 ;
; Comentários:                                                    ;
;   -1) deve construir as linhas da interface                     ;
;-----------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina line)                           ;
;-----------------------------------------------------------------;	

        line:
            push bp
            mov bp,sp
            pushf                        ;coloca os flags na pilha
            push ax
            push bx
            push cx
            push dx
            push si
            push di
            mov ax,[bp+10]   ; resgata os valores das coordenadas
            mov bx,[bp+8]    ; resgata os valores das coordenadas
            mov cx,[bp+6]    ; resgata os valores das coordenadas
            mov dx,[bp+4]    ; resgata os valores das coordenadas
            cmp ax,cx
            je line2
            jb line1
            xchg ax,cx
            xchg bx,dx
            jmp line1
                    
            line2:    ; deltax=0
                cmp bx,dx  ;subtrai dx de bx
                jb line3
                xchg bx,dx        ;troca os valores de bx e dx entre eles
                    
            line3:  ; dx > bx
                push ax
                push bx
                call plot_xy
                cmp bx,dx
                jne line31
                jmp fim_line
                    
            line31: 
                inc bx
                jmp line3
                ;deltax <>0
                    
            line1:
                ; comparar m�dulos de deltax e deltay sabendo que cx>ax
                ; cx > ax
                push cx
                sub cx,ax
                mov [deltax],cx
                pop cx
                push dx
                sub dx,bx
                ja line32
                neg dx
                    
            line32:   
                mov [deltay],dx
                pop dx
                push ax
                mov ax,[deltax]
                cmp ax,[deltay]
                pop ax
                jb line5
                    
                ; cx > ax e deltax>deltay
                push cx
                sub cx,ax
                mov [deltax],cx
                pop cx
                push dx
                sub dx,bx
                mov [deltay],dx
                pop dx
                mov si,ax
                    
            line4:
                push ax
                push dx
                push si
                sub si,ax ;(x-x1)
                mov ax,[deltay]
                imul si
                mov si,[deltax]   ;arredondar
                shr si,1
                ; se numerador (DX)>0 soma se <0 subtrai
                cmp dx,0
                jl ar1
                add ax,si
                adc dx,0
                jmp arc1
                    
            ar1:
                sub ax,si
                sbb dx,0
                    
            arc1:
                idiv word [deltax]
                add ax,bx
                pop si
                push si
                push ax
                call plot_xy
                pop dx
                pop ax
                cmp si,cx
                je  fim_line
                inc si
                jmp line4
                    
            line5:    
                cmp bx,dx
                jb  line7
                xchg ax,cx
                xchg bx,dx
                    
            line7:
                push cx
                sub cx,ax
                mov [deltax],cx
                pop cx
                push dx
                sub dx,bx
                mov [deltay],dx
                pop dx
                mov si,bx
                    
            line6:
                push dx
                push si
                push ax
                sub si,bx ;(y-y1)
                mov ax,[deltax]
                imul si
                mov si,[deltay]   ;arredondar
                shr si,1
                ; se numerador (DX)>0 soma se <0 subtrai
                cmp dx,0
                jl ar2
                add ax,si
                adc dx,0
                jmp arc2
	  
            ar2:    
                sub ax,si
                sbb dx,0
                    
            arc2:
                idiv word [deltay]
                mov di,ax
                pop ax
                add di,ax
                pop si
                push di
                push si
                call plot_xy
                pop dx
                cmp si,dx
                je fim_line
                inc si
                jmp line6
                    
            fim_line:
                pop di
                pop si
                pop dx
                pop cx
                pop bx
                pop ax
                popf
                pop bp
                ret 8 
	 
;-----------------------------------------------------------------;	
;                 Construtor de Coordenadas                       ;
;                                                                 ;
; Comentários:                                                    ;
;   -1) deve rotirna para plotar as Coordenadas X x Y             ;  
;   -2) deve obedecer  os limites de x<639 e y<479                ;
;   -3) deve corresponder a mesma cor da variavel cor             ;
;-----------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina plot_xy)                        ;
;-----------------------------------------------------------------;	
        plot_xy:
            push bp
            mov bp,sp
            pushf
            push ax
            push bx
            push cx
            push dx
            push si
            push di
            mov ah,0ch
            mov al,[cor]
            mov bh,0
            mov dx,479
            sub dx,[bp+4]
            mov cx,[bp+6]
            int 10h
            pop di
            pop si
            pop dx
            pop cx
            pop bx
            pop ax
            popf
            pop bp
            ret 4
                    
;-----------------------------------------------------------------------------------;	
;                        Mensagem Abrir da Interface                                ;
;                                                                                   ;
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve seguir o padrão de:                                                    ;
;                              4 caracteres (cx)                                    ;
;                              2 linha variando de 0-29 (dh)                        ;
;                              12 coluna variando de 0-79 (dl)                      ;
;   -3) deve incrementar o caractere e a coluna em um loop                          ;
;   -4) deve recuperar o contexto dos registradores utilizados                      ;
;-----------------------------------------------------------------------------------;
; FONTE: baseado no aquivo line.asm (escrever uma mensagem),                        ;
;        esta localizado abaixo do desenho dos circulos                             ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;
	    interface_msgA:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            mov cx,5      ;padrão escolhido de caracteres, linha e coluna
            mov bx,0
            mov dh,2     
            mov dl,2      
	                
            abrir_l:
                call cursor
                mov al,[bx+msg_a] 
                call  caracter
                inc bx      
                inc dl      
            loop abrir_l

	        pop dx  ;recupera contexto 
            pop cx
            pop bx
            pop ax
	        ret

;-----------------------------------------------------------------;	
;                 Construtor de Cursor                            ;
;                                                                 ;
; Comentários:                                                    ;
;   -1) deve seguir o padrão de:                                  ;
;                 dh = linha (0-29)                               ;
;                 dl=coluna  (0-79)                               ;  
;-----------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina cursor)                         ;
;-----------------------------------------------------------------;
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

;-----------------------------------------------------------------;	
;                 Construtor de Caracteres                        ;
;                                                                 ;
; Comentários:                                                    ;
;   -1) deve escrever o caractere em al                           ;  
;   -2) deve corresponder a mesma cor da variavel cor             ;
;-----------------------------------------------------------------;	
; FONTE: arquivo line.asm (rotina caracter)                       ;
;-----------------------------------------------------------------;
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
;                        Mensagem Sair da Interface                                 ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve seguir o padrão de:                                                    ;
;                              4 caracteres (cx)                                    ;
;                              2 linha variando de 0-29 (dh)                        ;
;                              12 coluna variando de 0-79 (dl)                      ;
;   -3) deve incrementar o caractere e a coluna em um loop                          ; 
;   -4) deve recuperar o contexto dos registradores utilizados                      ;
;-----------------------------------------------------------------------------------;
; FONTE: baseado no aquivo line.asm (escrever uma mensagem),                        ;
;        esta localizado abaixo do desenho dos circulos                             ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;
        interface_msgS:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            mov cx,4 ;padrão escolhido de caracteres, linha e coluna   
            mov bx,0
            mov dh,2        
            mov dl,12  

            sair_l:
                call cursor
                mov al,[bx+msg_s]
                call caracter
                inc bx      
                inc dl      
            loop sair_l

            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
            ret

;-----------------------------------------------------------------------------------;	
;                     Mensagem Filtro Passa Baixa da Interface                      ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve seguir o padrão de:                                                    ;
;                              11 caracteres (cx)                                   ;
;                              2 linha variando de 0-29 (dh)                        ;
;                              24 coluna variando de 0-79 (dl)                      ;
;   -3) deve incrementar o caractere e a coluna em um loop                          ;    
;   -4) deve recuperar o contexto dos registradores utilizados                      ; 
;-----------------------------------------------------------------------------------;
; FONTE: baseado no aquivo line.asm (escrever uma mensagem),                        ;
;        esta localizado abaixo do desenho dos circulos                             ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;
        interface_msgFPB:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            mov cx,11 ;padrão escolhido de caracteres, linha e coluna   
            mov bx,0
            mov dh,2
            mov dl,24 

            filtro_passa_baixa_l:
                call cursor
                mov al,[bx+msg_fpb]
                call caracter
                inc bx              
                inc dl              
            loop filtro_passa_baixa_l

            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
            ret

;-----------------------------------------------------------------------------------;	
;                     Mensagem Filtro Passa Alta da Interface                       ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve seguir o padrão de:                                                    ;
;                              10 caracteres (cx)                                   ;
;                              2 linha variando de 0-29 (dh)                        ;
;                              45 coluna variando de 0-79 (dl)                      ;
;   -3) deve incrementar o caractere e a coluna em um loop                          ;
;   -4) deve recuperar o contexto dos registradores utilizados                      ; 
;-----------------------------------------------------------------------------------;
; FONTE: baseado no aquivo line.asm (escrever uma mensagem),                        ;
;        esta localizado abaixo do desenho dos circulos                             ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------; 
        interface_msgFBA:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            mov cx,10      ;padrão escolhido de caracteres, linha e coluna   
            mov bx,0
            mov dh,2           
            mov dl,45  
                    
            filtro_passa_alta_l:
                call cursor
                    mov al,[bx+msg_fpa]
                    call caracter
                    inc bx             
                    inc dl              
            loop filtro_passa_alta_l

            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
            ret 

;-----------------------------------------------------------------------------------;	
;                     Mensagem Filtro Gradiente da Interface                        ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve seguir o padrão de:                                                    ;
;                              9 caracteres (cx)                                    ;
;                              2 linha variando de 0-29 (dh)                        ;
;                              65 coluna variando de 0-79 (dl)                      ;
;   -3) deve incrementar o caractere e a coluna em um loop                          ; 
;   -4) deve recuperar o contexto dos registradores utilizados                      ; 
;-----------------------------------------------------------------------------------;
; FONTE: baseado no aquivo line.asm (escrever uma mensagem),                        ;
;        esta localizado abaixo do desenho dos circulos                             ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;
        interface_msgG:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            mov cx,9      ;padrão escolhido de caracteres, linha e coluna   
            mov bx,0
            mov dh,2           
            mov dl,65  
                    
            gradiente_l:
                call cursor
                mov al,[bx+msg_g]
                call caracter
                inc bx             
                inc dl              
            loop gradiente_l

            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
            ret 

;-----------------------------------------------------------------------------------;	
;                     Mensagem Identificação da Interface                           ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve seguir o padrão de:                                                    ;
;                              47 caracteres (cx)                                   ;
;                              27 linha variando de 0-29 (dh)                       ;
;                              14 coluna variando de 0-79 (dl)                      ;
;   -3) deve incrementar o caractere e a coluna em um loop                          ;   
;   -4) deve recuperar o contexto dos registradores utilizados                      ; 
;-----------------------------------------------------------------------------------;
; FONTE: baseado no aquivo line.asm (escrever uma mensagem),                        ;
;        esta localizado abaixo do desenho dos circulos                             ;
;       Laboratórios e Slides de aulas presenciais                                  ;
;-----------------------------------------------------------------------------------;
        interface_msgID: 
                push ax ;salva contexto
                push bx
                push cx
                push dx

                mov cx,54     ;padrão escolhido de caracteres, linha e coluna   
                mov bx,0
                mov dh,27          
                mov dl,14   
                
                id_l:
                    call cursor
                    mov al,[bx+msg_id]
                    call caracter
                    inc bx             
                    inc dl              
                loop id_l

                pop dx ;recupera contexto
                pop cx
                pop bx
                pop ax
                ret 




;-----------------------------------------------------------------------------------;	
;                        Escolha da Opção Abir na Interface                         ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve mudar a cor para amarelo (selecionar)                                  ;
;   -2) deve mostar a mensagem referente a opção abrir                              ;
;   -3) deve manter os outros campos em branco (outras opções)                      ;
;   -4) deve apagar o mouse (ax=2h)                                                 ;
;   -5) verifica se a imagem ja foi aberta alguma vez                               ;
;       imagem_aberta =0 (primeira vez ->abre arquivo)                              ;
;       imagem_aberta =1 (nao é a primeira vez ->limpa a imagem)                    ;
;   -6) deve realizar a operação de abrir                                           ;
;        Abrir aquivo com a imagem                                                  ;
;        Caso seja não seja a primeira vez, ira fechar o aquivo                     ;
;          e após fechar, irá abrir novamente                                       ;
;   -7) deve ascender o mouse (ax=1h)                                               ;
;   -8) deve voltar o modo do mouse para clique teste                               ;                         
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: ligar mouse = https://stanislavs.org/helppc/int_33-1.html                  ;
;        apagar mouse = https://stanislavs.org/helppc/int_33-2.html                 ; 
;        mudar cor das linhas = arquivo line.asm                                    ;
;       Laboratórios e Slides de aulas presenciais                                  ;                                                                                   
;-----------------------------------------------------------------------------------;
        b_abrir:
            mov byte[cor],amarelo
	        call interface_msgA   
                             
            mov byte[cor],branco_intenso
            call interface_msgS   
            call interface_msgFPB 
            call interface_msgFBA 
            call interface_msgG  
            call interface_msgID
	                
            mov ax,2h ;apagando o mouse
            int 33h
    
            mov al,byte[imagem_aberta]     
	        cmp al,0
		    je  imagem_abrir       
	        call imagem_esquerdaP

	        mov bx,[arquivo_fecha]
            mov ah,3eh
            mov al,00h
            int 21h

	        imagem_abrir:
	            call arquivo_abrir
                    
            mov ax,1h ;mostrando mouse
            int 33h 

            mov ax,1h
            int 33h 
            jmp clique_teste


;-----------------------------------------------------------------------------------;	
;                        Mudar a cor da Esquerda para Preto                         ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve usar a dimensão 300x300 (x->linha x y->coluna)                         ;
;   -3) deve plotar X x Y pintando na cor preta:                                    ;
;       X = sendo a coluna atual                                                    ;   
;       Y = sendo a linha  atual                                                    ;
;   -4) deve crementar a coluna e decrementar a linha no processo                   ;
;   -5) deve recuperar o contexto dos registradores utilizados                      ;                                   
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ; 
;       Laboratórios e Slides de aulas presenciais                                  ;                                                                                                                  
;-----------------------------------------------------------------------------------;
        imagem_esquerdaP:    
            push    cx  ;salva contexto   
            push    ax
            push    dx
            push    bx

            mov word[linha_atual],0
            mov word[coluna_atual],0
	        mov cx,300 ;X a ser plotado
            linha_esquerda:
                push cx
                mov cx, 300 ;Y a ser plotado
		        coluna_esquerda:
                    call pixel_plotaEsquerda   
                    inc word[coluna_atual] ;incrementa a coluna
                loop coluna_esquerda

                dec word[linha_atual] ;decrementa a linha
                mov word[coluna_atual],0
                pop cx
            loop linha_esquerda
                    
            pop   bx ;recupera contexto
            pop   dx
            pop   ax    
            pop   cx
            ret

;-----------------------------------------------------------------------------------;	
;        Mudar a cor dos Pixeis da Dimensão 13 x 389 para Preto na Esquerda         ;  
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;  
;   -2) deve usar a dimensão 13x389 (x->linha x y->coluna)                          ; 
;   -3) deve plotar X x Y pintando na cor preta:                                    ; 
;       X = sendo a coluna atual                                                    ; 
;       Y = sendo a linha  atual                                                    ; 
;   -4) deve recuperar o contexto dos registradores utilizados                      ;                         
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;        mudar cor das linhas = arquivo line.asm                                    ;                                                                                   
;-----------------------------------------------------------------------------------;
        
        
        pixel_plotaEsquerda:  
            push ax ;salva contexto   
            push bx
            push dx

            mov byte[cor],preto   ;pintar de preto
            mov bx,[coluna_atual]

            add bx,13 ;X a ser plotado
            push bx       
            mov bx,[linha_atual]
            add bx,389 ;Y a ser plotado
                    
            push bx       
            call plot_xy ;rotina retirada do line.asm

            pop dx ;recupera contexto
            pop bx
            pop ax
            ret

;-----------------------------------------------------------------------------------;	
;                        Escolha da Opção Abir na Interface                         ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;	-1) deve salvar o contexto, com push de cada registrador                        ;    
;	-2) deve abrir o arquivo somente para a leitura	salvando	                    ;
;		o endereço no "arquivo_fecha" 							                    ;
;	-3) deve verificar se o arquivo foi aberto corretamente		                    ;
;		caso contrário deve retornar ao clique_teste                                ; 
;   -4) deve recuperar o contexto dos registradores utilizados                      ;                        
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE:int 21h= https://4beginner.com/8086-Assembly-Language-INT-21h-Dos-Interrupt ;
;       Laboratórios e Slides de aulas presenciais                                  ;                                                                                                                                      
;-----------------------------------------------------------------------------------;
		arquivo_abrir:
			push cx     
			push ax
			push dx
			push bx

			mov ah,3dh        
			mov al,00h
			mov dx,arquivo_nome
			int 21h
			mov [arquivo_fecha],ax ;grava endereço

			lahf            ;carrega flags    
			and ah,01           
			cmp ah,01           
			jne arquivo_sucesso

			pop   bx ;recupara contexto
			pop   dx
			pop   ax    
			pop   cx
			ret
;-----------------------------------------------------------------------------------;	
;                             Sucesso na Abertura 		                            ;    
;-----------------------------------------------------------------------------------;	
			arquivo_sucesso:
				mov byte[imagem_aberta],1

;-----------------------------------------------------------------------------------;	
;                  Mapear coluna, linha atual e quantidade de byte lido		        ;    
;-----------------------------------------------------------------------------------;
            arquivo_leitura:
				mov word[coluna_atual],0
				mov word[linha_atual],0
				mov word[byte_lido],0 

;-----------------------------------------------------------------------------------;	
;                      Linhas, Colunas e Bytes do Arquivo	                        ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;	-1) deve ler 1 byte de char por vez (byte a byte)                               ; 
;   -2) deve ler um espaço, caso seja um novo pixel (numero)                        ; 
;   -3) deve converter para decimal e ler o proximo caso o byte                     ; 
;       não seja espaço                                                             ; 
;   -4) deve ir para o proximo byte, caso o primeiro byte a ser                     ; 
;       lido for um espaço (pois não há pixel a ser plotado)                        ; 
;   -5) deve parar de ler o byte ao chegar no final do arquivo                      ; 
;   -6) deve transformar pixel (unidade,dezena e centenas) em                       ; 
;       um numero decimal                                                           ;    
;   -7) deve agrupar os pixeis transformados                                        ; 
;   -8) deve plotar o pixel na tela                                                 ; 
;   -9) deve fechar o arquivo                                                       ; 
;   -10)deve retornar o contexto                                                    ; 
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE:int 21h= https://4beginner.com/8086-Assembly-Language-INT-21h-Dos-Interrupt ;
;       slides das aulas presenciais e laboratórios                                 ;                                                                                    
;-----------------------------------------------------------------------------------;

                mov cx,300
				    linhas:
					    push cx
					    mov cx,300
					    colunas:
                            push cx
                            byte_proximo:
                                mov bx,[arquivo_fecha]
                                mov dx, buffer
                                mov cx,1 ;apenas um byte  
                                mov ah,3Fh      
                                int 21h      
                                cmp ax,cx
                                jne arquivo_final

                                mov al, [buffer] ;al recebe o byte lido
                                mov [ascii],al
                                cmp al,20h
                                je pixel_proximo

                                inc word[byte_lido] ;conversão para decimal
                                call converte_asciiXdecimal
                            jmp byte_proximo

                            pixel_proximo:
                                cmp word[byte_lido],0
                            je byte_proximo

                            call pixel_agrupa ;agrupando pixel para ser plotado
                            call pixel_plota
                            inc word[coluna_atual]
                            pop cx
		                loop colunas
                        dec word[linha_atual]
                        mov word[coluna_atual],0
                        pop cx
	                loop linhas
	  
                    arquivo_final:
                        pop cx
                        pop cx    
                        mov word[linha_atual],0
                        mov word[coluna_atual],0
   
                        mov bx,[arquivo_fecha] ;fechando o arquivo
                        mov ah,3eh
                        mov al,00h
                        int 21h
        
                        pop   bx ;retornando o contexto
                        pop   dx
                        pop   ax    
                        pop   cx
                        ret 
                    

;-----------------------------------------------------------------------------------;	
;                Potar Pixel da Imagem Original (16 cores) 	                        ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;  
;   -2) deve usar a cor referente ao pixel em sua forma decimal                     ;  
;   -3) deve plotar X x Y:                                                          ;  
;       X = sendo a coluna atual                                                    ;  
;       Y = sendo a linha  atual                                                    ;  
;   -4) deve recuperar o contexto dos registradores utilizados                      ;                                                                                                          
;-----------------------------------------------------------------------------------;
; FONTE:int 21h= https://4beginner.com/8086-Assembly-Language-INT-21h-Dos-Interrupt ;
;       slides das aulas presenciais e laboratórios                                 ;                                                                                    
;-----------------------------------------------------------------------------------;
        pixel_plota:      
            push ax ;salvando o contexto
            push bx
            push dx

            mov dl,16
            mov al,byte[pixel_decimal]
            xor ah,ah
            div dl   
            mov byte[cor],al

            mov bx,[coluna_atual]; X a ser plotado
            add bx,13
            push bx   
 
            mov bx,[linha_atual]; Y a ser plotado
            add bx,389
            push bx   

	        call plot_xy ;rotina retirada do line.asm
	
            pop dx ;recupera contexto
            pop bx
            pop ax
            ret 


;-----------------------------------------------------------------------------------;	
;                      Escolha da Opção Gradiente na Interface                      ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve mudar a cor para amarelo (selecionar)                                  ;
;   -2) deve mostar a mensagem referente ao gradiente                               ;
;   -3) deve manter os outros campos em branco (outras opções)                      ;
;   -4) deve apagar o mouse                                                         ;
;   -5) deve realizar a operação de gradiente                                       ;
;   -6) deve ascender o mouse                                                       ;
;   -7) deve voltar o modo do mouse para clique teste                               ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: ligar mouse = https://stanislavs.org/helppc/int_33-1.html                  ;
;        apagar mouse = https://stanislavs.org/helppc/int_33-2.html                 ; 
;        mudar cor das linhas = arquivo line.asm                                    ; 
;       Laboratórios e Slides de aulas presenciais                                  ;                                                                                  
;-----------------------------------------------------------------------------------;
        b_filtroGradiente:                	
            mov byte[cor],amarelo
            call interface_msgG  
                                 
            mov byte[cor],branco_intenso
            call interface_msgA   
            call interface_msgS   
            call interface_msgFPB 
            call interface_msgFBA 
            call interface_msgID
                
            mov ax,2h ;apagando o mouse
	        int 33h

            call filtroGradiente
                
            mov ax,1h ;mostrando o mouse
	        int 33h 
                
            jmp clique_teste


;-----------------------------------------------------------------------------------;	
;                        Construção do Filtro Gradiente                             ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;      
;   -2) deve checar se o arquivo foi aberto para usar  o filtro                     ;
;   -3) deve recuperar o contexto dos registradores utilizados                      ;                                                                                                                                                                                   
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        filtroGradiente:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            cmp byte[imagem_aberta],0
            jne aplica_filtroGradiente

            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
            ret 
;-----------------------------------------------------------------------------------;	
;                        Aplicação do Filtro Gradiente                              ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve ler 3 linhas por vez do arquivo                                        ;
;   -2) deve plotar o filtro                                                        ;
;   -3) deve verificar se Gx ou Gy é negativo, e se for.. deve fazer seu módulo     ;
;   -4) deve somar o gradiente de Gx e Gy                                           ;
;   -5) deve verificar se a soma ira ultrapassar o limite superior de 255           ;
;   -6) deve fechar o arquivo após aplicar filtro                                   ;
;   -7) deve recuperar o contexto dos registradores                                 ;
;                                                                                   ;  
;       Legenda<                                                                    ;
;       Area Especial = trata das 3 primeiras linhas do arquivo de forma diferente  ;
;       Area Comum = trata do restantes das linhas  de forma geral                  ;                                                                                                                                                                                   
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        aplica_filtroGradiente:
            call imagem_direitaP
            call linha_leituraInicial;ler 3 primeiras linhas do arquivo

            mov word[coluna_atual],0 
            mov word[linha_atual],0
            mov bx,0
            mov cx,300

            linha_pintaPretoG:
            mov byte[pixel_corrente],preto
            call pixel_plotaFiltro   ;plotar o filtro           
            inc word[coluna_atual]
            inc bx
            loop linha_pintaPretoG

            dec word[linha_atual]
            mov word[coluna_atual],0
            mov bx,0
            mov cx,300

            linha_criaEspecialG:
                xor ax,ax ;zera os registradores
                xor dx,dx
                    
                mov al,[linha_superior + bx]
                mov dh,2
                imul dh
                xor dh,dh
                sub dx,ax
                mov ax,dx
                xor dh,dh
                mov dl,[linha_superior + bx + 1]
                sub ax,dx 
                mov dl,[linha_superior + bx - 1]
                sub ax,dx
                mov dx,ax
                mov al,[linha_inferior + bx]
                xor ah,ah
                push bx
                mov bh,2
                mul bh
                pop bx
                add ax,dx
                mov dl,[linha_inferior + bx + 1]
                xor dh,dh
                add ax,dx
                mov dl,[linha_inferior + bx - 1]
                add ax,dx

		        mov [mascara_axiliar],ax

                or ax,0	;verifica se Gx é negativo, caso negativo faz o seu módulo
                jns gradiente_yEspecial
		        neg word[mascara_axiliar]		 

                gradiente_yEspecial:
                    xor ax,ax ;zera os registradores
                    xor dx,dx

                    mov dl,[linha_superior + bx + 1] ;faz o gradiente Gy
                    add ax,dx 
                    mov dl,[linha_superior + bx - 1]
                    sub ax,dx
                    mov dl,[linha_inferior + bx + 1]
                    add ax,dx 
                    mov dl,[linha_superior + bx - 1]
                    sub ax,dx
                    mov dx,ax
                    mov al,[linha_meio + bx + 1]
                    xor ah,ah
                    push bx
                    mov bh,2
                    mul bh
                    pop bx
                    add ax,dx 
                    mov dx,ax
                    mov al,[linha_meio + bx - 1]
                    xor ah,ah
                    push bx
                    mov bh,2
                    mul bh
                    pop bx
                    sub dx,ax
                    mov ax,dx
                    mov dx,ax

		            or ax,0 ;;verifica se Gy é negativo, caso negativo faz o seu módulo
		            jns gradiente_somaEspecial ; 
                    neg dx 

                    gradiente_somaEspecial:  ;com Gx e Gy positivos, faz a sua soma e verifica se excede o limite de 255
                        add dx,[mascara_axiliar]
                        cmp dx,255; 		
                        jb moveSomaEspecial
                        mov dx,255

                        moveSomaEspecial:
                            mov [pixel_corrente],dl
                            call pixel_plotaFiltro
                            inc word[coluna_atual]
                            inc bx
                            dec cx
                            cmp cx,0
                            je linha_decrementa
            jmp linha_criaEspecialG
	  
            linha_decrementa:
                dec word[linha_atual]
                mov word[coluna_atual],0
	  
            mov cx,298
            linha_criaComumG:
                push cx ;salva o contexto

		        call linha_leituraProxima
		        mov bx,0
		        coluna_criaGradiente:
                    xor ax,ax ;zera os registradores
                    xor dx,dx
                            
                    mov al,[linha_superior + bx]
                    mov dh,2
                    imul dh
                    xor dh,dh
                    sub dx,ax
                    mov ax,dx
                    xor dh,dh
                    mov dl,[linha_superior + bx + 1]
                    sub ax,dx 
                    mov dl,[linha_superior + bx - 1]
                    sub ax,dx
                    mov dx,ax
                    mov al,[linha_inferior + bx]
                    xor ah,ah
                    push bx
                    mov bh,2
                    mul bh
                    pop bx
                    add ax,dx
                    mov dl,[linha_inferior + bx + 1]
                    xor dh,dh
                    add ax,dx
                    mov dl,[linha_inferior + bx - 1]
                    add ax,dx
                    mov [mascara_axiliar],ax

                    or ax,0 ;verifica se Gx é negativo, caso negativo faz o seu módulo
                    jns gradiente_yComum
			        neg word[mascara_axiliar]

			        gradiente_yComum: 
                        xor ax,ax ;zera os registradores
                        xor dx,dx

                        mov dl,[linha_superior + bx + 1];faz o gradiente Gy
                        add ax,dx 
                        mov dl,[linha_superior + bx - 1]
                        sub ax,dx
                        mov dl,[linha_inferior + bx + 1]
                        add ax,dx 
                        mov dl,[linha_superior + bx - 1]
                        sub ax,dx
                        mov dx,ax
                        mov al,[linha_meio + bx + 1]
                        xor ah,ah
                        push bx
                        mov bh,2
                        mul bh
                        pop bx
                        add ax,dx 
                        mov dx,ax
                        mov al,[linha_meio + bx - 1]
                        xor ah,ah
                        push bx
                        mov bh,2
                        mul bh
                        pop bx
                        sub dx,ax
                        mov ax,dx
                        mov dx,ax

                        or ax,0 ;verifica se Gy é negativo, caso negativo faz o seu módulo      
			            jns gradiente_somaComum
			            neg dx 	

			            gradiente_somaComum: ;com Gx e Gy positivos, faz a sua soma e verifica se excede o limite de 255
                            add dx,[mascara_axiliar]
                            cmp dx,255 

                            jb moveSomaComum
                            mov dx,255
                                    
                            moveSomaComum:
                                mov [pixel_corrente],dl
                                call pixel_plotaFiltro
                                inc word[coluna_atual]
                                inc bx
                                cmp bx,300
                                je coluna_fim

                jmp coluna_criaGradiente

                coluna_fim:
                    dec word[linha_atual]
                    mov word[coluna_atual],0
                    pop cx
                    dec cx
                    cmp cx,0
                    je gradiente_sai
    
            jmp linha_criaComumG
            gradiente_sai:
	            mov bx,[arquivo_fecha];Fecha arquivo 
                mov ah,3eh
                mov al,00h
                int 21h
	
                pop dx;recupera contexto
                pop cx
                pop bx
                pop ax
                ret  

;-----------------------------------------------------------------------------------;	
;                        Mudar a cor da Direita para Preto                          ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;
;   -2) deve usar a dimensão 300x300 (x->linha x y->coluna)                         ;
;   -3) deve plotar X x Y pintando na cor preta:                                    ;
;       X = sendo a coluna atual                                                    ;   
;       Y = sendo a linha  atual                                                    ;
;   -4) deve crementar a coluna e decrementar a linha no processo                   ;
;   -5) deve recuperar o contexto dos registradores utilizados                      ;                              
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;                                                                                                                   
;-----------------------------------------------------------------------------------;
        imagem_direitaP:    
            push    cx ;salva contexto       
            push    ax
            push    dx
            push    bx

            mov word[linha_atual],0
            mov word[coluna_atual],0
            mov cx,300      ;X a ser plotado
            linha_direita:
                push cx
                mov cx, 300 ;Y a ser plotado

		        coluna_direita:
		            call pixel_plotaDireita 
                    inc word[coluna_atual] ;incrementa a coluna
                loop coluna_direita

                dec word[linha_atual] ;decrementa a linha
                mov word[coluna_atual],0
                pop cx
            loop linha_direita
	
            pop   bx ;recupera contexto 
            pop   dx
            pop   ax    
            pop   cx
            ret
	


;-----------------------------------------------------------------------------------;	
;         Mudar a cor dos Pixeis da Dimensão 333 x 389 para Preto na Direita        ;  
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;  
;   -2) deve usar a dimensão 333x389 (x->linha x y->coluna)                         ; 
;   -3) deve plotar X x Y pintando na cor preta:                                    ; 
;       X = sendo a coluna atual                                                    ; 
;       Y = sendo a linha  atual                                                    ; 
;   -4) deve recuperar o contexto dos registradores utilizados                      ;                         
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;        mudar cor das linhas = arquivo line.asm                                    ;                                                                                   
;-----------------------------------------------------------------------------------;
        pixel_plotaDireita: 
            push ax ;salva contexto 
            push bx
            push dx

            mov byte[cor],preto ;pintar de preto  

            mov bx,[coluna_atual]
            add bx,333 ;X a ser plotado
            push bx  

            mov bx,[linha_atual]
            add bx,389 ;Y a ser plotado
            push bx  

            call plot_xy ;rotina retirada do line.asm

            pop dx ;recupera contexto 
            pop bx
            pop ax
            ret


;-----------------------------------------------------------------------------------;	
;        Rotina Auxiliar para Aplicação de Filtros - Leitura da Linha Inicial       ;  
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ; 
;   -2) deve ler somente as 3 linhas corrente do arquivo                            ;
;        para aplicar o filtro                                                      ;
;   -3) deve ler 1 byte de char por vez (byte a byte)                               ;
;   -4) deve ser interrompido pela interrupção 3Fh                                  ;
;   -5) deve realizar os seguistes passos para as linhas                            ;
;       superior->meio->inferior:                                                   ;
;           ler um espaço (caso seja um novo pixel)                                 ;
;           converter de  ascii para decimal                                        ;
;           agrupar os pixeis                                                       ;
;           incrementar o pixel (para saber está no limite 300)                     ;
;   -6)deve retornar o contexto                                                     ;                         
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE:int 21h= https://4beginner.com/8086-Assembly-Language-INT-21h-Dos-Interrupt ;
;       laboratórios e slides de aulas presenciais                                  ;                                                                                   
;-----------------------------------------------------------------------------------;
        linha_leituraInicial:
            push ax ;salva contexto
            push bx
            push cx
            push dx
                    
            mov ah,3dh        
            mov al,00h
            mov dx,arquivo_nome
            int 21h
            mov [arquivo_fecha],ax  

            mov bx, [arquivo_fecha]
            mov dx, buffer              ;byte lido em bx
            mov cx,1                    ;1 byte por vez
            mov ah,3Fh                  ;Interrupção
            int 21h                 
            mov word[pixel_lido],0          ;pixel lido

	        linha_auxSuperior:
                mov bx,[arquivo_fecha]
                mov dx, buffer
                mov cx,1 
                mov ah,3Fh      
		        int 21h       
		        mov al, [buffer]

		        mov [ascii],al ;espaço lido = novo pixel lido
                cmp al,20h
                je pixel_proximoSuperior
                call converte_asciiXdecimal
	        jmp linha_auxSuperior
     
            pixel_proximoSuperior:
                call pixel_agrupa ;agrupar os pixeis
                mov ah,[pixel_decimal]
                mov bx,[pixel_lido]
                mov [linha_superior + bx],ah

                inc word[pixel_lido] ;incrementar o pixel
                cmp word[pixel_lido],300
	        jne linha_auxSuperior

            mov word[pixel_lido],0
            linha_auxMeio:
                mov bx,[arquivo_fecha]
                mov dx, buffer
                mov cx,1      
                mov ah,3Fh      
                int 21h       
                mov al, [buffer]
                mov [ascii],al
	            cmp al,20h
                je pixel_proximoMeio
                call converte_asciiXdecimal
	        jmp linha_auxMeio
	  
            pixel_proximoMeio:
                call pixel_agrupa
                mov ah,[pixel_decimal]
                mov bx,[pixel_lido]
                mov [linha_meio + bx],ah

                inc word[pixel_lido]
                cmp word[pixel_lido],300
            jne linha_auxMeio
	  
            mov word[pixel_lido],0
            linha_auxInferior:
                mov bx,[arquivo_fecha]
                mov dx, buffer
                mov cx,1      
                mov ah,3Fh      
                int 21h       
                mov al, [buffer]
                mov [ascii],al
                cmp al,20h
                je pixel_proximoInferior
                call converte_asciiXdecimal
            jmp linha_auxInferior
	  
            pixel_proximoInferior:
                call pixel_agrupa
                mov ah,[pixel_decimal]
                mov bx,[pixel_lido]

                mov [linha_inferior + bx],ah
                inc word[pixel_lido]
                cmp word[pixel_lido],300
                jne linha_auxInferior
	   
                sair_inicial:
                    pop dx ;recupera o contexto
                    pop cx
                    pop bx
                    pop ax
                    ret 
;-----------------------------------------------------------------------------------;	
;                      Conversão de Dados   Ascii x Decimal                         ;  
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   1) deve salvar o contexto dos registradores utilizados                          ;
;   2) deve fazer Numero em ASCCI - 30h                                             ;
;   3) deve fazer um shift-left:                                                    ;
;        unidade<= novo valor (lido)                                                ;
;        dezena<= valor anterior (lido)...                                          ;
;   4) deve recuperar o contexto dos registradores utilizados                       ;                                                                                                          
;-----------------------------------------------------------------------------------;
; FONTE: baseado no Lab 04: Funções em Assembly (Função Fibonacci)                  ;
;        laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        converte_asciiXdecimal:
            push ax ;salva contexto
	        push cx
   
            xor cx,cx
            mov al,[ascii]
            sub al,30h
            mov cl, byte[pixel_unidade] 
            mov ch, byte[pixel_dezena] 

            mov byte[pixel_unidade],al ;shift - left dos pixeis auxiliares
            mov byte[pixel_dezena],cl  
            mov byte[pixel_centena],ch  
                    
            pop cx ;recupera contexto
            pop ax
            ret

;-----------------------------------------------------------------------------------;	
;                       Agrupamento  de Dados  (Pixeis)                             ;  
;                                                                                   ;                                                                   
;Comentários:                                                                       ;     
;   1) deve salvar o contexto dos registradores utilizados                          ;  
;   2) deve agrupar os pixeis para formar um numero decimal                         ;  
;      decimal <= 100* (centena) + 10* (dezena) + 1* (unidade)                      ;  
;   3) deve zerar pixel_centena, pixel_dezena e pixel_unidade                       ;  
;   4) deve recuperar o contexto dos registradores utilizados                       ;                                                                                                          
;-----------------------------------------------------------------------------------;
; FONTE: baseado no Lab 04: Funções em Assembly (Função Fibonacci)                  ;
;        laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        pixel_agrupa:
            push ax ;salvando o contexto
            push bx
            push cx

            xor ah,ah   ;zerando
            xor ch,ch
                    
            ;agrupamento
            mov al,byte[pixel_centena]
            mov bl,100
            mul bl
            mov cx,ax 
                    
            xor ah,ah
            mov al,byte[pixel_dezena]
            mov bl,10
            mul bl
            add cx,ax
                    
            xor ah,ah
            mov al,[pixel_unidade]
            add cx,ax 
                    
            mov byte[pixel_decimal],cl ; move para o decimal

            mov byte[pixel_unidade],0 ;zera os pixeis auxiliares
            mov byte[pixel_dezena],0
            mov byte[pixel_centena],0

            pop   cx ;recupera contexto
            pop   bx
            pop   ax
            ret

;-----------------------------------------------------------------------------------;	
;        Rotina Auxiliar para Aplicação de Filtros - Leitura da Linha Proxima       ;  
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ; 
;   -2) deve trocar as linhas (o filtro aplica 3 linhas por vez):                   ;
;       linha do meio antiga <= linha superior antiga                               ;
;       linha inferior antiga <= linha do meio antiga                               ;
;   -3) deve ler apenas a linha inferior (nova)                                     ;
;   -4) deve ler 1 byte de char por vez (byte a byte)                               ;
;   -5) deve ler um espaço, caso seja um novo pixel (numero)                        ;
;   -6) deve converter de  ascii para decimal                                       ;
;   -7) deve agrupar os pixeis                                                      ;                         
;                                                                                   ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE:int 21h= https://4beginner.com/8086-Assembly-Language-INT-21h-Dos-Interrupt ;
;       Laboratórios e Slides de aulas presenciais                                  ;                                                                                   
;-----------------------------------------------------------------------------------;
        linha_leituraProxima:
            push ax ;salva contexto
            push bx
            push cx
            push dx
            mov bx,0
            mov cx,300

            linha_troca:
                mov al,[linha_meio + bx]
                mov [linha_superior + bx],al
                mov al,[linha_inferior + bx]
                mov [linha_meio + bx], al
                inc bx
            loop linha_troca
	  
            mov word[pixel_lido],0
            linha_inferiorNova:
                mov bx,[arquivo_fecha]
                mov dx, buffer
                mov cx,1      
                mov ah,3Fh      
                int 21h
                cmp ax,cx
                jne sair_proximo   

                mov al, [buffer]
                mov [ascii],al
                cmp al,20h
                je pixel_proximoInferiorNovo
                call converte_asciiXdecimal
                jmp linha_inferiorNova
	  
                pixel_proximoInferiorNovo:
                    call pixel_agrupa
                    mov ah,[pixel_decimal]
                    mov bx,[pixel_lido]
                    mov [linha_inferior + bx],ah
                    inc word[pixel_lido]
                    cmp word[pixel_lido], 300
                jne linha_inferiorNova
                    
                sair_proximo: ;retorna contexto
                pop dx 
                pop cx
                pop bx
                pop ax
                ret 

;-----------------------------------------------------------------------------------;	
;                              Plota Filtro de Pixeis                               ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto, com push de cada registrador                        ; 
;   -2) deve utilizar a cor referente ao pixel corrente                             ; 
;   -3) deve plotar X x Y do filtro:                                                ; 
;       X = sendo a coluna atual                                                    ; 
;       Y = sendo a linha  atual                                                    ; 
;   -4) deve recuperar o contexto                                                   ;                                                                                                         
;-----------------------------------------------------------------------------------;
; FONTE:  slides das aulas presenciais, laboratório  e arquivo line.asm             ;                                                                                   
;-----------------------------------------------------------------------------------;
        pixel_plotaFiltro:
            push ax ;salcando o contexto
            push bx
            push dx

            mov bl,16 ;cor referente ao pixel
            mov al,byte[pixel_corrente]
            xor ah,ah
            div bl 
            mov byte[cor],al

            mov bx,[coluna_atual] ;X a ser plotado 
            add bx,333
            push bx 

            mov bx,[linha_atual] ;Y a ser plotado
            add bx,389
            push bx   
            call plot_xy ;rotina retirada do line.asm
                    
            pop dx ;recupera contexto
            pop bx
            pop ax
            ret 


;-----------------------------------------------------------------------------------;	
;                              Escolha da Opção Sair                                ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve mudar a cor para amarelo (selecionar)                                  ;
;   -2) deve mostar a mensagem referente ao sair                                    ;
;   -3) deve manter os outros campos em branco (outras opções)                      ;
;   -4) deve sair do programa                                                       ;                                                                                                         
;-----------------------------------------------------------------------------------;
; FONTE:  mudar cor das linhas = arquivo line.asm                                   ;                                                                                   
;-----------------------------------------------------------------------------------;
        b_sair:
            mov byte[cor],amarelo
            call interface_msgS   

            mov byte[cor],branco_intenso                   
            call interface_msgA   
            call interface_msgFPB 
            call interface_msgFBA 
            call interface_msgG  
            call interface_msgID 
                	
            jmp sair ;saindo

;-----------------------------------------------------------------------------------;
;                              Sair do Programa                                     ;                                                                                   
;-----------------------------------------------------------------------------------;
        sair:
            mov ah,0                
            mov al,[modo_anterior]    
            int 10h
            mov ax,4c00h
            int 21h



;-----------------------------------------------------------------------------------;	
;                   Escolha da Opção Filtro Passa Baixa na Interface                ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve mudar a cor para amarelo (selecionar)                                  ;
;   -2) deve mostar a mensagem referente ao passa baixa                             ;
;   -3) deve manter os outros campos em branco (outras opções)                      ;
;   -4) deve apagar o mouse                                                         ;
;   -5) deve realizar a operação de filtro passa                                    ;
;   -6) deve ascender o mouse                                                       ;
;   -7) deve voltar o modo do mouse para clique teste                               ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: ligar mouse = https://stanislavs.org/helppc/int_33-1.html                  ;
;        apagar mouse = https://stanislavs.org/helppc/int_33-2.html                 ; 
;        mudar cor das linhas = arquivo line.asm                                    ;
;       Laboratórios e Slides de aulas presenciais                                  ;                                                                                   
;-----------------------------------------------------------------------------------;
        b_filtroPassaBaixa:
            mov byte[cor],amarelo ;pintar de amarelo (selecionado)
            call interface_msgFPB 

            mov byte[cor],branco_intenso  ;pintar de branco_intenso                 
            call interface_msgA   
            call interface_msgS 
            call interface_msgFBA   
            call interface_msgG  
            call interface_msgID 
                    
            mov ax,2h ;apagando o mouse
	        int 33h

            call filtroPassaBaixa
                
            mov ax,1h ;mostrando o mouse
	        int 33h 	

            jmp clique_teste

;-----------------------------------------------------------------------------------;	
;                      Construção do Filtro Passa Baixa                             ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;      
;   -2) deve checar se o arquivo foi aberto para usar  o filtro                     ;
;   -3) deve recuperar o contexto dos registradores utilizados                      ;                                                                                                                                                                                   
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        filtroPassaBaixa:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            cmp byte[imagem_aberta],0
            jne aplica_filtroPB

            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
            ret 


;-----------------------------------------------------------------------------------;	
;                        Aplicação do Filtro Passa Baixa                            ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;                                                                                   ;                                                                   
;   -1) deve ler 3 linhas por vez do arquivo                                        ;
;   -2) deve plotar o filtro                                                        ;
;   -6) deve fechar o arquivo após aplicar filtro                                   ;
;   -7) deve recuperar o contexto dos registradores                                 ;
;                                                                                   ;  
;       Legenda<                                                                    ;
;       Area Especial = trata das 3 primeiras linhas do arquivo de forma diferente  ;
;       Area Comum = trata do restantes das linhas  de forma geral                  ;                                                                                                                                                                                   
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        aplica_filtroPB:
            call imagem_direitaP
            call linha_leituraInicial

            mov word[coluna_atual],0
            mov word[linha_atual],0
            mov bx,0
            mov cx,300

            linha_pintaPretoFPB:
                mov byte[pixel_corrente],preto
                call pixel_plotaFiltro   ;plotar o filtro           
                inc word[coluna_atual]
                inc bx
            loop linha_pintaPretoFPB

            dec word[linha_atual]
            mov word[coluna_atual],0
            mov bx,0
            mov cx,300

            linha_criaEspecialFPB:
                xor ax,ax ;zera os registradores
                xor dx,dx

                mov al,byte[linha_meio + bx]
                mov dl,byte[linha_meio + bx + 1]
                add ax,dx
                mov dl,byte[linha_meio + bx - 1]
                add ax,dx
                mov dl,byte[linha_superior + bx]
                add ax,dx
                mov dl,byte[linha_superior + bx + 1]
                add ax,dx
                mov dl,byte[linha_superior + bx - 1]
                add ax,dx
                mov dl,byte[linha_inferior + bx]
                add ax,dx
                mov dl,byte[linha_inferior + bx + 1]
                add ax,dx
                mov dl,byte[linha_inferior + bx - 1]
                add ax,dx

                mov dl,9
                div dl
                mov [pixel_corrente],al
                call pixel_plotaFiltro
                inc word[coluna_atual]
                inc bx
	            loop linha_criaEspecialFPB
                dec word[linha_atual]
                mov word[coluna_atual],0
                mov cx,298

                linha_criaComumFPB:
                    push cx ;salva o contexto

                    call linha_leituraProxima  ;ler o proximo conjunto de tres linhas
                    mov bx,0

                    coluna_criaFPB:
                        xor ax,ax ;zera os registradores
                        xor dx,dx

                        mov al,byte[linha_meio + bx]
                        mov dl,byte[linha_meio + bx + 1]
                        add ax,dx
                        mov dl,byte[linha_meio + bx - 1]
                        add ax,dx
                        mov dl,byte[linha_superior + bx]
                        add ax,dx
                        mov dl,byte[linha_superior + bx + 1]
                        add ax,dx
                        mov dl,byte[linha_superior + bx - 1]
                        add ax,dx
                        mov dl,byte[linha_inferior + bx]
                        add ax,dx
                        mov dl,byte[linha_inferior + bx + 1]
                        add ax,dx
                        mov dl,byte[linha_inferior + bx - 1]

                        add ax,dx
                        mov dl,9
                        div dl
                        mov [pixel_corrente],al
                        call pixel_plotaFiltro
                        inc word[coluna_atual]
                        inc bx
                        cmp bx,300
		            jne coluna_criaFPB

                        dec word[linha_atual]
                        mov word[coluna_atual],0
                        pop cx
                loop linha_criaComumFPB
	
                mov bx,[arquivo_fecha] ;fechadando o filtro
                mov ah,3eh
                mov al,00h
                int 21h
                    
                pop dx  ;recupera contexto
                pop cx
                pop bx
                pop ax
                ret


;-----------------------------------------------------------------------------------;	
;                   Escolha da Opção Filtro Passa Alta na Interface                 ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve mudar a cor para amarelo (selecionar)                                  ;
;   -2) deve mostar a mensagem referente ao passa alta                              ;
;   -3) deve manter os outros campos em branco (outras opções)                      ;
;   -4) deve apagar o mouse                                                         ;
;   -5) deve realizar a operação de filtro passa alta                               ;
;   -6) deve ascender o mouse                                                       ;
;   -7) deve voltar o modo do mouse para clique teste                               ;                                                                                                           
;-----------------------------------------------------------------------------------;
; FONTE: ligar mouse = https://stanislavs.org/helppc/int_33-1.html                  ;
;        apagar mouse = https://stanislavs.org/helppc/int_33-2.html                 ; 
;        mudar cor das linhas = arquivo line.asm                                    ;
;       Laboratórios e Slides de aulas presenciais                                  ;                                                                                   
;-----------------------------------------------------------------------------------;
        b_filtroPassaAlta:
            mov byte[cor],amarelo
            call interface_msgFBA 

            mov byte[cor],branco_intenso                   
            call interface_msgA   
            call interface_msgS   
            call interface_msgFPB 
            call interface_msgG  
            call interface_msgID 

            mov ax,2h ;apagando o mouse
	        int 33h

            call filtroPassaAlta
                
            mov ax,1h ;mostrando o mouse
	        int 33h 	

            jmp clique_teste

 

;-----------------------------------------------------------------------------------;	
;                      Construção do Filtro Passa Alta                              ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;   -1) deve salvar o contexto dos registradores utilizados                         ;      
;   -2) deve checar se o arquivo foi aberto para usar  o filtro                     ;
;   -3) deve recuperar o contexto dos registradores utilizados                      ;                                                                                                                                                                                   
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        filtroPassaAlta:
            push ax ;salva contexto
            push bx
            push cx
            push dx

            cmp byte[imagem_aberta],0
            jne aplica_filtroPA

            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
            ret 



;-----------------------------------------------------------------------------------;	
;                        Aplicação do Filtro Passa Baixa                            ;
;                                                                                   ;                                                                   
;Comentários:                                                                       ;
;                                                                                   ;
;   -1) deve ler 3 linhas por vez do arquivo                                        ;
;   -2) deve plotar o filtro                                                        ;
;   -3) deve criar um pixel auxiliar (máscara auxiliar)                             ;
;   -4) deve verificar o valor dessa máscara                                        ;
;       Negativo:  muda para o valor mais pr�ximo da scala de cinza, no caso "0"   ;
;       Positivo:  verifica se o valor deu acima de 255, caso excede esse valor     ;
;                  muda para o valor mais próximo (o valor 255)                     ;
;   -5) deve fechar o arquivo após aplicar filtro                                   ;
;   -6) deve recuperar o contexto dos registradores                                 ;
;                                                                                   ;  
;       Legenda<                                                                    ;
;       Area Especial = trata das 3 primeiras linhas do arquivo de forma diferente  ;
;       Area Comum = trata do restantes das linhas  de forma geral                  ;                                                                                                                                                                                   
;-----------------------------------------------------------------------------------;
; FONTE: laboratórios e slides de aulas presenciais                                 ;  
;-----------------------------------------------------------------------------------;
        aplica_filtroPA:
            call imagem_direitaP
            call linha_leituraInicial;ler 3 primeiras linhas do arquivo

            mov word[coluna_atual],0 
            mov word[linha_atual],0
            mov bx,0
            mov cx,300

            linha_pintaPretoFPA:
                mov byte[pixel_corrente],preto
                call pixel_plotaFiltro   ;plotar o filtro           
                inc word[coluna_atual]
                inc bx
            loop linha_pintaPretoFPA

            dec word[linha_atual]
            mov word[coluna_atual],0
            mov bx,0
            mov cx,300

	        linha_criaEspecialFPA:
                xor ax,ax ;zera os registradores
                xor dx,dx
                    
                mov al,[linha_meio + bx]
                mov dh,9
                mul dh
                xor dh,dh
                mov dl,[linha_meio + bx + 1]
                sub ax,dx
                mov dl,[linha_meio + bx - 1]
                sub ax,dx
                mov dl,[linha_superior + bx]
                sub ax,dx
                mov dl,[linha_superior + bx + 1]
                sub ax,dx
                mov dl,[linha_superior + bx - 1]
                sub ax,dx
                mov dl,[linha_inferior + bx]
                sub ax,dx
                mov dl,[linha_inferior + bx + 1]
                sub ax,dx
                mov dl,[linha_inferior + bx - 1]
                sub ax,dx

                mov [mascara_axiliar],ax	;cria máscara e verifica se o seu valor deu negativo    
                or  ax, 0         
                jns mascara_positivaEspecial; 
                mov word[mascara_axiliar],0	
                        
                mascara_positivaEspecial:
                    mov ax,[mascara_axiliar]
                    cmp ax,255  ; verifica se o valor deu acima de 255
                    jb moveEspecial
                    mov ax,255
                    moveEspecial:
                        mov [pixel_corrente],al
                        call pixel_plotaFiltro   ;plotar o filtro           
                        inc word[coluna_atual]
                        inc bx
	        loop linha_criaEspecialFPA

            dec word[linha_atual]
	        mov word[coluna_atual],0

            mov cx,298
            linha_criaComumFPA:
                push cx ;salva o contexto
                call linha_leituraProxima  ;ler o proximo conjunto de tres linhas
                mov bx,0

                coluna_criaFPA:
                    xor ax,ax ;zera os registradores
                    xor dx,dx

                    mov al,[linha_meio + bx]
                    mov dh,9
                    mul dh
                    xor dh,dh
                    mov dl,[linha_meio + bx + 1]
                    sub ax,dx
                    mov dl,[linha_meio + bx - 1]
                    sub ax,dx
                    mov dl,[linha_superior + bx]
                    sub ax,dx
                    mov dl,[linha_superior + bx + 1]
                    sub ax,dx
                    mov dl,[linha_superior + bx - 1]
                    sub ax,dx
                    mov dl,[linha_inferior + bx]
                    sub ax,dx
                    mov dl,[linha_inferior + bx + 1]
                    sub ax,dx
                    mov dl,[linha_inferior + bx - 1]
                    sub ax,dx

                    mov [mascara_axiliar],ax ;cria máscara e verifica se o seu valor deu negativo   
                    or  ax, 0          
                    jns mascara_positivaComum
                    mov word[mascara_axiliar],0 ;
                            
                    mascara_positivaComum:
                        mov ax,[mascara_axiliar]
                        cmp ax,255 ;verifica se o valor deu acima de 255
                        jb moveComum
                        mov ax,255

                        moveComum:
			                mov [pixel_corrente],al
                            call pixel_plotaFiltro ;plota filtro
                            inc word[coluna_atual]
                            inc bx
                            cmp bx,300

                jne coluna_criaFPA

                dec word[linha_atual]
                mov word[coluna_atual],0
                pop cx

	        loop linha_criaComumFPA
	
            mov bx,[arquivo_fecha] ;fecha arquivo
            mov ah,3eh
            mov al,00h
            int 21h	
                    
            pop dx ;recupera contexto
            pop cx
            pop bx
            pop ax
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

	cor           db    branco_intenso
	  
    preto			equ   0
    azul			equ   1
    verde			equ   2
    cyan      		equ   3
    vermelho    	equ   4
    magenta     	equ   5
    marrom      	equ   6
    branco      	equ   7
    cinza     		equ   8
    azul_claro    	equ   9
    verde_claro   	equ   10
    cyan_claro    	equ   11
    rosa      		equ   12
    magenta_claro 	equ   13
    amarelo     	equ   14
    branco_intenso  equ   15
        
        
    modo_anterior 	db    0
    deltax      	dw    0
    deltay      	dw    0
	  
;-----------------------------------------------------------------------------------;
;                          MENSAGENS DO MENU DE FUNÇÕES                             ;  
;-----------------------------------------------------------------------------------;
 
    msg_a			    db    	'ABRIR'
    msg_s			    db      'SAIR'
    msg_fpb         	db      'PASSA-BAIXA'
    msg_fpa         	db      'PASSA-ALTA'
    msg_g         	    db      'GRADIENTE'
    msg_id         	    db      'Sistemas Embarcados I - 2022/1 - Dionatas Santos Brito'
    ;mens7         	db      'SAIR'
	  

;-----------------------------------------------------------------------------------;
;                   VARIÁVEIS PARA LEITURAR/ ABERTURA DE ARQUIVOS                   ;  
;-----------------------------------------------------------------------------------;

    arquivo_nome		db		'imagem.txt$',00h
	arquivo_fecha   	dw      0
	buffer        	    db    	0
	imagem_aberta       db    	0
    pixel_decimal      	db    	0
	pixel_dezena       	db    	0
	pixel_unidade       db    	0
	pixel_centena       db      0
    pixel_corrente     	db		0
    pixel_lido   	    dw   	0
    linha_atual     	dw    	0
    coluna_atual  	    dw    	0
    byte_lido  	        dw 		0
    mascara_axiliar		dw		0
    ascii			    db		0
    linha_superior      resb    300
    linha_meio    	    resb    300
    linha_inferior      resb    300
      
;-----------------------------------------------------------------------------------
	
	segment stack stack
	resb    512
	stacktop:
;----------------------------------------------------------------------------------- 