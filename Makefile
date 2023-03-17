# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 19:30:21 by cormiere          #+#    #+#              #
#    Updated: 2022/10/27 18:39:32 by cormiere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJ)
	${AR} ${NAME} $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	re all clean fclean
