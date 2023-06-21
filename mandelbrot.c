/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:33:31 by wwatik            #+#    #+#             */
/*   Updated: 2023/06/19 20:21:03 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(t_data *va, double a, double b)
{
	int		i;
	double	x;
	double	y;
	double	p;

	i = 0;
	x = 0;
	y = 0;
	va->c_re = ((((va->max - va->min) * a) / WIDTH) + va->min) * va->zoom;
	va->c_im = (((-(va->max - va->min) * b) / HEIGHT) + va->max) * va->zoom;
	while (((x * x + y * y) < 4) && i < ITERA)
	{
		p = x * x - y * y + va->c_re;
		y = 2 * x * y + va->c_im;
		x = p;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *img)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			i = mandelbrot_iter(img, x, y);
			my_mlx_pixel_put(img, x, y, get_color(i));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
