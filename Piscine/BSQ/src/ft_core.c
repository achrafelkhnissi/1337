/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:40:36 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:46:13 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

int	ft_core(void)
{
	g_current_square.l = ft_min(g_x, g_y);
	g_current_square.x = 0;
	g_current_square.y = 1;
	while (g_current_square.l > 0)
	{
		while (g_current_square.y + g_current_square.l <= g_y + 1)
		{
			g_current_square.x = 0;
			while (g_current_square.x + g_current_square.l <= g_x)
			{
				if (ft_square_valid(g_current_square))
					return (1);
				(g_current_square.x)++;
			}
			(g_current_square.y)++;
		}
		(g_current_square.l)--;
		(g_current_square.x) = 0;
		(g_current_square.y) = 1;
	}
	return (0);
}
