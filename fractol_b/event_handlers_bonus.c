/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:27:04 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/31 14:19:53 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_move(int x, int y, t_fract *t)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < WIDTH && t->stop == 0
		&& ft_strcmp(t->set, "j") == 0)
	{
		t->x_zero = (((double)x / WIDTH) * 4) - 2;
		t->y_zero = (((double)y / HIGHT) * 4) - 2;
		draw_set(t);
	}
	return (1);
}

int	mouse_press(int button, int x, int y, t_fract *t)
{
	if (button == 5 && t->stop == 1)
	{
		zoom(t, (double)x, (double)y, 1.1);
		t->zoom_coff *= 1.101;
	}
	else if (button == 4 && t->stop == 1)
	{
		zoom(t, (double)x, (double)y, 0.9);
		t->zoom_coff /= 1.101;
	}
	draw_set(t);
	return (1);
}

void	zoom(t_fract *t, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
	yy = ((y / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
	t->start_x = xx + ((t->start_x - xx) * zoom);
	t->start_y = yy + ((t->start_y - yy) * zoom);
	t->end_y = yy + ((t->end_y - yy) * zoom);
	t->end_x = xx + ((t->end_x - xx) * zoom);
	if (t->max <= 120)
		t->max += 2;
}

int	quiet(t_fract *t)
{
	exit_handler(t);
	return (0);
}
