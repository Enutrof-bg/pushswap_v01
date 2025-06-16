/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:12:11 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 11:12:13 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **lst)
{
	int	temp;
	int	temp_next;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		temp_next = (*lst)->next->content;
		(*lst)->next->content = temp;
		(*lst)->content = temp_next;
	}
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **lst)
{
	int	temp;
	int	temp_next;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		temp_next = (*lst)->next->content;
		(*lst)->next->content = temp;
		(*lst)->content = temp_next;
	}
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_list **lst, t_list **lst2)
{
	int	temp;
	int	temp_next;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		temp_next = (*lst)->next->content;
		(*lst)->next->content = temp;
		(*lst)->content = temp_next;
	}
	if (*lst2 && (*lst2)->next)
	{
		temp = (*lst2)->content;
		temp_next = (*lst2)->next->content;
		(*lst2)->next->content = temp;
		(*lst2)->content = temp_next;
	}
	write(1, "ss\n", 3);
}

void	ft_swap_a_test(t_list **lst)
{
	int	temp;
	int	temp_next;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		temp_next = (*lst)->next->content;
		(*lst)->next->content = temp;
		(*lst)->content = temp_next;
	}
}

void	ft_swap_b_test(t_list **lst)
{
	int	temp;
	int	temp_next;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		temp_next = (*lst)->next->content;
		(*lst)->next->content = temp;
		(*lst)->content = temp_next;
	}
}

void	ft_swap_ss_test(t_list **lst, t_list **lst2)
{
	int	temp;
	int	temp_next;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		temp_next = (*lst)->next->content;
		(*lst)->next->content = temp;
		(*lst)->content = temp_next;
	}
	if (*lst2 && (*lst2)->next)
	{
		temp = (*lst2)->content;
		temp_next = (*lst2)->next->content;
		(*lst2)->next->content = temp;
		(*lst2)->content = temp_next;
	}
}
