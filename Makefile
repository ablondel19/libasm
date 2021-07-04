# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 18:14:36 by ablondel          #+#    #+#              #
#    Updated: 2021/02/21 14:22:38 by ablondel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NASM = nasm

NFLAGS = -f macho64

NAME = libasm.a

SRC = ft_strlen.s \
ft_strcpy.s \
ft_strcmp.s \
ft_write.s \
ft_read.s \
ft_strdup.s

OBJ = $(SRC:.s=.o)

LINK = ar rc

all: $(NAME)

$(NAME): $(OBJ)
	$(LINK) $(NAME) $(OBJ)

%.o: %.s
	$(NASM) $(NFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re