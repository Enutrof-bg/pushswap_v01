/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:56:23 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 14:56:25 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	void	*content_data;

	while (lst != NULL)
	{
		content_data = lst->content;
		(*f)(content_data);
		lst = lst->next;
	}
}
/*
void	ft_test(void *s)
{
	// char	*s1;

	// s1 = (char *)s;
	printf("ft_test 1: %s\n", (char *)s);
	s = "test";
	printf("ft_test 2: %s\n", (char *)s);
}

int main()
{
	t_list *node1 = ft_lstnew("node10");
	t_list *node2 = ft_lstnew("node2");
	t_list *node3 = ft_lstnew("node3");
	t_list *node4 = ft_lstnew("node4");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	ft_lstiter(node1, ft_test);

	t_list *temp = node1;
	while (temp->next != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("%s\n", (char *)temp->content);
}*/