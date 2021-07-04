global _ft_read

extern ___error								;permettre a ft_read d'appeler la ft ___error

section .text

	_ft_read:								;fonction // ft_read(unsigned int rdi, void *rsi, size_t rdx)

			mov rax, 33554435				;placer dans rax le code du syscall read
			syscall							;appeler le kernel
			jc _error						;jc (jump if carry flag == 1) erreur de syscall
			ret								;retourner le nombre de char lus dans rax

	_error:									;si le syscall a echoué

			push rax						;sauvegarder la valeur de rax
			call ___error					;appeler ___error
			pop qword[rax]					;replacer le registre rax
			mov rax, -1						;mettre rax a -1
			ret								;retourner rax