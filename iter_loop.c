/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:07:24 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/19 01:11:43 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_loop_mandelbrot(fract_t *t)
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

void	iter_loop_bsh(fract_t *t)
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
