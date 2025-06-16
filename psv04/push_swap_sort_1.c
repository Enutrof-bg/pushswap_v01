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

void ft_print_steps(t_list **lst)
{
	t_list *temp;
	int pos;

	pos = 1;
	temp = (*lst);
	ft_printf("ft_printf_steps\n");
	while ((*lst))
	{
		printf("pos:%d value:%d steps:%ld soluce:%d target:%d\n", pos++, (*lst)->content, (*lst)->steps, (*lst)->soluce, (*lst)->target);
		//ATTENTION FT_PRINTF PAS DE LONG, ALORS PRINTF
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
}

void ft_reset_steps(t_list **lst)
{
	t_list *temp;

	temp = (*lst);
	while ((*lst))
	{
		(*lst)->steps = LONG_MAX;
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	// ft_print_steps(lst);
}

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
//trouve la plus petite 
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

//trouve la plus grande
int	ft_get_target_2(t_list *lstA, t_list *lstB, int cible)
{
	(void)lstB;
	long	target;
	t_list	*temp;

	target = LONG_MIN;
	temp = lstA;
	while ((lstA))
	{
		// printf("cacatarget:%ld lstb:%d lsta:%d\n", target, cible, lstA->content);
		if (cible > (lstA)->content
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
		//
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
			// ft_sort_5value_a(lstA, target, ft_target_pos(*lstA, target), nbr_value);
			// ft_push_b(lstA, lstB);
			if (ft_find_high(*lstA, target, nbr_value) == 0)
			{
				while ((*lstA)->content != target)
				{
					
					ft_reverse_rotate_a(lstA);
				}
			}
			if (ft_find_high(*lstA, target, nbr_value) == 1)
			{
				while ((*lstA)->content != target)
				{
					ft_rotate_a(lstA);
					
				}
			}
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
					// ft_reverse_rotate_a(lstA);
					ft_rotate_a(lstA);
				}
			}
			if (ft_find_high(*lstA, small, nbr_value) == 1)
			{
				while ((*lstA)->content != small)
				{
					// ft_rotate_a(lstA);
					ft_reverse_rotate_a(lstA);
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

	if (nbr_value > 4)
		ft_push_b(lstA, lstB);
	ft_push_b(lstA, lstB);
	//
	// ft_lstprint_2(*lstA, *lstB);
	// while ((*lstA))
	while (ft_list_size(*lstA) > 3)
	{
		small = ft_get_smallest(*lstB);
		high = ft_get_highest(*lstB);
		// ft_printf("small:%d high:%d\n", small, high);
		if ((*lstA)->content > small && (*lstA)->content < high)
		{
			target = ft_get_target_2(*lstB, *lstA, (*lstA)->content);
			// ft_printf("target:%d\n", target);
			// ft_sort_5value_b(lstB, target, ft_target_pos(*lstB, target), nbr_value);
			// ft_push_b(lstA, lstB);
			if (ft_find_high(*lstB, target, nbr_value) == 0)
			{
				while ((*lstB)->content != target)
				{
					// ft_rotate_b(lstB);
					ft_reverse_rotate_b(lstB);
				}
			}
			if (ft_find_high(*lstB, target, nbr_value) == 1)
			{
				while ((*lstB)->content != target)
				{
					ft_rotate_b(lstB);
					// ft_reverse_rotate_b(lstB);
				}
			}
		}
		// ft_printf("small:%d high:%d\n", small, high);
		else if (/*(*lstA)->content < small || */(*lstA)->content > high)
		{
			if (ft_find_high(*lstB, high, nbr_value) == 0)
			{
				while ((*lstB)->content != high)
				{
					// ft_printf("test1\n");
					// ft_rotate_b(lstB);
					ft_reverse_rotate_b(lstB);
				}
			}
			if (ft_find_high(*lstB, high, nbr_value) == 1)
			{
				while ((*lstB)->content != high)
				{
					// ft_printf("test2\n");
					ft_rotate_b(lstB);
					// ft_reverse_rotate_b(lstB);
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
					// ft_printf("test3\n");
					ft_reverse_rotate_b(lstB);
					// ft_rotate_b(lstB);
				}
			}
			if (ft_find_high(*lstB, high, nbr_value) == 1)
			{
				while ((*lstB)->content != high)
				{
					// ft_printf("test4\n");
					ft_rotate_b(lstB);
					// ft_reverse_rotate_b(lstB);
				}
			}
			// ft_push_b(lstA, lstB);
		}
		ft_push_b(lstA, lstB);
		//
		// ft_lstprint_2(*lstA, *lstB);
	}
	ft_sort_3value(lstA);
	ft_sort_back(lstA, lstB, nbr_value);
	// ft_sort_end(lstA, lstB, nbr_value);
}

int ft_target(t_list *lstA, t_list *lstB, int cible)
{
	int small;
	int high;

	small = ft_get_smallest(lstB);
	high = ft_get_highest(lstB);
	if (cible > small && cible < high)
	{
		// ft_printf("test:1 ");
		return (ft_get_target_2(lstB, lstA, cible));
	}
	else
	{
		// ft_printf("test:2 ");
		return (high);
	}
}

long ft_test_check_r_test(t_list *lstA, t_list *lstB, int cible, int target)
{
	(void)lstA;
	(void)lstB;
	(void)cible;
	(void)target;
	long steps_temp;
	// long tempA;
	// long tempB;

	steps_temp = 0;
	// tempA = lstA->content;
	// tempB = lstB->content;
	// ft_printf("test_check_rotate\n");
	// target = ft_target(lstA, lstB, cible);
	// ft_printf("target:%d\n", target);
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_rr_test(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_rotate\n");
		// ft_lstprint_2(lstA, lstB);
		// target = ft_target(lstA, lstB, cible);
		// ft_printf("cible:%d target:%d\n", cible, target);
		ft_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a_test(&lstA);
		steps_temp++;
	}
	// while (lstA->content != tempA)
	// 	ft_rotate_a_test(&lstA);
	// while (lstB->content != tempB)
	// 	ft_rotate_b_test(&lstB);
	return (steps_temp);
}

long ft_test_check_reverse_r_test(t_list *lstA, t_list *lstB, int cible, int target)
{
	(void)lstA;
	(void)lstB;
	(void)cible;
	(void)target;
	long steps_temp;
	// long tempA;
	// long tempB;

	steps_temp = 0;
	// tempA = lstA->content;
	// tempB = lstB->content;
	// ft_printf("test_check_reverse_rotate\n");
	while (lstA->content != cible && lstB->content != target)
	{
		ft_reverse_rotate_rrr_test(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_reverse_rotate\n");
		ft_reverse_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a_test(&lstA);
		steps_temp++;
	}
	// while (lstA->content != tempA)
	// 	ft_rotate_a_test(&lstA);
	// while (lstB->content != tempB)
	// 	ft_rotate_b_test(&lstB);
	return (steps_temp);
}

long ft_test_check_inverse_r_test(t_list *lstA, t_list *lstB, int cible, int target)
{
	(void)lstA;
	(void)lstB;
	(void)cible;
	(void)target;
	long steps_temp;
	// long tempA;
	// long tempB;

	steps_temp = 0;
	// tempA = lstA->content;
	// tempB = lstB->content;
	// ft_printf("test_check_inverse_rotate\n");
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_a_test(&lstA);
		ft_reverse_rotate_b_test(&lstB);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_inverse_rotate\n");
		ft_reverse_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a_test(&lstA);
		steps_temp++;
	}
	// while (lstA->content != tempA)
	// 	ft_rotate_a_test(&lstA);
	// while (lstB->content != tempB)
	// 	ft_rotate_b_test(&lstB);
	return (steps_temp);
}

long ft_test_check_inverse_reverse_r_test(t_list *lstA, t_list *lstB, int cible, int target)
{
	long steps_temp;

	steps_temp = 0;
	// long tempA;
	// long tempB;

	// tempA = lstA->content;
	// tempB = lstB->content;
	// ft_printf("test_check_inverse_reverse_rotate\n");
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_b_test(&lstB);
		ft_reverse_rotate_a_test(&lstA);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_inverse_reverse_rotate\n");
		ft_rotate_b_test(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a_test(&lstA);
		steps_temp++;
	}
	// while (lstA->content != tempA)
	// 	ft_rotate_a_test(&lstA);
	// while (lstB->content != tempB)
	// 	ft_rotate_b_test(&lstB);
	return (steps_temp);
}


long ft_test_check_r(t_list *lstA, t_list *lstB, int cible, int target)
{
	(void)lstA;
	(void)lstB;
	(void)cible;
	(void)target;
	long steps_temp;

	steps_temp = 0;
	// ft_printf("test_check_rotate\n");
	// target = ft_target(lstA, lstB, cible);
	// ft_printf("target:%d\n", target);
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_rr(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_rotate\n");
		// ft_lstprint_2(lstA, lstB);
		// target = ft_target(lstA, lstB, cible);
		// ft_printf("cible:%d target:%d\n", cible, target);
		ft_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long ft_test_check_reverse_r(t_list *lstA, t_list *lstB, int cible, int target)
{
	(void)lstA;
	(void)lstB;
	(void)cible;
	(void)target;
	long steps_temp;

	steps_temp = 0;
	// ft_printf("test_check_reverse_rotate\n");
	while (lstA->content != cible && lstB->content != target)
	{
		ft_reverse_rotate_rrr(&lstA, &lstB);
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_reverse_rotate\n");
		ft_reverse_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long ft_test_check_inverse_r(t_list *lstA, t_list *lstB, int cible, int target)
{
	(void)lstA;
	(void)lstB;
	(void)cible;
	(void)target;
	long steps_temp;

	steps_temp = 0;
	// ft_printf("test_check_inverse_rotate\n");
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_a(&lstA);
		ft_reverse_rotate_b(&lstB);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_inverse_rotate\n");
		ft_reverse_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

long ft_test_check_inverse_reverse_r(t_list *lstA, t_list *lstB, int cible, int target)
{
	long steps_temp;

	steps_temp = 0;
	// ft_printf("test_check_inverse_reverse_rotate\n");
	while (lstA->content != cible && lstB->content != target)
	{
		ft_rotate_b(&lstB);
		ft_reverse_rotate_a(&lstA);
		steps_temp++;
		steps_temp++;
	}
	while (lstA->content == cible && lstB->content != target)
	{
		// ft_printf("test_check_inverse_reverse_rotate\n");
		ft_rotate_b(&lstB);
		steps_temp++;
	}
	while (lstA->content != cible && lstB->content == target)
	{
		ft_reverse_rotate_a(&lstA);
		steps_temp++;
	}
	return (steps_temp);
}

void ft_copy_list(t_list **tempA, t_list **tempB, t_list *lstA, t_list *lstB)
{
	if (*tempA)
		ft_clear(tempA);
	if (*tempB)
		ft_clear(tempB);
	*tempA = ft_lstmap_test(lstA);
	*tempB = ft_lstmap_test(lstB);
}

void ft_set_soluce(t_list **lst, int cible, int soluce, int target)
{
	t_list *temp;
	(void)target;
	temp = *lst;
	while (*lst)
	{
		if ((*lst)->content == cible)
		{
			(*lst)->soluce = soluce;
			(*lst)->target = target;
			break ;
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
}

long ft_how_many_steps(t_list **lstA, t_list **lstB, int cible, int target)
{
	long steps;
	long steps_temp;
	t_list *tempA;
	t_list *tempB;

	steps = LONG_MAX;
	tempA = NULL;
	tempB = NULL;
	// tempA = ft_lstmap_test(lstA);
	// tempB = ft_lstmap_test(lstB);
	ft_copy_list(&tempA, &tempB, *lstA, *lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_r_test(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 100, target);
	}
	// ft_printf("MIN_STEPS:%d\n", steps);
	// ft_clear(&tempA);
	// ft_clear(&tempB);
	// tempA = ft_lstmap_test(lstA);
	// tempB = ft_lstmap_test(lstB);
	ft_copy_list(&tempA, &tempB, *lstA, *lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_reverse_r_test(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 200, target);
	}
	// ft_printf("MIN_STEPS:%d\n", steps);

	ft_copy_list(&tempA, &tempB, *lstA, *lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_inverse_r_test(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 300, target);
	}
	// ft_printf("MIN_STEPS:%d\n", steps);


	ft_copy_list(&tempA, &tempB, *lstA, *lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_inverse_reverse_r_test(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		ft_set_soluce(lstA, cible, 400, target);
	}
	// ft_printf("MIN_STEPS:%d\n", steps);

	// ft_lstprint_2(tempA, tempB);
	ft_clear(&tempA);
	ft_clear(&tempB);

	// ft_lstprint_2(lstA, lstB);

	return (steps);
}


long ft_sauvage(t_list *lstA, t_list *lstB, int cible, int target)
{
	long steps;
	long steps_temp;
	t_list *tempA;
	t_list *tempB;

	steps = LONG_MAX;
	tempA = NULL;
	tempB = NULL;
	// tempA = ft_lstmap_test(lstA);
	// tempB = ft_lstmap_test(lstB);
	ft_copy_list(&tempA, &tempB, lstA, lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_r(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		lstA->soluce = 1;
	}
	// ft_printf("MIN_STEPS:%d\n", steps);
	// ft_clear(&tempA);
	// ft_clear(&tempB);
	// tempA = ft_lstmap_test(lstA);
	// tempB = ft_lstmap_test(lstB);
	ft_copy_list(&tempA, &tempB, lstA, lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_reverse_r(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		lstA->soluce = 999;
	}
	// ft_printf("MIN_STEPS:%d\n", steps);

	ft_copy_list(&tempA, &tempB, lstA, lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_inverse_r(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		lstA->soluce = 3;
	}
	// ft_printf("MIN_STEPS:%d\n", steps);


	ft_copy_list(&tempA, &tempB, lstA, lstB);
	// ft_lstprint_2(lstA, lstB);
	// ft_lstprint_2(tempA, tempB);
	steps_temp = ft_test_check_inverse_reverse_r(tempA, tempB, cible, target);
	if (steps_temp < steps)
	{
		steps = steps_temp;
		lstA->soluce = 4;
	}
	// ft_printf("MIN_STEPS:%d\n", steps);


	// ft_lstprint_2(lstA, lstB);

	return (steps);
}

long ft_calculate_steps_node(t_list **lstA, t_list **lstB, int cible)
{
	(void)lstA;
	(void)lstB;
	long steps;
	int target;
	
	steps = LONG_MAX;
	// steps = 9999999;
	target = ft_target(*lstA, *lstB, cible);
	// printf("cible:%d target:%d\n", cible, target);
	steps = ft_how_many_steps(lstA, lstB, cible, target);
	return (steps);
}

long ft_calculate_steps_node_2(t_list **lstA, t_list **lstB, int cible)
{
	(void)lstA;
	(void)lstB;
	long steps;
	int target;
	
	steps = LONG_MAX;
	// steps = 9999999;
	target = ft_target(*lstA, *lstB, cible);
	// printf("cible:%d target:%d\n", cible, target);
	// steps = ft_how_many_steps(lstA, lstB, cible, target);
	return (steps);
}

int ft_min_step(t_list *lst)
{
	t_list *temp;
	t_list *value;

	temp = lst;
	value = lst;
	while (lst)
	{
		// ft_printf("c:%d s:%d cn:%d sn:%d\n", lst->content, lst->steps, lst->next->content, lst->next->steps);
		if (lst->next && value->steps > lst->next->steps)
		{
			// ft_printf("c:%d s:%d cn:%d sn:%d\n", lst->content, lst->steps, lst->next->content, lst->next->steps);
			value = lst->next;
		}
		lst = lst->next;
	}
	// ft_printf("c:%d s:%d cn:%d sn:%d\n", lst->content, lst->steps, lst->next->content, lst->next->steps);
	lst = temp;
	return (value->content);
}
/*
int ft_find_soluce(t_list **lst, t_list **lstB, int cible)
{
	t_list *temp;
	// int soluce;
	(void)cible;
	int soluce;

	soluce = -1;
	temp = *lst;
	while (*lst)
	{
		if ((*lst)->content == cible)
		{
			soluce = ft_sauvage(temp, *lstB, cible, ft_target(temp, *lstB, cible));
		}
		// ft_printf("content:%d soluce:%d\n", lst->content, lst->soluce);

		*lst = (*lst)->next;
	}
	*lst = temp;
	return (soluce);
}
*/
void ft_execute_soluce(t_list **lstA, t_list **lstB, int value)
{
	t_list *temp;
	int target;

	temp = (*lstA);
	target = ft_target(temp, *lstB, value);
	// printf("target:%d\n", target);
	while (*lstA)
	{
		if ((*lstA)->content == value)
		{
			if ((*lstA)->soluce == 100)
				ft_test_check_r(temp, *lstB, value, ft_target(temp, *lstB, value));
			if ((*lstA)->soluce == 200)
				ft_test_check_reverse_r(temp, *lstB, value, ft_target(temp, *lstB, value));
			if ((*lstA)->soluce == 300)
				ft_test_check_inverse_r(temp, *lstB, value, ft_target(temp, *lstB, value));
			if ((*lstA)->soluce == 400)
				ft_test_check_inverse_reverse_r(temp, *lstB, value, ft_target(temp, *lstB, value));
			break ;
		}
		(*lstA) = (*lstA)->next;
	}
	(*lstA) = temp;
}

void ft_execute_soluce_back(t_list **lstA, t_list **lstB, int value)
{
	t_list *temp;
	int target;

	temp = (*lstA);
	target = ft_get_target(*lstB, temp);
	// printf("target:%d\n", target);
	while (*lstA)
	{
		if ((*lstA)->content == value)
		{
			if ((*lstA)->soluce == 100)
				ft_test_check_r(temp, *lstB, value, target);
			if ((*lstA)->soluce == 200)
				ft_test_check_reverse_r(temp, *lstB, value, target);
			if ((*lstA)->soluce == 300)
				ft_test_check_inverse_r(temp, *lstB, value, target);
			if ((*lstA)->soluce == 400)
				ft_test_check_inverse_reverse_r(temp, *lstB, value, target);
			break ;
		}	
		(*lstA) = (*lstA)->next;
	}
	(*lstA) = temp;
}

void ft_calculate_steps_lst(t_list **lstA, t_list **lstB)
{
	(void)lstA;
	(void)lstB;
	t_list *temp;
	int value;
	int soluce;

	value = 0;
	soluce = 999;
	while (ft_list_size(*lstA) > 3)
	{
	// temp = ft_lstmap_test(*lstA);
		temp = (*lstA);
		while ((*lstA))
		{
			(*lstA)->steps = ft_calculate_steps_node(&temp, (lstB), (*lstA)->content);
			(*lstA) = (*lstA)->next;
		}
		(*lstA) = temp;
		// ft_print_steps(lstA);
		// ft_lstprint_2(*lstA, *lstB);
		value = ft_min_step((*lstA));
		// ft_lstprint_2(*lstA, *lstB);
		// soluce = ft_find_soluce((lstA), lstB, value);
		// ft_printf("value:%d soluce:%d\n", value, soluce);
		// ft_printf("value:%d\n", value);
		// ft_clear(&temp);
		// ft_lstprint_2(*lstA, *lstB);
		ft_execute_soluce(lstA, lstB, value);
		ft_push_b(lstA, lstB);
	}
	ft_sort_3value(lstA);
	int test = ft_get_target(*lstA, *lstB);
	// ft_printf("toto:%d\n", test);
	// temp = (*lstA);
	t_list *tempA;
	t_list *tempB;
	tempA = NULL;
	tempB = NULL;
	while (*lstB)
	{
		ft_copy_list(&tempA, &tempB, *lstA, *lstB);

		long steps = LONG_MAX;
		long temp_steps;
		// ft_printf("steps:%d\n", steps);
		temp_steps = ft_test_check_r_test(tempB, tempA, (*lstB)->content, test);
		// ft_printf("temp_steps:%d\n", temp_steps);
		if (temp_steps < steps)
		{
			steps = temp_steps;
			ft_set_soluce(lstB, (*lstB)->content, 100, test);
		}
		ft_copy_list(&tempA, &tempB, *lstA, *lstB);
		// ft_printf("steps:%d\n", steps);
		temp_steps = ft_test_check_reverse_r_test(tempB, tempA, (*lstB)->content, test);
		// ft_printf("temp_steps:%d\n", temp_steps);
		if (temp_steps < steps)
		{
			steps = temp_steps;
			ft_set_soluce(lstB, (*lstB)->content, 200, test);
		}
		// ft_printf("steps:%d\n", steps);
		// ft_printf("stepslstb:%d\n", (*lstB)->soluce);
		ft_clear(&tempA);
		ft_clear(&tempB);
		ft_execute_soluce_back(lstB, lstA, (*lstB)->content);
		ft_push_a(lstA, lstB);
	}
	int small = ft_get_smallest(*lstA);
	ft_copy_list(&tempA, &tempB, *lstA, *lstB);
	long steps = LONG_MAX;
	long temp_steps = 0;
	int rotate = 0;
	while ((tempA)->content != small)
	{
		ft_rotate_a_test(&tempA);
		temp_steps++;
	}
	if (temp_steps < steps)
	{
		steps = temp_steps;
		rotate = 1;
	}
	ft_copy_list(&tempA, &tempB, *lstA, *lstB);
	while ((tempA)->content != small)
	{
		ft_reverse_rotate_a_test(&tempA);
		temp_steps++;
	}
	if (temp_steps < steps)
	{
		steps = temp_steps;
		rotate = 2;
	}
	if (rotate == 1)
	{
		while ((*lstA)->content != small)
		{
			ft_rotate_a(lstA);
		}
	}
	else if (rotate == 2)
	{
		while ((*lstA)->content != small)
		{
			ft_reverse_rotate_a(lstA);
		}
	}
	ft_clear(&tempA);
	ft_clear(&tempB);
}

void ft_sort_jsp(t_list **lstA, t_list **lstB, int nbr_value)
{
	(void)lstA;
	(void)lstB;
	(void)nbr_value;
	ft_reset_steps(lstA);
	if (nbr_value > 4)
		ft_push_b(lstA, lstB);
	ft_push_b(lstA, lstB);
	// ft_push_b(lstA, lstB);
	// ft_push_b(lstA, lstB);
	// ft_push_b(lstA, lstB);
	// ft_push_b(lstA, lstB);
	// ft_push_b(lstA, lstB);
	ft_calculate_steps_lst(lstA, lstB);
	// ft_calculate_steps_lst(lstA, lstB);
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
		// ft_sort_test(lstA, lstB, nbr_value);
		ft_sort_jsp(lstA, lstB, nbr_value);
	}
}
