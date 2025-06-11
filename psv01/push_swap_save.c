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

int ft_int_check(char *argv)
{
	int i;

	i = 0;
	if (argv[0] == '-')
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

int	ft_dup_check(char *argv, int *tab, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (tab[i] == ft_atoi(argv))
			return (0);
		i++;
	}
	return (1);
}

int	ft_limit_check(char *argv)
{
	int result;
	int i;
	int signe;

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
		result = result * 10 + argv[i] - '0';
		i++;
	}
	return (1);
}

int	ft_check(int argc, char **argv, int *tabint)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_int_check(argv[i]) == 0)
			return (0);
		if (ft_dup_check(argv[i], tabint, i - 1) == 0)
			return (0);
		if (ft_limit_check(argv[i]) == 0)
			return (0);
		tabint[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int	ft_check_arg2(int argc, char **argv, int *tabint)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_int_check(argv[i]) == 0)
			return (0);
		if (ft_dup_check(argv[i], tabint, i) == 0)
			return (0);
		if (ft_limit_check(argv[i]) == 0)
			return (0);
		tabint[i] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int *tabint;
	int toto = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[toto])
			toto++;
		tabint = malloc(sizeof(int) * (toto));
		//TODO ERREUR MALLOC
		if (ft_check_arg2(toto, argv, tabint) == 0)
		{
			free(tabint);
			ft_printf("Error\n");
			return (0);
		}
		int chinois = 0;
		while (chinois < toto)
		{
			ft_printf("%d\n", tabint[chinois]);
			chinois++;
		}
		int i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
		free(tabint);
	}
	else if (argc > 2)
	{
		tabint = malloc(sizeof(int) * (argc - 1));
		// if (!tabint) 
		//TODO erreur malloc
		if (ft_check(argc, argv, tabint) == 0)
		{
			free(tabint);
			ft_printf("Error\n");
			return (0);
		}
		//pour afficher int *tabint
		int chinois = 0;
		while (chinois < argc - 1)
		{
			ft_printf("%d\n", tabint[chinois]);
			chinois++;
		}
		free(tabint);
	}
	

	return 0;
}