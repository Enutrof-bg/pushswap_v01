/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:17:40 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 12:17:41 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_list **lst)
{
	t_list	*first;
	int		temp;
	int		temp2;

	if (*lst)
	{
		first = (*lst);
		temp = (*lst)->content;
		temp2 = (*lst)->content;
		while ((*lst)->next != NULL)
		{
			(*lst) = (*lst)->next;
			temp2 = (*lst)->content;
			(*lst)->content = temp;
			temp = temp2;
		}
		(*lst) = first;
		(*lst)->content = temp2;
	}
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_list **lst)
{
	t_list	*first;
	int		temp;
	int		temp2;

	if (*lst)
	{
		first = (*lst);
		temp = (*lst)->content;
		temp2 = (*lst)->content;
		while ((*lst)->next != NULL)
		{
			(*lst) = (*lst)->next;
			temp2 = (*lst)->content;
			(*lst)->content = temp;
			temp = temp2;
		}
		(*lst) = first;
		(*lst)->content = temp2;
	}
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_rrr2(t_list **lst2)
{
	t_list	*first;
	int		temp;
	int		temp2;

	if (*lst2)
	{
		first = (*lst2);
		temp = (*lst2)->content;
		temp2 = (*lst2)->content;
		while ((*lst2)->next != NULL)
		{
			(*lst2) = (*lst2)->next;
			temp2 = (*lst2)->content;
			(*lst2)->content = temp;
			temp = temp2;
		}
		(*lst2) = first;
		(*lst2)->content = temp2;
	}
}

void	ft_reverse_rotate_rrr(t_list **lst, t_list **lst2)
{
	t_list	*first;
	int		temp;
	int		temp2;

	if (*lst)
	{
		first = (*lst);
		temp = (*lst)->content;
		temp2 = (*lst)->content;
		while ((*lst)->next != NULL)
		{
			(*lst) = (*lst)->next;
			temp2 = (*lst)->content;
			(*lst)->content = temp;
			temp = temp2;
		}
		(*lst) = first;
		(*lst)->content = temp2;
	}
	ft_reverse_rotate_rrr2(lst2);
	write(1, "rrr\n", 4);
}
