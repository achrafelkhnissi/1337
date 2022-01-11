/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:57:27 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:17:54 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	ft_close(t_program *game)
{
	ft_free(game, "WINDOW CLOSED");
	return (0);
}

void	ft_new_window(t_program *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->map.col * SQUARE,
			(game->map.row + 1) * SQUARE, "so_long");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
}
