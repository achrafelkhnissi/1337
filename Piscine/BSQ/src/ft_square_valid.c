/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:43:36 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:43:38 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

int	ft_square_valid(t_square square)
{
	int			i;

	i = 0;
	while (i < g_board.obs_count)
	{
		if ((g_obstacles[i].x >= square.x
				&& g_obstacles[i].x <= square.x + square.l - 1)
			&& (g_obstacles[i].y >= square.y
				&& g_obstacles[i].y <= square.y + square.l - 1))
			return (0);
		i++;
	}
	return (1);
}
