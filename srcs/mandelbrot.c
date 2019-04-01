/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:48:35 by bbear             #+#    #+#             */
/*   Updated: 2019/04/01 20:42:07 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fract *f)
{
	int		i;

	f->buff = 0 + f->frac.cre;
	while (f->y < f->y_max)
	{
		f->frac.newre = f->buff;
		f->frac.newim = 0 + f->frac.cim;
		i = -1;
		while (++i < f->maxiter)
		{
			f->frac.oldre = f->frac.newre;
			f->frac.oldim = f->frac.newim;
			f->frac.newre = f->frac.oldre * f->frac.oldre - f->frac.oldim *
			f->frac.oldim + (f->x - 0.5 * f->wid) / (0.45 * f->wid * f->zoom)
			+ f->movex;
			f->frac.newim = 2 * f->frac.oldre * f->frac.oldim + (f->y - 0.5
			* f->hei) / (0.45 * f->hei * f->zoom) + f->movey;
			if (f->frac.newre * f->frac.newre + f->frac.newim
			* f->frac.newim > 4)
				break ;
		}
		color(f, i);
		f->y++;
	}
}

void	burningship(t_fract *f)
{
	int		i;

	f->buff = 0 + f->frac.cre;
	while (f->y < f->y_max)
	{
		f->frac.newre = f->buff;
		f->frac.newim = 0 + f->frac.cim;
		i = -1;
		while (++i < f->maxiter)
		{
			f->frac.oldre = f->frac.newre;
			f->frac.oldim = f->frac.newim;
			f->frac.newre = -1 * (f->frac.oldre * f->frac.oldre - f->frac.oldim
			* f->frac.oldim) + (f->x - 0.5 * f->wid) / (0.45 * f->wid
			* f->zoom) + f->movex;
			f->frac.newim = fabs(2 * f->frac.oldre * f->frac.oldim) + (f->y
			- 0.5 * f->hei) / (0.45 * f->hei * f->zoom) + f->movey;
			if (f->frac.newre * f->frac.newre + f->frac.newim
			* f->frac.newim > 4)
				break ;
		}
		color(f, i);
		f->y++;
	}
}

void	trimandelbrot(t_fract *f)
{
	int		i;

	f->buff = 0 + f->frac.cre;
	while (f->y < f->y_max)
	{
		f->frac.newre = f->buff;
		f->frac.newim = 0 + f->frac.cim;
		i = -1;
		while (++i < f->maxiter)
		{
			f->frac.oldre = f->frac.newre;
			f->frac.oldim = f->frac.newim;
			f->frac.newre = f->frac.oldre * f->frac.oldre * f->frac.oldre - 3
			* f->frac.oldim * f->frac.oldim * f->frac.oldre + (f->x - 0.5
			* f->wid) / (0.45 * f->wid * f->zoom) + f->movex;
			f->frac.newim = 3 * f->frac.oldre * f->frac.oldre * f->frac.oldim
			- f->frac.oldim * f->frac.oldim * f->frac.oldim + (f->y - 0.5
			* f->hei) / (0.45 * f->hei * f->zoom) + f->movey;
			if (f->frac.newre * f->frac.newre + f->frac.newim
			* f->frac.newim > 4)
				break ;
		}
		color(f, i);
		f->y++;
	}
}

void	biomorph(t_fract *f)
{
	int		i;

	f->buff = (f->x - f->wid * 0.5) / (0.45 * f->wid * f->zoom) + f->movex;
	while (f->y < f->y_max)
	{
		f->frac.newre = f->buff;
		f->frac.newim = (f->y - f->hei * 0.5)
		/ (0.45 * f->hei * f->zoom) + f->movey;
		i = -1;
		while (++i < f->maxiter)
		{
			f->frac.oldre = f->frac.newre;
			f->frac.oldim = f->frac.newim;
			f->frac.newre = (f->frac.oldre * f->frac.oldre * f->frac.oldre
			* f->frac.oldre - 6 * f->frac.oldre * f->frac.oldre * f->frac.oldim
			* f->frac.oldim + f->frac.cre);
			f->frac.newim = (4 * f->frac.oldre * f->frac.oldre * f->frac.oldre
			* f->frac.oldim * f->frac.oldim * f->frac.oldim + f->frac.cim);
			if (f->frac.newre * f->frac.newre + f->frac.newim
			* f->frac.newim > 4)
				break ;
		}
		color(f, i);
		f->y++;
	}
}
