/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:24:23 by bbear             #+#    #+#             */
/*   Updated: 2019/03/13 19:46:12 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_fract *fract)
{
	int		x;
	int		y;

	x = -1;
	while (++x < fract->wid)
	{
		y = -1;
		while (++y < fract->hei)
		{
			fract->data[y * fract->wid + x] = 0;
		}
	}
	julia(fract);
}
