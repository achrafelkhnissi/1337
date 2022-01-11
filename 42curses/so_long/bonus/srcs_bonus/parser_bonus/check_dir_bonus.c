/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:42:17 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 17:42:18 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	check_dir(char	*file_name)
{
	int	fd;

	fd = open(file_name, O_DIRECTORY);
	if (fd != -1)
	{
		printf("%sso_long: %s: %s%s\n", RED, file_name, DIR_ERROR, END);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
