/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:12:27 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/31 13:18:43 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
}
