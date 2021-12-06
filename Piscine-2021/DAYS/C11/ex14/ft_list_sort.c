/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:57:32 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:57:33 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

