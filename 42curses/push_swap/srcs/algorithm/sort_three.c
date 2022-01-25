/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:39:33 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/20 02:30:13 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	min;

	min = get_elem_index(*a, get_min(a));
	if (min == 1)
	{
		if (a->top->data > a->bottom->data)
			ra_rotate_a(a, false);
		else
			sa_swap_a(a, false);
	}
	else if (min == 2)
	{
		if (a->top->data > a->top->bellow->data)
		{
			sa_swap_a(a, false);
			rra_reverse_rotate_a(a, false);
		}
		else
			rra_reverse_rotate_a(a, false);
	}
	else
	{
		sa_swap_a(a, false);
		ra_rotate_a(a, false);
	}
}
