/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:45:24 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/19 23:45:35 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem_index(t_stack a, int elem)
{
	int	index;

	index = 0;
	if (!a.top)
		return (-1);
	while (a.top && a.top->data != elem)
	{
		a.top = a.top->bellow;
		index++;
	}
	return (index);
}
