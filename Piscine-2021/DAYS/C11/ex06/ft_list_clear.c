/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:55:34 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:55:35 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *begin_list;
	if (!ptr)
		return ;
	while (ptr)
	{
		tmp = ptr;
		free(ptr);
		ptr = tmp->next;
	}
	*begin_list = NULL;
}
