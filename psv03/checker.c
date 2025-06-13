/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:40:06 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/12 16:40:07 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		nbr_value;

	stacka = NULL;
	stackb = NULL;
	if (argc == 2)
		nbr_value = ft_stack_arg2(argv, &stacka);
	else if (argc > 2)
		nbr_value = ft_stack_arg_more(argv, &stacka, argc);
	if (argc >= 2)
	{
		// ft_swap_ss(&stacka, &stackb);
		// ft_rotate_a(&stacka);
		// ft_rotate_b(&stackb);
		// ft_rotate_rr(&stacka, &stackb);
		// ft_reverse_rotate_a(&stacka);
		// ft_reverse_rotate_b(&stackb);
		// ft_reverse_rotate_rrr(&stacka, &stackb);
		// ft_push_a(&stacka, &stackb);
		// ft_push_b(&stacka, &stackb);
		// ft_push_b(&stacka, &stackb);
		// ft_push_b(&stacka, &stackb);
		// ft_push_b(&stacka, &stackb);
		// ft_push_a(&stacka, &stackb);
		// ft_push_a(&stacka, &stackb);
		// ft_push_a(&stacka, &stackb);
		// ft_push_a(&stacka, &stackb);
		ft_sort_1(&stacka, &stackb, nbr_value);
		ft_lstprint_2(stacka, stackb);
		ft_if_sorted(stacka, stackb);
	}
	ft_clear(&stacka);
	ft_clear(&stackb);
	return (0);
}