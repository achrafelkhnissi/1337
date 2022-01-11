/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:56:22 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:01:04 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	count_number_of_enemies(t_program *game)
{
	int	x;
	int	y;

	x = 0;
	game->map.number_of_enemies = 0;
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (game->map.map[x][y] == ENEMY)
				game->map.number_of_enemies++;
			y++;
		}
		x++;
	}
}

void	get_enemies_positions(t_program *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	game->map.enemy = malloc(sizeof(t_vector) * game->map.number_of_enemies);
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (game->map.map[x][y] == ENEMY)
			{
				game->map.enemy[i].x = x;
				game->map.enemy[i].y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

static void	enemy_moves_action(t_program *game, int i, int x, int y)
{
	if (game->map.map[x - 1][y] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].x - 1][game->map.enemy[i].y],
			&game->map.map[game->map.enemy[i].x][game->map.enemy[i].y]);
		game->map.enemy[i].x--;
	}
	else if (game->map.map[x + 1][y] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].x + 1][game->map.enemy[i].y],
			&game->map.map[game->map.enemy[i].x][game->map.enemy[i].y]);
		game->map.enemy[i].x++;
	}
	else if (game->map.map[x][y - 1] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].x][game->map.enemy[i].y - 1],
			&game->map.map[game->map.enemy[i].x][game->map.enemy[i].y]);
		game->map.enemy[i].y--;
	}
	else if (game->map.map[x][y + 1] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].x][game->map.enemy[i].y + 1],
			&game->map.map[game->map.enemy[i].x][game->map.enemy[i].y]);
		game->map.enemy[i].y++;
	}
}

void	enemy_moves(t_program *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < game->map.number_of_enemies)
	{
		x = game->map.enemy[i].x;
		y = game->map.enemy[i].y;
		enemy_moves_action(game, i, x, y);
		i++;
	}
}
