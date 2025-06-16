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
push_swap_small_value.c \
push_swap_get_target.c \
push_swap_utlis_2.c \
push_swap_ft_check_test.c \
push_swap_ft_execute.c \
push_swap_ft_execute_soluce.c \
push_swap_step.c \
push_swap_test_reverse.c \
push_swap_test_rotate.c \
push_swap_test_swap.c
# ft_lstnew_bonus.c \
# ft_lstclear_bonus.c \
# ft_lstdelone_bonus.c \
# ft_lstiter_bonus.c \
# ft_lstlast_bonus.c \
# ft_lstmap_bonus.c \
# ft_lstsize_bonus.c 

SRCBONUS = checker.c \
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
gnl/get_next_line.c \
gnl/get_next_line_utils.c \
push_swap_small_value.c \
push_swap_get_target.c \
push_swap_utlis_2.c \
push_swap_ft_check_test.c \
push_swap_ft_execute.c \
push_swap_ft_execute_soluce.c \
push_swap_step.c \
push_swap_test_reverse.c \
push_swap_test_rotate.c \
push_swap_test_swap.c
# DIRPRINTF = ft_printf
# SRCPRINTF = ${DIRPRINTF}/ft_printf.c \
# ${DIRPRINTF}/ft_putcharstr.c \
# ${DIRPRINTF}/ft_puthexa.c \
# ${DIRPRINTF}/ft_putnbr.c \
# ${DIRPRINTF}/ft_putptr.c \
# ${DIRPRINTF}/ft_putunsigned.c\

OBJ = ${SRC:.c=.o}

OBJBONUS = ${SRC:.c=.o}

NAME = push_swap
CHECKER = checker

all : ${NAME}

${NAME} : ${OBJ}
	make -C ft_printf
	${CC} ${CFLAGS} $^ -o $@ -Lft_printf -lftprintf

%.o:%.c
	${CC} ${CFLAGS} -c $^ -o $@

bonus:${CHECKER}

${CHECKER}:${SRCBONUS}
	make -C ft_printf
	${CC} ${CFLAGS} $^ -o $@ -Lft_printf -lftprintf


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
	push_swap_sort_1.o \
	gnl/get_next_line.o \
	gnl/get_next_line_utils.o \
	push_swap_small_value.o \
	push_swap_get_target.o \
	push_swap_utlis_2.o \
	push_swap_ft_check_test.o \
	push_swap_ft_execute.o \
	push_swap_ft_execute_soluce.o \
	push_swap_step.o \
	push_swap_test_reverse.o \
	push_swap_test_rotate.o \
	push_swap_test_swap.o
	make fclean -C ft_printf

fclean : clean
	rm -f push_swap
	rm -f checker

re: fclean
	make