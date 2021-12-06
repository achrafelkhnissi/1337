/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:55:08 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:55:08 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"
#include "ft_list_last.c"

void	print_list(t_list *head);
t_list	*create_node(void *data);
void	append_node(t_list **head, void *data);
void	insert_node(t_list **head, void *data);

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*last;
	int	i;

	head = NULL;
	i = 0;
	if (ac)
	{
		while (i < ac)
			append_node(&head, av[i++]);
		print_list(head);
	}
	last = ft_list_last(head);
	printf("\nlast: ");
	print_list(last);
	insert_node(&head, "test1");
	insert_node(&head, "test2");
	printf("\n");
	print_list(head);
	return (0);
}

void	insert_node(t_list **head, void *data)
{
	t_list	*node;

	if (*head)
	{
		node = create_node(data);
		node->next = *head;
		*head = node;
	}
	else
		*head = create_node(data);
}

void	append_node(t_list **head, void *data)
{
	t_list	*node;

	if (*head)
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = create_node(data);
	}
	else
		*head = create_node(data);
}

t_list	*create_node(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	print_list(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("%d: %s\n", i++, head->data);
		head = head->next;
	}
}
