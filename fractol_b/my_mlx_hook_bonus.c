/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:42:19 by zessadqu          #+#    #+#             */
/*   Updated: 2022/08/01 12:07:40 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_hook(t_fract *t)
{
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	mlx_hook(t->win, 4, 0, mouse_press, t);
	mlx_hook(t->win, 6, 0, mouse_move, t);
	mlx_hook(t->win, 2, 0, key_handler, t);
	mlx_hook(t->win, 17, 0, quiet, t);
	mlx_loop(t->ptr);
}
