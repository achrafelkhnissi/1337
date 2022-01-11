/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ECP.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:09:15 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/08 11:16:51 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_ecp(t_program game)
{
	int	e;
	int	c;
	int	p;
	int	i;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (game.map.map[i])
	{
		if (ft_strchr(game.map.map[i], 'E') == 1)
			e = 1;
		if (ft_strchr(game.map.map[i], 'C') == 1)
			c = 1;
		if (ft_strchr(game.map.map[i], 'P') == 1)
			p = 1;
		i++;
	}
	return (e && c && p);
}
