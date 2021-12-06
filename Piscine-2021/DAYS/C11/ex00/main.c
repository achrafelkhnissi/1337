/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:53:57 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:53:59 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

void	push1(t_list **begin_list, void *data);
void	print_list(t_list *list);

void	test_push1(void); // using double pointers.

t_list	*create_node(void *data)
{
	t_list	*test;

	test = malloc(sizeof(t_list));
	if (!test)
		return (NULL);
	test->data = data;
	test->next = NULL;
	return (test);
}

int	main(void)
{
	printf("test1: \n");
	test_push1();
	return (0);
}

void	test_push1(void)
{
	t_list	*head;

	head = NULL;
	push1(&head, "double1");
	push1(&head, "double2");
	push1(&head, "double3");
	push1(&head, "double4");
	print_list(head);
}

void	push1(t_list **begin_list, void *data)
{
	t_list *elem;

	if (*begin_list)
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void	print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current != NULL)
	{
		printf("%s\n", current->data);
		current = current->next;
	}
}
