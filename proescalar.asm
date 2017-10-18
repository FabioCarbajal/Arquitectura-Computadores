.text
.globl __start
__start:
	la $a1, vec1
	la $a2, vec2
	lw $t2, tam
	l.d $f4, sum
	la $a0, menu 
	li $v0, 4
	syscall
loop:
	l.d $f6,($a1)
	l.d $f8,($a2)
	mul.d $f6,$f6,$f8
	add.d $f4,$f4,$f6
	add $a1,$a1,8
	add $a2,$a2,8
	add $t2,$t2,-1
	bnez $t2,loop
	mov.d $f12,$f4
	li $v0, 3
	syscall
		li $v0,10
		syscall
		
.data
menu1: .ascii "Para calcular el producto escalar de dos vectores escriba 0: \n"
menu2: .ascii "Para calcular el vector producto de dos vectores escriba 1: \n"
tam: .word 3
sum: .double 0
vec1: .double 2.3,5.5,7.1
vec2: .double 1.5,4.1,3.2