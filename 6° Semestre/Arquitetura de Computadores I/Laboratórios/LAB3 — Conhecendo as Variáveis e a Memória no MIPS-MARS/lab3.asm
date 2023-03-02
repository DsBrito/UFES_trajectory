.data 0x10010000
var1: .word 0x55 	# var1 is a word (32 bit) with the initial value 0x55
var2: .word 0xaa
 
.text
.globl main
main: addu $s0, $ra, $0 	# save $31 in $16
li $t0, 307   # o numero 307 é referente aos 3 ultimos numeros da matricula de um integrante do grupo (Dionatas)
move $t1, $t0
la $t2, var2
lw $t3, var2
sw $t2, var1
 
# restore now the return address in $ra and return from main
addu $ra, $0, $s0 	# return address back
jr $ra 			# return from main
