/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:46:26 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/19 23:46:37 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_stack *a, t_stack *b)
{
	int	i;
	int	index;

	while (!is_empty(b))
	{
		i = 0;
		index = get_elem_index(*b, get_max(b));
		if (index == -1)
			return ;
		if (index <= b->size / 2)
			while (i++ < index)
				rb_rotate_b(b, false);
		else
			while (i++ < b->size - index)
				rrb_reverse_rotate_b(b, false);
		pa_push_a(a, b);
	}
}
