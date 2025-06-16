/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:07:11 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 13:07:12 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
void ft_del(void *s)
{
	free(s);
}

int main()
{
	t_list *node1 = ft_lstnew("node1");
	t_list *node2 = ft_lstnew("node2");
	t_list *node3 = ft_lstnew("node3");
	// printf("%s\n", (char *)node1->content);
	// free(node1);
	// printf("%s\n", (char *)node1->content);

	node1->next = node2;
	node2->next = node3;

	t_list *temp = node1;
	while (temp->next != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("%s\n", (char *)temp->content);
	

	printf("\n");

	temp = node2;

	// ft_lstdelone(node2, &ft_del);
	free(temp);
	// printf("%s\n", (char *)node2->content);
	// printf("%s\n", (char *)temp->next->content);

	// int i = 0;

	// if(temp->next == NULL)
	// {
	// 	temp = temp->next;
	// 	printf("%s\n", (char *)temp->content);
	// }
	

	// while(temp->next != NULL)
	// {
	// 	printf("%s\n", (char *)temp->content);
	// 	temp = temp->next;
	// }

	// printf("%s\n", (char *)temp->content);
	
}
*/