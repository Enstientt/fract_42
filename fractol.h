/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:12:39 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/24 19:31:34 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 700
# define HIGHT 700

typedef struct fract_s
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
	double			zoom_coff;
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

}	t_fract;

void	mandelbrot(t_fract *t);
void	julia(t_fract *t);
void	burn_ship(t_fract *t);
void	init_env(t_fract *t, char *str);
void	draw_set(t_fract *t);
void	iter_loop_mandelbrot(t_fract *t);
void	iter_loop_bsh(t_fract *t);
void	set_color(t_fract *t, int color);
void	map(t_fract *t);
void	zoom(t_fract *t, double x, double y, double zoom);
void	mlx_ho(t_fract *t);
void	map_julia(t_fract *t);
void	looping(t_fract *t);
int		ft_strcmp(char *s1, char *s2);
int		mouse_move(int x, int y, t_fract *t);
int		mouse_press(int btn, int x, int y, t_fract *t);
int		key_handler(int keycode, t_fract *t);

#endif
