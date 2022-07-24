/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:42:19 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/24 20:40:09 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_ho(t_fract *t)
{
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	mlx_hook(t->win, 4, 1, mouse_press, t);
	mlx_hook(t->win, 6, 1, mouse_move, t);
	mlx_hook(t->win, 2, 1, key_handler, t);
	mlx_loop(t->ptr);
}
