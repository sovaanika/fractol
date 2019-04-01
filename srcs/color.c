/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:31:16 by bbear             #+#    #+#             */
/*   Updated: 2019/04/01 19:57:47 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	colorinit(t_fract *f)
{
	f->color.r = 0;
	f->color.g = 5;
	f->color.b = 5;
}

void	changecolor(t_fract *f, int key)
{
	if (key == 15 && f->color.r < 9)
		f->color.r++;
	else if (key == 5 && f->color.g < 9)
		f->color.g++;
	else if (key == 11 && f->color.b < 9)
		f->color.b++;
	else if (key == 15 && f->color.r == 9)
		f->color.r = 0;
	else if (key == 5 && f->color.g == 9)
		f->color.g = 0;
	else if (key == 11 && f->color.b == 9)
		f->color.b = 0;
}

void	color(t_fract *f, int i)
{
	double	n;

	if (f->colorflag)
	{
		n = (double)i - log(log(f->frac.newre * f->frac.newre - f->frac.newim
		* f->frac.newim) / log(2048)) / log(2);
		i = (int)n;
	}
	if (f->x < f->wid && f->y < f->hei && i != f->maxiter)
		f->data[f->y * f->wid + f->x] =
		(((i * f->color.r) % 255) << 16) + (((i * f->color.g) % 255) << 8)
		+ (i * f->color.b) % 255;
	else if ((f->x < f->wid && f->y < f->hei))
		f->data[f->y * f->wid + f->x] = 0;
}
