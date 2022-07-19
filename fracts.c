/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:52:46 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:56 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(fract_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_real = 0;
	while (t->y_real < WIDTH)
	{
		t->x_real = 0;
		while (t->x_real < HIGHT)
		{
			t->iter = 0;
			map_julia(t);
			iter_loop_mandelbrot(t);
			if (t->iter == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_real++;
		}
		t->y_real++;
	}
	mlx_ho(t);
}

void		mandelbrot(fract_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_real = 0;
	while (t->y_real < HIGHT)
	{
		t->x_real = 0;
		while (t->x_real < WIDTH)
		{
			t->iter = 0;
			map(t);
			iter_loop_mandelbrot(t);
			if (t->iter == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_real++;
		}
		t->y_real++;
	}
	t->stop = 1;
	mlx_ho(t);
}

void		burn_ship(fract_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_real = 0;
	while (t->y_real < HIGHT)
	{
		t->x_real = 0;
		while (t->x_real < WIDTH)
		{
			t->iter = 0;
			map(t);
			iter_loop_bsh(t);
			if (t->iter == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_real++;
		}
		t->y_real++;
	}
	t->stop = 1;
	mlx_ho(t);
}

