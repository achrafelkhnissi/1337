/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:41:00 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:46:21 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

void	ft_reset_g_values(void)
{
	if (g_obstacles)
		free(g_obstacles);
	if (g_board.bd)
		free(g_board.bd);
}

void	ft_init_g_values(char **map)
{
	g_board.bd = map;
	g_board.x = g_x;
	g_board.y = g_y;
	g_board.obs_count = ft_obs_count();
	g_obstacles = ft_get_obstacles();
}
