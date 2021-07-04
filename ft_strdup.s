global _ft_strdup

extern _ft_strlen							;permettre l' appel de ft_strlen
extern _ft_strcpy							;permettre l' appel de ft_strcpy
extern _malloc								;permettre l' appel de malloc

section .text

	_ft_strdup:								;fonction // ft_strdup(char *rsi)

			push rsi						;sauvegarder rsi sur la stack pour preserver son contenu
			push rdi						;suavegarder rdi sur la stack pour preserver son contenu
			call _ft_strlen					;appeler ft_strlen pour le nombre de char a allouer
			mov r9, rdi						;copier rdi/dst dans r9 qui sera le registre de travail de malloc
			mov rdi, rax					;copier rax dans rdi qui sera la chaine a dupliquer
			inc rdi							;incrementer rdi
			push r9							;sauvegarder r9/dst sur la stack pour appeler malloc
			call _malloc					;appeler malloc
			pop r9							;replacer r9 depuis la stack
			cmp rax, 0						;verivier que rax contient une chaine et que malloc a reussi
			je _error						;si rax vaut 0 alors retourner une erreur
			mov rsi, r9						;replacer r9 dans rsi
			mov rdi, rax					;replacer rax dams rdi
			call _ft_strcpy					;appeler ft_strcpy pour copier rsi/src dans rdi/dst
			pop rdi							;replacer rdi depuis la stack
			pop rsi							;replacer rsi depuis la stack
			ret								;retourner l' adresse de la chaine dupliquee

	_error:									;en cas d' erreur

			xor rax, rax					;remettre rax a 0/NULL
			pop rdi							;replacer rdi depuis la stack
			pop rsi							;replacer rsi depuis la stack
			ret								;retourner rax
