/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft_execute_soluce.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:25:28 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 16:25:29 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_soluce(t_list **lstA, t_list **lstB, int value)
{
	t_list	*temp;
	int		target;

	temp = (*lstA);
	target = ft_target(temp, *lstB, value);
	while (*lstA)
	{
		if ((*lstA)->content == value)
		{
			if ((*lstA)->soluce == 100)
				ft_test_check_r(temp, *lstB, value, target);
			if ((*lstA)->soluce == 200)
				ft_test_check_reverse_r(temp, *lstB, value, target);
			if ((*lstA)->soluce == 300)
				ft_test_check_inverse_r(temp, *lstB, value, target);
			if ((*lstA)->soluce == 400)
				ft_test_check_inverse_reverse_r(temp, *lstB, value, target);
			break ;
		}
		(*lstA) = (*lstA)->next;
	}
	(*lstA) = temp;
}

void	ft_execute_soluce_back(t_list **lstA, t_list **lstB, int value)
{
	t_list	*temp;
	int		target;

	temp = (*lstA);
	target = ft_get_target(*lstA, *lstB);
	while (*lstB)
	{
		if ((*lstB)->content == value)
		{
			if ((*lstB)->soluce == 100)
				ft_test_check_r(temp, *lstB, target, value);
			if ((*lstB)->soluce == 200)
				ft_test_check_reverse_r(temp, *lstB, target, value);
			if ((*lstB)->soluce == 300)
				ft_test_check_inverse_r(temp, *lstB, target, value);
			if ((*lstB)->soluce == 400)
				ft_test_check_inverse_reverse_r(temp, *lstB, value, value);
			break ;
		}	
		(*lstA) = (*lstA)->next;
	}
	(*lstA) = temp;
}
