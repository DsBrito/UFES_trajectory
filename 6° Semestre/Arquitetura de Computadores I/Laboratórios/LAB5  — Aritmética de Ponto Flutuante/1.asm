.data
	Zero.s:		.word		0x00000000
	PlusInf.s:	.word		0x7F800000
	MinusInf.s:	.word		0xFF800000
	PlusNaN.s:	.word		0x7F800001
	MinusNaN.s:	.word		0xFF800001

	Zero.d: 	.word		0x00000000
	Zero_l.d: 	.word		0x00000000
	PlusInf.d:	.word		0x7FF00000
	PlusInf_l.d:	.word		0x00000000
	MinusInf.d:	.word		0xFFF00000
	MinusInf_l.d:	.word		0x00000000
	PlusNaN.d:	.word		0x7FF00000
	PlusNaN_l.d:	.word		0x00000011
	MinusNaN.d:	.word		0xFFF00000
	MinusNaN_l.d:	.word		0x00000011
	

	endl: .asciiz "\n"

.text
	lwc1 $f0, Zero.s
	lwc1 $f1, PlusInf.s
	lwc1 $f2, MinusInf.s
	lwc1 $f3, PlusNaN.s
	lwc1 $f4, MinusNaN.s
	
	lw $t0, Zero_l.d
	lw $t1, Zero.d
	mtc1.d $t0, $f6
	lw $t0, PlusInf_l.d
	lw $t1, PlusInf.d
	mtc1.d $t0, $f8
	lw $t0, MinusInf_l.d
	lw $t1, MinusInf.d
	mtc1.d $t0, $f10
	lw $t0, PlusNaN_l.d
	lw $t1, PlusNaN.d
	mtc1.d $t0, $f14
	lw $t0, MinusNaN_l.d
	lw $t1, MinusNaN.d
	mtc1.d $t0, $f16

	mov.s $f12, $f0
	li $v0, 2
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.s $f12, $f1
	li $v0, 2
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.s $f12, $f2
	li $v0, 2
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.s $f12, $f3
	li $v0, 2
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.s $f12, $f4
	li $v0, 2
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.d $f12, $f6
	li $v0, 3
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.d $f12, $f8
	li $v0, 3
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.d $f12, $f10
	li $v0, 3
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.d $f12, $f14
	li $v0, 3
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	
	mov.d $f12, $f16
	li $v0, 3
	syscall
	la $a0, endl
	li $v0, 4
	syscall

	li $v0, 10
	syscall
