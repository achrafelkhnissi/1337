/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:52:42 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:13:41 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_get_image(char c, int can_exit)
{
	char	*output;

	(void)can_exit;
	output = NULL;
	if (c == WALL)
		output = "sprites/wall.xpm";
	else if (c == PLAYER)
		output = "sprites/player.xpm";
	else if (c == COL)
		output = "sprites/col.xpm";
	else if (c == ENEMY)
		output = "sprites/enemy.xpm";
	else if (c == EXIT)
	{
		if (can_exit)
			output = "sprites/exit_open.xpm";
		else
			output = "sprites/exit_closed.xpm";
	}
	return (output);
}

void	render_images_action(t_program game, int x, int y)
{
	char	*img_path;

	if (game.map.collectibles == 0)
		game.can_exit = 1;
	img_path = ft_get_image(game.map.map[x][y], game.can_exit);
	if (img_path)
	{
		game.img_ptr = mlx_xpm_file_to_image(game.mlx, img_path,
				&game.img_size, &game.img_size);
		mlx_put_image_to_window(game.mlx, game.win_ptr, game.img_ptr,
			y * SQUARE, x * SQUARE);
		mlx_destroy_image(game.mlx, game.img_ptr);
	}
}

void	ft_render_images(t_program game)
{
	int		x;
	int		y;

	x = 0;
	game.img_size = SQUARE;
	while (game.map.map[x])
	{
		y = 0;
		while (game.map.map[x][y] != '\n' && game.map.map[x][y])
		{
			render_images_action(game, x, y);
			y++;
		}
		x++;
	}
}
