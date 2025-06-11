/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:57:36 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 13:57:37 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3value(t_list **lstA)
{
	if (((*lstA)->content > (*lstA)->next->content)
		&& (*lstA)->content < (*lstA)->next->next->content)
		ft_swap_a(lstA);
	else if (((*lstA)->content > (*lstA)->next->content)
		&& (*lstA)->content > (*lstA)->next->next->content
		&& (*lstA)->next->content > (*lstA)->next->next->content)
	{
		ft_swap_a(lstA);
		ft_reverse_rotate_a(lstA);
	}
	else if (((*lstA)->content < (*lstA)->next->content)
		&& (*lstA)->content < (*lstA)->next->next->content
		&& (*lstA)->next->content > (*lstA)->next->next->content)
	{
		ft_swap_a(lstA);
		ft_rotate_a(lstA);
	}
	else if (((*lstA)->content > (*lstA)->next->content)
		&& (*lstA)->content > (*lstA)->next->next->content)
		ft_rotate_a(lstA);
	else if (((*lstA)->content < (*lstA)->next->content)
		&& (*lstA)->content > (*lstA)->next->next->content)
		ft_reverse_rotate_a(lstA);
}

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

int ft_target_pos(t_list *lstA, int target)
{
	int pos;

	pos = 0;
	while (lstA)
	{
		if (lstA->content == target)
		{
			return (pos);
		}
		pos++;
		lstA = lstA->next;
	}
	return (-1);
}

void ft_sort_5value_2(t_list **lstA, int target, int pos, int nbr_value)
{
	while ((*lstA)->content != target)
	{
		if (nbr_value / 2 >= pos)
			ft_reverse_rotate_a(lstA);
		else
			ft_rotate_a(lstA);
	}
}

void	ft_sort_5value(t_list **lstA, t_list **lstB, int nbr_value)
{
	int target;
	int push;
	int pos;

	push = 0;
	while (nbr_value - push++ > 3)
	{
		ft_push_b(lstA, lstB);
		// ft_lstprint_2(*lstA, *lstB);
	}
	ft_sort_3value(lstA);
	ft_printf("sort3\n");
	// ft_lstprint_2(*lstA, *lstB);
	while ((*lstB))
	{
		target = ft_get_target(*lstA, *lstB);
		// ft_printf("target:%d\n", target);
		pos = ft_target_pos(*lstA, target);
		ft_sort_5value_2(lstA, target, pos, nbr_value);
		ft_push_a(lstA, lstB);
		// ft_lstprint_2(*lstA, *lstB);
	}
	
	// target = ft_get_target(*lstA, *lstB);
	// // ft_printf("target:%d\n", target);
	// pos = ft_target_pos(*lstA, target);
	// ft_sort_5value_2(lstA, target, pos, nbr_value);
	// ft_push_a(lstA, lstB);
	int small;

	small = ft_get_smallest(*lstA);
	while ((*lstA)->content != small)
	{
		ft_rotate_a(lstA);
	}
}

void	ft_sort_1(t_list **lstA, t_list **lstB, int nbr_value)
{
	if (nbr_value == 3)
	{
		(void)lstB;
		ft_sort_3value(lstA);
	}
	if (nbr_value >= 4)
	{
		ft_sort_5value(lstA, lstB, nbr_value);
	}
}
