global _ft_strcpy

section .text

	_ft_strcpy:								;fonction // ft_strcpy(char *rdi, const char *rsi)

			push rbx						;sauvegarder rbx sur la stack
			mov rax, rdi					;copier dest dans rax
			mov rbx, rsi					;copier src dans rbx
			cmp rbx, 0						;verifier que rbx existe
			je _return						;si rbx vaut zero retourner dest/rax
			mov rcx, -1						;initialiser le compteur

	_loop:

			inc rcx							;incrementer le compteur
			mov dl, byte[rbx + rcx]			;copier un byte de rbx/src dans le plus petit register de rcx
			mov byte[rax + rcx], dl			;copier ce byte dans rax/dest
			cmp byte[rbx + rcx], 0			;verifier que ce byte est different de '\0'
			jne _loop						;si different jne (jump if not equal) relancer la boucle
			je _return						;si ce byte vaut '\0' je (jump if equal) retourner la chaine rax

	_return:

			pop rdx							;replacer rdx depuis la stack
			ret								;retourner rax/dest