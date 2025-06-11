/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:17:28 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 12:17:29 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **lst)
{
	int		temp;
	t_list	*first;

	if (*lst)
	{
		temp = (*lst)->content;
		first = (*lst);
		while ((*lst)->next != NULL)
		{
			(*lst)->content = (*lst)->next->content;
			(*lst) = (*lst)->next;
		}
		(*lst)->content = temp;
		(*lst) = first;
		write(1, "ra\n", 3);
	}
}

void	ft_rotate_b(t_list **lst)
{
	int		temp;
	t_list	*first;

	if (*lst)
	{
		temp = (*lst)->content;
		first = (*lst);
		while ((*lst)->next != NULL)
		{
			(*lst)->content = (*lst)->next->content;
			(*lst) = (*lst)->next;
		}
		(*lst)->content = temp;
		(*lst) = first;
		write(1, "rb\n", 3);
	}
}

void	ft_rotate_rr2(t_list **lst2)
{
	int		temp;
	t_list	*first;

	if (*lst2)
	{
		temp = (*lst2)->content;
		first = (*lst2);
		while ((*lst2)->next != NULL)
		{
			(*lst2)->content = (*lst2)->next->content;
			(*lst2) = (*lst2)->next;
		}
		(*lst2)->content = temp;
		(*lst2) = first;
	}
}

void	ft_rotate_rr(t_list **lst, t_list **lst2)
{
	int		temp;
	t_list	*first;

	if (*lst)
	{
		temp = (*lst)->content;
		first = (*lst);
		while ((*lst)->next != NULL)
		{
			(*lst)->content = (*lst)->next->content;
			(*lst) = (*lst)->next;
		}
		(*lst)->content = temp;
		(*lst) = first;
	}
	ft_rotate_rr2(lst2);
	write(1, "rr\n", 3);
}
