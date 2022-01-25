/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:29:19 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/20 02:29:20 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_sort(t_stack *a, t_stack *b)
{
	int	subdiv;
	int	div;
	int	min;
	int	max;
	int	i;

	i = 1;
	if (a->size >= 100 && a->size < 500)
		div = 6;
	else
		div = 12;
	min = get_min(a);
	max = get_max(a);
	subdiv = (min + max) / div;
	while (!is_empty(a))
		push_chunk_elems(a, b, subdiv * i++);
	push_to_stack_a(a, b);
}
