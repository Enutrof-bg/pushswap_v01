/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:57:36 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/11 13:57:37 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_2value(t_list **lstA)
{
	if ((*lstA)->content > (*lstA)->next->content)
		ft_swap_a(lstA);
}

void	ft_sort_3value(t_list **lstA)
{
	if (((*lstA)->content > (*lstA)->next->content)
		&& (*lstA)->content < (*lstA)->next->next->content)
		ft_swap_a(lstA);
	else if (((*lstA)->content > (*lstA)->next->content)
		&& (*lstA)->content > (*lstA)->next->next->content
		&& (*lstA)->next->content > (*lstA)->next->next->content)
	{
		ft_swap_a(lstA);
		ft_reverse_rotate_a(lstA);
	}
	else if (((*lstA)->content < (*lstA)->next->content)
		&& (*lstA)->content < (*lstA)->next->next->content
		&& (*lstA)->next->content > (*lstA)->next->next->content)
	{
		ft_swap_a(lstA);
		ft_rotate_a(lstA);
	}
	else if (((*lstA)->content > (*lstA)->next->content)
		&& (*lstA)->content > (*lstA)->next->next->content)
		ft_rotate_a(lstA);
	else if (((*lstA)->content < (*lstA)->next->content)
		&& (*lstA)->content > (*lstA)->next->next->content)
		ft_reverse_rotate_a(lstA);
}

int	ft_get_smallest(t_list *lstA)
{
	long	small;

	small = LONG_MAX;
	while ((lstA))
	{
		if (small > (lstA)->content)
		{
			small = (lstA)->content;
		}
		(lstA) = (lstA)->next;
	}
	return (small);
}

int ft_get_highest(t_list *lstA)
{
	long high;

	high = LONG_MIN;
	while (lstA)
	{
		if (high < lstA->content)
			high = lstA->content;
		lstA = lstA->next;
	}
	return (high);
}

int	ft_get_target(t_list *lstA, t_list *lstB)
{
	long	target;
	t_list	*temp;

	target = LONG_MAX;
	temp = lstA;
	while ((lstA))
	{
		if ((lstB)->content < (lstA)->content
			&& (lstA)->content < target)
			target = (lstA)->content;
		(lstA) = (lstA)->next;
	}
	lstA = temp;
	if (target == LONG_MAX)
		return (ft_get_smallest(lstA));
	else
		return (target);
}

int	ft_get_target_2(t_list *lstA, t_list *lstB)
{
	long	target;
	t_list	*temp;

	target = LONG_MIN;
	temp = lstA;
	while ((lstA))
	{
		if ((lstB)->content > (lstA)->content
			&& (lstA)->content > target)
			target = (lstA)->content;
		(lstA) = (lstA)->next;
	}
	lstA = temp;
	if (target == LONG_MAX)
		return (ft_get_smallest(lstA));
	else
		return (target);
}

int ft_target_pos(t_list *lstA, int target)
{
	int pos;

	pos = 0;
	while (lstA)
	{
		if (lstA->content == target)
		{
			return (pos);
		}
		pos++;
		lstA = lstA->next;
	}
	return (-1);
}

// void ft_sort_5value_2(t_list **lstA, int target, int pos, int nbr_value)
// {
// 	while ((*lstA)->content != target)
// 	{
// 		if (nbr_value / 2 >= pos)
// 			ft_reverse_rotate_a(lstA);
// 		else
// 			ft_rotate_a(lstA);
// 	}
// }

void ft_sort_5value_a(t_list **lstA, int target, int pos, int nbr_value)
{
	while ((*lstA)->content != target)
	{
		if (nbr_value / 2 >= pos)
			ft_rotate_a(lstA);
		else
			ft_reverse_rotate_a(lstA);
	}
}

void ft_sort_5value_b(t_list **lstA, int target, int pos, int nbr_value)
{
	while ((*lstA)->content != target)
	{
		if (nbr_value / 2 >= pos)
			ft_rotate_b(lstA);
		else
			ft_reverse_rotate_b(lstA);
	}
}
void	ft_sort_pas_opti(t_list **lstA, t_list **lstB, int nbr_value)
{
	int target;
	int push;
	int pos;

	push = 0;
	while (nbr_value - push++ > 3)
	{
		ft_push_b(lstA, lstB);
		// ft_lstprint_2(*lstA, *lstB);
	}
	ft_sort_3value(lstA);
	// ft_printf("sort3\n");
	// ft_lstprint_2(*lstA, *lstB);
	while ((*lstB))
	{
		target = ft_get_target(*lstA, *lstB);
		// ft_printf("target:%d\n", target);
		pos = ft_target_pos(*lstA, target);
		ft_sort_5value_a(lstA, target, pos, nbr_value);
		ft_push_a(lstA, lstB);
		// ft_lstprint_2(*lstA, *lstB);
	}
	
	// target = ft_get_target(*lstA, *lstB);
	// // ft_printf("target:%d\n", target);
	// pos = ft_target_pos(*lstA, target);
	// ft_sort_5value_2(lstA, target, pos, nbr_value);
	// ft_push_a(lstA, lstB);
	int small;

	small = ft_get_smallest(*lstA);
	// while ((*lstA)->content != small)
	// {
		ft_sort_5value_a(lstA, small, ft_target_pos(*lstA, small), nbr_value);
		// ft_rotate_a(lstA);
	// }
}

int ft_find_high(t_list *lstA, int high, int nbr_value)
{
	// int pos_small;
	int pos_high;
	int pos;
	long move;

	move = LONG_MAX;
	pos = 0;
	while (lstA)
	{
		// if (lstA->content == small)
		// 	pos_small = pos;
		if (lstA->content == high)
			pos_high = pos;
		pos++;
		lstA = lstA->next;
	}
	// if (nbr_value - pos_high > nbr_value - pos_small && nbr_value - pos_high < move)
	if (nbr_value - pos_high > pos_high)
	{
		return (1);
	}
	else
		return (0);
}

int ft_find_small(t_list *lstA, int small, int nbr_value)
{
	// int pos_small;
	int pos_small;
	int pos;
	long move;

	move = LONG_MIN;
	pos = 0;
	while (lstA)
	{
		// if (lstA->content == small)
		// 	pos_small = pos;
		if (lstA->content == small)
			pos_small = pos;
		pos++;
		lstA = lstA->next;
	}
	// if (nbr_value - pos_small > nbr_value - pos_small && nbr_value - pos_small < move)
	if (nbr_value - pos_small > pos_small)
	{
		return (1);
	}
	else
		return (0);
}

int ft_list_size(t_list *lst)
{
	int size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void ft_sort_back(t_list **lstA, t_list **lstB, int nbr_value)
{
	// while (!(*lstB))
	// {

	// }
	(void)lstB;
	(void)nbr_value;
	int small;
	int high;
	int target = 0;

	// ft_lstprint_2(*lstA, *lstB);
	// target = ft_get_target(*lstA, *lstB);
	// ft_printf("target:%d small:%d high:%d\n", target, small, high);
	// ft_sort_5value_2(lstA, target, ft_target_pos(*lstA, target), nbr_value);
	while ((*lstB))
	{
		// ft_lstprint_2(*lstA, *lstB);
		small = ft_get_smallest(*lstA);
		high = ft_get_highest(*lstA);
		// ft_printf("target:%d small:%d high:%d\n", target, small, high);
		// // ft_lstprint_2(*lstA, *lstB);
		// target = ft_get_target(*lstA, *lstB);
		// // ft_printf("target:%d\n", target);
		// ft_sort_5value_2(lstA, target, ft_target_pos(*lstA, target), nbr_value);
		// ft_push_a(lstA, lstB);

		if ((*lstB)->content > small && (*lstB)->content < high)
		{
			target = ft_get_target(*lstA, *lstB);
			// ft_printf("target:%d\n", target);
			ft_sort_5value_a(lstA, target, ft_target_pos(*lstA, target), nbr_value);
			// ft_push_b(lstA, lstB);
		}
		else if (/*(*lstA)->content < small || */(*lstB)->content > high)
		{
			if (ft_find_small(*lstA, small, nbr_value) == 0)
			{
				while ((*lstA)->content != small)
				{
					ft_reverse_rotate_a(lstA);
					// ft_rotate_a(lstA);
				}
			}
			if (ft_find_small(*lstA, small, nbr_value) == 1)
			{
				while ((*lstA)->content != small)
				{
					// ft_reverse_rotate_a(lstA);
					ft_rotate_a(lstA);
				}
			}
			// ft_push_b(lstA, lstB);
		}
		else if ((*lstB)->content < small/* || (*lstA)->content > high*/)
		{
			if (ft_find_high(*lstA, small, nbr_value) == 0)
			{
				while ((*lstA)->content != small)
				{
					ft_reverse_rotate_b(lstB);
					// ft_rotate_a(lstA);
				}
			}
			if (ft_find_high(*lstA, small, nbr_value) == 1)
			{
				while ((*lstA)->content != small)
				{
					ft_rotate_b(lstB);
					// ft_reverse_rotate_a(lstA);
				}
			}
			// ft_push_b(lstA, lstB);
		}
		ft_push_a(lstA, lstB);

	}
	small = ft_get_smallest(*lstA); 
	ft_sort_5value_a(lstA, small, ft_target_pos(*lstA, small), nbr_value);
}

void ft_sort_test(t_list **lstA, t_list **lstB, int nbr_value)
{
	(void)nbr_value;
	int small;
	int high;
	int target;

	ft_push_b(lstA, lstB);
	ft_push_b(lstA, lstB);
	// ft_lstprint_2(*lstA, *lstB);
	// while ((*lstA))
	while (ft_list_size(*lstA) > 3)
	{
		small = ft_get_smallest(*lstB);
		high = ft_get_highest(*lstB);
		// ft_printf("small:%d high:%d\n", small, high);
		if ((*lstA)->content > small && (*lstA)->content < high)
		{
			target = ft_get_target_2(*lstB, *lstA);
			// ft_printf("target:%d\n", target);
			ft_sort_5value_b(lstB, target, ft_target_pos(*lstB, target), nbr_value);
			// ft_push_b(lstA, lstB);
		}
		// ft_printf("small:%d high:%d\n", small, high);
		else if (/*(*lstA)->content < small || */(*lstA)->content > high)
		{
			if (ft_find_high(*lstB, high, nbr_value) == 0)
			{
				while ((*lstB)->content != high)
				{
					ft_rotate_b(lstB);
					// ft_reverse_rotate_b(lstB);
				}
			}
			if (ft_find_high(*lstB, high, nbr_value) == 1)
			{
				while ((*lstB)->content != high)
				{
					// ft_rotate_b(lstB);
					ft_reverse_rotate_b(lstB);
				}
			}
			// ft_push_b(lstA, lstB);
		}
		else if ((*lstA)->content < small/* || (*lstA)->content > high*/)
		{
			if (ft_find_high(*lstB, high, nbr_value) == 0)
			{
				while ((*lstB)->content != high)
				{
					ft_reverse_rotate_b(lstB);
					// ft_rotate_b(lstB);
				}
			}
			if (ft_find_high(*lstB, high, nbr_value) == 1)
			{
				while ((*lstB)->content != high)
				{
					ft_rotate_b(lstB);
					// ft_reverse_rotate_b(lstB);
				}
			}
			// ft_push_b(lstA, lstB);
		}
		ft_push_b(lstA, lstB);
		// ft_lstprint_2(*lstA, *lstB);
	}
	ft_sort_3value(lstA);
	ft_sort_back(lstA, lstB, nbr_value);
	// ft_sort_end(lstA, lstB, nbr_value);
}

void	ft_sort_1(t_list **lstA, t_list **lstB, int nbr_value)
{
	if (nbr_value == 2)
	{
		ft_sort_2value(lstA);
	}
	if (nbr_value == 3)
	{
		ft_sort_3value(lstA);
	}
	if (nbr_value >= 4)
	{
		// ft_sort_pas_opti(lstA, lstB, nbr_value);
		ft_sort_test(lstA, lstB, nbr_value);
	}
}
