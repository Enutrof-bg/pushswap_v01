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
		&& (*lstA)->content < (*lstA)->next->next->content)
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

void	ft_sort_5value(t_list **lstA, t_list **lstB, int nbr_value)
{
	while (nbr_value-- > 3)
		ft_push_b(lstA, lstB);
	ft_sort_3value(lstA);
}

void	ft_sort_1(t_list **lstA, t_list **lstB, int nbr_value)
{
	if (nbr_value == 3)
	{
		(void)lstB;
		ft_sort_3value(lstA);
	}
	if (nbr_value >= 4 && nbr_value <= 5)
	{
		ft_sort_5value(lstA, lstB, nbr_value);
	}
}
