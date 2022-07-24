/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:21:15 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/24 19:53:10 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	arrow_handler(int keycode, t_fract *t);

static void	iter_handler(int keycode, t_fract *t);

static void	color_handler(t_fract *t);

static void	exit_handler(t_fract *t);

int	key_handler(int keycode, t_fract *t)
{
	if (keycode >= 123 && keycode <= 126)
		arrow_handler(keycode, t);
	if (keycode == 53)
		exit_handler(t);
	if (keycode == 69 || keycode == 78)
		iter_handler(keycode, t);
	if (keycode == 8)
		color_handler(t);
	if (keycode == 49)
		t->stop = 1;
	return (1);
}

static void	arrow_handler(int keycode, t_fract *t)
{
	if (keycode == 124)
	{
		t->start_x = t->start_x - t->zoom_coff;
		t->end_x = t->end_x - t->zoom_coff;
		draw_set(t);
	}
	else if (keycode == 125)
	{
		t->start_y = t->start_y - t->zoom_coff;
		t->end_y = t->end_y - t->zoom_coff;
		draw_set(t);
	}
	else if (keycode == 126)
	{
		t->start_y = t->start_y + t->zoom_coff;
		t->end_y = t->end_y + t->zoom_coff;
		draw_set(t);
	}
	if (keycode == 123)
	{
		t->start_x = t->start_x + t->zoom_coff;
		t->end_x = t->end_x + t->zoom_coff;
		draw_set(t);
	}
}

static void	exit_handler(t_fract *t)
{
	mlx_destroy_image(t->ptr, t->image);
	mlx_destroy_window(t->ptr, t->win);
	exit(0);
}

static void	iter_handler(int keycode, t_fract *t)
{
	if (keycode == 69)
		t->max += 8;
	if (keycode == 78)
		t->max -= 8;
	draw_set(t);
}

static void	color_handler(t_fract *t)
{
	t->color += 1000;
	draw_set(t);
}
