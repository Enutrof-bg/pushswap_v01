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

typedef struct s_list
{
	// char *test;
	int				content;
	// void *content;
	// struct s_list prev;
	struct s_list	*next;
}t_list;

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
void	ft_stack_arg2(char **argv, t_list **stacka);
void	ft_stack_arg_more(char **argv, t_list **stacka, int argc);

//push_swap_free.c
void	ft_clear(t_list **lst);
void	ft_clear_double_tab(char **argv);

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
