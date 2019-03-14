/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:49:28 by bbear             #+#    #+#             */
/*   Updated: 2019/03/14 20:00:09 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(t_fract *fract)
{
	int		i;
	int		x;
	int		y;

	x = -1;
	while (++x < fract->wid)
	{
		y = -1;
		while (++y < fract->hei)
		{
			fract->frac.newre = 1.5 * (x - fract->wid / 2) / (0.5 * fract->wid);
			fract->frac.newim = (y - fract->hei / 2) / (0.5 * fract->hei);
			i = -1;
			while (++i < fract->maxiter)
			{
				fract->frac.oldre = fract->frac.newre;
				fract->frac.oldim = fract->frac.newim;
				fract->frac.newre = fract->frac.oldre * fract->frac.oldre - fract->frac.oldim * fract->frac.oldim + fract->frac.cre;
				fract->frac.newim = 2 * fract->frac.oldre * fract->frac.oldim + fract->frac.cim;
				if (fract->frac.newre * fract->frac.newre + fract->frac.newim * fract->frac.newim > 4)
					break;
			}
			fract->data[x + y * fract->wid] = (i * 7) % 255 * 256 * 256 + (i * 4) % 255 * 256 + (i * 9) % 255;
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
	mlx_string_put(fract->mlx_ptr, fract->win_ptr, 20, 20, 16777215,
	ft_itoa(fract->maxiter));
}