/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:06:59 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 12:07:00 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int main()
{	
	t_list *start = NULL;
	// t_list *start = ft_lstnew("start");
	t_list *node1 = ft_lstnew("node1");
	t_list *node2 = ft_lstnew("node2");
	t_list *node3 = ft_lstnew("node3");

	ft_lstadd_front(&start, node3);
	ft_lstadd_front(&start, node2);
	ft_lstadd_front(&start, node1);

	// printf("%s\n", (char *)liste->content);
	// printf("%s\n", (char *)node1->content);

	// printf("%s\n", (char *)node1->next->content);
	t_list *test = node1;

	while (test != NULL)
	{
		printf("%s\n", (char *)test->content);
		test = test->next;
	}

	// printf("%s\n", (char *)test->content);

}
*/