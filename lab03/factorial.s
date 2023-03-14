.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    add t0 a0 x0# counter = n
    addi t1 x0 1# result = 1
loop:
    mul t1 t1 t0# result = result * n
    addi t0 t0 -1# n--
    bne t0 x0 loop# while true
    add a0 t1 x0
    jr ra#return，但为什么打印的是8
