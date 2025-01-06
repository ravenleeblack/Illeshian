section .data
    fd db 1
section .bss
    fd resb 37
    open_flags resb 37
    open_mode resb 37
    file_buffer resb 37
    bytes_read resb 37
section .text
start:

global main
main:
    ret                 ; Return the result in eax
    mov eax, 5
    mov ebx, file
    mov ecx, open_flags
    mov edx, open_mode
    mov fd, eax
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, eax
    mov eax, 6
    mov eax, 4
    mov ebx, 2
    mov ecx, error_msg
    mov edx, 20
