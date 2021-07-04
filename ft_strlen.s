global _ft_strlen

section .text

	_ft_strlen:								;fonction // ft_strlen(char *rdi)

			cmp rdi, 0						;verifier si la chaine existe
			je _protection					;protection en cas de chaine inexistante
			push rdi						;sauvegarder rdi sur la stack
			xor rcx, rcx					;mettre le registre rcx a zero

	_loop:									;boucle // while (rdi[x] != '\0') x++

			cmp[rdi + rcx], byte 0			;verifier si le byte contenu dans rdi[rcx] vaut '\0'
			je _return						;si oui retourner le compteur
			inc rcx							;sinon incrementer le compteur
			jmp _loop						;relancer la boucle

	_return:								;retour // return (x)

			mov rax, rcx					;placer le compteur dans le registre rax
			pop rdi							;replacer rdi depuis la stack
			ret								;retourner rax

	_protection:							;protection // if (!rdi) return (0)

			mov rax, 0						;placer 0 dans rax
			pop rdi							;replacer rdi depuis la stack
			ret								;retourner rax