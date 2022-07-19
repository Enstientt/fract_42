/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:21:10 by zessadqu          #+#    #+#             */
/*   Updated: 2022/07/19 00:48:14 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_set(fract_t *t)
{
	if (ft_strcmp("Mandelbrot", t->set) == 0)
		mandelbrot(t);
	else if (ft_strcmp("Julia", t->set) == 0)
		julia(t);
	else if (ft_strcmp("BurningShip", t->set) == 0)
		burn_ship(t);
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tMandelbrot\tBurningship\tJulia\n", 30);
	}
}

void	init_env(fract_t *t, char *str)
{
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
int			main(int ac, char *av[])
{
	fract_t		t;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1]
		, "Burningship") == 0 || ft_strcmp(av[1], "julia") == 0)
		{
			t.ptr = mlx_init();
			t.win = mlx_new_window(t.ptr, WIDTH, HIGHT, "Fractol");
			t.image = mlx_new_image(t.ptr, WIDTH, HIGHT);
			t.chr = (unsigned char*)mlx_get_data_addr(t.image, &t.bpp
			, &t.size_l, &t.endian);
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