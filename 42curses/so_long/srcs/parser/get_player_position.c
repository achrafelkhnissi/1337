/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:09:26 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/08 14:23:09 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
