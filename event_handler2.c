/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:27:17 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/19 01:57:33 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void		destroy_exit(fract_t *t)
{
	mlx_destroy_image(t->ptr, t->image);
	mlx_destroy_window(t->ptr, t->win);
}