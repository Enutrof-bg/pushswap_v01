/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:05:48 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/05 10:05:49 by kevwang          ###   ########.fr       */
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
	// t_list	*stack2;
	// t_list	*stack3;
	// stackb = ft_lstnew_test(10);
	// stack2 = ft_lstnew_test(20);
	// stack3 = ft_lstnew_test(30);
	// stackb->next = stack2;
	// stack2->next = stack3;
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
	}
	ft_clear(&stacka);
	ft_clear(&stackb);
	return (0);
}
