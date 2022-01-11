/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:57:09 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 16:43:33 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	ft_input(int key, void *param)
{
	t_program	*game;

	game = (t_program *)param;
	if (key == ESC_KEY)
		ft_free(game, "QUITTING THE GAME!.");
	else if (key == UP_KEY)
		move_up(game);
	else if (key == DOWN_KEY)
		move_down(game);
	else if (key == RIGHT_KEY)
		move_right(game);
	else if (key == LEFT_KEY)
		move_left(game);
	enemy_moves(game);
	mlx_clear_window(game->mlx, game->win_ptr);
	ft_render_images(game);
	return (0);
}
