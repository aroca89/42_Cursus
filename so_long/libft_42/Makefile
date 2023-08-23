# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 08:42:24 by aroca-pa          #+#    #+#              #
#    Updated: 2023/08/23 14:40:09 by aroca-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

INCLUDES = libft.h

CC = gcc

CFLAG = -Werror -Wall -Wextra -g

SRC = ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c  \
	  ft_strchr.c  \
	  ft_strrchr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_atoi.c    \
	  ft_memset.c  \
	  ft_bzero.c   \
	  ft_itoa.c    \
	  ft_strdup.c  \
	  ft_calloc.c  \
	  ft_memcpy.c  \
	  ft_strdup.c  \
	  ft_strncmp.c \
	  ft_memchr.c  \
	  ft_substr.c  \
	  ft_strjoin.c \
	  ft_memcmp.c  \
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_memmove.c\
	  ft_strnstr.c\
	  ft_strmapi.c\
	  ft_putnbr_fd.c\
	  ft_strtrim.c\
	  ft_split.c\
	  ft_striteri.c\

SRC_BONUS = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\

		
OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(SRC_BONUS:.c=.o)

.o: %.c 
	$(CC) -c $(CFLAG) $^

#######################################

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES) 
	ar rsc $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(OBJ) $(INCLUDE)
	ar rsc $(NAME) $(BONUS_OBJ) $(OBJ)

clean:
	rm -f *.o
	
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

#######################################

.PHONY: all clean fclean re bonus
