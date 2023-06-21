/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:33:13 by wwatik            #+#    #+#             */
/*   Updated: 2023/06/19 20:52:38 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define WIDTH 600
# define HEIGHT 600
# define ITERA 50

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	max;
	double	min;
	double	c_re;
	double	c_im;
	int		data;
}	t_data;

void	mandelbrot(t_data *img);
int		mandelbrot_iter(t_data *va, double a, double b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		julia_iter(t_data *va, double a, double b);
void	julia(t_data *img);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_arg(t_data *img, int argc, char *argv[]);
int		ft_function(int keycode, t_data *var);
int		mouse_hook(int code, int x, int y, t_data *var);
int		ft_close(t_data *var);
int		get_color(int i);

#endif
