/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:31:18 by bbear             #+#    #+#             */
/*   Updated: 2019/03/15 20:39:02 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	if (x > fract->x)
		fract->frac.cre += 0.0025;
	else if (x < fract->x)
		fract->frac.cre -= 0.0025;
	if (y > fract->y)
		fract->frac.cim += 0.0025;
	else if (y < fract->y)
		fract->frac.cim -= 0.0025;
	fract->x = x;
	fract->y = y;
	draw(fract);
	return (0);
}

void	init(t_fract *fract)
{
	fract->wid = 1500;
	fract->hei = 1500;
	fract->frac.cre = -0.70176;
	fract->frac.cim = -0.3842;
	fract->minre = 0;
	fract->minim = 0;
	fract->maxre = fract->wid;
	fract->maxim = fract->hei;
	fract->x = 0;
	fract->y = 0;
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, fract->wid, fract->hei, "fract");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, fract->wid, fract->hei);
	fract->data = (int *)mlx_get_data_addr(fract->img_ptr, &fract->bpp,
	&fract->size_l, &fract->end);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	//if (button == 1)
	//{
		if (button == 4)
		{
			zoomin(x, y, fract);
			draw(fract);
		}

		//mlx_hook(fract->win_ptr, 4, 0, zoom, (void *)fract);
	//}
	return (0);
}

int		checkargs(int i, char *str)
{
	if (i == 0)
		return (ft_strcmp(str, "mandelbrot"));
	else if (i == 1)
		return (ft_strcmp(str, "julia"));
	return (ft_strcmp(str, "anotherfract"));
}

int		main(int argc, char **argv)
{
	t_fract	*fract;
	int		arg[3];
	int		i;

	if (argc > 1)
	{
		i = -1;
		while (++i < 3)
			arg[i] = checkargs(i, argv[1]);
		if (!arg[0] || !arg[1] || !arg[2])
		{
			fract = (t_fract *)malloc(sizeof(*fract));
			fract->mlx_ptr = mlx_init();
			fract->maxiter = 40;
			if (!arg[0])
			{
				init(fract);
				mandelbrot(fract);
				mlx_key_hook(fract->win_ptr, key_press, (void *)fract);
				mlx_hook(fract->win_ptr, 17, 0, ft_close, (void *)0);
				mlx_mouse_hook(fract->win_ptr, mouse_press, (void *)fract);
				//mlx_hook(fract->win_ptr, 4, 0, mouse_press, (void *)fract);
				//mlx_hook(fract->win_ptr, 5, 1L<<12, zoomout, (void *)fract);
				mlx_loop(fract->mlx_ptr);
			}
			else if (!arg[1])
			{
				init(fract);
				julia(fract);
				mlx_hook(fract->win_ptr, 6, 0, mouse_move, (void *)fract);
				mlx_key_hook(fract->win_ptr, key_press, (void *)fract);
				mlx_hook(fract->win_ptr, 17, 0, ft_close, (void *)0);
				mlx_loop(fract->mlx_ptr);
			}
		}
	}
}
