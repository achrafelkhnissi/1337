/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:12:07 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/12 09:21:31 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	err_player(t_program *game, char *file_name)
{
	printf("%sso_long: %s: Only one player is allowed!%s\n", RED,
		file_name, END);
	free_map(game);
}

int	check_player(t_program game)
{
	int	p;
	int	i;

	i = 0;
	p = 0;
	while (game.map.map[i])
	{
		if (ft_strchr(game.map.map[i], 'P') == 1)
			p++;
		i++;
	}
	return (p == 1);
}
