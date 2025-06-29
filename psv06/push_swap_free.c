/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:05:57 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/10 18:05:59 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_list **lst)
{
	t_list	*del;

	while (*lst != NULL)
	{
		del = *lst;
		*lst = (*lst)->next;
		free(del);
	}
	*lst = NULL;
}

void	ft_clear_2(t_list **lst, t_list **lst2)
{
	t_list	*del;

	while (*lst != NULL)
	{
		del = *lst;
		*lst = (*lst)->next;
		free(del);
	}
	*lst = NULL;
	while (*lst2 != NULL)
	{
		del = *lst2;
		*lst2 = (*lst2)->next;
		free(del);
	}
	*lst2 = NULL;
}

void	ft_clear_double_tab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
