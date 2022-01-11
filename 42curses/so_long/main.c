/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:36:04 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/08 13:37:56 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_program	game;

	if (ac != 2)
		exit(EXIT_FAILURE);
	display_banner();
	check_map(av[1], &game);
	game.mlx = mlx_init();
	ft_new_window(&game);
	ft_render_images(game);
	mlx_hook(game.win_ptr, 2, 0, *ft_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
