/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:56:25 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:56:27 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list_reverse.c"

void	append(t_list **begin_list, void *data);
void	print_list(t_list *head);
t_list	*create_elem(void * data);

int	main(void)
{
	t_list	*head;

	head = 0;
	append(&head, "Hello");
	append(&head, "World");
	print_list(head);
	ft_list_reverse(&head);
	printf("reversed:\n");
	print_list(head);
	return (0);
}

void	append(t_list **begin_list, void *data)
{
	t_list	*elem;

	if (*begin_list)
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = create_elem(data);	
	}
	else
		*begin_list = create_elem(data);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", head->data);
		head = head->next;
	}
}

t_list	*create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = data;
	new->next = NULL;
	return (new);
}
