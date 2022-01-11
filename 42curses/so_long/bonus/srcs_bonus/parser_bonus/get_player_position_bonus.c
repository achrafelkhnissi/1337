/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:43:44 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 17:43:49 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	get_player_position(t_program *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map.map[row])
	{
		col = 0;
		while (game->map.map[row][col])
		{
			if (game->map.map[row][col] == 'P')
			{
				game->map.player.x = row;
				game->map.player.y = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
