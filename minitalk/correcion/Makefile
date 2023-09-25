# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 16:59:30 by aroca-pa          #+#    #+#              #
#    Updated: 2023/07/26 19:41:54 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile para compilar el programa server

# ********************************* VARIABLES ******************************** #
SERVER_NAME = server
CLIENT_NAME = client

INCLUDES = 
CC = gcc
CFLAGS = -Wall -Werror  -Wextra -g3 #-fsanitize=address #-02

SERVER_SRC = server.c\

CLIENT_SRC = client.c\

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# ********************************* VARIABLES ******************************** #

LIBFT_DIR = libft_42
LIBFT = $(LIBFT_DIR)/libft.a

# ********************************* Reglas ************************************ #
all: title $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)

%.O: %.C $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT):
	make bonus -C $(LIBFT_DIR)

clean:
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
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

# ******************************** Titulos *********************************** #
print-%:
	@echo $* = $($*)

title:
	@echo "==============================================="
	@echo "    Compilando el programa server y client            "
	@echo "==============================================="

# ************************ VARIABLES de depuracion *************************** #

$(foreach v, $(.VARIABLES), $(if $(filter-out environment% default automatic, $(origin $v)), $(warning $v=$($v) ($(value $v)))))