/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:12:39 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/19 12:40:17 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
#	define FRACTOL_H

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#	define WIDTH 600
#	define HIGHT 600

typedef struct		fract_s
{
	double			x;
	double			y;
	double			x_real;
	double			y_real;
	double			start_y;
	double			end_y;
	double			start_x;
	double			end_x;
	double			x_zero;
	double			y_zero;
	double			xtmp;
	double			ytmp;
	int				iter;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	int				zoom;
	int				stop;
	int				color;
	int				max;
	void			*ptr;
	void			*win;
	void			*image;
	char			*set;
	unsigned char	*chr;

}   fract_t;

void    mandelbrot(fract_t *t);
void	julia(fract_t *t);
void	burn_ship(fract_t *t);
void	init_env(fract_t *t, char *str);
void	draw_set(fract_t *t);
void	iter_loop_mandelbrot(fract_t *t);
void	iter_loop_bsh(fract_t *t);
void	set_color(fract_t *t, int color);
void	map(fract_t *t);
int		ft_strcmp(const char *s1, const char *s2);
int		mouse_move(int x, int y, fract_t *t);
int		mouse_press(int btn, int x, int y, fract_t *t);
void	zoom(fract_t *t, double x, double y, double zoom);
void	mlx_ho(fract_t *t);
void	map_julia(fract_t *t);

#    endif