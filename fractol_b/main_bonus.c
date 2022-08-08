/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:21:10 by zessadqu          #+#    #+#             */
/*   Updated: 2022/08/01 11:38:59 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	usage_message(void)
{
	ft_putstr_fd(
		"usage: ./fractol_bon <set name> | m  b  j\n", 1);
	ft_putstr_fd(
		"features : m , j and b (new set) buttons ", 1);
	ft_putstr_fd("to switch from a set to an another \n", 1);
	ft_putstr_fd(" \tarrows to navigate through the set\n", 1);
	ft_putstr_fd(" \tmouse while to zoom in and out\n", 1);
	ft_putstr_fd(" \t + and - to add or substract max iteration\n", 1);
	ft_putstr_fd(" \ti to return to the initial form of set\n", 1);
	ft_putstr_fd(" \t space button to stop Julia set\n", 1);
	ft_putstr_fd(" \tc button to switch colors\n", 1);
}

void	draw_set(t_fract *t)
{
	if (ft_strcmp(t->set, "j") == 0)
		julia(t);
	else if (ft_strcmp(t->set, "m") == 0)
		mandelbrot(t);
	else if (ft_strcmp("b", t->set) == 0)
		mandelbrot(t);
	else
		ft_putstr_fd(
			"usage: ./fractol <set name> | m  b  j\n", 1);
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
	t->color = 10;
	t->set = str;
}

int	main(int ac, char *av[])
{
	t_fract		t;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "m") == 0
			|| ft_strcmp(av[1], "b") == 0
			|| ft_strcmp(av[1], "j") == 0)
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
		usage_message();
	return (0);
}
