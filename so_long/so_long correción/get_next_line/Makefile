# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 18:00:55 by aroca-pa          #+#    #+#              #
#    Updated: 2023/08/23 14:43:41 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM= gnl.a
INCLUDES =	get_next_line.h\
CC = gcc
CFLAGS+= -Wall -Werror -Wextra
SRC= 	get_next_line_utils.c\
		get_next_line.c\

OBJ=$(SRC:.c=.o)

all: $(NOM)

$(NOM):	$(OBJ)
	ar -rc $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	rm -f $(NOM) $(OBJ) *~

re: clean all