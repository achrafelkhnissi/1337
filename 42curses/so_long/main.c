/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:19:40 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/15 16:08:54 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, void *param)
{
	(void)param;
	printf("Key: %d\n", key);
	//you can put your code here ex: mlx_pixel_put..
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img_ptr;

	mlx_ptr = mlx_init(); 
	/* mlx_init is a function that will establish a connection to the correct
	 * graphical sysytem and will return a void* which holds the locaiton of
	 * our current MLX instance. */

	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "M7Y7");
	/*
	 * mlx_new_window is a function that will return a pointer to the window
	 * we have just created. We can give the window height, width and a titile.
	 * We then will have to call mlx_loop to initiate the window rendering.*/

	img_ptr.img = mlx_new_image(mlx_ptr, 400, 400); /* Check the note on mlx_pixel_put */
	/* After creating an image, we can call 'mlx_get_data_addr', we pass
	 * 'bits_per_pixel', 'line_length', and 'endian' by reference. The will
	 * then be set accordingly for the *current* data address */

	img_ptr.addr = mlx_get_data_addr(img_ptr.img, &img_ptr.bits_per_pixel,
		&img_ptr.line_length, &img_ptr.endian);

	my_mlx_pixel_put(&img_ptr, 50, 50, 0x00FF0000);

	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr.img, 50, 50);
	
	/*
	mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF);
	// Note that the mlx_pixel_put function is very, very slow. This is
	 * because it tires to push the pixel instantly to the window (without
	 * waiting for the frame to be entirely rendered). Because of this sole
	 * reason, we will have to buffer all of our pizels to a image, which we
	 * will then push to the window. //
	*/

	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
