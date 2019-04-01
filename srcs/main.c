/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:31:18 by bbear             #+#    #+#             */
/*   Updated: 2019/04/01 20:32:40 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	if (f->flag == 0)
	{
		f->frac.cre = (x - 0.5 * f->wid) * 0.0015;
		f->frac.cim = (y - 0.5 * f->hei) * 0.0015;
		draw(f);
	}
	return (0);
}

void	init(t_fract *f)
{
	f->wid = 1200;
	f->hei = 1200;
	f->frac.cre = 0;
	f->frac.cim = 0;
	f->x = 0;
	f->y = 0;
	f->thread = 120;
	f->zoom = 1;
	f->flag = 0;
	f->movex = 0;
	f->movey = 0;
	colorinit(f);
	f->win_ptr = mlx_new_window(f->mlx_ptr, f->wid, f->hei, "fractol");
	f->img_ptr = mlx_new_image(f->mlx_ptr, f->wid, f->hei);
	f->data = (int *)mlx_get_data_addr(f->img_ptr, &f->bpp,
	&f->size_l, &f->end);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	if (button == 1)
	{
		if (f->flag == 0)
			f->flag++;
		else
			f->flag--;
	}
	if (button == 4)
	{
		zoom(x, y, f, 1.1);
		draw(f);
	}
	else if (button == 5)
	{
		zoom(x, y, f, 0.9);
		draw(f);
	}
	return (0);
}

int		checkargs(int i, char *str)
{
	if (i == 0)
		return (ft_strcmp(str, "mandelbrot"));
	else if (i == 1)
		return (ft_strcmp(str, "julia"));
	else if (i == 2)
		return (ft_strcmp(str, "trimandelbrot"));
	else if (i == 3)
		return (ft_strcmp(str, "biomorph"));
	return (ft_strcmp(str, "burningship"));
}

int		main(int argc, char **argv)
{
	t_fract	*f;
	int		arg[5];
	int		i;

	if (argc > 1)
	{
		i = -1;
		while (++i < 5)
			arg[i] = checkargs(i, argv[1]);
		if (!arg[0] || !arg[1] || !arg[2] || !arg[3] || !arg[4])
		{
			f = (t_fract *)malloc(sizeof(*f));
			f->mlx_ptr = mlx_init();
			f->maxiter = 40;
			f->arg = argv[1];
			init(f);
			draw(f);
			mlx_hook(f->win_ptr, 6, 0, mouse_move, (void *)f);
			mlx_key_hook(f->win_ptr, key_press, (void *)f);
			mlx_hook(f->win_ptr, 17, 0, ft_close, (void *)0);
			mlx_mouse_hook(f->win_ptr, mouse_press, (void *)f);
			mlx_loop(f->mlx_ptr);
		}
	}
}
