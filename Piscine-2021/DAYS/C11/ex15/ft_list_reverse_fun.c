/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:57:43 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:57:44 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*head;
	void	*tmp;
	int	size;
	int	i;
	int	j;

	head = begin_list;
	size = 0;
	i = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	while (i < size - 1)
	{
		head = begin_list;
		j = i;
		while (head && j < size - 1)
		{
			tmp = head->data;
			head->data = head->next->data;
			head->next->data = tmp;
			head = head->next;
			j++;
		}
		i++;
	}
}

