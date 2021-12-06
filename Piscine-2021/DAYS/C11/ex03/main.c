/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:54:53 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:54:54 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"
#include "ft_list_size.c"

t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);

int	main(void)
{
	t_list	*head;
	int	list_size;

	head = NULL;
	list_size = 0;
	ft_list_push_back(&head, "1");
	ft_list_push_back(&head, "2");
	ft_list_push_front(&head, "0");
	ft_list_push_front(&head, "-1");
	printf("size = %d\n", ft_list_size(head));
	return (0);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	if (*begin_list)
	{
		elem = ft_create_elem(data);
		elem->next = *begin_list;
		*begin_list = elem;
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;

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


t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
