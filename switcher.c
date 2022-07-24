/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:12:27 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/24 21:32:17 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switcher(int keycode, t_fract *t)
{
	if (keycode == 46)
	{
		init_env(t, "Mandelbrot");
		draw_set(t);
	}
	if (keycode == 38)
	{
		init_env(t, "Julia");
		draw_set(t);
	}
	if (keycode == 11)
	{
		init_env(t, "BurningShip");
		draw_set(t);
	}
}
