.data
	msg: .ascii "Enter a number: \0"
	endl: .ascii "\n"
	
.text
	readingLoop:
		la $a0, msg
		li $v0, 4
		syscall

		li $v0, 5
		syscall

		move $t0, $v0

		bltz $t0, readingLoop

	li $t1, 1
	mtc1 $t1, $f1
	cvt.s.w $f1, $f1
	beq $t0, $zero, endFactorial

	factorial:
		mtc1 $t0, $f3
		cvt.s.w $f3, $f3
		mul.s $f1, $f1, $f3
		mul $t1, $t1, $t0
	addi $t0, $t0, -1
	bgtz $t0, factorial
	
	endFactorial:
	li $v0, 1
	move $a0, $t1
	syscall
	
	# endl ('\n')
	la $a0, endl
	li $v0, 4
	syscall
	
	li $v0, 2
	mov.s $f12, $f1
	syscall
	
	# endl ('\n')
	la $a0, endl
	li $v0, 4
	syscall
	
	# parte da questão 3
	cvt.w.s $f1, $f1
	mfc1 $t1, $f1
	
	move $a0, $t1
	li $v0, 1
	syscall

	li $v0, 10
	syscall
