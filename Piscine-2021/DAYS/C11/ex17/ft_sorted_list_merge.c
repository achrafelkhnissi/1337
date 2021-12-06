/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:58:21 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:58:23 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list **begin_list2)
{
	t_list	*head;

	head = *begin_list1;
	while (head->next)
		head = head->next;
	head->next = *begin_list2;
}

void	swap_elems(t_list *elem)
{
	void	*tmp;

	tmp = elem->data;
	elem->data = elem->next->data;
	elem->next->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;

	curr = *begin_list;
	while (curr->next)
	{
		if (cmp(curr->data, curr->next->data) > 0)
		{
			swap_elems(curr);
			curr = *begin_list;
		}
		else
			curr = curr->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, &begin_list2);
	ft_list_sort(begin_list1, cmp);
}
