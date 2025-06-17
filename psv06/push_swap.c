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

int	ft_check_space(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ' && argv[1][i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		nbr_value;

	stacka = NULL;
	stackb = NULL;
	if (argc == 2)
	{
		if (ft_check_space(argv) == 0)
			return (0);
		nbr_value = ft_stack_arg2(argv, &stacka);
	}
	else if (argc > 2)
		nbr_value = ft_stack_arg_more(argv, &stacka, argc);
	if (argc >= 2)
	{
		if (ft_if_sorted(stacka, stackb) == 1)
			return (ft_clear(&stacka), ft_clear(&stackb), 0);
		ft_sort_1(&stacka, &stackb, nbr_value);
		ft_clear(&stacka);
		ft_clear(&stackb);
	}
	return (0);
}
