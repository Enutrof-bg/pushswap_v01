/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:07:10 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 16:07:13 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2value(t_list **lstA)
{
	if ((*lstA)->content > (*lstA)->next->content)
		ft_swap_a(lstA);
}

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
