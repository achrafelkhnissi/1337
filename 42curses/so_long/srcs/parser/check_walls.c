/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:10:16 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/08 14:16:18 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_walls(t_program *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.col = ft_strlen(game->map.map[0]) - 1;
	while (i < game->map.row)
	{
		j = 0;
		while (game->map.map[i][j] != '\n' && game->map.map[i][j]
			&& j < game->map.col)
		{
			if (i == 0 || i == game->map.row - 1)
				if (game->map.map[i][j] != '1')
					return (1);
			if (j == 0 || j == game->map.col - 1)
				if (game->map.map[i][j] != '1')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}
