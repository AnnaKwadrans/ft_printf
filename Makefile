# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 00:32:58 by akwadran          #+#    #+#              #
#    Updated: 2024/12/10 00:37:23 by akwadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar -rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all