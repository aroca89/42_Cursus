# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 12:16:22 by aroca-pa          #+#    #+#              #
#    Updated: 2023/08/11 13:56:59 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile para compilar el programa so_long

# ********************************* VARIABLES ******************************** #
NAME = SO_LONG
INCLUDES = so_long.h
CC = gcc
CFLAGS = -Wall -Werror Wextra -lm -g3 -fsanitize=address #-02

RESOURCERS_PATH = ./resourcers
RESOURCERS =	main.c\
				checkargument.c\

# ****************************** CREACION OBJECTS ***************************** #

OBJECTS_PATH = objects
OBJS = $(addprefix $(OBJECTS_PATH)/, $(RESOURCERS:.c=.o))

$(OBJECTS_PATH)/%.o: $(RESOURCERS_PATH)/%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -C $< -o $@

# ************************* VARIABLES OTRAS BIBLIOTECAS *********************** #

LIBFT_PATH = ./libft_42
LIBFT_A = $(LIBFT_PATH)/libft.a

PRINTF_PATH = ./ft_printf
PRINTF_A = $(PRINTF_PATH)/ft_printf.a

GNL_PATH = ./get_next_line
GNL_A = $(GNL_PATH)/gnl.a

MLX_PATH = ./minilibx_opengl
MLX_A = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

# ********************************* Reglas ************************************ #

ALL: $(NAME)

$(NAME): $(OBJECTS)
	make bonus -C $(LIBFT_PATH)
	make bonus -C $(PRINTF_PATH)
	make bonus -C $(GNL_PATH)
	make bonus -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJECTS_PATH) $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_A) -o $@



# ******************************** Reglas debug ******************************* #
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
	@echo "    Compilando el programa so_long             "
	@echo "==============================================="

# ************************ VARIABLES de depuracion *************************** #

$(foreach v, $(.VARIABLES), $(if $(filter-out environment% default automatic, $(origin $v)), $(warning $v=$($v) ($(value $v)))))