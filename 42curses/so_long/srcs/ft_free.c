/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:17:48 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:05:37 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_program *game, char *msg)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	mlx_destroy_window(game->mlx, game->win_ptr);
	if (ft_strcmp(msg, "BRAVO!") == 0)
		printf("\n%s%s%s\n", GREEN,
			"⊱ ──────────────── {.⋅ ✯ BRAVO! ✯ ⋅.} ───────────────── ⊰", END);
	else
		printf("\n%s%s%s\n", RED, msg, END);
	exit(EXIT_SUCCESS);
}
