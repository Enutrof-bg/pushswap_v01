/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:17:53 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 12:17:54 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_list **lstA, t_list **lstB)
{
	t_list	*temp;

	if (*lstB != NULL)
	{
		temp = (*lstB);
		(*lstB) = (*lstB)->next;
		if (!(*lstA))
		{
			*lstA = ft_lstnew_test(temp->content);
			if (!(*lstA))
				exit(EXIT_FAILURE);
			free((*lstB)->prev);
		}
		else
		{
			(*lstA)->prev = temp;
			(*lstA)->prev->next = (*lstA);
			(*lstA) = (*lstA)->prev;
		}
	}
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list **lstA, t_list **lstB)
{
	t_list	*temp;

	if (*lstA != NULL)
	{
		temp = (*lstA);
		(*lstA) = (*lstA)->next;
		if (!(*lstB))
		{
			*lstB = ft_lstnew_test(temp->content);
			if (!(*lstB))
				exit(EXIT_FAILURE);
			free((*lstA)->prev);
		}
		else
		{
			(*lstB)->prev = temp;
			(*lstB)->prev->next = (*lstB);
			(*lstB) = (*lstB)->prev;
		}
	}
	write(1, "pb\n", 3);
}
