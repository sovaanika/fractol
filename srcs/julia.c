/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:49:28 by bbear             #+#    #+#             */
/*   Updated: 2019/04/01 20:42:49 by bbear            ###   ########.fr       */
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
		f->frac.newim = (f->y - f->hei * 0.5) / (0.45 * f->hei * f->zoom)
		+ f->movey;
		i = -1;
		while (++i < f->maxiter)
		{
			f->frac.oldre = f->frac.newre;
			f->frac.oldim = f->frac.newim;
			f->frac.newre = (f->frac.oldre * f->frac.oldre - f->frac.oldim
			* f->frac.oldim + f->frac.cre);
			f->frac.newim = (2 * f->frac.oldre * f->frac.oldim
			+ f->frac.cim);
			if (f->frac.newre * f->frac.newre + f->frac.newim
			* f->frac.newim > 4)
				break ;
		}
		color(f, i);
		f->y++;
	}
}

void	*fract_alg(void *fra)
{
	t_fract	*f;
	int		buff;

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
	pthread_t	t[f->thread];
	t_fract		fr[f->thread];

	i = -1;
	while (++i < f->thread)
	{
		ft_memcpy((void*)&fr[i], (void*)f, sizeof(t_fract));
		fr[i].y = THREAD_W * i;
		fr[i].y_max = THREAD_W * (i + 1);
		pthread_create(&t[i], NULL, fract_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
