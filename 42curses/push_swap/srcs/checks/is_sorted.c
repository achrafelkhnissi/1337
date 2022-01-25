/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:03:50 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/16 15:28:36 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted: a function to check if stack is sorted or not */
int	is_sorted(t_stack stack)
{
	if (is_empty(&stack))
		return (1);
	while (stack.top->bellow)
	{
		if (stack.top->data > stack.top->bellow->data)
			return (0);
		stack.top = stack.top->bellow;
	}
	return (1);
}
