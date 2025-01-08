section .data
section .bss
    num_1 resb 5
    num_2 resb 7
section .text
global _start
    extern printf
    jmp (null)
main:
    mov eax, 
    add eax, 
    mov , eax
    push 
    push 
    push 
    push 
    call printf
    add esp, 
    mov eax, 
    test ebx, ebx
    int 80
    call yield
