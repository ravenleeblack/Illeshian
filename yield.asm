section .data
section .bss
section .text
global yield

yield:
    mov eax, 1
    xor ebx, ebx
    int 0x80
