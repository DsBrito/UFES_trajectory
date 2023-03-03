.data:
	string0: .asciiz "Digite o primeiro operando:"
	string1: .asciiz "Digite o segundo operando:"
	string2: .asciiz "\nEscolha a operacao: (1) +, (2) -, (3) *, (4) /\n"
	string3: .asciiz "\nResultado:"
	string4: .asciiz "\nDeseja fazer outra operacao? (1) Sim, (0) Nao\n"
	string5: .asciiz "Obrigado! Python 2 Mips\n"
	x: .word 0
	op1: .word 0
	op2: .word 0
	res: .word 0
	buffer: .space 20

.text:

.globl main

main:
	li $s0, 1
	la $t0, x
	move $t0, $s0
	 loop0:
	li $s0, 0
	beq $t0, $s0, endLoop0
	la $s1, string0
	la $a0, ($s1)
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s1, $v0
	la $t1, op1
	move $t1, $s1
	la $s1, string1
	la $a0, ($s1)
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s1, $v0
	la $t2, op2
	move $t2, $s1
	la $s1, string2
	la $a0, ($s1)
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s1, $v0
	move $t0, $s1
	li $s1, 1
	bne $t0, $s1, else0
	add $s2, $t1, $t2
	la $t3, res
	move $t3, $s2
	j endElse0
	 else0:
	 endElse0:
	li $s2, 2
	bne $t0, $s2, else1
	sub $s3, $t1, $t2
	move $t3, $s3
	j endElse1
	 else1:
	 endElse1:
	li $s3, 3
	bne $t0, $s3, else2
	mul $s4, $t1, $t2
	move $t3, $s4
	j endElse2
	 else2:
	 endElse2:
	li $s4, 4
	bne $t0, $s4, else3
	div $t1, $t2
	mflo $s5
	move $t3, $s5
	j endElse3
	 else3:
	 endElse3:
	la $s5, string3
	la $a0, ($s5)
	li $v0, 4
	syscall
	li $a0, 10
	li $v0, 11
	syscall
	la $a0, ($t3)
	li $v0, 1
	syscall
	li $a0, 10
	li $v0, 11
	syscall
	la $s5, string4
	la $a0, ($s5)
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s5, $v0
	move $t0, $s5
	j loop0
	 endLoop0:
	la $s5, string5
	la $a0, ($s5)
	li $v0, 4
	syscall
	li $a0, 10
	li $v0, 11
	syscall
