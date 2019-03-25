/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:24:23 by bbear             #+#    #+#             */
/*   Updated: 2019/03/25 20:16:04 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_fract *fract)
{
	int		x;
	int		y;

	mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
	x = -1;
	while (++x < fract->wid)
	{
		y = -1;
		while (++y < fract->hei)
		{
			fract->data[y * fract->wid + x] = 0;
		}
	}
	//julia(fract);
	mandelbrot(fract);
}
