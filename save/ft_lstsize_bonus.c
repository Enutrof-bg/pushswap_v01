/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:20:26 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 12:20:27 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int main()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;

	node1 = ft_lstnew("11");
	node2 = ft_lstnew("22");
	node3 = ft_lstnew("33");
	node4 = ft_lstnew("44");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	printf("%d\n", ft_lstsize(node1));

	node1->next = NULL;
	printf("%d\n", ft_lstsize(node1));

	node1 = NULL;
	printf("%d\n", ft_lstsize(node1));
}*/