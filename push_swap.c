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

t_list	*ft_lstnew_test(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstprint(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stacka;

	stacka = NULL;
	if (argc == 2)
		ft_stack_arg2(argv, &stacka);
	else if (argc > 2)
		ft_stack_arg_more(argv, &stacka, argc);
	ft_lstprint(stacka);
	ft_clear(&stacka);
	return (0);
}
