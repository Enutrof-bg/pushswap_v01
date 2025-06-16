/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_get_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:09:54 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 16:09:58 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_smallest(t_list *lstA)
{
	long	small;

	small = LONG_MAX;
	while ((lstA))
	{
		if (small > (lstA)->content)
		{
			small = (lstA)->content;
		}
		(lstA) = (lstA)->next;
	}
	return (small);
}

int	ft_get_highest(t_list *lstA)
{
	long	high;

	high = LONG_MIN;
	while (lstA)
	{
		if (high < lstA->content)
			high = lstA->content;
		lstA = lstA->next;
	}
	return (high);
}

int	ft_get_target(t_list *lstA, t_list *lstB)
{
	long	target;
	t_list	*temp;

	target = LONG_MAX;
	temp = lstA;
	while ((lstA))
	{
		if ((lstB)->content < (lstA)->content
			&& (lstA)->content < target)
			target = (lstA)->content;
		(lstA) = (lstA)->next;
	}
	lstA = temp;
	if (target == LONG_MAX)
		return (ft_get_smallest(lstA));
	else
		return (target);
}

int	ft_get_target_2(t_list *lstA, t_list *lstB, int cible)
{
	long	target;
	t_list	*temp;

	(void)lstB;
	target = LONG_MIN;
	temp = lstA;
	while ((lstA))
	{
		if (cible > (lstA)->content
			&& (lstA)->content > target)
			target = (lstA)->content;
		(lstA) = (lstA)->next;
	}
	lstA = temp;
	if (target == LONG_MAX)
		return (ft_get_smallest(lstA));
	else
		return (target);
}

int	ft_target(t_list *lstA, t_list *lstB, int cible)
{
	int	small;
	int	high;

	small = ft_get_smallest(lstB);
	high = ft_get_highest(lstB);
	if (cible > small && cible < high)
	{
		return (ft_get_target_2(lstB, lstA, cible));
	}
	else
	{
		return (high);
	}
}
