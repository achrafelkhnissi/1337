/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:53:48 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 17:04:06 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	reset_struct(t_program *game)
{
	game->mlx = NULL;
	game->win_ptr = NULL;
	game->img_ptr = NULL;
	game->img_size = 0;
	game->fd = 0;
	game->can_exit = 0;
	game->mv_count = 0;
	game->map.map = NULL;
	game->map.col = 0;
	game->map.row = 0;
	game->map.collectibles = 0;
	game->map.number_of_enemies = 0;
	game->map.player.y = 0;
	game->map.player.x = 0;
	game->map.enemy = NULL;
}
