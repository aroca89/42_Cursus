# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 06:12:46 by aroca-pa          #+#    #+#              #
#    Updated: 2022/11/20 18:08:43 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ft_printf.h

cc = gcc

CFLAGS = -Werror -Wextra -Wall -g3

SRC = ft_printf.c \
	  ft_checkflags.c \

OBJ = $(SRC:.c=.o)


.o: %.c
	$(CC) -c $(CFLAGS) $^ 

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft/
	mv ./libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	make clean -C libft
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus
