/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:54:35 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:54:37 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_list
{
	void	*data;
	struct s_list	*next;
}	t_list;

t_list	*create_node(void *data);
void	append_node(t_list **head, void *data);
void	inset_node(t_list **head, void *data);
void	print_list(t_list *head);

int	main(void)
{
	t_list	*test;

	test = NULL;
	inset_node(&test, "Hello world!");
	append_node(&test, "1111");
	inset_node(&test, "0000");
	print_list(test);
	return (0);
}

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		printf("%s\n", current->data);
		current = current->next;
	}
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

void	append_node(t_list **head, void *data)
{
	t_list	*elem;

	if (*head)
	{
		elem = *head; 
		while(elem->next)
			elem = elem->next;
		elem->next = create_node(data);	
	}
	else
		*head = create_node(data);
}

void	inset_node(t_list **head, void *data)
{
	t_list	*elem;

	if (*head)
	{
		elem = create_node(data);
		elem->next = *head;
		*head = elem;
	}
	else
		*head = create_node(data);
}
