/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obs_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:42:38 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:42:40 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

int	ft_obs_count(void)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y <= g_board.y)
	{
		x = 0;
		while (x < g_board.x)
		{
			if (g_board.bd[y][x] == g_chars[1])
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
