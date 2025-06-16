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

void	ft_commande(char *str, t_list **stacka, t_list **stackb)
{
	if (str[0] == 'p' && str[1] == 'a')
		ft_push_a(stacka, stackb);
	if (str[0] == 'p' && str[1] == 'b')
		ft_push_b(stacka, stackb);
	if (str[0] == 's' && str[1] == 'a')
		ft_swap_a(stacka);
	if (str[0] == 's' && str[1] == 'b')
		ft_swap_b(stackb);
	if (str[0] == 's' && str[1] == 's')
		ft_swap_ss(stacka, stackb);
	if (str[0] == 'r' && str[1] == 'a')
		ft_rotate_a(stacka);
	if (str[0] == 'r' && str[1] == 'b')
		ft_rotate_b(stackb);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		ft_rotate_rr(stacka, stackb);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_reverse_rotate_a(stacka);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_reverse_rotate_b(stackb);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_reverse_rotate_rrr(stacka, stackb);
}

void	ft_execute(char *str, t_list **stacka, t_list **stackb)
{
	char	**tab;	
	int		i;

	i = 0;
	tab = ft_split(str, '\n');
	while (tab[i])
	{
		ft_commande(tab[i], stacka, stackb);
		i++;
	}
}

char	*ft_get_input(void)
{
	char	*test;
	char	*str;
	char	*temp;

	str = malloc(sizeof(char) * 1);
	str[0] = '\0';
	test = get_next_line(0);
	while (test)
	{
		temp = ft_strjoin(str, test);
		free(str);
		free(test);
		str = temp;
		test = get_next_line(0);
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		nbr_value;
	char	*str;

	stacka = NULL;
	stackb = NULL;
	if (argc >= 2)
	{
		str = ft_get_input();
		if (argc == 2)
			nbr_value = ft_stack_arg2(argv, &stacka);
		else if (argc > 2)
			nbr_value = ft_stack_arg_more(argv, &stacka, argc);
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
