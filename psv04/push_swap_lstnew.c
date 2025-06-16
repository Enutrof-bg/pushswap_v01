/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:42:20 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 13:42:27 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_test(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstclear_test(t_list **lst)
{
	t_list	*test;

	while (*lst != NULL)
	{
		test = *lst;
		*lst = (*lst)->next;
		free(test);
	}
	*lst = NULL;
}

t_list	*ft_lstmap_test(t_list *lst)
{
	t_list	*newlist;
	t_list	*first;
	t_list	*temp;
	int		content_temp;

	if (lst == NULL)
		return (NULL);
	first = NULL;
	temp = lst;
	while (lst != NULL)
	{
		content_temp = (lst)->content;
		newlist = ft_lstnew_test(content_temp);
		if (newlist == NULL)
		{
			ft_lstclear_test(&first);
			return (NULL);
		}
		ft_lstadd_back(&first, newlist);
		lst = lst->next;
	}
	lst = temp;
	return (first);
}