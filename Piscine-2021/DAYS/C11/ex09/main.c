/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:56:37 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:56:39 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list_foreach.c"

t_list	*create_elem(void *data);
void	print_list(t_list *head);
void	insert_elem(t_list **head, void *data);

void	test_func(void *data)
{
	printf("%s\n", data);
}

int	main(void)
{
	t_list	*head;

	head = 0;
	insert_elem(&head, "Hello");
	insert_elem(&head, "World!");
	print_list(head);
	printf("Another test:\n");
	ft_list_foreach(head, test_func);
	return (0);
}

void	insert_elem(t_list **head, void *data)
{
	t_list	*elem;

	if (*head)
	{
		elem = create_elem(data);
		elem->next = *head;
		*head = elem;
	}
	else
		*head = create_elem(data);
}

t_list	*create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s ", head->data);
		head = head->next;
	}
	putchar('\n');
}
