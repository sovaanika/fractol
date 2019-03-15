/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:48:35 by bbear             #+#    #+#             */
/*   Updated: 2019/03/15 20:46:39 by bbear            ###   ########.fr       */
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

	x = -1;
	while (++x < fract->wid)
	{
		y = -1;
		while (++y < fract->hei)
		{
			newre = 0;
			newim = 0;
			i = -1;
			while (++i < fract->maxiter)
			{
				oldre = newre;
				oldim = newim;
				newre = (oldre * oldre - oldim * oldim + 1.5 * (x - fract->wid / 2) / (0.5 * fract->wid)) * 1.5;
				newim = (2 * oldre * oldim + (y - fract->hei / 2) / (0.5 * fract->hei)) * 1.5;
				if (newre * newre + newim * newim > 4)
					break;
			}
			if (x > fract->minre && y > fract->minim && x < fract->maxre && y < fract->maxim)
				fract->data[x + y * fract->wid] = (i * 7) % 255 * 256 * 256 + (i * 4) % 255 * 256 + (i * 9) % 255;
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
	mlx_string_put(fract->mlx_ptr, fract->win_ptr, 20, 20, 16777215,
	ft_itoa(fract->maxiter));
}