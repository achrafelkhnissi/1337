/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_chunk_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:49:30 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/19 23:49:45 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_elems(t_stack *a, t_stack *b, int subdiv)
{
	int	*elem;
	int	index;
	int	i;

	elem = get_chunk_elem(a, subdiv);
	while (elem)
	{
		i = 0;
		index = get_elem_index(*a, *elem);
		if (index == -1)
			return ;
		if (index <= a->size / 2)
			while (i++ < index)
				ra_rotate_a(a, false);
		else
			while (i++ < a->size - index)
				rra_reverse_rotate_a(a, false);
		pb_push_b(a, b);
		elem = get_chunk_elem(a, subdiv);
	}
}
