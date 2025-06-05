# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 10:05:33 by kevwang           #+#    #+#              #
#    Updated: 2025/06/05 10:05:38 by kevwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c push_swap_utils.c\
ft_printf/ft_printf.c ft_printf/ft_putcharstr.c ft_printf/ft_puthexa.c ft_printf/ft_putnbr.c ft_printf/ft_putptr.c ft_printf/ft_putunsigned.c\
ft_split.c

OBJ = ${SRC:.c=.o}

NAME = pushswap

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} $^ -o $@ 

%.o:%.c
	${CC} ${CFLAGS} -c $^ -o $@

clean: 
	rm -f push_swap.o push_swap_utils.o \
	ft_printf/ft_printf.o ft_printf/ft_putcharstr.o ft_printf/ft_puthexa.o ft_printf/ft_putnbr.o ft_printf/ft_putptr.o ft_printf/ft_putunsigned.o \
	ft_split.o

fclean : clean
	rm -f pushswap

re: fclean
	make