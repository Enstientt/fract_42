/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:07:24 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/24 19:31:50 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_loop_mandelbrot(t_fract *t)
{
	while (t->iter < t->max)
	{
		t->xtmp = t->x * t->x - t->y * t->y;
		t->ytmp = 2 * t->x * t->y;
		t->x = t->xtmp + t->x_zero;
		t->y = t->ytmp + t->y_zero;
		if (t->x * t->x + t->y * t->y > 4)
			break ;
		t->iter++;
	}
}

void	iter_loop_bsh(t_fract *t)
{
	while (t->iter < t->max)
	{
		t->xtmp = t->x * t->x - t->y * t->y;
		t->ytmp = fabs(2 * t->x * t->y);
		t->x = t->xtmp + t->x_zero;
		t->y = t->ytmp + t->y_zero;
		if (t->x * t->x + t->y * t->y > 4)
			break ;
		t->iter++;
	}
}

void	looping(t_fract *t)
{
	if (ft_strcmp(t->set, "Mandelbrot") == 0 || ft_strcmp(t->set, "Julia") == 0)
		iter_loop_mandelbrot(t);
	if (ft_strcmp(t->set, "BurningShip") == 0)
		iter_loop_bsh(t);
}
