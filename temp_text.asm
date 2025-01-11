section .text
global _start

start:
    extern printf
    extern yield
    jmp main
global main

main:
    mov byte [num_1], 5
    mov byte [num_2], 7
    mov eax, num_1
    add eax, num_2
    mov eax, eax
    push result
    push num_2
    push num_1
    push format
    call printf
    add esp, 16
    mov eax, 1
    test ebx, ebx
    int 0x80
    call yield
