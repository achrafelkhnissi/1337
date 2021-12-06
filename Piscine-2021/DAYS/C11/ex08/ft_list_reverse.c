/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:56:19 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:56:21 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*head;
	t_list	*prev;
	t_list	*next;

	head = *begin_list;
	prev = NULL;
	next = NULL;
	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	*begin_list = prev;
}
