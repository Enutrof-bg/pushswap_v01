/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:01:27 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 17:01:28 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_step(t_list **lstA, t_list **lstB)
{
	t_list	*temp;
	int		value;

	while (ft_list_size(*lstA) > 3)
	{
		temp = (*lstA);
		ft_reset_steps(lstA);
		while ((*lstA))
		{
			(*lstA)->steps = ft_calculate_steps_node(&temp,
					(lstB), (*lstA)->content);
			if ((*lstA)->steps < 1)
				break ;
			(*lstA) = (*lstA)->next;
		}
		(*lstA) = temp;
		value = ft_min_step((*lstA));
		ft_execute_soluce(lstA, lstB, value);
		ft_push_b(lstA, lstB);
	}
	ft_sort_3value(lstA);
}

void	ft_second_step_step(t_list **lstA, t_list **lstB, long steps)
{
	int		test;
	long	temp_steps;
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = NULL;
	temp_b = NULL;
	test = ft_get_target(*lstA, *lstB);
	ft_copy_list(&temp_a, &temp_b, lstA, lstB);
	temp_steps = ft_test_check_reverse_r_test(temp_b,
			temp_a, (*lstB)->content, test);
	if (temp_steps < steps)
	{
		steps = temp_steps;
		ft_set_soluce(lstB, (*lstB)->content, 200, test);
	}
	ft_clear_2(&temp_a, &temp_b);
}

void	ft_second_step(t_list **lstA, t_list **lstB)
{
	int		test;
	t_list	*temp_a;
	t_list	*temp_b;
	long	steps;
	long	temp_steps;

	temp_a = NULL;
	temp_b = NULL;
	while (*lstB)
	{
		steps = LONG_MAX;
		test = ft_get_target(*lstA, *lstB);
		ft_copy_list(&temp_a, &temp_b, lstA, lstB);
		temp_steps = ft_test_check_r_test(temp_b,
				temp_a, (*lstB)->content, test);
		if (temp_steps < steps)
		{
			steps = temp_steps;
			ft_set_soluce(lstB, (*lstB)->content, 100, test);
		}
		ft_clear_2(&temp_a, &temp_b);
		ft_second_step_step(lstA, lstB, steps);
		ft_execute_soluce_back(lstA, lstB, (*lstB)->content);
		ft_push_a(lstA, lstB);
	}
}

// int	ft_third_check(t_list **lstA, t_list **lstB, int small)
// {
// 	t_list	*temp_a;
// 	long	steps;
// 	long	steps_temp;

// 	temp_a = NULL;
// 	steps = 0;
// 	steps_temp = 0;
// 	temp_a = ft_lstmap_test(*lstA);
// 	if (!temp_a)
// 	{
// 		ft_clear_2(lstA, lstB);
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((temp_a)->content != small)
// 	{
// 		ft_rotate_a_test(&temp_a);
// 		steps_temp++;
// 	}
// 	ft_clear(&temp_a);
// 	temp_a = ft_lstmap_test(*lstA);
// 	if (!temp_a)
// 	{
// 		ft_clear_2(lstA, lstB);
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((temp_a)->content != small)
// 	{
// 		ft_reverse_rotate_a_test(&temp_a);
// 		steps++;
// 	}
// 	ft_clear(&temp_a);
// 	if (steps > steps_temp)
// 		return (2);
// 	return (1);
// }

// void ft_third_check_2(t_steps *struct_t, t_list **lstA, t_list **lstB)
// {
// 	struct_t->temp_a = ft_lstmap_test(*lstA);
// 	if (!struct_t->temp_a)
// 	{
// 		ft_clear_2(lstA, lstB);
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((struct_t->temp_a)->content != struct_t->small)
// 	{
// 		ft_reverse_rotate_a_test(&struct_t->temp_a);
// 		struct_t->steps++;
// 	}
// 	ft_clear(&struct_t->temp_a);
// }

// int	ft_third_check(t_list **lstA, t_list **lstB, int small)
// {
// 	t_steps struct_t;

// 	struct_t.temp_a = NULL;
// 	struct_t.steps = 0;
// 	struct_t.steps_temp = 0;
// 	struct_t.small = small;
// 	struct_t.temp_a = ft_lstmap_test(*lstA);
// 	if (!struct_t.temp_a)
// 	{
// 		ft_clear_2(lstA, lstB);
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((struct_t.temp_a)->content != small)
// 	{
// 		ft_rotate_a_test(&struct_t.temp_a);
// 		struct_t.steps_temp++;
// 	}
// 	ft_clear(&struct_t.temp_a);
// 	ft_third_check_2(&struct_t, lstA, lstB);
// 	if (struct_t.steps > struct_t.steps_temp)
// 		return (2);
// 	return (1);
// }

// void	ft_third_step(t_list **lstA, int rotate, int small)
// {
// 	if (rotate == 1)
// 	{
// 		while ((*lstA)->content != small)
// 		{
// 			ft_rotate_a(lstA);
// 		}
// 	}
// 	else if (rotate == 2)
// 	{
// 		while ((*lstA)->content != small)
// 		{
// 			ft_reverse_rotate_a(lstA);
// 		}
// 	}
// }
