/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:48:35 by bbear             #+#    #+#             */
/*   Updated: 2019/03/13 16:49:17 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fract *fract)
{
	double	newim;
	double	newre;
	double	oldre;
	double	oldim;
	int		i;
	int		x;
	int		y;
	int		maxiter;

	x = -1;
	maxiter = 3000;
	while (++x < fract->wid)
	{
		y = -1;
		while (++y < fract->hei)
		{
			newre = 0;
			newim = 0;
			i = -1;
			while (++i < maxiter)
			{
				oldre = newre;
				oldim = newim;
				newre = oldre * oldre - oldim * oldim + 1.5 * (x - fract->wid / 2) / (0.5 * fract->wid);
				newim = 2 * oldre * oldim + (y - fract->hei / 2) / (0.5 * fract->hei);
				if (newre * newre + newim * newim > 3)
					break;
			}
			fract->data[x + y * fract->wid] = (i * 1) % 255 * 256 * 256 + (i * 4) % 255;
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
}