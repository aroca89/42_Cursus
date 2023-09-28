# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 07:25:36 by aroca-pa          #+#    #+#              #
#    Updated: 2023/07/26 17:15:31 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile para compilar el programa push_swap

# ********************************* VARIABLES ******************************** #
NAME = push_swap
INCLUDES = ./push_swap.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra -v #-02

SRC_DIR = ./src
SRC = push_swap.c\
	  push.c\
	  rotate.c\
	  reverse_rotate.c\
	  swap.c\
	  checkerror.c\
	  main.c\
	  onetwothree.c\

# ****************************** CREACION OBJECTS ***************************** #

OBJ_DIR = ./obj
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************* VARIABLES ******************************** #

LIBFT_DIR = ./libft_42
LIBFT = $(LIBFT_DIR)/libft.a

# ********************************* Reglas ************************************ #
all: $(NAME)

$(NAME): $(OBJECTS)
	make bonus -C $(LIBFT_DIR)
	rm -f logs
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re debug sani noflags


# ******************************** Reglas debug ******************************** #
noflags: CFLAGS =
noflags: re

debug: CFLAGS += -g3
debug: clean $(NAME)

sani: CFLAGS += -g3 -fsanitize=address
sani: clean $(NAME)

# *************************** Reglas de commits *************************** #

commit: fclean
	git add .
	git commit -m "save make"
	git push

# ******************************** Titulos *********************************** #
print-%:
	@echo $* = $($*)

title:
	@echo "==============================================="
	@echo "    Compilando el programa push_swap           "
	@echo "==============================================="

# ************************ VARIABLES de depuracion *************************** #

$(foreach v, $(.VARIABLES), $(if $(filter-out environment% default automatic, $(origin $v)), $(warning $v=$($v) ($(value $v)))))

