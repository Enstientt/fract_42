/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:21:10 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/24 19:58:41 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_set(t_fract *t)
{
	if (ft_strcmp(t->set, "Julia") == 0)
		julia(t);
	else if (ft_strcmp(t->set, "Mandelbrot") == 0)
		mandelbrot(t);
	else if (ft_strcmp("BurningShip", t->set) == 0)
		mandelbrot(t);
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tMandelbrot\tBurningship\tJulia\n", 30);
	}
}

void	init_env(t_fract *t, char *str)
{
	t->zoom_coff = 0.040;
	t->start_x = -2;
	t->end_x = 2;
	t->start_y = -2;
	t->end_y = 2;
	t->x_zero = -0.4;
	t->y_zero = 0.6;
	t->zoom = 0;
	t->stop = 0;
	t->max = 40;
	t->color = 20;
	t->set = str;
}

int	main(int ac, char *av[])
{
	t_fract		t;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0
			|| ft_strcmp(av[1], "BurningShip") == 0
			|| ft_strcmp(av[1], "Julia") == 0)
		{
			t.ptr = mlx_init();
			t.win = mlx_new_window(t.ptr, WIDTH, HIGHT, "Fractol");
			t.image = mlx_new_image(t.ptr, WIDTH, HIGHT);
			t.chr = (unsigned char *)mlx_get_data_addr(t.image, &t.bpp,
					&t.size_l, &t.endian);
		}
		init_env(&t, av[1]);
		draw_set(&t);
	}
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tMandelbrot\tBurningship\tJulia\n", 30);
	}
	return (0);
}
