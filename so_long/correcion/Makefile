# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 12:16:22 by aroca-pa          #+#    #+#              #
#    Updated: 2023/09/25 16:27:19 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile para compilar el programa so_long

# ********************************* VARIABLES ******************************** #
NAME = so_long.a
INCLUDES = so_long.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra

RESOURCES_PATH = ./resources
RESOURCES =		main.c\
				checkargument.c\
				readmap.c\
				checkmap.c\
				errorlist.c\
				start_game.c\
				movement.c\

# ****************************** CREACION OBJECTS ***************************** #

OBJECTS_PATH = ./objects
OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(RESOURCES:.c=.o))

$(OBJECTS_PATH)/%.o: $(RESOURCES_PATH)/%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# ************************* VARIABLES OTRAS BIBLIOTECAS *********************** #

LIBFT_PATH = ./libft_42
LIBFT_A = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx_opengl
MLX_A = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

# ********************************* Reglas ************************************ #

all: $(NAME)

$(NAME): $(OBJECTS)
	make bonus -C $(LIBFT_PATH)
	make -C $(MLX_PATH) 2> logs
	rm -f logs
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_A) -o $@ -lm

clean:
	rm -rf $(OBJECTS_PATH)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean 
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)
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
