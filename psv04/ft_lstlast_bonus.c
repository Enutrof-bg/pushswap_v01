/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:41:59 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 12:42:03 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (lst == NULL)
		return (NULL);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

/*
int main()
{
	t_list *node1 = ft_lstnew("toto");
	t_list *node2 = ft_lstnew("coco");
	t_list *node3 = ft_lstnew("momo");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// t_list *test;
	// test = ft_lstlast(node1);
	// printf("%s\n", (char *)test->content);

	t_list *val = ft_lstlast(node1);
    int i = 0;
    void *content = val->content;
    char *char_s = (char *)content;
    while (char_s[i])
        write(1, &(char_s[i++]), 1);
    write(1, " test1\n", 7);


    node1->next = NULL;
    val = ft_lstlast(node1);
    char_s = val->content;
    i = 0;
    while (char_s[i])
        write(1, &(char_s[i++]), 1);
    write(1, " test2\n", 7);


    node1 = NULL;
    val = ft_lstlast(node1);
    if (val == NULL)
        write(1, "NULL", 4);
    write(1, " test3\n", 7);
}
*/