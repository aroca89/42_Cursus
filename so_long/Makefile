# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 12:16:22 by aroca-pa          #+#    #+#              #
#    Updated: 2023/08/23 20:56:43 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile para compilar el programa so_long

# ********************************* VARIABLES ******************************** #
NAME = so_long.a
INCLUDES = so_long.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address #-02

RESOURCES_PATH = ./resources
RESOURCES =		main.c\
				checkargument.c\
				checkfuntions.c\
				readmap.c\
				checkmap.c\

# ****************************** CREACION OBJECTS ***************************** #

OBJECTS_PATH = ./objects
OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(RESOURCES:.c=.o))

$(OBJECTS_PATH)/%.o: $(RESOURCES_PATH)/%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

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
	make -C $(PRINTF_PATH)
	make -C $(GNL_PATH)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_A) -o $@ -lm

clean:
	rm -rf $(OBJECTS_PATH)
	make clean -C $(LIBFT_PATH)
	make clean -C $(PRINTF_PATH)
	make clean -C $(GNL_PATH)
	make clean -C $(MLX_PATH)

fclean: clean 
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(PRINTF_PATH)
	make clean -C $(GNL_PATH)
	make clean -C $(MLX_PATH)
	
	
re: fclean all 

.PHONY: all clean fclean re debug sani noflags

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