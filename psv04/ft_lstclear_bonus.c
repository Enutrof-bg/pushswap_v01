/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:34:27 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 14:34:29 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*test;

	while (*lst != NULL)
	{
		test = *lst;
		*lst = (*lst)->next;
		(*del)(test->content);
		free(test);
	}
	*lst = NULL;
}
/*
void	ft_del(void *s)
{
	// free(s);
}

int main()
{
	t_list *node1 = ft_lstnew("node1");
	t_list *node2 = ft_lstnew("node2");
	t_list *node3 = ft_lstnew("node3");
	t_list *node4 = ft_lstnew("node4");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	ft_lstclear(&node2, &ft_del);
	while(node1 != NULL)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
	}
}
*/