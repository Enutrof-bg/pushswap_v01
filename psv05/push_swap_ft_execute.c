/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:16 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 16:21:18 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_test_check_r(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_rr(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test0");
		ft_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long	ft_test_check_reverse_r(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_reverse_rotate_rrr(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test1");
		ft_reverse_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long	ft_test_check_inverse_r(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_a(&lstA);
		ft_reverse_rotate_b(&lstB);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		ft_reverse_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long	ft_test_check_inverse_reverse_r(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_b(&lstB);
		ft_reverse_rotate_a(&lstA);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		ft_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}
