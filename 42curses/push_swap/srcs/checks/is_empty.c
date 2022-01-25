/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:02:50 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/14 11:29:15 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* a funciton to check if stack empty or not */
int	is_empty(t_stack *stack)
{
	return (stack->top == NULL && stack->bottom == NULL);
}
