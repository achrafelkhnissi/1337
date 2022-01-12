/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:57:01 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/12 09:04:54 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	move_up(t_program *game)
{
	if (game->map.map[game->map.player.x - 1][game->map.player.y] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x - 1][game->map.player.y],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x--;
		printf("[%sMOVED UP%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
		game->map.player.x--;
	}
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'E'
		&& !game->map.collectibles)
		ft_free(game, "BRAVO!");
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'X')
		ft_free(game, "YOU DIED!!.. RETARD HH.");
}

void	move_down(t_program *game)
{
	if (game->map.map[game->map.player.x + 1][game->map.player.y] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x + 1][game->map.player.y],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x++;
		printf("[%sMOVED DOWN%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x + 1][game->map.player.y] = 'P';
		game->map.player.x++;
	}
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'E'
		&& !game->map.collectibles)
		ft_free(game, "BRAVO!");
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'X')
		ft_free(game, "YOU DIED!!.. RETARD HH.");
}

void	move_left(t_program *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y - 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y - 1],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y--;
		printf("[%sMOVED LEFT%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
		game->map.player.y--;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'E'
		&& !game->map.collectibles)
		ft_free(game, "BRAVO!");
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'X')
		ft_free(game, "YOU DIED!!.. RETARD HH.");
}

void	move_right(t_program *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y + 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y + 1],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y++;
		printf("[%sMOVED RIGHT%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
		game->map.player.y++;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'E'
		&& !game->map.collectibles)
		ft_free(game, "BRAVO!");
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'X')
		ft_free(game, "YOU DIED!!.. RETARD HH.");
}
