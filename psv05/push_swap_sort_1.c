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

long	ft_how_many_steps(t_list **lstA, t_list **lstB, int cible, int target)
{
	long	steps;
	long	steps_temp;
	t_list	*temp_a;
	t_list	*temp_b;

	steps = LONG_MAX;
	temp_a = NULL;
	temp_b = NULL;
	ft_copy_list(&temp_a, &temp_b, *lstA, *lstB);
	steps_temp = ft_test_check_r_test(temp_a, temp_b, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 100, target);
	}
	ft_copy_list(&temp_a, &temp_b, *lstA, *lstB);
	steps_temp = ft_test_check_reverse_r_test(temp_a, temp_b, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 200, target);
	}
	ft_copy_list(&temp_a, &temp_b, *lstA, *lstB);
	steps_temp = ft_test_check_inverse_r_test(temp_a, temp_b, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 300, target);
	}
	ft_copy_list(&temp_a, &temp_b, *lstA, *lstB);
	steps_temp = ft_test_check_inverse_reverse_r_test(temp_a,
			temp_b, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 400, target);
	}
	ft_clear(&temp_a);
	ft_clear(&temp_b);
	return (steps);
}

long	ft_calculate_steps_node(t_list **lstA, t_list **lstB, int cible)
{
	long	steps;
	int		target;

	steps = LONG_MAX;
	target = ft_target(*lstA, *lstB, cible);
	steps = ft_how_many_steps(lstA, lstB, cible, target);
	return (steps);
}

void	ft_calculate_steps_lst(t_list **lstA, t_list **lstB)
{
	int	small;
	int	rotate;

	ft_first_step(lstA, lstB);
	ft_second_step(lstA, lstB);
	small = ft_get_smallest(*lstA);
	rotate = ft_third_check(lstA, small);
	ft_third_step(lstA, rotate, small);
}

void	ft_sort_jsp(t_list **lstA, t_list **lstB, int nbr_value)
{
	ft_reset_steps(lstA);
	if (nbr_value > 4)
		ft_push_b(lstA, lstB);
	ft_push_b(lstA, lstB);
	ft_calculate_steps_lst(lstA, lstB);
}

void	ft_sort_1(t_list **lstA, t_list **lstB, int nbr_value)
{
	if (nbr_value == 2)
	{
		ft_sort_2value(lstA);
	}
	if (nbr_value == 3)
	{
		ft_sort_3value(lstA);
	}
	if (nbr_value >= 4)
	{
		ft_sort_jsp(lstA, lstB, nbr_value);
	}
}
