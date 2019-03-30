/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:48:35 by bbear             #+#    #+#             */
/*   Updated: 2019/03/30 17:47:48 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fract *f)
{
	int		i;
	// double	n;

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
			f->frac.newre = f->frac.oldre * f->frac.oldre - f->frac.oldim * f->frac.oldim + (f->x - 0.5 * f->wid) / (0.45 * f->wid * f->zoom) + f->movex;
			f->frac.newim = 2 * f->frac.oldre * f->frac.oldim + (f->y - 0.5 * f->hei) / (0.45 * f->hei * f->zoom) + f->movey;
			if (f->frac.newre * f->frac.newre + f->frac.newim * f->frac.newim > 4)
				break;
		}
		// n = (double)i - log2(0.1 * log(f->frac.newre * f->frac.newre + f->frac.newim * f->frac.newim) / log(2));
		// i = ((int)n);
		f->data[f->x + f->y * f->wid] = (i) % 255 * 256 * 256 + (i * 1) % 255 * 256 + (i * 1) % 255;
		f->y++;
	}
}

void	burningship(t_fract *f)
{
	int		i;
	//double	n;

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
			f->frac.newre = -1 * (f->frac.oldre * f->frac.oldre - f->frac.oldim * f->frac.oldim)+ (f->x - 0.5 * f->wid) / (0.45 * f->wid * f->zoom) + f->movex;
			f->frac.newim = fabs(2 * f->frac.oldre * f->frac.oldim) + (f->y - 0.5 * f->hei) / (0.45 * f->hei * f->zoom) + f->movey;
			if (f->frac.newre * f->frac.newre + f->frac.newim * f->frac.newim > 4)
				break;
		}
		//n = (double)i - log(log(f->frac.newre * f->frac.newre - f->frac.newim * f->frac.newim) / log(1024)) / log(2);
		//i = abs((int)n);
		f->data[f->x + f->y * f->wid] = (i * 7) % 255 * 256 * 256 + (i * 7) % 255 * 256 + (i * 7) % 255;
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
			f->frac.newre = f->frac.oldre * f->frac.oldre * f->frac.oldre - 3 * f->frac.oldim * f->frac.oldim * f->frac.oldre + (f->x - 0.5 * f->wid) / (0.45 * f->wid * f->zoom) + f->movex;
			f->frac.newim = 3 * f->frac.oldre * f->frac.oldre * f->frac.oldim - f->frac.oldim * f->frac.oldim * f->frac.oldim + (f->y - 0.5 * f->hei) / (0.45 * f->hei * f->zoom) + f->movey;
			if (f->frac.newre * f->frac.newre + f->frac.newim * f->frac.newim > 4)
				break;
		}
		//n = (double)i - log(log(f->frac.newre * f->frac.newre - f->frac.newim * f->frac.newim) / log(1024)) / log(2);
		//i = abs((int)n);
		f->data[f->x + f->y * f->wid] = (i * 5) % 255 * 256 * 256 + (i * 4) % 255 * 256 + (i * 7) % 255;
		f->y++;
	}
}

void	biomorph(t_fract *f)
{
	int		i;
	double	n;

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
			f->frac.newre = (f->frac.oldre * f->frac.oldre * f->frac.oldre * f->frac.oldre - 6 * f->frac.oldre * f->frac.oldre * f->frac.oldim * f->frac.oldim + f->frac.cre);
			f->frac.newim = (4 * f->frac.oldre * f->frac.oldre * f->frac.oldre * f->frac.oldim * f->frac.oldim * f->frac.oldim + f->frac.cim);
			if (f->frac.newre * f->frac.newre + f->frac.newim * f->frac.newim > 4)
				break;
		}
		n = (double)i - log(log(f->frac.newre * f->frac.newre - f->frac.newim * f->frac.newim) / log(1024)) / log(2);
		i = abs((int)n);
		f->data[f->x + f->y * f->wid] = (i * 5) % 255 * 256 * 256 + (i * 4) % 255 * 256 + (i * 7) % 255;
		f->y++;
	}
}

// void	mandelbrot(t_fract *f)
// {
// 	long double	newim;
// 	long double	newre;
// 	long double	oldre;
// 	long double	oldim;
// 	int		i;
// 	int		x;
// 	int		y;
// 	//double	n;

// 	x = -1;
// 	while (++x < f->wid)
// 	{
// 		y = -1;
// 		while (++y < f->hei)
// 		{
// 			newre = 0 + f->frac.cre;
// 			newim = 0 + f->frac.cim;
// 			i = -1;
// 			while (++i < f->maxiter)
// 			{
// 				oldre = newre;
// 				oldim = newim;
// 				newre = oldre * oldre - oldim * oldim + (x - 0.5 * f->wid) / (0.45 * f->wid * f->zoom) + f->movex;
// 				newim = 2 * oldre * oldim + (y - 0.5 * f->hei) / (0.45 * f->hei * f->zoom) + f->movey;
// 				if (newre * newre + newim * newim > 4)
// 					break;
// 			}
// 			//n = (double)i - log(log(newre * newre - newim * newim) / log(256)) / log(2);
// 			//i = (int)n;
// 				//f->data[x + y * f->wid] = (i * 7) % 255 * 256 * 256 + (i * 4) % 255 * 256 + (i * 9) % 255;
// 			f->data[x + y * f->wid] = (i * 9) % 255 * 256 * 256 + (i * 0) % 255 * 256 + (i * 9) % 255;
// 		}
// 	}
// 	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
// 	mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 20, 16777215,
// 	ft_itoa(f->maxiter));
// }