/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_third_step.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:04:13 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/17 13:04:14 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_third_check_2(t_steps *struct_t, t_list **lstA, t_list **lstB)
{
	struct_t->temp_a = ft_lstmap_test(*lstA);
	if (!struct_t->temp_a)
	{
		ft_clear_2(lstA, lstB);
		exit(EXIT_FAILURE);
	}
	while ((struct_t->temp_a)->content != struct_t->small)
	{
		ft_reverse_rotate_a_test(&struct_t->temp_a);
		struct_t->steps++;
	}
	ft_clear(&struct_t->temp_a);
}

int	ft_third_check(t_list **lstA, t_list **lstB, int small)
{
	t_steps struct_t;

	struct_t.temp_a = NULL;
	struct_t.steps = 0;
	struct_t.steps_temp = 0;
	struct_t.small = small;
	struct_t.temp_a = ft_lstmap_test(*lstA);
	if (!struct_t.temp_a)
	{
		ft_clear_2(lstA, lstB);
		exit(EXIT_FAILURE);
	}
	while ((struct_t.temp_a)->content != small)
	{
		ft_rotate_a_test(&struct_t.temp_a);
		struct_t.steps_temp++;
	}
	ft_clear(&struct_t.temp_a);
	ft_third_check_2(&struct_t, lstA, lstB);
	if (struct_t.steps > struct_t.steps_temp)
		return (1);
	return (2);
}

void	ft_third_step(t_list **lstA, int rotate, int small)
{
	if (rotate == 1)
	{
		while ((*lstA)->content != small)
		{
			ft_rotate_a(lstA);
		}
	}
	else if (rotate == 2)
	{
		while ((*lstA)->content != small)
		{
			ft_reverse_rotate_a(lstA);
		}
	}
}
