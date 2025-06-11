/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:24:56 by kevwang           #+#    #+#             */
/*   Updated: 2025/04/28 11:24:58 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
/*
int main()
{
	// char str[] = "bonjour";
	// t_list	*test;

	// test = ft_lstnew(str);

	// printf("%s\n", (char *)test->content);

	int tab[] = {11,22,33,44,55};
	// int tab = 55;
	t_list	*test;

	test = ft_lstnew(&tab);
	int i = 0;
	int val;
	int *s = (int *)test->content;
	while(i< 5)
	{
		val = s[i];
		printf("%d\n", val);
		i++;
	}
}
*/
/*
int main()
{
    // char    str [] = "lorem ipsum dolor sit";
    int str = 42;
    t_list *elem;
    if (!(elem = ft_lstnew(&str)))
            printf("NULL1");
    else
    {
        if (!(elem->content))
            printf("NULL2");
        else
        {
            printf("test : %d", *(int *)elem->content);
        }
        if (!(elem->next))
        {
            write(1, "\n", 1);
            printf("NULL3");
        }
    }
}
*/