.data
source:
    .word   3
    .word   1
    .word   4
    .word   1
    .word   5
    .word   9
    .word   0
dest:
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0

.text
main:
    addi t0, x0, 0 #k
    addi s0, x0, 0 #varible sum is in s0
    la s1, source #pointer to source array
    la s2, dest #pointer to dest array
loop:#loop is here :)
    slli s3, t0, 2  #左移，但似乎好像没有任何意义？主要是s3的意思没明白;原来是k*4，将index换算成现实世界的距离
    add t1, s1, s3  #k in t1
    lw t2, 0(t1) #souece[k] in t2
    beq t2, x0, exit  #若source[k]!=0，循环继续
    add a0, x0, t2 #a0 = t2
    addi sp, sp, -8 # stack pointer-8,即扩展两字长
    sw t0, 0(sp) #prologue
    sw t2, 4(sp)
    jal square #调用square函数
    lw t0, 0(sp)#epliogue
    lw t2, 4(sp)
    addi sp, sp, 8#栈指针复原
    add t2, x0, a0 #t2 = a0
    add t3, s2, s3#t3 = s2 + s3
    sw t2, 0(t3)# t2 = *t3
    add s0, s0, t2
    addi t0, t0, 1# k++
    jal x0, loop
square:
    add t0, a0, x0
    add t1, a0, x0
    addi t0, t0, 1
    addi t2, x0, -1
    mul t1, t1, t2
    mul a0, t0, t1
    jr ra
exit:
    add a0, x0, s0
    add a1, x0, x0
    ecall # Terminate ecall