/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:44:17 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:43:02 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	err_extention(char *file_name)
{
	printf("%sso_long: %s: Invalid file extention.%s\n",
		RED, file_name, END);
	exit(EXIT_FAILURE);
}

void	err_rectangular(t_program *game, char *file_name)
{
	printf("%sso_long: %s: Map isn't rectangualr!.%s\n", RED,
		file_name, END);
	free_map(game);
}

void	err_characters(t_program *game, char *file_name)
{
	printf("%sso_long: %s: Invalid character found!.%s\n",
		RED, file_name, END);
	free_map(game);
}

void	err_walls(t_program *game, char *file_name)
{
	printf("%sso_long: %s: Invalid walls!.%s\n", RED, file_name, END);
	free_map(game);
}

void	err_ecp(t_program *game, char *file_name)
{
	printf("%sso_long: %s: Player or Exit or Collectible not Found!!.%s\n",
		RED, file_name, END);
	free_map(game);
}
