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
/*
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
	ft_clear_2(&temp_a, &temp_b);
	// ft_clear(&temp_b);
	return (steps);
}*/

// void ft_set_struct(t_steps *struct_s, int cible, int target)
// {
// 	struct_s->steps = LONG_MAX;
// 	struct_s->cible = cible;
// 	struct_s->target = target;
// 	struct_s->temp_a = NULL;
// 	struct_s->temp_b = NULL;
// }

// void ft_how_many_steps_2(t_steps *struct_s, t_list **lstA, t_list **lstB)
// {
// 	struct_s->steps_temp = ft_test_check_inverse_r_test(struct_s->temp_a,
// 		struct_s->temp_b, struct_s->cible, struct_s->target);
// 	if (struct_s->steps_temp < struct_s->steps)
// 	{
// 		struct_s->steps = struct_s->steps_temp;
// 		ft_set_soluce(lstA, struct_s->cible, 300, struct_s->target);
// 	}
// 	ft_copy_list(&struct_s->temp_a, &struct_s->temp_b, *lstA, *lstB);
// 	struct_s->steps_temp =
		// ft_test_check_inverse_reverse_r_test(struct_s->temp_a,
// 			struct_s->temp_b, struct_s->cible, struct_s->target);
// 	if (struct_s->steps_temp < struct_s->steps)
// 	{
// 		struct_s->steps = struct_s->steps_temp;
// 		ft_set_soluce(lstA, struct_s->cible, 400, struct_s->target);
// 	}
// }

// long	ft_how_many_steps(t_list **lstA, t_list **lstB, int cible, int target)
// {
// 	t_steps struct_s;

// 	ft_set_struct(&struct_s, cible, target);
// 	ft_copy_list(&struct_s.temp_a, &struct_s.temp_b, *lstA, *lstB);
// 	struct_s.steps_temp = ft_test_check_r_test(struct_s.temp_a,
// 		struct_s.temp_b, struct_s.cible, struct_s.target);
// 	if (struct_s.steps_temp < struct_s.steps)
// 	{
// 		struct_s.steps = struct_s.steps_temp;
// 		ft_set_soluce(lstA, struct_s.cible, 100, struct_s.target);
// 	}
// 	ft_copy_list(&struct_s.temp_a, &struct_s.temp_b, *lstA, *lstB);
// 	struct_s.steps_temp = ft_test_check_reverse_r_test(struct_s.temp_a,
// 		struct_s.temp_b, struct_s.cible, struct_s.target);
// 	if (struct_s.steps_temp < struct_s.steps)
// 	{
// 		struct_s.steps = struct_s.steps_temp;
// 		ft_set_soluce(lstA, cible, 200, struct_s.target);
// 	}
// 	ft_copy_list(&struct_s.temp_a, &struct_s.temp_b, *lstA, *lstB);
// 	ft_how_many_steps_2(&struct_s, lstA, lstB);
// 	ft_clear_2(&struct_s.temp_a, &struct_s.temp_b);
// 	return (struct_s.steps);
// }

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
