section .data
    format db "The result of %d + %d is: %d", 0
section .bss
    num_1 resb 5
    num_2 resb 7
section .text
global _start
    extern printf
    jmp main
main:
    mov , 1
