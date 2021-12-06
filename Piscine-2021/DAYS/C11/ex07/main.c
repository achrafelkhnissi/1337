/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:56:09 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:56:11 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"
#include "ft_list_at.c"

void	print_list(t_list *head);
void	append_elem(t_list **head, void *data);
void	free_list(t_list **head);

int	main(void)
{
	t_list	*head;
	t_list	*ptr;

	head = 0;
	/*
	append_elem(&head, "test0");
	append_elem(&head, "test1");
	append_elem(&head, "test2");
	append_elem(&head, "test3");
	append_elem(&head, "test4");
	append_elem(&head, "test5");
	append_elem(&head, "test6");
	*/
	print_list(head);
	ptr = ft_list_at(head, 4);
	print_list(head);
	//printf("The 4th elemnt is = %s\n", ptr->data);
	free_list(&head);
	return (0);
}

void	free_list(t_list **head)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *head;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*head = 0;
}

void	append_elem(t_list **head, void *data)
{
	t_list	*elem;

	if (*head)
	{
		elem = *head;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
	else
		*head = ft_create_elem(data);

}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", head->data);
		head = head->next;
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
