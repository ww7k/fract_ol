/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:33:06 by wwatik            #+#    #+#             */
/*   Updated: 2023/06/19 21:32:34 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *var, int x, int y, int color)
{
	char	*dst;

	dst = var->addr + (y * var->line_length + x * (var->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_data(t_data *img)
{
	img->c_re = -0.8;
	img->c_im = 0.156;
	img->zoom = 1;
	img->min = -2;
	img->max = 2;
	img->data = 0;
}

void	ft_arg(t_data *img, int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "choose between mandelbrot or julia", 34);
		exit(0);
	}
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		mandelbrot(img);
		img->data = 1;
	}
	else if (!ft_strcmp(argv[1], "julia"))
	{
		julia(img);
		img->data = 2;
	}
	else
	{
		write(1, "choose between mandelbrot or julia", 34);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_data	img;

	ft_init_data(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "fractol");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	ft_arg(&img, argc, argv);
	mlx_hook(img.mlx_win, 17, 0, ft_close, &img);
	mlx_key_hook(img.mlx_win, ft_function, &img);
	mlx_mouse_hook(img.mlx_win, mouse_hook, &img);
	mlx_loop(img.mlx);
}
