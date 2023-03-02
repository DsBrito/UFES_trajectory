#X = Y * Z com X,Y,Z [4x4]
# C code:
#void mm (int x[][],int y[][], int z[][]) {  
#	int i, j, k;
#	for (i = 0; i! = 32; i = i + 1)
#	    for (j = 0; j! = 32; j = j + 1)
#                      for (k = 0; k! = 32; k = k + 1)
#                             x[i][j] = y[i][k] * z[k][j];   }

.data
#Y preenchido com valores 
Y: .word 
50, 2, 34, 79, 85, 22, 28, 57,
77, 25, 53, 99, 22, 87, 72, 70,
13, 28, 91, 72, 56, 74, 69, 93,
61, 18,  4, 75, 56, 38, 93, 6,
39, 26, 84, 23, 48, 12, 80, 24,
36, 33, 23, 57, 19, 94, 27, 32,
22, 17,  4, 77, 90, 72, 70, 50,
89, 74, 24, 45, 11, 17, 50, 49
Z: .word 
1, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 1, 0, 0, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 1, 0, 0,
0, 0, 0, 0, 0, 0, 1, 0,
0, 0, 0, 0, 0, 0, 0, 1

X: .space 256

tam: .word 8 #dimensão da matriz quadrada
newTab: .asciiz "\t"
newLine: .asciiz "\n"

.text
la $a0, X
la $a1, Y
la $a2, Z

li $t1, 8 #dimensão da matriz
li $s0, 0  
L1: 	li $s1, 0  
L2: 	li $s2, 0  
	sll $t2, $s0, 3
	addu $t2, $t2, $s1
	sll $t2, $t2, 2
	addu $t2, $a0, $t2
	lw $t4, 0($t2)
L3: 	sll $t0, $s2, 3
	addu $t0, $t0, $s1
	sll $t0, $t0, 2
	addu $t0, $a2, $t0
	lw $t6, 0($t0)
	
	sll $t0, $s0, 3
	addu $t0, $t0, $s2
	sll $t0, $t0, 2
	addu $t0, $a1, $t0
	lw $t8, 0($t0)
	
	mult $t6, $t8
	mflo $s7
	add $t4, $t4, $s7
	addi $s2, $s2, 1	
	bne $s2, $t1, L3
	
	sw $t4, 0($t2)
	
	addi $s1, $s1, 1	
	bne $s1, $t1, L2
	
	addi $s0, $s0, 1
	bne $s0, $t1, L1
	
#Imprime Matriz

# contador de colunas
move $t0, $zero
# contador de elementos
move $t1, $zero

# ponteiro para X - resultado
la $t2, X
lw $t5, tam
# numero de elementos da matriz quadrada
mul $t3, $t5, $t5

while1: 
	beq $t3, $t1, exit
	lw $t4, 0($t2)
	# imprime elemento após tabulação	
	li $v0, 4
	la $a0, newTab
	syscall
	li $v0, 1
	move $a0, $t4
	syscall
	# incrementa contadores
	addi $t2, $t2, 4
	addi $t1, $t1, 1
	addi $t0, $t0, 1
	# verifica se é necessário quebrar linha
	beq $t0, $t5, end1
	j while1
end1:
	# quebra linha
	li $v0, 4
	la $a0, newLine
	syscall	
	move $t0, $zero
	j while1
		
exit:
li $v0, 10
syscall
