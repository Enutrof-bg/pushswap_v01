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

SRC = push_swap.c \
push_swap_utils.c \
push_swap_check.c \
push_swap_free.c \
push_swap_create_lst.c \
ft_split.c \
ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c \
push_swap_sort_swap.c \
push_swap_sort_rotate.c \
push_swap_sort_reverse.c \
push_swap_sort_push.c \
push_swap_lstnew.c \
push_swap_print.c \
push_swap_sort_1.c \
# ft_lstnew_bonus.c \
# ft_lstclear_bonus.c \
# ft_lstdelone_bonus.c \
# ft_lstiter_bonus.c \
# ft_lstlast_bonus.c \
# ft_lstmap_bonus.c \
# ft_lstsize_bonus.c 

# DIRPRINTF = ft_printf
# SRCPRINTF = ${DIRPRINTF}/ft_printf.c \
# ${DIRPRINTF}/ft_putcharstr.c \
# ${DIRPRINTF}/ft_puthexa.c \
# ${DIRPRINTF}/ft_putnbr.c \
# ${DIRPRINTF}/ft_putptr.c \
# ${DIRPRINTF}/ft_putunsigned.c\

OBJ = ${SRC:.c=.o}

NAME = push_swap

all : ${NAME}

${NAME} : ${OBJ}
	make -C ft_printf
	${CC} ${CFLAGS} $^ -o $@ -Lft_printf -lftprintf

%.o:%.c
	${CC} ${CFLAGS} -c $^ -o $@

clean: 
	rm -f push_swap.o push_swap_utils.o \
	push_swap_check.o \
	push_swap_free.o \
	push_swap_create_lst.o \
	ft_split.o \
	ft_lstadd_back_bonus.o \
	ft_lstadd_front_bonus.o \
	ft_lstclear_bonus.o \
	ft_lstdelone_bonus.o \
	ft_lstiter_bonus.o \
	ft_lstlast_bonus.o \
	ft_lstmap_bonus.o  \
	ft_lstnew.o \
	ft_lstsize_bonus.o \
	push_swap_sort_swap.o \
	push_swap_sort_rotate.o \
	push_swap_sort_reverse.o \
	push_swap_sort_push.o \
	push_swap_lstnew.o \
	push_swap_print.o \
	push_swap_sort_1.o
	make fclean -C ft_printf

fclean : clean
	rm -f pushswap

re: fclean
	make