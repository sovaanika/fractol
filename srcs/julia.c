/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:49:28 by bbear             #+#    #+#             */
/*   Updated: 2019/03/30 17:12:58 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(t_fract *f)
{
	int		i;

	f->buff = (f->x - f->wid * 0.5) / (0.45 * f->wid * f->zoom) + f->movex;
	while (f->y < f->y_max)
	{
		f->frac.newre = f->buff;
		f->frac.newim = (f->y - f->hei * 0.5) / (0.45 * f->hei * f->zoom) + f->movey;
		i = -1;
		while (++i < f->maxiter)
		{
			f->frac.oldre = f->frac.newre;
			f->frac.oldim = f->frac.newim;
			f->frac.newre = (f->frac.oldre * f->frac.oldre - f->frac.oldim * f->frac.oldim + f->frac.cre);
			f->frac.newim = (2 * f->frac.oldre * f->frac.oldim + f->frac.cim);
			if (f->frac.newre * f->frac.newre + f->frac.newim * f->frac.newim > 4)
				break;
		}
		//n = (double)i - log(log(f->frac.newre * f->frac.newre - f->frac.newim * f->frac.newim) / log(1024)) / log(2);
		//i = abs((int)n);
		f->data[f->x + f->y * f->wid] = (i * 5) % 255 * 256 * 256 + (i * 4) % 255 * 256 + (i * 7) % 255;
		f->y++;
	}
}

void	*fract_alg(void *fra)
{
	t_fract	*f;
	int		buff;
	//int		x;
	//int		y;
	//double	n;

	f = (t_fract *)fra;
	f->x = -1;
	buff = f->y;
	while (++f->x < f->wid)
	{
		f->y = buff;
		if (!ft_strcmp(f->arg, "julia"))
			julia(f);
		else if (!ft_strcmp(f->arg, "mandelbrot"))
			mandelbrot(f);
		else if (!ft_strcmp(f->arg, "burningship"))
			burningship(f);
		else if (!ft_strcmp(f->arg, "trimandelbrot"))
			trimandelbrot(f);
		else if (!ft_strcmp(f->arg, "biomorph"))
			biomorph(f);
	}
	return (fra);
}

void	fract(t_fract *f)
{
	int			i;
	pthread_t	t[THREAD];
	t_fract		fr[THREAD];

	i = -1;
	while (++i < THREAD)
	{
		ft_memcpy((void*)&fr[i], (void*)f, sizeof(t_fract));
		fr[i].y = THREAD_W * i;
		fr[i].y_max = THREAD_W * (i + 1);
		pthread_create(&t[i], NULL, fract_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	//mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 20, 16777215,
	//ft_itoa(f->maxiter));
	//mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 35, 16777215,
	//ft_itoa(f->zoom));
}