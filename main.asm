section .data
    msg db "Hello, World. Testing strand!", 0x0A

section .text
global _start
_start:
    call main
main:
    mov eax, msg
    call strlen
    mov edx, eax
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov ebx, 0
    mov eax, 1
    int 0x80

strlen:
    push ebx
    mov ebx, eax
next_char:
    cmp byte [eax], 0
    jz  finished
    inc eax
    jmp next_char
finished:
    sub eax, ebx
    pop ebx
    ret
