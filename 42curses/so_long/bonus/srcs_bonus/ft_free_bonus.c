/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:56:33 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:47:00 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	ft_free(t_program *game, char *msg)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	free(game->map.enemy);
	mlx_destroy_window(game->mlx, game->win_ptr);
	if (ft_strcmp(msg, "BRAVO!") == 0)
		printf("\n%s%s%s\n", GREEN,
			"⊱ ──────────────── {.⋅ ✯ BRAVO! ✯ ⋅.} ───────────────── ⊰", END);
	else
		printf("\n%s%s%s\n", RED, msg, END);
	exit(EXIT_SUCCESS);
}
