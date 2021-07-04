global _ft_write

extern ___error

section .text

	_ft_write:

			mov rax, 33554436
			syscall
			jc _error
			ret

	_error:

			push rax
			call ___error
			pop qword[rax]
			mov rax, -1
			ret
