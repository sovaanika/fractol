/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:24:23 by bbear             #+#    #+#             */
/*   Updated: 2019/04/01 20:09:21 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_fract *f)
{
	int		x;
	int		y;
	char	*tmp;

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
	tmp = ft_itoa(f->maxiter);
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 20, 16777215, tmp);
	free(tmp);
	tmp = ft_itoa(f->zoom);
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 35, 16777215, tmp);
	free(tmp);
}
