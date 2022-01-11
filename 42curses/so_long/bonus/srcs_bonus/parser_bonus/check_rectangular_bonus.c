/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:42:40 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 17:42:41 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	check_rectangular(t_program game)
{
	int	row;
	int	len;
	int	line_len;

	row = 0;
	line_len = ft_strlen(game.map.map[row]);
	while (game.map.map[row] != NULL)
	{
		len = ft_strlen(game.map.map[row]);
		if (line_len != len)
			return (1);
		row++;
	}
	return (0);
}
