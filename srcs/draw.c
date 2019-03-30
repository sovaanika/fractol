/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:24:23 by bbear             #+#    #+#             */
/*   Updated: 2019/03/29 19:55:10 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_fract *f)
{
	int		x;
	int		y;

	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	x = -1;
	while (++x < f->wid)
	{
		y = -1;
		while (++y < f->hei)
		{
			f->data[y * f->wid + x] = 0;
		}
	}
	fract(f);
	//mandelbrot(f);
}
