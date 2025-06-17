/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_how_many.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:15:32 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/17 11:15:33 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_struct(t_steps *struct_s, int cible, int target)
{
	struct_s->steps = LONG_MAX;
	struct_s->cible = cible;
	struct_s->target = target;
	struct_s->temp_a = NULL;
	struct_s->temp_b = NULL;
}

void	ft_how_many_steps_2(t_steps *struct_s, t_list **lstA, t_list **lstB)
{
	struct_s->steps_temp = ft_test_check_inverse_r_test(struct_s->temp_a,
			struct_s->temp_b, struct_s->cible, struct_s->target);
	if (struct_s->steps_temp < struct_s->steps)
	{
		struct_s->steps = struct_s->steps_temp;
		ft_set_soluce(lstA, struct_s->cible, 300, struct_s->target);
	}
	ft_copy_list(&struct_s->temp_a, &struct_s->temp_b, *lstA, *lstB);
	struct_s->steps_temp
		= ft_test_check_inverse_reverse_r_test(struct_s->temp_a,
			struct_s->temp_b, struct_s->cible, struct_s->target);
	if (struct_s->steps_temp < struct_s->steps)
	{
		struct_s->steps = struct_s->steps_temp;
		ft_set_soluce(lstA, struct_s->cible, 400, struct_s->target);
	}
}

long	ft_how_many_steps(t_list **lstA, t_list **lstB, int cible, int target)
{
	t_steps	struct_s;

	ft_set_struct(&struct_s, cible, target);
	ft_copy_list(&struct_s.temp_a, &struct_s.temp_b, *lstA, *lstB);
	struct_s.steps_temp = ft_test_check_r_test(struct_s.temp_a,
			struct_s.temp_b, struct_s.cible, struct_s.target);
	if (struct_s.steps_temp < struct_s.steps)
	{
		struct_s.steps = struct_s.steps_temp;
		ft_set_soluce(lstA, struct_s.cible, 100, struct_s.target);
	}
	ft_copy_list(&struct_s.temp_a, &struct_s.temp_b, *lstA, *lstB);
	struct_s.steps_temp = ft_test_check_reverse_r_test(struct_s.temp_a,
			struct_s.temp_b, struct_s.cible, struct_s.target);
	if (struct_s.steps_temp < struct_s.steps)
	{
		struct_s.steps = struct_s.steps_temp;
		ft_set_soluce(lstA, cible, 200, struct_s.target);
	}
	ft_copy_list(&struct_s.temp_a, &struct_s.temp_b, *lstA, *lstB);
	ft_how_many_steps_2(&struct_s, lstA, lstB);
	ft_clear_2(&struct_s.temp_a, &struct_s.temp_b);
	return (struct_s.steps);
}
