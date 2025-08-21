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

int	ft_commande(char *str, t_list **stacka, t_list **stackb)
{
	if (str[0] == 'p' && str[1] == 'a')
		return (ft_push_a_test(stacka, stackb), 0);
	else if (str[0] == 'p' && str[1] == 'b')
		return (ft_push_b_test(stacka, stackb), 0);
	else if (str[0] == 's' && str[1] == 'a')
		return (ft_swap_a_test(stacka), 0);
	else if (str[0] == 's' && str[1] == 'b')
		return (ft_swap_b_test(stackb), 0);
	else if (str[0] == 's' && str[1] == 's')
		return (ft_swap_ss_test(stacka, stackb), 0);
	else if (str[0] == 'r' && str[1] == 'a')
		return (ft_rotate_a_test(stacka), 0);
	else if (str[0] == 'r' && str[1] == 'b')
		return (ft_rotate_b_test(stackb), 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		return (ft_rotate_rr_test(stacka, stackb), 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		return (ft_reverse_rotate_a_test(stacka), 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		return (ft_reverse_rotate_b_test(stackb), 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		return (ft_reverse_rotate_rrr_test(stacka, stackb), 0);
	return (1);
}

void	ft_execute(char *str, t_list **stacka, t_list **stackb)
{
	char	**tab;	
	int		i;

	i = 0;
	tab = ft_split(str, '\n');
	if (!tab)
	{
		free(str);
		ft_clear_2(stacka, stackb);
		exit(EXIT_FAILURE);
	}
	while (tab[i])
	{
		ft_commande(tab[i], stacka, stackb);
		i++;
	}
	ft_clear_double_tab(tab);
}

char	*ft_get_input(void)
{
	char	*test;
	char	*str;
	char	*temp;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	test = get_next_line(0);
	if (!test)
		return (free(str), NULL);
	while (test)
	{
		temp = ft_strjoin(str, test);
		free(str);
		free(test);
		if (!temp)
			return (NULL);
		str = temp;
		test = get_next_line(0);
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	char	*str;

	stacka = NULL;
	stackb = NULL;
	if (argc >= 2)
	{
		str = ft_get_input();
		if (!str)
			return (1);
		if (argc == 2)
			ft_stack_arg2(argv, &stacka);
		else if (argc > 2)
			ft_stack_arg_more(argv, &stacka, argc);
		ft_execute(str, &stacka, &stackb);
		free(str);
		if (ft_if_sorted(stacka, stackb) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_clear(&stacka);
	ft_clear(&stackb);
	return (0);
}
