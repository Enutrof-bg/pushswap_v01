/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:32:28 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/10 14:32:30 by kevwang          ###   ########.fr       */
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

int	ft_list_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int ft_sort_radix(t_list **stacka, t_list **stackb)
{
	int size = ft_list_size(*stacka);
	// printf("size:%d\n", size);

	int max_num = size -1;

	int max_bits = 0;
	while( max_num >> max_bits != 0)
	{
		max_bits++;
	}
	// printf("max_bits:%d\n", max_bits);


	int i = 0;
	int j = 0;
	while (i < max_bits)
	{
		while (j < size)
		{
			if (((*stacka)->content >> i) & (1 == 1))
				ft_rotate_a(stacka);
			else
				ft_push_b(stacka, stackb);
			j++;
		}
		j = 0;
		while (*stackb)
		{
			ft_push_a(stacka, stackb);
		}
		// ft_lstprint(*stacka);
		// printf("\n");
		i++;
	}
	return (0);
}

int ft_bubble_sort(t_list **stacka)
{
	t_list *copy = ft_lstmap_test(*stacka);
	int size = ft_list_size(copy);
	// printf("size:%d\n", size);

	int i = 0;
	int j = 0;
	int temp;
	t_list *begin;
	t_list *begin2;

	begin2 = *stacka;
	begin = copy;
	while (i < size)
	{
		while (j < size - 1)
		{
			if (copy->content > copy->next->content)
			{
				temp = copy->next->content;
				copy->next->content = copy->content;
				copy->content = temp;
			}
			j++;
			if (copy->next)
				copy = copy->next;
		}
		copy = begin;
		i++;
		j = 0;
	}
	copy = begin;
	// ft_lstprint(copy);
	// printf("test\n");

	i = 0;
	while (i < size)
	{
		copy->index = i;
		copy = copy->next;
		i++;
	}
	copy = begin;
	// printf("test2\n");
	// ft_lstprint(copy);
	// printf("test3\n");

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			// printf("%d %d\n", stacka->content, copy->content);
			if ((*stacka)->content == copy->content)
			{
				// printf("%d \n", copy->index);
				(*stacka)->content = copy->index;
				// printf("%d \n", stacka->content);
				break ;
			}
			copy = copy->next;
			j++;
		}
		copy = begin;
		*stacka = (*stacka)->next;
		i++;
		j = 0;
	}
	*stacka = begin2;
	// return (copy);
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

	ft_bubble_sort(&stacka);

	// int i = 0;
	// int j = 0;
	// int size = ft_list_size(copy);
	// while (i < size)
	// {
	// 	while (j < size)
	// 	{
	// 		// printf("%d %d\n", stacka->content, copy->content);
	// 		if (stacka->content == copy->content)
	// 		{
	// 			// printf("%d \n", copy->index);
	// 			stacka->content = copy->index;
	// 			// printf("%d \n", stacka->content);
	// 			break ;
	// 		}
	// 		copy = copy->next;
	// 		j++;
	// 	}
	// 	copy = begin;
	// 	stacka = stacka->next;
	// 	i++;
	// 	j = 0;
	// }
	// stacka = begin2;
	// ft_lstprint(stacka);

	ft_sort_radix(&stacka, &stackb);

	return (0);
}