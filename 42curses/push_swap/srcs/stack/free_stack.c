/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:01:14 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/19 23:28:07 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* free_stack: a function to free everything before exiting */
void	free_stack(t_stack *stack)
{
	while (!is_empty(stack))
		pop_elem(stack);
	free(stack);
}
