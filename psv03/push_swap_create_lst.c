/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_create_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:12:39 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/10 18:12:40 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_link_prev(t_list **lst)
{
	t_list	*temp;
	t_list	*temp_prev;
	t_list	*last;

	temp = *lst;
	temp_prev = *lst;
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		(*lst)->prev = temp_prev;
		temp_prev = temp_prev->next;
	}
	last = *lst;
	*lst = temp;
	(*lst)->prev = last;
}

int	ft_check(int argc, char **argv, t_list **lst)
{
	int		i;
	int		test;
	t_list	*temp;

	i = 1;
	while (i < argc)
	{
		if (ft_int_check(argv[i]) == 0)
			return (0);
		if (ft_dup_check(argv[i], *lst) == 0)
			return (0);
		if (ft_limit_check(argv[i]) == 0)
			return (0);
		test = ft_atoi(argv[i]);
		temp = ft_lstnew_test(test);
		if (!(temp))
			exit(EXIT_FAILURE);
		ft_lstadd_back(lst, temp);
		i++;
	}
	ft_lst_link_prev(lst);
	return (1);
}

int	ft_check_arg2(int argc, char **argv, t_list **lst)
{
	int		i;
	int		test;
	t_list	*temp;

	i = 0;
	while (i < argc)
	{
		if (ft_int_check(argv[i]) == 0)
			return (0);
		if (ft_dup_check(argv[i], *lst) == 0)
			return (0);
		if (ft_limit_check(argv[i]) == 0)
			return (0);
		test = ft_atoi(argv[i]);
		temp = ft_lstnew_test(test);
		if (!(temp))
			exit(EXIT_FAILURE);
		ft_lstadd_back(lst, temp);
		i++;
	}
	ft_lst_link_prev(lst);
	return (1);
}

int	ft_stack_arg2(char **argv, t_list **stacka)
{
	int	toto;

	toto = 0;
	argv = ft_split(argv[1], ' ');
	while (argv[toto])
		toto++;
	if (ft_check_arg2(toto, argv, stacka) == 0)
	{
		ft_clear_double_tab(argv);
		ft_clear(stacka);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	ft_clear_double_tab(argv);
	return (toto);
}

int	ft_stack_arg_more(char **argv, t_list **stacka, int argc)
{
	if (ft_check(argc, argv, stacka) == 0)
	{
		ft_clear(stacka);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return (argc - 1);
}
