/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 10:09:20 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:16:25 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_program *game)
{
	ft_free(game, "WINDOW CLOSED!");
	return (0);
}

void	ft_new_window(t_program *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->map.col * SQUARE,
			game->map.row * SQUARE, "so_long");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
}
