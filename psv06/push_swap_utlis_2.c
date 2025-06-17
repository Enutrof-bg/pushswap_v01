/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utlis_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:18:58 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 16:19:03 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_steps(t_list **lst)
{
	t_list	*temp;

	temp = (*lst);
	while ((*lst))
	{
		(*lst)->steps = LONG_MAX;
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
}

int	ft_list_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_copy_list(t_list **tempA,
	t_list **tempB, t_list **lstA, t_list **lstB)
{
	if (*tempA)
		ft_clear(tempA);
	if (*tempB)
		ft_clear(tempB);
	*tempA = ft_lstmap_test(*lstA);
	if (!(tempA))
	{
		ft_clear_2(lstA, lstB);
		exit(EXIT_FAILURE);
	}
	*tempB = ft_lstmap_test(*lstB);
	if (!(tempB))
	{
		ft_clear_2(lstA, lstB);
		exit(EXIT_FAILURE);
	}
}

void	ft_set_soluce(t_list **lst, int cible, int soluce, int target)
{
	t_list	*temp;

	(void)target;
	temp = *lst;
	while (*lst)
	{
		if ((*lst)->content == cible)
		{
			(*lst)->soluce = soluce;
			(*lst)->target = target;
			break ;
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
}

int	ft_min_step(t_list *lst)
{
	t_list	*temp;
	t_list	*value;

	temp = lst;
	value = lst;
	while (lst)
	{
		if (lst->next && value->steps > lst->next->steps)
		{
			value = lst->next;
		}
		lst = lst->next;
	}
	lst = temp;
	return (value->content);
}
