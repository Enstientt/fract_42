/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:52:46 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/31 14:19:59 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia(t_fract *t)
{
	t->y_real = 0;
	while (t->y_real < WIDTH)
	{
		t->x_real = 0;
		while (t->x_real < HIGHT)
		{
			t->iter = 0;
			map_julia(t);
			looping(t);
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

void	mandelbrot(t_fract *t)
{
	t->y_real = 0;
	while (t->y_real < HIGHT)
	{
		t->x_real = 0;
		while (t->x_real < WIDTH)
		{
			t->iter = 0;
			map(t);
			looping(t);
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
