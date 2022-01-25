/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:44:37 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/19 23:44:52 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_chunk_elem(t_stack *a, int subdiv)
{
	t_node	*top;
	t_node	*bottom;
	int		i;
	int		j;

	top = a->top;
	bottom = a->bottom;
	i = 0;
	j = a->size - 1;
	while (i++ <= j--)
	{
		if (top->data <= subdiv)
			return (&top->data);
		else if (bottom->data <= subdiv)
			return (&bottom->data);
		top = top->bellow;
		bottom = bottom->above;
	}
	return (NULL);
}
