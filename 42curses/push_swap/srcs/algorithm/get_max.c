/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:45:46 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/19 23:45:58 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	tmp = stack->top;
	max = tmp->data;
	while (tmp->bellow)
	{
		tmp = tmp->bellow;
		if (max < tmp->data)
			max = tmp->data;
	}
	return (max);
}
