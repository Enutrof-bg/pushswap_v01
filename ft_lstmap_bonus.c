/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:25:55 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 15:25:56 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_test_f(void *s)
{
	return (s);
}

void	ft_test_del(void *s)
{
	if (s)
		return ;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*first;
	void	*content_temp;

	if (lst == NULL)
		return (NULL);
	content_temp = f(lst->content);
	newlist = ft_lstnew(content_temp);
	if (newlist == NULL)
	{
		if (del)
			del(content_temp);
		return (NULL);
	}
	first = newlist;
	newlist = newlist->next;
	lst = lst->next;
	while (lst != NULL)
	{
		content_temp = f(lst->content);
		newlist = ft_lstnew(content_temp);
		if (newlist == NULL)
		{
			if (del)
				del(content_temp);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, newlist);
		// newlist = newlist->next;
		lst = lst->next;
	}
	return (first);
}
/*
int main()
{
	t_list *node1 = ft_lstnew("node1");
	t_list *node2 = ft_lstnew("node2");
	t_list *node3 = ft_lstnew("node3");
	t_list *node4 = ft_lstnew("node4");

	// node1->next = node2;
	// node2->next = node3;
	// node3->next = node4;

	t_list *test;
	test = ft_lstmap(node1, &ft_test_f, &ft_test_del);
	int i = 0;
	while (test != NULL)
	{
		printf("test %d: %s\n", i,(char *)test->content);
		test = test->next;
		i++;
	}

	while (node1 != NULL)
	{
		printf("node1 %d: %s\n", i,(char *)node1->content);
		node1 = node1->next;
		i++;
	}
	write(1,"\n",1);
	// i = 0;
	test = node1;
	while (test != NULL)
	{
		printf("test %d: %s\n", i,(char *)test->content);
		test = test->next;
		i++;
	}

}
*/