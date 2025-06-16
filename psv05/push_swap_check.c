/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:03:13 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/10 18:03:14 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '-' || argv[0] == '+')
		i++;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_dup_check(char *argv, t_list *lst)
{
	int	test;

	test = ft_atoi(argv);
	while (lst != NULL)
	{
		if (lst->content == test)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_limit_check2(int signe, int result, int i, char *argv)
{
	if (signe == 1)
	{
		if (result > (2147483647 - (argv[i] - '0')) / 10)
			return (0);
	}
	else if (signe == -1)
	{
		if ((result * signe < ((-2147483648) + (argv[i] - '0')) / 10))
			return (0);
	}
	return (1);
}

int	ft_limit_check(char *argv)
{
	int	result;
	int	i;
	int	signe;

	signe = 1;
	i = 0;
	result = 0;
	if (argv[i] == '+' || argv[i] == '-')
	{
		if (argv[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		if (ft_limit_check2(signe, result, i, argv) == 0)
			return (0);
		result = result * 10 + argv[i] - '0';
		i++;
	}
	return (1);
}
