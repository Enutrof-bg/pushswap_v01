/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:06:19 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/05 10:06:21 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*prev;
	struct s_list	*next;
}t_list;

//truc
int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
char	**ft_split(char const *s, char c);

//push_swap.c
t_list	*ft_lstnew_test(int content);
void	ft_lstprint(t_list *lst);

//push_swap_check.c
int		ft_int_check(char *argv);
int		ft_dup_check(char *argv, t_list *lst);
int		ft_limit_check(char *argv);

//push_swap_create_lst.c
void	ft_lst_link_prev(t_list **lst);
int		ft_stack_arg2(char **argv, t_list **stacka);
int		ft_stack_arg_more(char **argv, t_list **stacka, int argc);

//push_swap_free.c
void	ft_clear(t_list **lst);
void	ft_clear_double_tab(char **argv);

//push_swap_lstnew.c
t_list	*ft_lstnew_test(int content);

//push_swap_print.c
void	ft_lstprint(t_list *lst);
void	ft_lstprint_reverse(t_list *lst);
void	ft_lstprint_2(t_list *lst, t_list *lst2);

//push_swap_sort_1.c
void	ft_sort_1(t_list **lstA, t_list **lstB, int nbr_value);

//push_swap_sort_swap.c
void	ft_push_a(t_list **lstA, t_list **lstB);
void	ft_push_b(t_list **lstA, t_list **lstB);

//push_swap_sort_reverse.c
void	ft_reverse_rotate_a(t_list **lst);
void	ft_reverse_rotate_b(t_list **lst);
void	ft_reverse_rotate_rrr(t_list **lst, t_list **lst2);

//push_swap_sort_rotate.c
void	ft_rotate_a(t_list **lst);
void	ft_rotate_b(t_list **lst);
void	ft_rotate_rr(t_list **lst, t_list **lst2);

//ft_swap_sort_push.c
void	ft_swap_a(t_list **lst);
void	ft_swap_b(t_list **lst);
void	ft_swap_ss(t_list **lst, t_list **lst2);

//truc
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
// void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
