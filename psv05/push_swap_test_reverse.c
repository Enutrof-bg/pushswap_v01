/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:12:47 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 17:12:48 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a_test(t_list **lst)
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
}

void	ft_reverse_rotate_b_test(t_list **lst)
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
}

void	ft_reverse_rotate_rrr2_test(t_list **lst2)
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

void	ft_reverse_rotate_rrr_test(t_list **lst, t_list **lst2)
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
	ft_reverse_rotate_rrr2_test(lst2);
}
