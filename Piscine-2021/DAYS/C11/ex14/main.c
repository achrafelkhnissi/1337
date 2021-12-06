/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:57:35 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:57:36 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_list_sort.c"

t_list	*create_elem(void *data);
void	print_list(t_list *head);
void	append_elem(t_list **head, void *data);

int	main(void)
{
	t_list	*list1;

	list1 = 0;
	append_elem(&list1, "1");
	append_elem(&list1, "0");
	append_elem(&list1, "9");
	append_elem(&list1, "3");
	append_elem(&list1, "7");
	append_elem(&list1, "4");
	print_list(list1);
	printf("\nAfter sort:\n");
	ft_list_sort(&list1, strcmp);
	print_list(list1);
	return (0);
}

void	append_elem(t_list **head, void *data)
{
	t_list	*elem;

	if (*head)
	{
		elem = *head;
		while (elem->next)
			elem = elem->next;
		elem->next = create_elem(data);
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
