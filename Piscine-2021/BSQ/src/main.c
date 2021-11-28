/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:43:56 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 18:25:17 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

int	main(int ac, char **av)
{
	int		i;

	if (ac == 1)
		ft_handle_stdin();
	i = 1;
	while (i < ac)
	{
		ft_handle_file(av[i]);
		if (i++ != ac - 1)
			ft_putchar('\n');
	}
	return (0);
}
