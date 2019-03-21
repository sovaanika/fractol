/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:49:28 by bbear             #+#    #+#             */
/*   Updated: 2019/03/21 19:40:37 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(t_fract *fract)
{
	int		i;
	int		x;
	int		y;
	double	n;

	x = -1;
	while (++x < fract->wid)
	{
		y = -1;
		while (++y < fract->hei)
		{
			fract->frac.newre = (x - fract->wid / 2) / (0.25 * fract->wid) * fract->zoom;
			fract->frac.newim = (y - fract->hei / 2) / (0.25 * fract->hei) * fract->zoom;
			i = -1;
			while (++i < fract->maxiter)
			{
				fract->frac.oldre = fract->frac.newre;
				fract->frac.oldim = fract->frac.newim;
				fract->frac.newre = (fract->frac.oldre * fract->frac.oldre - fract->frac.oldim * fract->frac.oldim + fract->frac.cre) * fract->zoom;
				fract->frac.newim = (2 * fract->frac.oldre * fract->frac.oldim + fract->frac.cim) * fract->zoom;
				if (fract->frac.newre * fract->frac.newre + fract->frac.newim * fract->frac.newim > 4)
					break;
			}
			n = (double)i - log(log(fract->frac.newre * fract->frac.newre - fract->frac.newim * fract->frac.newim) / log(1024)) / log(2);
			i = abs((int)n);
			fract->data[x + y * fract->wid] = (i * 7) % 255 * 256 * 256 + (i * 4) % 255 * 256 + (i * 9) % 255;
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
	mlx_string_put(fract->mlx_ptr, fract->win_ptr, 20, 20, 16777215,
	ft_itoa(fract->maxiter));
	mlx_string_put(fract->mlx_ptr, fract->win_ptr, 20, 35, 16777215,
	ft_itoa(fract->zoom));
}