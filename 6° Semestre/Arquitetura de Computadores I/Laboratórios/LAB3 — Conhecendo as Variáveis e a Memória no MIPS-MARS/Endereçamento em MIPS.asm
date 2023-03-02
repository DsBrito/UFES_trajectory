#Reserve espaço na memoria para 4 variaveis (var1,var2,var3,var4) de tamanho da palavra 

#1-passo = segmento de data
.data  0x10010000 # segmento de data, aqui é onde ira começar o segmento de data

#2-passo = criar as variaveis do tipo word (no segmento de data) com valores iniciais
var1: .word 4
var2: .word 8192
var3: .word 4096
var4: .word 2048

#3-passo = reservar espaço (no segmento data) para duas variaveis (primeiro e ultimo) do tipo Byte
#primeiro: .byte D
#ultimo: .byte B

#4-passo = fechamento do segmento data e inicio do segmento de texto
.text
.globl main
main: addu $s0,$ra,$0 #salvar 31 em 16

#5 passo = O programa troca os valores das variáveis na memória:
#o novo valor de var1 será o valor inicial de var4,
#o novo valor de var2 será o valor inicial de var3,
#var3 receberá o valor inicial de var2,
#e finalmente o var4 obterá o valor inicial de var1

#5.1 passso (carregar) nos registradores
#Os registradores estao armazendando os valores das variaveis tipo word, carregando a palavra nos registradores %t0 até $t3
lw $t0, var1
lw $t1, var2
lw $t2, var3  #lw destino, origem (levar da memoria para os registradores)
lw $t3, var4

#5.2 passo (mover)
#Apos carregar, os valores armazenados pelos registradores,
#irão ser movidos para outros registradores e assim ser possivel realizar a troca
move $t4,$t0
move $t5,$t1   # move destino,origem (mover)
move $t6,$t2
move $t7,$t3

#5.3 passo (mover inversamente)
#Os registradores 4-7, serao movidos para 0-3
move $t0,$t7
move $t1,$t6
move $t2,$t5
move $t3,$t4

#5.4 passo (mover para a memoria)
#Os registradores invertidos (0-3) serão levados para a memoria 
sw $t0,var1
sw $t1,var2   # sw origem,destino (levar) -
sw $t2,var3
sw $t3,var4



