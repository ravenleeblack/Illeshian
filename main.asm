section .data
    fd db 1
section .bss
    fd resb 37
    open_flags resb 37
    open_mode resb 37
    file_buffer resb 37
    bytes_read resb 37
global _start
    jmp main
main:
    mov eax, 5
    mov ebx, file
    mov ecx, open_flags
    mov edx, open_mode
    test eax, eax
    jng handle_error
    mov fd, eax
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, eax
    mov eax, 6
    jmp yield
    ret
.handle_error:
    mov eax, 4
    mov ebx, 2
    mov ecx, error_msg
    mov edx, 20
    jmp yield
