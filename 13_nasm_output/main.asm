section .data
program_start:
section .data
start:
section .data
main:
section .data
assign_section:
section .bss
fd resb 1
section .bss
assign_section resb 0
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
