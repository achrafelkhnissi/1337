/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:47:25 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/11 08:36:14 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	in_set(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "X10CEP";
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_characters(t_program game)
{
	int	row;
	int	col;

	row = 0;
	while (game.map.map[row] != NULL)
	{
		col = 0;
		while (game.map.map[row][col] != '\n' && game.map.map[row][col] != '\0')
		{
			if (!in_set(game.map.map[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
