/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:07:09 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/20 01:11:33 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* free_stack: a function to free everything before exiting */
void	free_stack(t_stack *stack)
{
	while (!is_empty(stack))
		pop_elem(stack);
	free(stack);
}
