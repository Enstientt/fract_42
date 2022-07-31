/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:12:27 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/31 14:20:18 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	switcher(int keycode, t_fract *t)
{
	if (keycode == 46)
	{
		init_env(t, "m");
		draw_set(t);
	}
	if (keycode == 38)
	{
		init_env(t, "j");
		draw_set(t);
	}
	if (keycode == 11)
	{
		init_env(t, "b");
		draw_set(t);
	}
}
