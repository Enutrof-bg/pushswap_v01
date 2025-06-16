/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft_check_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:16:24 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 16:16:25 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_test_check_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_rr_test(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		ft_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a_test(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long	ft_test_check_reverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_reverse_rotate_rrr_test(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		ft_reverse_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a_test(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long	ft_test_check_inverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_a_test(&lstA);
		ft_reverse_rotate_b_test(&lstB);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		ft_reverse_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a_test(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long	ft_test_check_inverse_reverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_b_test(&lstB);
		ft_reverse_rotate_a_test(&lstA);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		ft_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a_test(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}
