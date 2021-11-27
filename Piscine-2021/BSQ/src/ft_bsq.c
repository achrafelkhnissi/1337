/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:40:25 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:46:06 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

void	ft_bsq(char **map)
{
	ft_extract(map[0]);
	if (g_y != 0 && ft_map_valid(map))
	{
		ft_init_g_values(map);
		if (ft_core())
		{
			ft_highlight_biggest_square();
			ft_show_board();
		}
		else
		{
			ft_puterr("no valid square :( try another map!\n");
			return ;
		}
	}
	else
		ft_puterr("map error\n");
}
