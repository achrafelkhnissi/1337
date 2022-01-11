/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:52:27 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/08 14:04:21 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
