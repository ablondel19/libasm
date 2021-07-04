global _ft_strcmp

section .text

	_ft_strcmp:								;fonction // ft_strcmp(char *rsi, char *rdi)

			xor rax, rax					;mettre rax a 0
			xor rcx, rcx					;mettre rcx a 0
			mov rdx, -1						;initialiser le compteur

	_loop:									;boucle // while (dst[x] == src[x]) x++

			inc rdx							;incrementer le compteur
			mov cl, [rsi + rdx]				;copier dans cl/rcx le caractere src[rdx]
			mov al, [rdi + rdx]				;copier dans al/rax le caractere dst[rdx]
			mov r8b, cl						;copier cl dans r8b
			mov r9b, al						;copier al dans r9b
			or r8b, r9b						;bitwise or entre r8b et r9b // mettra a 0 r8b si les 2 valent 0
			cmp r8b, 0						;verifier si r8b contient desormais un 0
			je _is_equal					;je (jump if equal)	si oui les deux chaines sont egales (0/0) retourner 0
			cmp rax, rcx					;sinon comparer les deux caracteres obtenus
			je _loop						;je (jump if equal)	si ils sont egaux relancer la boucle
			jg _is_greater					;jg (jump if greater) retourner 1
			jl _is_less						;jl (jump if less) retourner -1
	
	_is_equal:								;si les deux chaines sont identiques

			mov rax, 0						;valeur de retour = 0
			ret								;retourner la valeur de rax

	_is_greater:							;si s1[x] > s2[x]

			mov rax, 1						;valeur de retour = 1
			ret								;retourner la valeur de rax

	_is_less:								;si s1[x] < s2[x]

			mov rax, -1						;valeur de retour = -1
			ret								;retourner la valeur de rax
