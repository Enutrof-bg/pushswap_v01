/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft_check_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:16:24 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/16 16:16:25 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// long	ft_test_check_r_test(t_list *lstA,
// 	t_list *lstB, int cible, int target)
// {
// 	long	steps_temp;

// 	steps_temp = 0;
// 	if (lstA && lstB)
// 	{
// 		while (lstA->content != cible && lstB->content != target)
// 		{
// 			ft_rotate_rr_test(&lstA, &lstB);
// 			steps_temp++;
// 		}
// 		while (lstA->content == cible && lstB->content != target)
// 		{
// 			ft_rotate_b_test(&lstB);
// 			steps_temp++;
// 		}
// 		while (lstA->content != cible && lstB->content == target)
// 		{
// 			ft_rotate_a_test(&lstA);
// 			steps_temp++;
// 		}
// 	}
// 	return (steps_temp);
// }
int	ft_get_pos_list(t_list *lst, int cible)
{
	int pos;

	pos = 0;
	while (lst)
	{
		if (lst->content == cible)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (pos);
}

long	ft_test_check_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;
	int step_a;
	int step_b;

	steps_temp = 0;
	if (lstA && lstB)
	{
		step_a = ft_get_pos_list(lstA, cible);
		step_b = ft_get_pos_list(lstB, target);
		if (step_a > step_b)
			return (step_a);
		else
			return (step_b);
		// while (lstA->content != cible && lstB->content != target)
		// {
		// 	ft_rotate_rr_test(&lstA, &lstB);
		// 	steps_temp++;
		// }
		// while (lstA->content == cible && lstB->content != target)
		// {
		// 	ft_rotate_b_test(&lstB);
		// 	steps_temp++;
		// }
		// while (lstA->content != cible && lstB->content == target)
		// {
		// 	ft_rotate_a_test(&lstA);
		// 	steps_temp++;
		// }
	}
	return (steps_temp);
}

// long	ft_test_check_reverse_r_test(t_list *lstA,
// 	t_list *lstB, int cible, int target)
// {
// 	long	steps_temp;

// 	steps_temp = 0;
// 	if (lstA && lstB)
// 	{
// 		while (lstA->content != cible && lstB->content != target)
// 		{
// 			ft_reverse_rotate_rrr_test(&lstA, &lstB);
// 			steps_temp++;
// 		}
// 		while (lstA->content == cible && lstB->content != target)
// 		{
// 			ft_reverse_rotate_b_test(&lstB);
// 			steps_temp++;
// 		}
// 		while (lstA->content != cible && lstB->content == target)
// 		{
// 			ft_reverse_rotate_a_test(&lstA);
// 			steps_temp++;
// 		}
// 	}
// 	return (steps_temp);
// }

long	ft_test_check_reverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;
	int		lst_size_a;
	int		lst_size_b;
	int step_a;
	int step_b;

	steps_temp = 0;
	if (lstA && lstB)
	{
		lst_size_a = ft_list_size(lstA);
		lst_size_b = ft_list_size(lstB);
		step_a = ft_get_pos_list(lstA, cible);
		step_b = ft_get_pos_list(lstB, target);
		// ft_printf("sizea:%d sizeb:%d stepa:%d stepb:%d\n", lst_size_a, lst_size_b, step_a, step_b);
		if (step_a == 0 && step_b == 0)
			return (step_a);
		if (step_a == 0)
			return (lst_size_b - step_b);
		if (step_b == 0)
			return (lst_size_a - step_a);
		if (lst_size_a - step_a > lst_size_b - step_b)
			return (lst_size_a - step_a);
		else
			return (lst_size_b - step_b);
		// while (lstA->content != cible && lstB->content != target)
		// {
		// 	ft_reverse_rotate_rrr_test(&lstA, &lstB);
		// 	steps_temp++;
		// }
		// while (lstA->content == cible && lstB->content != target)
		// {
		// 	ft_reverse_rotate_b_test(&lstB);
		// 	steps_temp++;
		// }
		// while (lstA->content != cible && lstB->content == target)
		// {
		// 	ft_reverse_rotate_a_test(&lstA);
		// 	steps_temp++;
		// }
	}
	return (steps_temp);
}
/*
long	ft_test_check_inverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	if (lstA && lstB)
	{
		while (lstA->content != cible && lstB->content != target)
		{
			ft_rotate_a_test(&lstA);
			ft_reverse_rotate_b_test(&lstB);
			steps_temp++;
			steps_temp++;
		}
		while (lstA->content == cible && lstB->content != target)
		{
			ft_reverse_rotate_b_test(&lstB);
			steps_temp++;
		}
		while (lstA->content != cible && lstB->content == target)
		{
			ft_rotate_a_test(&lstA);
			steps_temp++;
		}
	}
	return (steps_temp);
}*/

long	ft_test_check_inverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;
	int		lst_size_a;
	int		lst_size_b;
	int step_a;
	int step_b;

	steps_temp = 0;
	if (lstA && lstB)
	{
		lst_size_a = ft_list_size(lstA);
		lst_size_b = ft_list_size(lstB);
		step_a = ft_get_pos_list(lstA, cible);
		step_b = ft_get_pos_list(lstB, target);
		// ft_printf("sizea:%d sizeb:%d stepa:%d stepb:%d\n", lst_size_a, lst_size_b, step_a, step_b);
		if (step_a == 0 && step_b == 0)
			return (step_a);
		if (step_a == 0)
			return (lst_size_b - step_b);
		if (step_b == 0)
			return (lst_size_a - (lst_size_a - step_a));
		// if (lst_size_a - (lst_size_a - step_a) > lst_size_b - step_b)
		// 	return (lst_size_a - step_a + 1);
		// else
		// 	return (lst_size_b - step_b);
		else
			return ((lst_size_a - (lst_size_a - step_a)) + (lst_size_b - step_b));
		// while (lstA->content != cible && lstB->content != target)
		// {
		// 	ft_rotate_a_test(&lstA);
		// 	ft_reverse_rotate_b_test(&lstB);
		// 	steps_temp++;
		// 	steps_temp++;
		// }
		// while (lstA->content == cible && lstB->content != target)
		// {
		// 	ft_reverse_rotate_b_test(&lstB);
		// 	steps_temp++;
		// }
		// while (lstA->content != cible && lstB->content == target)
		// {
		// 	ft_rotate_a_test(&lstA);
		// 	steps_temp++;
		// }
	}
	return (steps_temp);
}
/*
long	ft_test_check_inverse_reverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;

	steps_temp = 0;
	if (lstA && lstB)
	{
		while (lstA->content != cible && lstB->content != target)
		{
			ft_rotate_b_test(&lstB);
			ft_reverse_rotate_a_test(&lstA);
			steps_temp++;
			steps_temp++;
		}
		while (lstA->content == cible && lstB->content != target)
		{
			ft_rotate_b_test(&lstB);
			steps_temp++;
		}
		while (lstA->content != cible && lstB->content == target)
		{
			ft_reverse_rotate_a_test(&lstA);
			steps_temp++;
		}
	}
	return (steps_temp);
}
*/

long	ft_test_check_inverse_reverse_r_test(t_list *lstA,
	t_list *lstB, int cible, int target)
{
	long	steps_temp;
	int		lst_size_a;
	int		lst_size_b;
	int step_a;
	int step_b;

	steps_temp = 0;
	if (lstA && lstB)
	{
		lst_size_a = ft_list_size(lstA);
		lst_size_b = ft_list_size(lstB);
		step_a = ft_get_pos_list(lstA, cible);
		step_b = ft_get_pos_list(lstB, target);
		// ft_printf("sizea:%d sizeb:%d stepa:%d stepb:%d\n", lst_size_a, lst_size_b, step_a, step_b);
		if (step_a == 0 && step_b == 0)
			return (step_a);
		if (step_a == 0)
			return (lst_size_b - (lst_size_b - step_b));
		if (step_b == 0)
			return (lst_size_a - step_a);
		// if (lst_size_a - (lst_size_a - step_a) > lst_size_b - step_b)
		// 	return (lst_size_a - step_a + 1);
		// else
		// 	return (lst_size_b - step_b);
		else
			return ((lst_size_a - step_a)) + (lst_size_b - (lst_size_b - step_b));
		// while (lstA->content != cible && lstB->content != target)
		// {
		// 	ft_rotate_b_test(&lstB);
		// 	ft_reverse_rotate_a_test(&lstA);
		// 	steps_temp++;
		// 	steps_temp++;
		// }
		// while (lstA->content == cible && lstB->content != target)
		// {
		// 	ft_rotate_b_test(&lstB);
		// 	steps_temp++;
		// }
		// while (lstA->content != cible && lstB->content == target)
		// {
		// 	ft_reverse_rotate_a_test(&lstA);
		// 	steps_temp++;
		// }
	}
	return (steps_temp);
}
