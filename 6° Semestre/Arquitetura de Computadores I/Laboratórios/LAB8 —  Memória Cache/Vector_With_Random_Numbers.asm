#
# "Random Vector  -- Assembly Version"
#
# This MIPS assembly code -- based on MIPS R3000's instruction set -- first
# receives the number of values to be created (N<=500) in a vector of integers V, 
# then creates random values, and then includes theses values in V
# and prints the Vector elements.
#
# Note: Dimension of the vector (N<=500).
#
# Author: Celso A S Santos
#
	.data
space:	.asciiz " "	# a space string.
line:	.asciiz	"\n"	# a newline string.
colonsp:	.asciiz ": "	# a colon string with space.
array:	.word	0 : 10	# an array of word, for storing values.
size:	.word	10	# actual count of the elements in the array.
max: 	.word	10 	# Set upper bound to 10 (max_int=2147483647)

param_info_string:	.asciiz	"Input number of values (0 < N < 10): "
receive_values_loop_info_string:	.asciiz	"Enter 0 to generate N random values OR an integer for input each value in vector: "
receive_values_loop_iter_string:	.asciiz	"Input value#"
array_string:	.asciiz "V= "

.text

params_info:
	li	$v0, 4			# 4 = print_string syscall.
	la	$a0, param_info_string	# load params_info_string to argument register $a0.
	syscall				# issue a system call.
params:
	li	$v0, 5		# 5 = read_int syscall.
	syscall			# issue a system call.	
	la	$t0, size		# load address of size to $t0.
	sw	$v0, 0($t0)	# store returned value in $v0 to size.	
receive_values_loop_info:
	li	$v0, 4		# 4 = print_string syscall.
	la	$a0, receive_values_loop_info_string	# load receive_values_loop_info_string to argument register $a0.
	syscall			# issue a system call.
	li	$v0, 5		# 5 = read_int syscall.
	syscall			# issue a system call.
	add 	$s0, $0, $v0
receive_values_loop_prep:
	la	$t0, array	# load array to $t0.
	lw	$t1, size		# load size to $t1.
	li	$t2, 0		# loop runner, starting from 0.
receive_values_loop:
	bge	$t2, $t1, receive_values_end	# while ($t2 < $t1).
	li	$v0, 4			# 4 = print_string syscall.
	la	$a0, receive_values_loop_iter_string # load receive_values_loop_iter_string to argument register $a0.
	syscall				# issue a system call.
	li	$v0, 1			# 1 = print_int syscall.
	addi	$a0, $t2, 1		# load (runner + 1) to argument register $a0.
	syscall				# issue a system call.
	li	$v0, 4			# 4 = print_string syscall.
	la	$a0, colonsp		# load colonsp to argument register $a0.
	syscall				# issue a system call.

	beq $s0,$0, if_random
	li	$v0, 5			# 5 = read_int syscall.
	syscall
	move $t7, $v0			# issue a system call.
	j if_not_random
if_random: #Generate random numbers
	addi $v0, $zero, 30      # Syscall 30: System Time syscall
	syscall                  # $a0 will contain the 32 LS bits of the system time
	add $t8, $zero, $a0      # Save $a0 value in $t0 

	addi $v0, $zero, 40       	# Syscall 40: Random seed
	add $a0, $zero, $zero   	# Set RNG ID to 0
	add $a1, $zero, $t8     	# Set Random seed to
	syscall

	addi $v0, $zero, 42        	# Syscall 42: Random int range
	add $a0, $zero, $zero   	# Set RNG ID to 0
	lw $a1, max		# Set upper bound to max
	syscall                  	# Generate a random number and put it in $a0
	
	li $v0, 1   # 1 is the system call code to show an int number
	syscall     # as I said your generated number is at $a0, so it will be printed
	move $t7, $a0
	li	$v0, 4		# 4 = print_string syscall.
	la	$a0, line		# load line to argument register $a0.
	syscall			# issue a system call.
if_not_random:    	
	sw $t7, 0($t0) # store returned random value from syscall in the array.
	addi	$t0, $t0, 4		# increment array pointer by 4.
	addi	$t2, $t2, 1		# increment loop runner by 1.
	j	receive_values_loop	# jump back to the beginning of the loop.
receive_values_end:
	li	$v0, 4			# 4 = print_string syscall.
	la	$a0, array_string	# load sorted_array_string to argument register $a0.
	syscall

	la	$t0, array
	lw	$t1, size
	li	$t2, 0
print_loop:
	bge	$t2, $t1, print_end
	li	$v0, 1
	lw	$a0, 0($t0)
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	addi	$t0, $t0, 4
	addi	$t2, $t2, 1
	j	print_loop
print_end:
	li	$v0, 4
	la	$a0, line
	syscall
	li $v0, 10
	syscall
