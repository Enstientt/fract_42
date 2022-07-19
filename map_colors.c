/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:14:48 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/19 12:29:46 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map(fract_t *t)
{
	t->x = t->x_real / (WIDTH / (t->end_x - t->start_x)) + t->start_x;
	t->y = t->y_real / (HIGHT / (t->end_y - t->start_y)) + t->start_y;
	t->x_zero = t->x;
	t->y_zero = t->y;
}

void	set_color(fract_t *t, int color)
{
	t->index = (4 * HIGHT * t->y_real) + t->x_real * 4;
	t->chr[t->index] = (t->iter * t->color + 680 + 179) * color;
	t->chr[t->index + 1] = (t->iter * t->color + 42 + 84) * color;
	t->chr[t->index + 2] = (t->iter * t->color + 936 + 45) * color;
	t->chr[t->index + 3] = 0;
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] -(unsigned char)s2[i]);
}

void		map_julia(fract_t *t)
{
	t->x = ((t->x_real / (double)WIDTH) *
	(t->end_x - t->start_x)) + t->start_x;
	t->y = ((t->y_real / (double)HIGHT) *
	(t->end_y - t->start_y)) + t->start_y;
}