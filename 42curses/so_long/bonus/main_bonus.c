/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:54:58 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 17:00:16 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_program	game;

	if (ac != 2)
		exit(EXIT_FAILURE);
	display_banner();
	reset_struct(&game);
	check_map(av[1], &game);
	game.mlx = mlx_init();
	ft_new_window(&game);
	mlx_loop_hook(game.mlx, ft_render_images, &game);
	mlx_hook(game.win_ptr, 2, 0, *ft_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
