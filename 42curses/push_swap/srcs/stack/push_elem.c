/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:28:36 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/20 02:28:37 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elem(t_stack *stack, t_node *elem)
{
	if (!is_empty(stack))
	{
		elem->bellow = stack->top;
		stack->top->above = elem;
	}
	else
		stack->bottom = elem;
	stack->top = elem;
	stack->size++;
}
