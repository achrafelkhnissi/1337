/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:10:06 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/07 14:17:35 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
