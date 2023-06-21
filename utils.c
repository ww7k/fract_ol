/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:33:33 by wwatik            #+#    #+#             */
/*   Updated: 2023/06/19 21:19:21 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	ft_close(t_data *var)
{
	mlx_destroy_image(var->mlx, var->img);
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit(0);
}

int	ft_function(int keycode, t_data *var)
{
	if (keycode == 53)
		ft_close(var);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_data *var)
{
	if (code == 4)
		var->zoom *= 1.5;
	if (code == 5)
		var->zoom /= 1.5;
	if (code == 1)
	{
		var->c_re = ((((var->max - var->min) * x) / WIDTH) + var->min);
		var->c_im = (((-(var->max - var->min) * y) / HEIGHT) + var->max);
	}
	if (var->data == 1)
		mandelbrot(var);
	if (var->data == 2)
		julia(var);
	return (0);
}

int	get_color(int i)
{
	int	color;

	if (i == ITERA)
		return (0);
	color = i * (0x00FFFF / ITERA);
	return (color);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
