/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:57:17 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/11 08:51:31 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static char	*ft_get_enemy_sprite(void)
{
	static int	i;
	char		*output;

	output = NULL;
	if (++i <= FRAME)
		output = "sprites_bonus/enemy-1.xpm";
	else if (i > FRAME && i <= FRAME * 2)
		output = "sprites_bonus/enemy-2.xpm";
	else
	{
		output = "sprites_bonus/enemy-2.xpm";
		i = 0;
	}
	return (output);
}

char	*ft_get_image(char c, int can_exit)
{
	char	*output;

	output = NULL;
	if (c == WALL)
		output = "sprites_bonus/wall.xpm";
	else if (c == PLAYER)
		output = "sprites_bonus/player.xpm";
	else if (c == COL)
		output = "sprites_bonus/col.xpm";
	else if (c == ENEMY)
		output = ft_get_enemy_sprite();
	else if (c == EXIT)
	{
		if (can_exit)
			output = "sprites_bonus/exit_open.xpm";
		else
			output = "sprites_bonus/exit_closed.xpm";
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

static void	put_str_to_window(t_program *game)
{
	char		*num;
	char		*str;

	num = ft_itoa(game->mv_count);
	str = ft_strjoin("MOVES: ", num);
	mlx_string_put(game->mlx, game->win_ptr,
		(((game->map.col - 1) * SQUARE) / 2) - SQUARE, game->map.row * SQUARE,
		0xff0000, str);
	free(num);
	free(str);
}

int	ft_render_images(void *param)
{
	t_program	*game;
	int			x;
	int			y;

	game = (t_program *)param;
	x = 0;
	game->img_size = SQUARE;
	mlx_clear_window(game->mlx, game->win_ptr);
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y] != '\n' && game->map.map[x][y])
		{
			render_images_action(*game, x, y);
			y++;
		}
		x++;
	}
	put_str_to_window(game);
	return (0);
}
