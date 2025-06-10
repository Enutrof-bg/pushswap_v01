/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:53:08 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 12:53:09 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
	*lst = temp;
}
/*
int main()
{	
	t_list *node0 = NULL;
	t_list *node1 =	ft_lstnew("node01");
	t_list *node2 = ft_lstnew("node02");
	t_list *node3 = ft_lstnew("node03");
	t_list *nodefin = ft_lstnew("nodefin");

	ft_lstadd_back(&node0, node1);
	ft_lstadd_back(&node0, node2);
	ft_lstadd_back(&node0, node3);
	ft_lstadd_back(&node0, nodefin);
	//test01
	t_list *temp = node1;
	while(temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}



}

*/