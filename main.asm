BITS 32

section .bss

section .data
	fd dd 1
	error_msg db "Error opening file"
	error_msg equ $ - error_msg

section .text
global start
start:
	extern write
	extern yield
	jmp main
main:
	mov eax, 5
	mov ebx, file
	mov ecx, open_flags
	mov edx, open_mode
	int 0x80

	test eax, eax
	jmp handle_error
	mov fd, eax
	mov eax, 4
	mov ebx, 1
	mov ecx, buffer
	mov edx, eax
	int 0x80

	mov eax, 6
	int 0x80

	jmp yield

; Global block: handle_error
handle_error:
	mov eax, 4
	mov ebx, 2
	mov ecx, error_msg
	mov edx, 20
	int 0x80

	jmp yield
