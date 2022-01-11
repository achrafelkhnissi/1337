/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:11:12 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 18:41:27 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
