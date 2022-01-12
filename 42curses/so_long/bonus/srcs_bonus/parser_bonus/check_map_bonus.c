/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:06:29 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/12 09:20:33 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	check_map(char *file_name, t_program *game)
{
	check_dir(file_name);
	if (check_extention(file_name, ".ber") != 0)
		err_extention(file_name);
	get_map(file_name, game);
	if (check_rectangular(*game) == 1)
		err_rectangular(game, file_name);
	if (check_characters(*game) == 0)
		err_characters(game, file_name);
	if (check_player(*game) == 0)
		err_player(game, file_name);
	if (check_walls(game) != 0)
		err_walls(game, file_name);
	if (check_ecp(*game) == 0)
		err_ecp(game, file_name);
	get_collectibles(game);
	get_player_position(game);
	count_number_of_enemies(game);
	get_enemies_positions(game);
}
