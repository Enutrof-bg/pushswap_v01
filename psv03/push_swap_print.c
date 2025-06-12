/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:44:01 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 13:44:02 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstprint_reverse(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->prev;
	}
}

void	ft_lstprint_2(t_list *lst, t_list *lst2)
{
	t_list	*temp;
	t_list	*temp2;

	temp = lst;
	temp2 = lst2;
	while (temp != NULL || temp2 != NULL)
	{
		if (temp != NULL)
		{
			ft_printf("%d ", temp->content);
			temp = temp->next;
		}
		else
			ft_printf("  ");
		if (temp2 != NULL)
		{
			ft_printf("%d", temp2->content);
			temp2 = temp2->next;
		}
		else
			ft_printf("  ");
		ft_printf("\n");
	}
	ft_printf("_ _\na b\n\n");
}
