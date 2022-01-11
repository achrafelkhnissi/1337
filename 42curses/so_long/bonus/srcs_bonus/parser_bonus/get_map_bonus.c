/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:43:37 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 17:43:38 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	get_map(char *file_name, t_program *game)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("%sso_long: %s: No such file or directory.%s\n",
			RED, file_name, END);
		exit(EXIT_FAILURE);
	}
	game->map.row = map_len(fd);
	close(fd);
	game->map.map = malloc(sizeof(char *) * (game->map.row + 1));
	if (!game->map.map)
	{
		printf("%s%s%s\n", RED, MALLOC_ERROR, END);
		exit(EXIT_FAILURE);
	}
	game->map.map[game->map.row] = 0;
	fd = open(file_name, O_RDONLY);
	while (i < game->map.row)
		game->map.map[i++] = get_next_line(fd);
	close(fd);
}
